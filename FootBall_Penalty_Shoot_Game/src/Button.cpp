#include "Button.h"
#include "iGraphics.h"

Button::Button(int x,int y,int w,int h)
{
    this->l=0;
    this->r=0;
    this->cr = 0;
    this->cb = 0;
    this->cg = 0;
    this->init(x,y,w,h);
    this->include();
    this->bgpath=NULL;
    this->clickState=0;
    this->ignoreColor = -1;
    this->secondbg = NULL;
    this->btAnim=5;
}
void Button::init(int x,int y,int w,int h){
    this->buttonX = x;
    this->buttonY = y;
    this->height = h;
    this->width = w;
}
void Button::setColor(int r,int g,int b){
    this->cr = r;
    this->cb = b;
    this->cg = g;
}
bool Button::clicked(){
    bool t=l;
    l=0;
    return t;
}
bool Button::rclicked(){
    bool t=r;
    r=0;
return t;
}
bool Button::isOn(int xr,int yr){
    int x = this->buttonX;
    int xx = x+this->width;
    int y = this->buttonY;
    int yy = y+this->height;
 return xr>x&&xr<xx&&yr>y&&yr<yy;
}
bool Button::addEventListener(string event,void (*fun)(GAMEELEMENTS *)){
    this->events[event] = fun;
    return 1;
}
void Button::setButtonBG(char *path,int duration){
    if(this->anim<=0){
            this->bgpath = path;
            this->anim = duration;
    }else{
            this->anim--;
    }
    //cout<<this->bgpath<<endl;
}
int Button::create(){
    int r = this->cr;
    int g = this->cg;
    int b = this->cb;
    iSetColor(r,g,b);
    if(this->bgpath!=NULL){
        iShowBMP2(this->buttonX,this->buttonY,this->bgpath,this->ignoreColor);
    }else{
        iFilledRectangle(this->buttonX,this->buttonY,this->width,this->height);
    }
    iSetColor(0,0,0);
    return 0;
}
vector <Button*> Button::buttonRegister;

bool Button::include(){
    buttonRegister.push_back(this);
}
void Button::makeAction(int x,int y){
    int i;
    for(i=0;i<buttonRegister.size();i++){
        bool clickInfo = buttonRegister[i]->isOn(x,y);
        if(clickInfo){
                if(buttonRegister[i]->listener()!=0) buttonRegister[i]->click();
                //cout<<"Pressed "<<i+1<<endl;
                break;
        }
    }
}
void Button::click(GAMEELEMENTS *point){
    if(this->getSecondBgPath()!=NULL)
        this->setButtonBG(this->getSecondBgPath(),this->btAnim);
    this->events["click"](this);
}
void Button::setAnim(int a){
this->btAnim=a;
}
Button::~Button()
{
    //dtor
}
void Button::setColorIgnore(int hex){
            this->ignoreColor = hex;
        }

void Button::register2ndbg(char *path){
    this->secondbg = path;
}

char *Button::getSecondBgPath(){
    return this->secondbg;
}
