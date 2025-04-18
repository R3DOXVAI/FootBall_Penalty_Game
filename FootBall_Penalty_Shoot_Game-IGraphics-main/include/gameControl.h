#ifndef GAMECONTROL_H
#define GAMECONTROL_H
#include<fstream>
#include<dirent.h>
#include "GAMEELEMENTS.h"

void imageClick(GAMEELEMENTS *obj=NULL);
void gameExit(GAMEELEMENTS *obj=NULL);
void gameStart(GAMEELEMENTS *obj=NULL);
void gamePause(GAMEELEMENTS *obj=NULL);
void gameOver(GAMEELEMENTS *obj=NULL);
void gameHome(GAMEELEMENTS *obj=NULL);
void setGameState(int state);
vector <string> folderToVector(char *dir);
int currentState();
char handleKey();
int rt(char ch);
#endif // GAMECONTROL_H
