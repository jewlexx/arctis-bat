mod ffi {
    #![allow(non_upper_case_globals)]
    #![allow(dead_code)]
    #![allow(non_camel_case_types)]

    include!(concat!(env!("OUT_DIR"), "/device.rs"));
}
use ffi::{device_status, get_device_status};
use hidapi_sys::{
    hid_close, hid_exit, hid_get_manufacturer_string, hid_get_product_string, hid_init, hid_open,
    wchar_t, wcslen,
};

use widestring::U16CString;

const MAX_STR: usize = 255;

fn main() {
    let mut res = 0;
    res = unsafe { hid_init() };

    let handle = unsafe {
        hid_open(
            ffi::VENDOR_ID as u16,
            ffi::PRODUCT_ID as u16,
            core::ptr::null(),
        )
    };

    let wstr: [wchar_t; MAX_STR] = [0; MAX_STR];

    res = unsafe { hid_get_manufacturer_string(handle, wstr.as_ptr().cast_mut(), MAX_STR) };
    let manufacturer_string = unsafe {
        U16CString::from_ptr_truncate(wstr.as_ptr().cast(), wcslen(wstr.as_ptr()) as usize)
    };

    res = unsafe { hid_get_product_string(handle, wstr.as_ptr().cast_mut(), MAX_STR) };
    let product_string = unsafe {
        U16CString::from_ptr_truncate(wstr.as_ptr().cast(), wcslen(wstr.as_ptr()) as usize)
    };
    let mut device_status = device_status {
        ..unsafe { core::mem::zeroed() }
    };

    if unsafe { get_device_status(handle.cast(), &mut device_status) } < 0 {
        eprintln!("Failed to get device status");
        unsafe { hid_close(handle) };
        unsafe { hid_exit() };
        std::process::exit(1);
    }

    let pretty_status = match device_status.status {
        3 => "Discharging",
        1 => "Charging",
        _ => "Disconnected",
    };

    unsafe { hid_close(handle) };
    res = unsafe { hid_exit() };

    println!("Manufacturer string: {}", manufacturer_string.display());
    println!("Product string: {}", product_string.display());
    println!(
        "Charging status: {} ({})",
        pretty_status, device_status.status
    );
    println!("Charge: {:.02}", device_status.battery_level);

    std::process::exit(res);
}
