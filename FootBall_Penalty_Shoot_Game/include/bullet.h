#ifndef BULLET_H
#define BULLET_H
#include "GAMEELEMENTS.h"
#include "Enemy.h"
#include "gameControl.h"
class bullet:public GAMEELEMENTS
{
    public:
        bullet(int x=0,int y=0);
        virtual ~bullet();
        void add(int x=0,int y=0);
        static void update();
        void setPosition(int x,int y);
        int create();
        void setSpeed(int spd);
        void creatBullet();
        void creatBullet(bullet &blt);
    protected:
    static vector <bullet> bullets;
    vector <string> images;
    int x,y,bulletIndex,damage;
    static int bltSpeed;
    private:
};

#endif // BULLET_H
