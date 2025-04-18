#include "render.h"

//queue <GAMEELEMENTS> render::render_queue;
render::render()
{
    //ctor
}
void render::addToRenderQueue(GAMEELEMENTS *elm){
    this->render_queue.push(elm);
}
void render::makeScreen(){
    int i=1;
    while(!this->render_queue.empty()){
        GAMEELEMENTS *elm = render_queue.front();
        render_queue.pop();
        Sleep(elm->create());
    }
}
void render::makeEmpty(){
while(!render_queue.empty()) render_queue.pop();
}
render::~render()
{
    //dtor
}
