#include "base.inc.h"
baseInc::baseInc(char *path,bool repeat)
{
    this->setBackground(path);
    this->deco = folderToVector("res/Castle/bmp");
    int i,cnt=0;
    for(i=0; i<this->deco.size(); i++,cnt+=400)
    {
        data[i]["x"] = 1400+cnt;
        data[i]["speed"] = 2;
        data[i]["y"]= 0;
        this->castle.push({i,this->deco[i]});
    }

    this->setRepeat(repeat);
}
void baseInc::setRepeat(bool repeat)
{
    this->repeatMode = repeat;
}
int baseInc::create()
{
    if(this->path!=NULL)
        iShowBMP(0,0,this->path);
    else
        iFilledRectangle(0,0,1300,1300);
    makeCastle();
    return 0;
}
void baseInc::setBackground(char path[])
{
    this->path = path;
}
baseInc::~baseInc()
{
    //dtor
}
void baseInc::makeCastle()
{
    int i=0;
    stack <pair<int,string> > temp;
    if(this->deco.size()!=0)
    {
        while(!castle.empty()&&i<4)
        {
            pair <int,string> p = castle.front();
            map <string,int> m = data[p.first];
            int x = m["x"];
            int y = m["y"];
            iShowBMP2(x,y,(char*) ("res/Castle/bmp/"+p.second).c_str(),0xffffff);

            if(currentState()==FLY||currentState()==SHOOT || currentState()==LOADING)x -= m["speed"];
            data[p.first]["x"] = x;
            castle.pop();
            if(x<0)
            {
                data[p.first]["x"] = 1700;
                data[p.first]["y"] = 0;
                castle.push(p);
            }else{
                temp.push(p);
            }

            i++;
        }

        while(!temp.empty()){
            this->castle.push(temp.top());
            temp.pop();
        }
    }
}
