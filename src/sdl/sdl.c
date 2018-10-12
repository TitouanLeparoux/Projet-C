#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL_image.h>

void pause()
{
  int continuer = 1;
  SDL_Event event;
  while (continuer) {
    SDL_WaitEvent(&event);
    if(event.type == SDL_QUIT) { continuer = 0; }
  }
}

/************************************************************************************/

int main(int argc, char *argv[])
{    
  /*******************************************************/
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Surface *screen;
  screen = SDL_SetVideoMode(32*16, 32*8, 32, SDL_HWSURFACE); // 640 480
  SDL_WM_SetCaption("TANK GAME !", NULL);
  /*******************************************************/

  SDL_Surface *background, *tank;
  SDL_Rect posBG, posTK;
  posBG.x = 0; posBG.y = 0;
  posTK.x = 0; posTK.y = 0;

  background    = IMG_Load("durt.bmp");
  tank          = IMG_Load("tank_bleu.png");
  for (int j = 0; j < 9; j++) {
    for (int i = 0; i < 17; i++) {
      SDL_BlitSurface(background, NULL, screen, &posBG);
      posBG.x += 32;
    }
    posBG.x = 0;
    posBG.y += 32;
  }
  SDL_BlitSurface(tank, NULL, screen, &posTK);
  SDL_Flip(screen);

  // END
  pause(); // Condition stop SDL
  SDL_FreeSurface(background);
  SDL_Quit();
  return EXIT_SUCCESS;
}
