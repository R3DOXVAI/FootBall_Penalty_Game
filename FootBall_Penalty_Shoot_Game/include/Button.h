#ifndef BUTTON_H
#define BUTTON_H
#include "GAMEELEMENTS.h"
using namespace std;
class Button:public GAMEELEMENTS
{
    public:
        Button(int x,int y,int w,int h);
        virtual ~Button();
        void init(int x,int y,int w,int h);
        void setColor(int r,int g,int b);
        bool clicked();
        bool rclicked();
        void click(GAMEELEMENTS* = NULL);
        bool include();
        bool isOn(int xr,int yr);
        bool addEventListener(string event,void (*fun)(GAMEELEMENTS*));
        int create();
        void setColorIgnore(int hex);
        void setButtonBG(char *path,int duration=-1);
        void register2ndbg(char *path);
        char *getSecondBgPath();
        bool listener(){
            //return (this->fun);
            return 1;
        }
        void setAnim(int a);
        static void makeAction(int x,int y);

        map <string,void (*)(GAMEELEMENTS *)> events;
        int buttonX,buttonY,height,width,cr,cg,cb;
        static vector <Button*> buttonRegister;
        bool l,r;
        char *bgpath,*secondbg;
        int clickState,anim=0;
        int ignoreColor,btAnim;
    protected:

    private:
};


#endif // BUTTON_H
