#include "Loader.h"
Loader::Loader()
{
    this->images = folderToVector("res/LOADER/bmp");
}
int Loader::create(){
    iSetColor(255,255,255);
    iFilledRectangle(0,0,1500,1300);
    if(this->i>=this->images.size()-3){
            if(GAMEELEMENTS::gameState==LOADING){
                gameHome();
            }else{
                return 0;
            }

    }
    string str = "res/LOADER/bmp/"+this->images[i];
    iShowBMP2(270,0,(char*)str.c_str(),-1);
    this->i+=1;
    return 0;
}
Loader::~Loader()
{
    //dtor
}
