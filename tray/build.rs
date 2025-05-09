use std::{env, path::PathBuf};

fn main() {
    println!("cargo:rustc-link-lib=hidapi-hidraw");

    let bindings = bindgen::Builder::default()
        .header("../device.h")
        .parse_callbacks(Box::new(bindgen::CargoCallbacks::new()))
        .generate()
        .expect("Successfully generated bindings");

    let out_path = PathBuf::from(env::var("OUT_DIR").unwrap());
    bindings.write_to_file(out_path.join("device.rs")).unwrap();
}
