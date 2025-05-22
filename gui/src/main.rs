// use gtk::{Application, glib};
// use gtk::{ApplicationWindow, prelude::*};

// mod ui;

// const APP_ID: &str = "dev.cordor.ArctisBattery";

// fn main() -> glib::ExitCode {
//     // Create a new application
//     let app = Application::builder().application_id(APP_ID).build();

//     app.connect_activate(build_ui);

//     // Run the application
//     app.run()
// }

// fn build_ui(app: &Application) {
//     // Create a window and set the title
//     let window = ui::ui(
//         ApplicationWindow::builder()
//             .application(app)
//             .title("Arctis Battery"),
//     )
//     .build();

//     // Present window
//     window.present();
// }

mod timer;

use std::time::Duration;

use arctisbat::DeviceStatus;
use eframe::egui;
use timer::Timer;

fn main() {
    let native_options = eframe::NativeOptions::default();
    eframe::run_native(
        "My egui App",
        native_options,
        Box::new(|cc| Ok(Box::new(MyEguiApp::new(cc)))),
    );
}

struct MyEguiApp {
    timer: Timer,
    device_status: DeviceStatus,
}

impl MyEguiApp {
    fn new(cc: &eframe::CreationContext<'_>) -> Self {
        // Customize egui here with cc.egui_ctx.set_fonts and cc.egui_ctx.set_visuals.
        // Restore app state using cc.storage (requires the "persistence" feature).
        // Use the cc.gl (a glow::Context) to create graphics shaders and buffers that you can use
        // for e.g. egui::PaintCallback.
        Self {
            timer: Timer::new(Duration::from_secs(2)),
            device_status: DeviceStatus::new().unwrap(),
        }
    }
}

impl eframe::App for MyEguiApp {
    fn update(&mut self, ctx: &egui::Context, frame: &mut eframe::Frame) {
        if self.timer.tick() {
            self.timer.reset();
            self.device_status.update().unwrap();
        }

        egui::CentralPanel::default().show(ctx, |ui| {
            ui.heading("Hello World!");
            ui.heading(format!(
                "{:.02}% ({})",
                self.device_status.battery_level, self.device_status.status
            ));
        });
    }
}
