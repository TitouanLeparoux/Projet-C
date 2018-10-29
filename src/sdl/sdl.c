// gcc sdl.c `sdl-config --cflags --libs` -lSDLmain -lSDL -lSDL_image

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL_image.h>

// INCLUDE FILES
#include "struct.h"
#include "var_global.h"
#include "load_map.c"
#include "game.c"


int main(int argc, char *argv[])
{    
  /*******************************************************/
  SDL_Init(SDL_INIT_VIDEO);
  screen = SDL_SetVideoMode(SCL*L, SCL*H, 32,
    SDL_HWSURFACE | SDL_DOUBLEBUF /*SDL_RESIZABLE | SDL_FULLSCREEN */);
  SDL_WM_SetCaption("TANK GAME !", NULL);
  /*******************************************************/

  game(); // Condition stop SDL
  
  // END
  SDL_Quit();
  return 0;
}