mod ffi {
    include!(concat!(env!("OUT_DIR"), "/device.rs"));
}

fn main() {
    println!("Hello, world!");
}
