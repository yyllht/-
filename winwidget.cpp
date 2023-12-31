#include "enumlist.h"
#include "winwidget.h"
#include "globalmanager.h"
#include "qapplication.h"

WinWidget::WinWidget(QWidget* parent) : AbstractWidget(parent)
{
    setFixedWidth(ForScale(GlobalManager::StanradWindowWidth));
    setFixedHeight(ForScale(GlobalManager::StanradWindowHeight));
    setMouseTracking(true);
    WinLabel = new QLabel(this);
    WinLabel->setMouseTracking(true);
    WinPixmap = new QPixmap(":/surface/res/images/surface/win.jpg");
    *WinPixmap = WinPixmap->scaled(ForScale(GlobalManager::StanradWindowWidth),
                                   ForScale(GlobalManager::StanradWindowHeight));
    WinLabel->resize(ForScale(GlobalManager::StanradWindowWidth),
                     ForScale(GlobalManager::StanradWindowHeight));
    WinLabel->move(0, 0);
    WinLabel->setPixmap(*WinPixmap);
    WinLabel->show();
}

WinWidget::~WinWidget()
{
    delete WinLabel;
    delete WinPixmap;
}

void WinWidget::mousePressEvent(QMouseEvent *event)
{
    qApp->quit();;
}
