#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL_image.h>

void load_map(int H, int L, SDL_Surface *screen)
{ 
  FILE *map = fopen("../map/map1.txt", "r");
  
  SDL_Surface *durt, *w1, *w2, *w3, *w4, *w6, *w7, *w9, *wd, *wg;
  SDL_Rect posBG; posBG.x = 0; posBG.y = 0;
  
  durt = IMG_Load("img/durt.png");
  w1 = IMG_Load("img/wall/wall_1.png");
  w2 = IMG_Load("img/wall/wall_2.png");
  w3 = IMG_Load("img/wall/wall_3.png");
  w4 = IMG_Load("img/wall/wall_4.png");
  w6 = IMG_Load("img/wall/wall_6.png");
  w7 = IMG_Load("img/wall/wall_7.png");
  w9 = IMG_Load("img/wall/wall_9.png");
  wd = IMG_Load("img/wall/wall_d.png");
  wg = IMG_Load("img/wall/wall_g.png");
  
  for (int j = 0; j < H+1; j++) { 
    for (int i = 0; i < L+1; i++) {
      SDL_BlitSurface(durt, NULL, screen, &posBG);
      switch (getc(map)) {
        case '1': SDL_BlitSurface(w1, NULL, screen, &posBG); break;
        case '2': SDL_BlitSurface(w2, NULL, screen, &posBG); break;
        case '3': SDL_BlitSurface(w3, NULL, screen, &posBG); break;
        case '4': SDL_BlitSurface(w4, NULL, screen, &posBG); break;
        case '6': SDL_BlitSurface(w6, NULL, screen, &posBG); break;
        case '7': SDL_BlitSurface(w7, NULL, screen, &posBG); break;
        case '9': SDL_BlitSurface(w9, NULL, screen, &posBG); break;
        case 'd': SDL_BlitSurface(wd, NULL, screen, &posBG); break;
        case 'g': SDL_BlitSurface(wg, NULL, screen, &posBG); break;
        default:  /* RIEN */; break; }
      posBG.x += 32; }
    posBG.x = 0;
    posBG.y += 32;
  }
  // SDL_Flip(screen);

  SDL_FreeSurface(durt);
  SDL_FreeSurface(w1);
  SDL_FreeSurface(w2);
  SDL_FreeSurface(w3);
  SDL_FreeSurface(w4);
  SDL_FreeSurface(w6);
  SDL_FreeSurface(w7);
  SDL_FreeSurface(w9);
  SDL_FreeSurface(wd);
}