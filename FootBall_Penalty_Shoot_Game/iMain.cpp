#include "include/base.inc.h"
#include "include/Button.h"
#include "include/render.h"
#include "include/Text.h"
#include "include/Plane.h"
#include "bullet.h"
#include "include/GAMEELEMENTS.h"
#include "gameControl.h"
#include "Loader.h"
#include "Image.h"
#include "Enemy.h"


using namespace std;
baseInc base(BGLEVEL1);
render renderer;
int i=0;
int speedX=10,speedY=10;

Button play(560,300,210,210);
Button help(10,280,63,63);
Button rating(10,200,63,63);
Button ext(10,40,63,63);
Button music(10,120,63,63);

Text text(0,0,"Created by: Shikh Farid , Dristy khatun, Sharif Hasan (L)",0,0,255);

Plane plane(100,280,0xFF0000);
bullet blt(1400,1400);
Loader loader;

Enemy dragon(1400,-1,rand()%10000,DRAGON1XR,"Dragon");
Enemy ball(1400,400,1000000,WITCH,"Witch",0xFF0000);

Image img("res/About/About.bmp",80,0);

char *btnBGPath = NULL;
void draw();
void finish();
void iDraw()
{
    iClear();
    finish();
}

void iMouseMove(int mx, int my)
{

}
//*******************************************************************ipassiveMouse***********************************************************************//
void iPassiveMouseMove(int mx, int my)
{

}

void iMouse(int button, int state, int mx, int my)
{
    int x = mx,y=my;
    //cout<<x<<" "<<y<<" "<<state<<endl;
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        Button::makeAction(x,y);

    }


    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {

    }
}


void iKeyboard(unsigned char key)
{
    if (key == '\r')
    {

    }
cout<<key<<endl;
if(currentState()==OVER&&key==' ') setGameState(FLY);
 if(currentState()==FLY||currentState()==OVER) return;


    else if(key == 'D'||key == 'd')
    {
        plane.setPosition(plane.posx+speedX,plane.posy);
    }
    else if(key == 'A'||key == 'a')
    {
        plane.setPosition(plane.posx-speedX,plane.posy);
    }
    else if(key=='W'||key=='w')
    {
        plane.setPosition(plane.posx,plane.posy+speedY);
    }
    else if(key=='s'||key=='S')
    {
        plane.setPosition(plane.posx,plane.posy-speedY);
    }
    else if(key=='e'||key=='E')
    {
        plane.setPosition(plane.posx+speedX,plane.posy+speedY);
    }
    else if(key=='z'||key=='Z')
    {
        plane.setPosition(plane.posx-speedX,plane.posy-speedY);
    }
    else if(key=='q'||key=='Q')
    {
        plane.setPosition(plane.posx-speedX,plane.posy+speedY);
    }
    else if(key=='x'||key=='X')
    {
        plane.setPosition(plane.posx+speedX,plane.posy-speedY);
    }

}
void iSpecialKeyboard(unsigned char key)
{
    if(currentState()==FLY) return;

    if (key == GLUT_KEY_RIGHT)
    {
        iKeyboard('D');
    }
    if (key == GLUT_KEY_LEFT)
    {
        iKeyboard('A');
    }
    if(key== GLUT_KEY_UP)
    {
        iKeyboard('W');
    }
    if(key==GLUT_KEY_DOWN)
    {
        iKeyboard('S');
    }

    if (key == GLUT_KEY_HOME)
    {

    }

}
void cntrlblt(){
    if(currentState()==SHOOT){
        blt.add(plane.posx+180,plane.posy+33);
        blt.add(plane.posx+230,plane.posy+50);
    }
}
void cntrEnemy(){
    Enemy::add(1400,-1,rand()%10000,DRAGON1XR,"Dragon");

}

void cntrBall(){
   Enemy ball(rand()%1400,800,10000000,WITCH,"Witch",0xFF0000);
   ball.addProperty(10,5,50,40,min(rand()%14,5),5);
   ball.showHitMap = 0;
   ball.add(&ball);
}
void showAbout(GAMEELEMENTS *obj=NULL){
    if(GAMEELEMENTS::btnAbout) GAMEELEMENTS::btnAbout =  0; else GAMEELEMENTS::btnAbout = 1;
}

