#include "gameControl.h"
#include "Enemy.h"
void setGameState(int state){
    GAMEELEMENTS::gameState=state;
}
void imageClick(GAMEELEMENTS *obj)
{
    //cout<<"Image click\n";
}
void gameExit(GAMEELEMENTS *obj){
//cout<<"Exited successfully\n";
exit(1);
}

void gameStart(GAMEELEMENTS *obj){
    GAMEELEMENTS::gameState=SHOOT;
    GAMEELEMENTS::btnAbout=0;
    GAMEELEMENTS::sound();
    Enemy::enemies.clear();
    //cout<<"GAME HAS BEEN STARTED "<<GAMEELEMENTS::gameState<<"\n";
}

void gamePause(GAMEELEMENTS *obj){

    GAMEELEMENTS::gameState=FLY;
    GAMEELEMENTS::sound();
    //cout<<"GAME HAS BEEN PAUSED "<<GAMEELEMENTS::gameState<<"\n";
}
void gameOver(GAMEELEMENTS *obj){
    GAMEELEMENTS::gameState=OVER;
    GAMEELEMENTS::sound();
}
void gameHome(GAMEELEMENTS *obj){
    GAMEELEMENTS::gameState = FLY;
    GAMEELEMENTS::mute = 0;
    GAMEELEMENTS::sound();

}
int currentState(){
    return GAMEELEMENTS::gameState;
}
int rt(char ch){
    return GetAsyncKeyState(ch)||GetAsyncKeyState(tolower(ch))||GetAsyncKeyState(toupper(ch));
}
char handleKey(){
     if((rt('D')|| rt(VK_RIGHT)) &&0x8000) return 'D';
     if((rt('A')|| rt(VK_LEFT))&&0x8000) return 'A';
     if((rt('W')|| rt(VK_UP)) &&0x8000) return 'W';
     if((rt('S')|| rt(VK_DOWN))&&0x8000) return 'S';

     if(rt('Q')&&0x8000) return 'Q';
     if(rt('Z')&&0x8000) return 'Z';
     if(rt('X')&&0x8000) return 'X';
     if(rt('E')&&0x8000) return 'E';


}

vector <string> folderToVector(char *dir){
vector <string> files;
DIR *pDIR;
        struct dirent *entry;
        if( pDIR=opendir(dir) ){
                while(entry = readdir(pDIR)){
                        if( strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0 )
                        files.push_back(entry->d_name);
                }
                closedir(pDIR);
        }
        return files;
}
