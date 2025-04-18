#ifndef TEXT_H
#define TEXT_H
#include "GAMEELEMENTS.h"
using namespace std;
class Text:public GAMEELEMENTS
{
    public:
        Text(int x=0,int y=0,string s="Text",int r=255,int g=255,int b=255,int font=(int)GLUT_BITMAP_8_BY_13);
        virtual ~Text();
        int create();
        void setText(string s);
        void setPosition(int x,int y);
        void setColor(int r,int g,int b);
        void setFont(int font);
        protected:
    string text;
    int font;
    int r,g,b,x,y;
    private:
};

#endif // TEXT_H
