#include "mainwindow.h"
#include "globalmanager.h"
#include<random>
#include<ctime>
#include <QApplication>

int main(int argc, char *argv[])
{    

    QApplication a(argc, argv);
    initGlobalManager();
    srand((unsigned)time(NULL));
    GlobalManager::night = rand()%100 < 50 ? true : false;
    GlobalManager::SunNumber = GlobalManager::night ? 225 : 100;
    MainWindow w;
    w.show();
    
    return a.exec();
}
