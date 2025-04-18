#include "Image.h"

Image::Image(char *url,int x,int y)
{
    this->url = url;
    this->x = x;
    this->y=y;
}

Image::~Image()
{
    //dtor
}
int Image::create(){
iShowBMP2(this->x,this->y,this->url,-1);
return 0;
}
