// Local includes
#include "WorkNotice.h"

// 3rd party includes
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow mainWindow;
    WorkNotice workNotice(&mainWindow);
    mainWindow.show();
    return app.exec();
}