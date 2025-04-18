#include "bullet.h"

bullet::bullet(int x,int y)
{
    this->setPosition(x,y);
    this->images = folderToVector("res/Bullet/bmp");
    this->bulletIndex=rand()%this->images.size();
    this->damage=50;
}

bullet::~bullet()
{
    //dtor
}
void bullet::add(int x,int y)
{
    bullet b(x,y);
    bullet::update();
    bullets.push_back(b);
    if(bullets[0].x>1400)
        bullets.erase(bullets.begin());
}

void bullet::setPosition(int x,int y)
{
    this->x=x;
    this->y=y;
}
int bullet::create()
{
    int i;
    for(i=0; i<bullets.size(); i++)
    {
        iSetColor(255,0,0);
        this->creatBullet(bullets[i]);
    }
    return 0;
}
void bullet::setSpeed(int spd)
{
    bullet::bltSpeed=spd;
}
void bullet::update()
{
    int i,j;
    for(j=0; j<bullets.size(); j++)
    {

        bullets[j].x+=bltSpeed;

    }
}
void bullet::creatBullet(bullet &blt)
{
    blt.bulletIndex%=blt.images.size();
    string str =   ("res/Bullet/bmp/"+blt.images[blt.bulletIndex]);
    bool flag=0;



    int i;
        for(i=0; i<Enemy::enemies.size(); i++)
        {

           if(Enemy::enemies[i].inCollision(blt.x,blt.y))
            {
                Enemy::enemies[i].life-=bullets[i].damage;
                bullets.erase(bullets.begin()+i);
                break;
            }

        }

    if(!flag)
        iShowBMP2(blt.x,blt.y,(char*)str.c_str(),0);
    blt.bulletIndex+=1;
}

vector <bullet> bullet::bullets;
int bullet::bltSpeed=30;
