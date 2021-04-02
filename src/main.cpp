#include <QtWidgets>
#include "view/mainwidget.h"
#include "model/model.h"
#include "persistence/persistence.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Persistence* p = new Persistence();
    Model* m = new Model(p);
    MainWidget w(m);
    w.show();
    return a.exec();
}
