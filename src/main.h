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
#include "include/struct.h"
#include "include/var_global.h"
#include "include/prototype.h"

// INCLUDE MENU FILE
#include "menu/menu_load.c"
#include "menu/menu_controlKey.c"
#include "menu/menu_printObject.c"
// INCLUDE GAME FILE
#include "game/game.c"
#include "game/game_load.c"
#include "game/game_controlKey.c"
#include "game/game_printObject.c"