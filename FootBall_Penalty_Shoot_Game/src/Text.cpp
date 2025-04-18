#include "Text.h"
Text::Text(int x,int y,string s,int r,int g,int b,int font)
{
    this->setColor(r,g,b);
    this->setPosition(x,y);
    this->setText(s);
    this->setFont(font);
}
void Text::setText(string s){
this->text = s;
}
void Text::setFont(int font){
this->font = font;
}
void Text::setColor(int r,int g,int b){
    this->r=r;
    this->g=g;
    this->b=b;
}
void Text::setPosition(int x,int y){
this->x = x;
this->y = y;
}
Text::~Text()
{
    //dtor
}
int Text::create(){
    iSetColor(this->r,this->g,this->b);
    char str[10000]={0};
    strcpy(str,this->text.c_str());
   iText(this->x, this->y, str, (void *)this->font);
    iSetColor(0,0,0);
   return 0;
}
