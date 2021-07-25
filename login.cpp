#include "login.h"
#include "ui_login.h"

#include <iostream>

LoginWindow::LoginWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::LoginWindow) {
    ui->setupUi(this);
    this->setCentralWidget(ui->centralwidget);
    connect(ui->launchButton,&QPushButton::pressed,this,&LoginWindow::launch);
}
LoginWindow::~LoginWindow() {
    delete ui;
}

void LoginWindow::launch() {

}

void LoginWindow::updateProgress(int percent, bool done) {
    if (percent >= 100) percent = 100;
    else if (percent <= 0) percent = 0;
    
    if (done) {
        ui->progressBar->hide();
        ui->launchButton->setDisabled(false);
        ui->updateState->setText("Up to date.");
    } else {
        ui->progressBar->show();
        ui->launchButton->setDisabled(true);
        ui->updateState->setText("Installing updates...");
    }

    ui->progressBar->setValue(percent);
}