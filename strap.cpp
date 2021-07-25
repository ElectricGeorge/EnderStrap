#include "strap.h"

#include <iostream>
#include <fstream>
#include <filesystem>
#include <thread>
#include <QApplication>
#include <QDir>
#include "login.h"
#include <json/json.h>
#include <curl/curl.h>
#include <jni.h>

#define PACK_TITLE "AndromedaModpack"
#define PACK_ID "1a123310dd34d97c0d2330e88c494bd40dbec111"
#define PACK_ASSETS_URL "http://mc.1.gawitt.net/assets"
#define PACK_AUTH "http://mc.1.gawitt.net"

int window(int argc, char* argv[], LoginWindow** handle) {

    QApplication app(argc, argv);
    LoginWindow loginWindow;
    *handle = &loginWindow;
    loginWindow.show();
    int result = app.exec();
    return result;
}

int main(int argc, char* argv[]) {
    
    Json::Value root;
    //std::cout << QDir::homePath().toStdString() + "/.enderstrap/user.json";
    std::string user_path = QDir::homePath().toStdString() + "/.enderstrap/" + PACK_ID;

    std::ifstream ifs;
    ifs.open(user_path + "/user.json");
    if (!ifs.is_open()) {
        std::filesystem::create_directories(user_path);
        std::ofstream newuser(user_path + "/user.json");
        newuser << "{}";
        newuser.close();
        ifs.open(user_path);
        if (!ifs.is_open()) {
            std::cout << "failed!" << std::endl;
            return -1;
        }
    }

    LoginWindow* windowHandle = nullptr;
    char* w_args = nullptr;
    std::thread window_thread(window, 0, &w_args, &windowHandle);
    while (windowHandle == nullptr);

    windowHandle->updateProgress(100, false);

    window_thread.join();
    
    return 0;
}
