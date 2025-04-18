#ifndef BASE_INC_H
#define BASE_INC_H
#include "GAMEELEMENTS.h"
#include "gameControl.h"
class baseInc:public GAMEELEMENTS
{
public:
    baseInc(char *path=NULL,bool repeat=0);
    virtual ~baseInc();

    int create();
    void setBackground(char path[]);
    void setRepeat(bool repeat);
    void makeCastle();
protected:
    char *path;
    vector <string> deco;
    queue <pair<int,string> > castle;
    map <int,map<string,int> > data;
    int castleIndex=0;
    bool repeatMode;
private:
};

#endif // BASE_INC_H
