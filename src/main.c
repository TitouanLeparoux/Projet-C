// cd Documents/ESIEA/projet/Projet-C/src
// gcc main.c `sdl-config --cflags --libs` -lSDLmain -lSDL -lSDL_image
// gcc main.c -std=c99 -pedantic -Wall -Wextra `sdl-config --cflags --libs` -lSDLmain -lSDL -lSDL_image

// GDB option de compilation -g, gdb a.out, run, where

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL_image.h>

// INCLUDE VARRIABLE, STRUCT & PROTOTYPE
#include "struct.h"
#include "var_global.h"
#include "prototype.h"

// INCLUDE GAME FILE
#include "game/game.c"
#include "game/game_load.c"
#include "game/game_controlKey.c"
#include "game/game_printObject.c"


int main(int argc, char *argv[])
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