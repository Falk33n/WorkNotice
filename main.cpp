#include "WorkNotice.h"
#include "QApplication"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow mainWindow;
    WorkNotice workNotice(&mainWindow);
    mainWindow.show();
    return app.exec();
}