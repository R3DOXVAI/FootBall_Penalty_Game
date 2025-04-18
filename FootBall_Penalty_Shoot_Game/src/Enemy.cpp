#include "Enemy.h"

Enemy::Enemy(int x,int y,int life,string path,string type,int ignoreColor)
{
    this->x = x==-1?1400:x;
    this->y=  y==-1?rand()%500:y;
    this->maxLife = life==-1?1000:life;
    this->life = life==-1?this->maxLife:life;
    this->setAnimationPath(path);
    this->type = type;
    this->init();
    this->addProperty();
    this->ignoreColor = ignoreColor;
    this->frameIndex = 0;
}

void Enemy::addProperty(int frontX,int frontY,int hotX,int hotY,int speedX,int speedY){
        this->hoty = hotY;
        this->hotx = hotX;
        this->frontx = frontX;
        this->fronty = frontY;
        this->speedX = speedX;
        this->speedY = speedY;
}

Enemy::~Enemy()
{

}

void Enemy::setAnimationPath(string path)
{
    this->spritePath = path;
}
void Enemy::setDest(GAMEELEMENTS *obj)
{
    Enemy::dst = obj;
}
int Enemy::create()
{
    if(Enemy::enemies.size()==0)
        return 0;
    int i;
    for(i=0; i<Enemy::enemies.size(); i++)
    {
        string enemyType = Enemy::enemies[i].type;

        int posx = Enemy::enemies[i].x;
        int posy = Enemy::enemies[i].y;
        /* Adding hot zone area */
        if(Enemy::enemies[i].showHitMap){
                iSetColor(255,255,255);
                map <string,int> hotZone = Enemy::enemies[i].getHotZone();
                iFilledRectangle(hotZone["x"],hotZone["y"],hotZone["xx"]-hotZone["x"],hotZone["yy"]-hotZone["y"]);
        }




        if(Enemy::frames[enemyType].size()!=0)
        {
            int fri = Enemy::enemies[i].frameIndex;
            string path = Enemy::enemies[i].spritePath+Enemy::frames[enemyType][fri];
            iShowBMP2(posx,posy,(char*)path.c_str(),Enemy::enemies[i].ignoreColor);

            int width = 50;
            int have = (int)((Enemy::enemies[i].life/(Enemy::enemies[i].maxLife*1.0))*width);
            iSetColor(0,0,255);
            if(enemyType=="Dragon") {
                iFilledRectangle(posx+300,posy+250,width,10);
                iSetColor(255,0,0);
                iFilledRectangle(posx+300,posy+250,have,10);
            }

        }

        else
        {
            iSetColor(255,0,0);
            iFilledCircle(posx,posy,20);
        }

        //cout<<enemyType<<" Created\n";
    }
    //Enemy::update();
    return 0;
}

bool Enemy::inCollision(int x,int y)
{
    map <string,int> hotZone = this->getHotZone();
    return (x>=hotZone["x"]&&x<=hotZone["xx"]&&y>=hotZone["y"]&&y<=hotZone["yy"]);

}
bool Enemy::overlap(/*L1*/int a,int b,/*R1*/int c,int d){
    map <string,int> hotZone = this->getHotZone();
    /*L2*/
    int u = hotZone["x"];
    int v = hotZone["y"];
    /*R2*/
    int x = hotZone["xx"];
    int y = hotZone["yy"];

    if(a>x || u>c) return false;
    if(b>y || v>d) return false;
    return true;

}
void Enemy::update()
{
    int i;
    for(i=0; i<Enemy::enemies.size(); i++)
    {
        if(i<0||i>=Enemy::enemies.size())
            return;

        string enemyType = Enemy::enemies[i].type;


        if(Enemy::frames[enemyType].size()!=0){
            Enemy::enemies[i].frameIndex+=1;
            Enemy::enemies[i].frameIndex%=Enemy::frames[enemyType].size();

        }

        Enemy::enemies[i].x-=Enemy::enemies[i].speedX;
        Enemy::enemies[i].y-=Enemy::enemies[i].speedY;

        int ex = Enemy::enemies[i].x;
        int ey = Enemy::enemies[i].y;

        int dx = ex-Enemy::dst->getx();
        int dy = ey-Enemy::dst->gety();

        if(Enemy::enemies[i].x<0 || Enemy::enemies[i].life<=0)
        {
            Enemy::enemies.erase(Enemy::enemies.begin()+i);
            //cout<<Enemy::enemies[i].type<<" erased for "<<(Enemy::enemies[i].life<=0)<<" and "<<(Enemy::enemies[i].x<0)<<" "<<Enemy::enemies[i].speedX<<endl;
        }
        if(Enemy::enemies.size()<2)
        {
            Enemy::add();
        }

        map <string,int> planeHotZone = dst->getHotZone();

        int x = planeHotZone["x"];
        int y = planeHotZone["y"];

        int xx = planeHotZone["xx"];
        int yy = planeHotZone["yy"];

        bool flag = 0;
        int t,j;
        if(x>xx)
            swap(x,xx);
        if(y>yy)
            swap(y,yy);
/*
@@We will not use brute force
        for(t=x; t<=xx; t+=10)
        {
            for(j=y; j<=yy; j+=10)
            {
                flag = Enemy::enemies[i].inCollision(t,j);
                if(flag)
                    break;
            }
        }
*/
        flag = Enemy::enemies[i].overlap(x,y,xx,yy);

        if( flag && currentState()==SHOOT)
            gameOver();
    }
}
map <string,int> Enemy::getHotZone()
{
    map<string,int> temp;
    temp["x"] = this->x+this->frontx;
    temp["y"] = this->y+this->fronty;
    temp["xx"] = this->x+this->hotx;
    temp["yy"] = this->y+this->hoty;
    return temp;
}
void Enemy::add(int x,int y,int life,string path,string type)
{

    Enemy obj(x,y,life,path,type);
    obj.type = type;
    obj.frameIndex=0;
    Enemy::enemies.push_back(obj);
}
void Enemy::add(Enemy *obj){
    Enemy::enemies.push_back(*obj);
}
void Enemy::init()
{

    if(Enemy::frames[this->type].size()==0)
    {
        //Enemy::randomSelect.push_back("Dragon");
        if(this->spritePath.length()==0)
            return;
        Enemy::frames[this->type] = folderToVector((char*)this->spritePath.c_str());
    }
}
map <string,vector<string> > Enemy::frames;
vector <string> Enemy::randomSelect;
vector <Enemy> Enemy::enemies;
GAMEELEMENTS *Enemy::dst=NULL;
