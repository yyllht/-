#ifndef REPEATER_H
#define REPEATER_H

#include "abstractplant.h"

class Repeater : public AbstractPlant
{
    Q_OBJECT
public:
    Repeater(int RowVal, int ColumnVal);
    ~Repeater();
    
signals:
    void EmitPea(int, int);
    
public slots:
    void StartEmitPea();
    void StopEmitPea();
    
private slots:
    void EmitPeaSlot();
    
private:
    QTimer *EmitPeaTimer;
};

#endif // REPEATER_H