void toggleMusic(GAMEELEMENTS *obj=NULL){
    if(GAMEELEMENTS::mute){
            GAMEELEMENTS::mute = 0;
            GAMEELEMENTS::sound();
    }
    else{
            GAMEELEMENTS::mute=1;
            GAMEELEMENTS::sound();
    }
}
void enemyUpdate(){
    Enemy::update();
}

int main()
{
    iSetTimer(20,&draw);
    iSetTimer(100,&cntrlblt);
    iSetTimer(20000,&cntrEnemy);
    iSetTimer(5000,&cntrBall);

    iSetTimer(100,&enemyUpdate);
    Enemy::add();
    Enemy::setDest(&plane);
    setGameState(LOADING);
    GAMEELEMENTS::sound();

    int w = glutGet(GLUT_SCREEN_WIDTH);
    int h = glutGet(GLUT_SCREEN_HEIGHT);
    iInitialize(w, h, "Sky warrior",1);
    glutFullScreen();
    return 0;
}

void draw(){
    iKeyboard(handleKey());
    bullet::update();
    play.addEventListener("click",&gameStart);
    play.setButtonBG(PLAYBTN);
    play.setColorIgnore(0xffffff);
    play.register2ndbg(PLAYBTNACTIVE);

    help.setButtonBG(HELP);
    help.addEventListener("click",&showAbout);
    help.setColorIgnore(0xffffff);
    help.register2ndbg(HELPACTIVE);


    rating.setButtonBG(RATING);
    rating.addEventListener("click",&imageClick);
    rating.setColorIgnore(0xffffff);
    rating.register2ndbg(RATINGACTIVE);

    if(GAMEELEMENTS::mute==1)
        music.setButtonBG(MUSIC);
    else
        music.setButtonBG(MUSICACTIVE);

    music.addEventListener("click",&toggleMusic);
    music.setColorIgnore(0xffffff);
    music.register2ndbg(MUSICACTIVE);

    text.setFont((int)GLUT_BITMAP_HELVETICA_12);
    i%=1300;
    text.setPosition(i,5);
    if(currentState()==FLY){
        ext.setButtonBG(EXIT);
        ext.addEventListener("click",&gameExit);
        ext.setColorIgnore(0xffffff);
        ext.register2ndbg(EXITACTIVE);
    }else if(currentState()==SHOOT){
        ext.setButtonBG(PAUSE);
        ext.addEventListener("click",&gamePause);
        ext.setColorIgnore(0xffffff);
        ext.register2ndbg(PAUSEACTIVE);
    }else if(currentState()==OVER){
        ext.setButtonBG(REPLAY);
        ext.addEventListener("click",&gameStart);
        ext.setColorIgnore(0xffffff);
        ext.register2ndbg(REPLAYACTIVE);

    }
    ext.setAnim(0);
    i+=10;

}

void finish(){
renderer.makeEmpty();
    if(currentState()==LOADING){
        renderer.addToRenderQueue(&loader);
        renderer.makeScreen();
        return;
    }

    renderer.addToRenderQueue(&base);
   // renderer.addToRenderQueue(&text);
    renderer.addToRenderQueue(&dragon);
    renderer.addToRenderQueue(&ball);
    renderer.addToRenderQueue(&plane);

    if(currentState()==0)
        renderer.addToRenderQueue(&play);
    if(currentState()==0)
        renderer.addToRenderQueue(&help);
    if(currentState()==0)
        renderer.addToRenderQueue(&rating);
    if(currentState()==0)
        renderer.addToRenderQueue(&music);
    if(currentState()==SHOOT)
        renderer.addToRenderQueue(&blt);

    renderer.addToRenderQueue(&ext);

    if(GAMEELEMENTS::btnAbout) renderer.addToRenderQueue(&img);
    renderer.makeScreen();
}
