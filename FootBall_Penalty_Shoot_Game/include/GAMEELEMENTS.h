#ifndef GAMEELEMENTS_H
#define GAMEELEMENTS_H
#include <bits/stdc++.h>
#include "iGraphics.h"
#include "windows.h"
#include "defenition.h"

using namespace std;
class GAMEELEMENTS
{
public:
    GAMEELEMENTS();
    virtual ~GAMEELEMENTS();
    int virtual create();
    void virtual setButtonBG(char*,int );
    int virtual getx();
    int virtual gety();
    map <string,int> virtual getHotZone();
    char virtual *getSecondBgPath();
    void setScreen();
    static void sound();
    int screenX,screenY;
    static int gameState;
    static bool btnAbout,mute;
protected:

private:
};

#endif // GAMEELEMENTS_H
