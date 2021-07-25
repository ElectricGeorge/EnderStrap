#include "strap.h"

#include <QApplication>
#include "login.h"
#include <json/json.h>
#include <curl/curl.h>
#include <jni.h>

#define PACK_TITLE "AndromedaModpack"



int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    LoginWindow loginWindow;
    loginWindow.show();

    return app.exec();
}
