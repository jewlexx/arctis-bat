use std::{fmt::Display, rc::Rc};

pub const VENDOR_ID: u16 = 0x1038;
pub const PRODUCT_ID: u16 = 0x2022;
pub const PRODUCT_ID_WIRED: u16 = 0x2000;

#[repr(u8)]
#[derive(Debug, Clone, Copy, PartialEq)]
pub enum ChargingStatus {
    Disconnected = 0x00,
    Charging = 0x01,
    Discharging = 0x03,
}

impl From<u8> for ChargingStatus {
    fn from(value: u8) -> Self {
        match value {
            0x01 => ChargingStatus::Charging,
            0x03 => ChargingStatus::Discharging,
            _ => ChargingStatus::Disconnected,
        }
    }
}

impl Display for ChargingStatus {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            ChargingStatus::Disconnected => "Disconnected".fmt(f),
            ChargingStatus::Charging => "Charging".fmt(f),
            ChargingStatus::Discharging => "Discharging".fmt(f),
        }
    }
}

#[derive(Debug, Clone)]
pub struct DeviceStatus {
    device: Rc<hidapi::HidDevice>,
    status: ChargingStatus,
    battery_level: f32,
}

impl DeviceStatus {
    const REQUEST: [u8; 2] = [0x00, 0xb0];

    pub fn new() -> Result<Self, hidapi::HidError> {
        let api = hidapi::HidApi::new()?;

        let device = api.open(VENDOR_ID, PRODUCT_ID)?;

        // let manu_string = device.get_manufacturer_string()?;

        // if let Some(manu_string) = manu_string {
        //     println!("Manufacturer String: {}", manu_string);
        // } else {
        //     println!("Missing Manufacturer String");
        // }

        // let product_string = device.get_product_string()?;

        // if let Some(product_string) = product_string {
        //     println!("Product String: {}", product_string);
        // } else {
        //     println!("Missing Product String");
        // }

        let mut buf = [0u8; 4];

        device.write(&Self::REQUEST)?;
        device.read(&mut buf)?;

        Ok(Self {
            device: Rc::new(device),
            status: buf[3].into(),
            battery_level: (buf[2] as f32 / 4.0) * 100.0,
        })
    }

    pub fn update(&mut self) -> Result<(), hidapi::HidError> {
        let mut buf = [0u8; 4];

        self.device.write(&Self::REQUEST)?;
        self.device.read(&mut buf)?;

        self.status = buf[3].into();
        self.battery_level = (buf[2] as f32 / 4.0) * 100.0;

        Ok(())
    }
}
