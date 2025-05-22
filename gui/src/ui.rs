use gtk::builders::ApplicationWindowBuilder;

pub fn ui(window: ApplicationWindowBuilder) -> ApplicationWindowBuilder {
    let padded = gtk::Box::builder()
        .orientation(gtk::Orientation::Vertical)
        .spacing(0);

    window.child(&padded)
}
