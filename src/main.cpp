#include <QApplication>
#include "view/mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    IQuiztMainWindow w;
    w.show();
    return a.exec();
}
