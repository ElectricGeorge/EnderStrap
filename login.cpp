#include "login.h"
#include "ui_login.h"

LoginWindow::LoginWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::LoginWindow) {
    ui->setupUi(this);
    this->setCentralWidget(ui->centralwidget);
}
LoginWindow::~LoginWindow() {
    delete ui;
}

void LoginWindow::setUsername() {

}

void LoginWindow::setPassword() {

}

void LoginWindow::exit() {

}

void LoginWindow::launch() {

}