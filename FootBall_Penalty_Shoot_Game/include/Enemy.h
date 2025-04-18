#ifndef ENEMY_H
#define ENEMY_H
#include "GAMEELEMENTS.h"
#include "gameControl.h"
class Enemy:public GAMEELEMENTS
{
    public:
        Enemy(int x=-1,int y=-1,int life=-1,string path=DRAGON1XR,string type="Dragon",int ignoreColor=0xffffff);
        virtual ~Enemy();
        int create();
        string type;
        static void add(int x=-1,int y=-1,int life=-1,string path=DRAGON1XR,string type="Dragon");
        void init();
        int frameIndex;
        void addProperty(int frontX=35,int frontY=200,int hotX=300,int hotY=270,int speedX=5,int speedY=0);
        static void update();
        static void setDest(GAMEELEMENTS *);
        void add(Enemy* obj);
        string spritePath;
        void setAnimationPath(string s);
        int speedX,speedY;
        bool inCollision(int x,int y);
        bool overlap(int ,int ,int ,int);
        bool showHitMap=0;
        map <string,int> getHotZone();
    static vector <Enemy > enemies;
    int x,y,life,frontx,fronty,hotx,hoty,maxLife;
    int ignoreColor=0xffffff;
    protected:
    static map <string,vector<string> > frames;
    static vector <string> randomSelect;
    static GAMEELEMENTS *dst;
    private:
};

#endif // ENEMY_H
