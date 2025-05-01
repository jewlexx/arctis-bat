use std::ffi::c_void;

use devinfo::{ChargingStatus, DeviceInfo as RustDeviceInfo};

mod devinfo;

#[repr(C)]
#[derive(Debug, Clone)]
pub struct DeviceInfo {
    inner: *const c_void,
}

impl DeviceInfo {
    pub fn from_rust(device: RustDeviceInfo) -> DeviceInfo {
        Self {
            inner: Box::into_raw(Box::new(device)).cast(),
        }
    }
}

#[unsafe(no_mangle)]
extern "C" fn initialize_device() -> DeviceInfo {
    let rdevice = RustDeviceInfo::new().expect("find valid arctis 7 headset");

    DeviceInfo::from_rust(rdevice)
}

#[repr(C)]
pub struct DeviceStatus {
    pub battery: f32,
    pub status: ChargingStatus,
}

#[unsafe(no_mangle)]
extern "C" fn get_status(device_info: *const c_void, status: *mut DeviceStatus) {
    let Some(device_info) = (unsafe { device_info.cast::<RustDeviceInfo>().as_ref() }) else {
        return;
    };

    let Ok(device_status) = device_info.get_status() else {
        return;
    };

    let Some(status) = (unsafe { status.as_mut() }) else {
        println!("Failed to convert status");
        return;
    };

    status.battery = device_status.battery();
    status.status = device_status.status();
}
