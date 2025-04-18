#ifndef PLANE_H
#define PLANE_H
#include "GAMEELEMENTS.h"
#include "gameControl.h"
class Plane:public GAMEELEMENTS
{
    public:
        Plane(int x=20,int y=200,int ignore=0xffffff);
        virtual ~Plane();
        void flyAnimation();
        void shootAnimation();
        void gameOverWindow();
        int create();
        void setPosition(int x,int y,int mx=1300,int my=700);
        void setColorInore(int color);
        int getx();
        int gety();
        map <string,int> getHotZone();
        int posx,posy,flyState,flyingFrame,ignore,mx,my,shootIndex,flag;
        int hotx,hoty,frontx,fronty;
        map <string,vector <string> >frames;
    protected:
    char *currentAnimImage;
    private:
};

#endif // PLANE_H
