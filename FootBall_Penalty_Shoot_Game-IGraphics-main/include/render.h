#ifndef RENDER_H
#define RENDER_H
#include "GAMEELEMENTS.h"
class render:public GAMEELEMENTS
{
    public:
        render();
        virtual ~render();
        void addToRenderQueue(GAMEELEMENTS *elm);
        queue <GAMEELEMENTS*> render_queue;
        void makeScreen();
        void makeEmpty();
    protected:

    private:
};

#endif // RENDER_H
