#include "Plane.h"

Plane::Plane(int x,int y,int ignore)
{
    this->flyState = 0;
    this->flyingFrame = 0;
    this->shootIndex = 0;
    this->currentAnimImage = NULL;
    this->setPosition(x,y);
    this->ignore = ignore;
    this->flag = 0;
    this->frontx = 0;
    this->fronty = 10;
    this->hotx = 250;
    this->hoty = 120;
    /*initiating game frames*/
    this->frames["normal"] = folderToVector(PLANEFLY);
    this->frames["shoot"] = folderToVector(PLANESHOOT);
}
void Plane::setPosition(int x,int y,int mx,int my){
    if(x<0) x=5;
    if(y<0) y=5;
    if(x>mx-400) x=mx-400;
    if(y>my-100) y=my-100;
    this->posx=x;
    this->posy=y;
    this->mx = mx;
    this->my = my;
}
Plane::~Plane()
{
    //dtor
}
void Plane::flyAnimation(){
    int x = this->posx;
    int y = this->posy;
    vector <string> v = frames["normal"];
    string s = PLANEFLY+v[this->flyingFrame];
    this->currentAnimImage = (char*) s.c_str();
    this->flyingFrame++;
    if(v.size()<=this->flyingFrame) this->flyingFrame = 0;
    iShowBMP2(this->posx,this->posy,this->currentAnimImage,this->ignore);
    //cout<<"Current flying frame = "<<this->flyingFrame<<endl;
}

void Plane::shootAnimation(){

    int x = this->posx;
    int y = this->posy;
    vector <string> v = frames["shoot"];
    string s = PLANESHOOT+v[this->shootIndex];

    this->currentAnimImage = (char*)s.c_str();
    this->shootIndex++;
    if(v.size()<=this->shootIndex) this->shootIndex = 0;
    if(this->flag==0){
        this->posx+=1;
        this->posy+=1;
        flag=1;
    }else{
        this->posx-=1;
        this->posy-=1;
        flag=0;
    }
    iShowBMP2(this->posx,this->posy,this->currentAnimImage,this->ignore);

}

void Plane::gameOverWindow(){
    this->currentAnimImage = GOVER;
    this->posy = 0;
    iShowBMP2(this->posx,this->posy,this->currentAnimImage,this->ignore);

}

void Plane::setColorInore(int color){
    this->ignore = color;
}
int Plane::create(){
           // map <string,int> hotZone = this->getHotZone();
           // iFilledRectangle(hotZone["x"],hotZone["y"],abs(hotZone["x"]-hotZone["xx"]),abs(hotZone["y"]-hotZone["yy"]));

    if(GAMEELEMENTS::gameState==FLY)
        this->flyAnimation();
    else if(GAMEELEMENTS::gameState==SHOOT)
        this->shootAnimation();
    else if(GAMEELEMENTS::gameState==OVER)
        this->gameOverWindow();
   return 0;
}

int Plane::getx(){
    return this->posx;
}

int Plane::gety(){
    return this->posy;
}

map<string,int> Plane::getHotZone(){
    map<string,int> temp;
    temp["x"] = this->posx+this->frontx;
    temp["y"] = this->posy+this->fronty;
    temp["xx"] = this->posx+this->hotx;
    temp["yy"] = this->posy+this->hoty;
    return temp;
}
