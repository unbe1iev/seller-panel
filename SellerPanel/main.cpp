#include "menu.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    menu sellerpanel;
    sellerpanel.init();
    sellerpanel.show();
    return a.exec();
}
