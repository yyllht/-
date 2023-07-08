#Plants vs Zombies Report
-----
##1 工程简介
该程序由Qt开发，库为Qt 5.7.0，默认编译器为mingw32 GNU Make 4.1版本。

其中，源文件和工程文件均位于工程根目录下，其中Plants-VS-Zombies.pro为该工程的工程文件。音乐文件位于 ./res/audio目录下，图片文件位于./res/images目录下。
##2 类设计
该程序的类设计主要分为抽象类，窗体类，植物类，僵尸类，管理器类和特殊类。
###2.1 抽象类：1）abstractwidget类，所有窗口的抽象，通过QT里的QWidget初始化，用于提供一个信号来控制窗体的产生和摧毁2）abstractplant类，所有植物共同点，通过QObject初始化，包括了框体label（用于选中）、血量blood、行列row和column、宽高width和height、动画movie，在abstractplant.cpp里设置了血量blood为零时的死亡3）abstractzombie类，与abstractplant类似，多了编号id和移动PosX、PosY。

###2.2 窗口类：welcomewidget类、winwidget类、advancewidget类和failwidget类都是通过程序控制，且通过窗口的消亡和产生来转变窗口的类和实例。

###2.3 植物类：1）向日葵（SunFlower）类，继承自abstractplant类，除了植物共同特点外，有一个时钟控制阳光产生，以及控制阳光产生的函数ProduceSun。2）豌豆射手类（Peashooter）同样继承自abstract类，通过StartEmitPea和StopEmitPea函数来控制开始和停止发射豌豆，通过EmitPea函数控制发射豌豆，以及有一个时钟来控制间隔。3）坚果墙类wallnut，继承自abstractplant类，通过数据来控制血量，有一个状态检测的函数，当血量低于特定值时动画会改变成一个被啃坏的坚果墙。4）双发豌豆类，继承自abstractplant类，发射豌豆频率与豌豆射手类相比更快。

###2.4 僵尸类：1）普通僵尸类NormalZombie，继承自abstractzombie，头和身体分开用框体label和动画movie，因为僵尸受到伤害时先断一只手，死亡时头先掉，然后身体倒下。有getAttack函数控制被攻击、死亡等，有ZombieMove函数控制移动，同时有与坚果墙类似的血量监测函数来控制血量较低时的变化。2）铁通僵尸BucketheadZombie，总体与普通僵尸类似，控制变化的函数SwitchStatus中多了铁桶的变化。3）撑杆跳僵尸PoleVaultingZombie，比普通僵尸多了跳跃相关的函数Jump，Jump2，Jump3分别控制跳跃的开始，跳跃过程和跳跃后的移动。4）路障僵尸类roadblockzombie，血量介于普通僵尸和铁桶僵尸之间，其余与铁桶僵尸类似。

###2.5 管理器类：1）CardManager类用于分配卡片、提供卡片索引、并在阳光值变化时、种植植物后改变卡片可否使用的状态（通过CheckAllCard函数），2）SunManager类，用于阳光的产生销毁，增减和打印，通过GenerateSun和SunNumberUpdate来记录阳光总量，通过AddSunNumber和MinusSunNumber来控制阳光的增减3）WarManager类负责全局规划、储存植物、豌豆和僵尸状态、进行战斗判定和刷新，通过abstractplant类指针的grass[5][9]数组来储存植物状态，PeaManager数组储存豌豆状态，通过abstractzombie类指针的ZombieManager[150]来储存僵尸状态。GeneratePea、GenerateZombie，DeletePlant，DeleteZombie，ClockUpdate等来刷新战斗状态。
	
###2.6 特殊类：1）阳光（sun.h和sun.cpp）在sun.h中建立了sun类，主要控制阳光的向日葵产生、天上下降产生、位置、超时消失、点击消失、出现间隔、持续时间等，在sun.cpp中对sun类的函数进行具体编写，例如将边界，位置等具体化。2）豌豆（pea）类，有框体PeaLabel、宽高、移动以及PeaPixmap。3）卡片类PlantCard，用于不同卡片的图像表示和卡片冷却、点亮等动画的操作。有NormalCard、DisableCard、FreezeCard等不同状态，也有阳光花费SunCost、冷却时间FreezeMsec、Timeused等属性，检测CheckThis、RecoveryFreeze等函数。

