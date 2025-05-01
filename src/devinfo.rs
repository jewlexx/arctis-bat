use std::rc::{Rc, Weak};

use hidapi::{HidApi, HidDevice};

#[derive(Debug, Copy, Clone, thiserror::Error)]
pub enum Error {
    #[error("Device not available")]
    DeviceNotAvailable,
    #[error("Timeout reading from device")]
    Timeout,
}

#[derive(Debug, Clone)]
pub struct DeviceInfo {
    device: Rc<HidDevice>,
}

impl DeviceInfo {
    pub fn new() -> Option<Self> {
        let mut api = HidApi::new_without_enumerate().unwrap();
        // find all devices with vendor ID 0x1038 (SteelSeries)
        // product ID is set to 0 for no filter
        api.add_devices(0x1038, 0).expect("Failed to scan devices");

        for device in api.device_list() {
            if device.product_id() == 0x2202 && device.interface_number() == 3 {
                let headset: HidDevice = device.open_device(&api).unwrap();

                return Some(Self::from_rc(Rc::new(headset)));
            }
        }

        None
    }

    fn from_rc(device: Rc<HidDevice>) -> Self {
        Self { device }
    }

    pub fn get_status(&self) -> Result<DeviceState, Error> {
        self.device.write(&[0x00, 0xb0]).unwrap();

        let mut buf = [0u8; 4];

        let num_read = self.device.read_timeout(&mut buf, 100).unwrap();

        if num_read == 0 {
            Err(Error::Timeout)
        } else {
            let status = ChargingStatus::from(buf[3]);
            let battery = (buf[2] as f32 / 4.0) * 100.0;

            Ok(DeviceState {
                battery,
                status,
                device: Rc::downgrade(&self.device),
            })
        }
    }
}

#[repr(u8)]
#[derive(Debug, Copy, Clone)]
pub enum ChargingStatus {
    Charging = 1,
    Discharging = 3,
    Disconnected = 0,
}

impl From<u8> for ChargingStatus {
    fn from(value: u8) -> Self {
        match value {
            1 => ChargingStatus::Charging,
            3 => ChargingStatus::Discharging,
            _ => ChargingStatus::Disconnected,
        }
    }
}

pub struct DeviceState {
    pub battery: f32,
    pub status: ChargingStatus,
    device: Weak<HidDevice>,
}

impl DeviceState {
    pub fn battery(&self) -> f32 {
        self.battery
    }

    pub fn status(&self) -> ChargingStatus {
        self.status
    }

    pub fn try_update(&mut self) -> Result<(), Error> {
        if let Some(device) = self.device.upgrade() {
            let state = DeviceInfo::from_rc(device).get_status()?;
            self.battery = state.battery;
            self.status = state.status;

            Ok(())
        } else {
            Err(Error::DeviceNotAvailable)
        }
    }
}
