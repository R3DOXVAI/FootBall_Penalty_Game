#ifndef IMAGE_H
#define IMAGE_H
#include "GAMEELEMENTS.h"

class Image:public GAMEELEMENTS
{
    public:
        Image(char *url,int x=0,int y=0);
        virtual ~Image();
        int create();
    protected:
    char *url;
    int x,y;
    private:
};

#endif // IMAGE_H
