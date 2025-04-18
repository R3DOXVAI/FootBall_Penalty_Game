#ifndef LOADER_H
#define LOADER_H
#include "GAMEELEMENTS.h"
#include "gameControl.h"

class Loader:public GAMEELEMENTS
{
    public:
        Loader();
        virtual ~Loader();
        int create();
    protected:
    vector <string> images;
    int i;
    private:
};

#endif // LOADER_H
