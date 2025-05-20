use std::{env, path::PathBuf};

fn main() {
    match (cfg!(feature = "libusb"), cfg!(feature = "hidraw")) {
        (true, true) => {
            println!("cargo::error=Cannot enable both libusb and hidraw features");
            return;
        }
        (true, false) => {
            println!("cargo::rustc-link-lib=hidapi-libusb");
        }
        (false, true) => {
            println!("cargo::rustc-link-lib=hidapi-hidraw");
        }
        (false, false) => {
            println!("cargo::error=Must enable either libusb or hidraw feature");
            return;
        }
    };

    let bindings = bindgen::Builder::default()
        .header("./wrapper.h")
        .parse_callbacks(Box::new(bindgen::CargoCallbacks::new()))
        .generate()
        .expect("Successfully generated bindings");

    let out_path = PathBuf::from(env::var("OUT_DIR").unwrap());
    bindings
        .write_to_file(out_path.join("bindings.rs"))
        .unwrap();
}
