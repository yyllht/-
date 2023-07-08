#include "repeater.h"
#include "globalmanager.h"
#include <QLabel>
#include <QMovie>
#include <QTimer>

Repeater::Repeater(int RowVal, int ColumnVal)
{
    ThisPlantType = PlantType::Repeater;
    Row = RowVal;
    Column = ColumnVal;
    Blood = 6;
    Width = 73;
    Height = 71;
    PlantLabel = new QLabel(GlobalManager::CurrentWidget);
    PlantLabel->setMouseTracking(true);
    PlantLabel->show();
    PlantLabel->raise();
    PlantLabel->setGeometry(ForScale(GlobalManager::PosX[Column] - 40 - Width / 2), 
                            ForScale(GlobalManager::PosY[Row] - 47 - Height / 2),
                            ForScale(Width), ForScale(Height));
    PlantMovie = new QMovie(":/plant/res/images/plant/Repeater/Repeater.gif");
    PlantMovie->setScaledSize(QSize(ForScale(Width), ForScale(Height)));
    PlantMovie->setSpeed(80);
    PlantLabel->setMovie(PlantMovie);
    PlantMovie->start();
    
    EmitPeaTimer = new QTimer;
    EmitPeaTimer->setInterval(750);
    connect(EmitPeaTimer, SIGNAL(timeout()), this, SLOT(EmitPeaSlot()));
}

Repeater::~Repeater()
{
    delete EmitPeaTimer;
}

void Repeater::EmitPeaSlot()
{
    emit EmitPea(Row, Column);
}

void Repeater::StartEmitPea()
{
    if(EmitPeaTimer->isActive())
        return;
    EmitPeaTimer->start();    
}

void Repeater::StopEmitPea()
{
    EmitPeaTimer->stop();
}
