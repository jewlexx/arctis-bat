use std::time::{Duration, SystemTime};

pub struct Timer {
    target: Duration,
    current: Duration,
    last_tick: SystemTime,
}

impl Timer {
    pub fn new(target: Duration) -> Self {
        Self {
            last_tick: SystemTime::now(),
            target,
            current: Duration::ZERO,
        }
    }

    pub fn tick(&mut self) -> bool {
        let time_since_tick = self.last_tick.elapsed().unwrap_or_default();
        self.last_tick = SystemTime::now();
        self.current += time_since_tick;

        self.current >= self.target
    }

    pub fn reset(&mut self) {
        self.current = Duration::ZERO;
    }
}
