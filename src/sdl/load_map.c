#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL_image.h>

void load_map(int H, int L, SDL_Surface *screen)
{ 
  FILE *map = fopen("../map/map2.txt", "r");
  
  SDL_Surface *durt, *w1, *w2;
  SDL_Rect posBG; posBG.x = 0; posBG.y = 0;
  
  durt = IMG_Load("img/deep_durt.png");
  w1 = IMG_Load("img/wall.png");
  w2 = IMG_Load("img/wall_used.png");
  
  for (int j = 0; j < H+1; j++) { 
    for (int i = 0; i < L+1; i++) {
      SDL_BlitSurface(durt, NULL, screen, &posBG);
      switch (getc(map)) {
        case 'w': SDL_BlitSurface(w1, NULL, screen, &posBG); break;
        case 'b': SDL_BlitSurface(w2, NULL, screen, &posBG); break;
        default:  /* RIEN */; break; }
      posBG.x += SCL; }
    posBG.x = 0;
    posBG.y += SCL;
  }
  // SDL_Flip(screen);

  SDL_FreeSurface(durt);
  SDL_FreeSurface(w1);
  SDL_FreeSurface(w2);
}