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
  unsigned int L = 20; unsigned int H = 15; unsigned int SCL = 32;
  screen = SDL_SetVideoMode(SCL*L, SCL*H, 32, SDL_HWSURFACE); // 640 480
  SDL_WM_SetCaption("TANK GAME !", NULL);
  /*******************************************************/

  SDL_Surface *background, *tank;
  SDL_Rect posBG, posTK;
  posBG.x = 0; posBG.y = 0;
  posTK.x = 0; posTK.y = 0;

  background    = IMG_Load("img/durt.bmp");
  // tank          = IMG_Load("img/tanks_bleu.png");
  for (int j = 0; j < H+1; j++) {
    for (int i = 0; i < L+1; i++) {
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
