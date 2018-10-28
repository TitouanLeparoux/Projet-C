// gcc sdl.c `sdl-config --cflags --libs` -lSDLmain -lSDL -lSDL_image

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL_image.h>

unsigned int SCL = 32;  // texture size in pixel
unsigned int L = 20;    // screen width in block of texture
unsigned int H = 15;    // screen height in block of texture

SDL_Surface *screen;

#include "load_map.c"
#include "game.c"


int main(int argc, char *argv[])
{    
  /*******************************************************/
  SDL_Init(SDL_INIT_VIDEO);
  // SDL_Surface *screen;
  screen = SDL_SetVideoMode(SCL*L, SCL*H, 32,
    SDL_HWSURFACE | SDL_DOUBLEBUF /*SDL_RESIZABLE SDL_FULLSCREEN*/);
  SDL_WM_SetCaption("TANK GAME !", NULL);
  /*******************************************************/

  // load_tank(screen);
  game(); // Condition stop SDL
  
  // END
  SDL_Quit();
  return 0;
}