#include "gui/MainWindow.h"

#include "DummyTaskService.h"

int main(int argc, char **argv)
{
    core::DummyTaskService *dts = new core::DummyTaskService();
    QApplication app(argc, argv);
    MainWindow mainWindow(dts);
    mainWindow.show();
    return app.exec();
}
