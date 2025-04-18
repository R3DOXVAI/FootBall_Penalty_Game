#include "GAMEELEMENTS.h"
#include "bits/stdc++.h"
using namespace std;

GAMEELEMENTS::GAMEELEMENTS()
{
    this->setScreen();
}

GAMEELEMENTS::~GAMEELEMENTS()
{
    //dtor
}
void GAMEELEMENTS::setScreen(){
    //this->screenX = glutGet(GLUT_WINDOW_WIDTH);
    //this->screenY = glutGet(GLUT_WINDOW_HEIGHT);
}
int GAMEELEMENTS::create()
{
    //cout<<"Not how i expected :) "<<endl;
}

void GAMEELEMENTS::setButtonBG(char *bg,int duration)
{

}
char * GAMEELEMENTS::getSecondBgPath()
{
}
void GAMEELEMENTS::sound(){
    if(!GAMEELEMENTS::mute){
        if(GAMEELEMENTS::gameState==FLY||GAMEELEMENTS::gameState==OVER) PlaySound(TEXT("res/Music/airplanes.wav"), NULL, SND_LOOP | SND_ASYNC);
        else if(GAMEELEMENTS::gameState==SHOOT) PlaySound(TEXT("res/Music/shoot.wav"),NULL, SND_LOOP | SND_ASYNC);
        else if(GAMEELEMENTS::gameState==LOADING) PlaySound(TEXT("res/Music/loading.wav"),NULL, SND_LOOP | SND_ASYNC);
    }
    else
        PlaySound(0,0,0);
}

int GAMEELEMENTS::getx(){

}
int GAMEELEMENTS::gety(){

}
map <string,int> GAMEELEMENTS::getHotZone(){

}
int GAMEELEMENTS::gameState = 0;
bool GAMEELEMENTS::btnAbout = 0;
bool GAMEELEMENTS::mute = 0;
