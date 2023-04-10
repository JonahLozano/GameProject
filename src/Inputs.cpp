#include "../include/Inputs.h"
#include "../include/sounds.h"

//sounds *snds = new sounds();



Inputs::Inputs()
{
    //ctor
}

Inputs::~Inputs()
{
    //dtor
}

void Inputs::keyEnv(parallax* plx, float speed)
{
    switch(wParam){
    case VK_LEFT:
        plx->xMax -= speed;
        plx->xMin -= speed;
        break;
    case VK_RIGHT:
        plx->xMax += speed;
        plx->xMin += speed;
        break;

    case VK_DOWN:
        plx->yMax -= speed;
        plx->yMin -= speed;
        break;
    case VK_UP:
        plx->yMax += speed;
        plx->yMin += speed;
        break;
    }
}

void Inputs::keyMap(levelLoader* lvl, float x, float y)
{
    switch(wParam){
    case VK_LEFT:
        lvl->spawnCols-=x;
        break;
    case VK_RIGHT:
        lvl->spawnCols+=x;
        break;

//    case VK_DOWN:
//        plx->yMax -= speed;
//        plx->yMin -= speed;
//        break;
//    case VK_UP:
//        plx->yMax += speed;
//        plx->yMin += speed;
//        break;
    }
}

void Inputs::keyPressed(Model * mdl)
{
    switch(wParam){
    case VK_LEFT:
        mdl->y_rotate -= 1.0;
        break;
    case VK_RIGHT:
        mdl->y_rotate += 1.0;
        break;

    case VK_DOWN:
        mdl->x_rotate -= 1.0;

        break;
    case VK_UP:
        mdl->x_rotate += 1.0;
        break;

    case VK_HOME:
        mdl->zoom += 1.0;
        break;
    case VK_END:
        mdl->zoom -= 1.0;
        break;

    }
}

void Inputs::keyUp()
{
    switch(wParam)
    {

    }
}

void Inputs::mouseBtnDwn(Model * mdl,double x, double y)
{
    prev_Mx = x;
    prev_My = y;

    switch(wParam)
    {
        case MK_LBUTTON: Mouse_Rotate = true; break;
        case MK_RBUTTON: Mouse_Translate = true; break;
        case MK_MBUTTON: break;
    }
}

void Inputs::mouseBtnUp()
{
    Mouse_Rotate = false;
    Mouse_Translate = false;
}

void Inputs::mouseWheel(Model * mdl,double delta)
{
    mdl->zoom -= delta/100.0;
}

void Inputs::mouseMove(Model * mdl,double x, double y)
{
    if(Mouse_Translate)
    {
        mdl->x_pos += (x - prev_Mx)/100.0;
        mdl->y_pos -= (y - prev_My)/100.0;
        prev_Mx = x;
        prev_My = y;
    }

    if(Mouse_Rotate)
    {
        mdl->y_rotate += (x - prev_Mx)/3.0;
        mdl->x_rotate += (y - prev_My)/3.0;
        prev_Mx = x;
        prev_My = y;
    }
}
void Inputs::keyPlayer(player* ply,sounds* _snds)
{
    switch(wParam){
    case VK_LEFT:
        ply->actions(ply->WALKLEFT,_snds);
        break;
    case VK_RIGHT:
        ply->actions(ply->WALKRIGHT,_snds);
        break;
    case VK_DOWN:
        break;
    case VK_UP:
        break;
    }

}

//void Inputs::zoom(GL_Scene* scene, double zoomAmnt)
//{
//    scene->zoom += zoomAmnt;
//}

//void Inputs::zoom(GL_Scene* scene, double zoomAmnt)
//{
//    scene->zoom += zoomAmnt;
//}
