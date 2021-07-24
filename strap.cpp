#include <QApplication>
#include <QLabel>
#include <QWidget>
#include <json/json.h>
#include <curl/curl.h>
#include <jni.h>

#define PACK_TITLE "AndromedaModpack"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    QLabel demo("<center>Demo window</center>");
    demo.setWindowTitle(PACK_TITLE);
    demo.resize(400, 400);
    demo.show();

    return app.exec();
}