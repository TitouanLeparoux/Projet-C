// gcc main.c `sdl-config --cflags --libs` -lSDLmain -lSDL -lSDL_image

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL_image.h>

// INCLUDE VARRIABLE AND STRUCT
#include "struct.h"
#include "var_global.h"
#include "prototype.h"
// INCLUDE FUNCTION FILE
#include "game.c"
#include "load.c"
#include "control_key.c"
#include "print_obj.c"
#include "new_rocket.c"


int main(int argc, char *argv[])
{    
  /*******************************************************/
  SDL_Init(SDL_INIT_VIDEO);
  screen = SDL_SetVideoMode(SCL*L, SCL*H, 32,
    SDL_HWSURFACE | SDL_DOUBLEBUF /*SDL_RESIZABLE | SDL_FULLSCREEN */);
  SDL_WM_SetCaption("TANK GAME !", NULL);
  /*******************************************************/

  if (mLoad == 0) { malloc_tabMap(); }

  TK_user = malloc(sizeof(tank)); // make user tank
  TK_user->type = 'U'; // make tank an user and not an enemy
  TK_user->posX = L / 2 * SCL; 
  TK_user->posY = 10 * SCL;
  TK_user->direction = 2;

  rocketN01 = malloc(sizeof(rocket));
  rocketN01->posX = 0;
  rocketN01->posY = 0;
  rocketN01->direction = 6;
  rocketN01->type = 'U';

  game(); // Condition stop SDL

  // END
  SDL_Quit();
  return 0;
}