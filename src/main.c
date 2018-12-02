#include "main.h"

int main(/*int argc, char *argv[]*/)
{    
  /*******************************************************/
  SDL_Init(SDL_INIT_VIDEO);
  screen = SDL_SetVideoMode(SCL*L, SCL*H, 32,
    SDL_HWSURFACE | SDL_DOUBLEBUF /*SDL_RESIZABLE | SDL_FULLSCREEN */);
  SDL_WM_SetCaption("TANK GAME !", NULL);
  /*******************************************************/


  load_game();


  /*********/
  SDL_Quit();
  return 0;
  /*********/
}