#include <QtGui/QApplication>
#include "LogWindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LogWindow w;
    w.show();

    return a.exec();
}
