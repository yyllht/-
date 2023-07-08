#ifndef ROADBLOCKZOMBIE_H
#define ROADBLOCKZOMBIE_H

#include <QLabel>
#include <QMovie>
#include "abstractzombie.h"

class RoadblockZombie : public AbstractZombie
{
    Q_OBJECT
public:
    explicit RoadblockZombie(int, int);
    ~RoadblockZombie();
    
    enum class RoadblockZombieStatus {HeadNormal, HeadEating, Normal, Eating, Die};
    
    void getAttack();
    void SwitchStatus();
    int getStatus() const { return static_cast<int>(CurrentStatus); }

public slots:
    void ZombieMove();
    
private slots:
    void DeleteHead();
    void DeleteBody();
    
private:
    QLabel* HeadLabel;
    QMovie* HeadMovie;
    QLabel* BodyLabel;
    QMovie* BodyMovie;
    RoadblockZombieStatus CurrentStatus;
};

#endif // ROADBLOCKZOMBIE_H

