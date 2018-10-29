#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL_image.h>

void load_tabMap()
{
  blockMap **tabMap = malloc(H * L * sizeof(blockMap));

  FILE *map = fopen("src/design/map/map2.txt", "r");

  for (int j = 0; j < H+1; j++) { 
    for (int i = 0; i < L+1; i++) {
      switch (getc(map)) {
        case 'w':
          tabMap[j][i].type = 'w';
          tabMap[j][i].life = 1;
          break; 
        default: /* RIEN */ ; break; 
      }
    }
  }
  fclose(map);
  free(tabMap);
  // return tabMap;
}

void load_img() 
{
  // IMG = malloc(sizeof(img));

  IMG.durt = IMG_Load("img/deep_durt.png");
  IMG.w1 = IMG_Load("img/wall.png");
  IMG.w2 = IMG_Load("img/wall_used.png");
  IMG.load = 1;
}

void deload_img()
{
  SDL_FreeSurface(IMG.durt);
  SDL_FreeSurface(IMG.w1);
  SDL_FreeSurface(IMG.w2);
}

void load_map()
{ 
  FILE *map = fopen("../map/map2.txt", "r");
  
  // SDL_Surface *durt, *w1, *w2;
  SDL_Rect posBG; posBG.x = 0; posBG.y = 0;
 
  if (IMG.load == 0) { load_img(); }

  for (int j = 0; j < H+1; j++) { 
    for (int i = 0; i < L+1; i++) {
      SDL_BlitSurface(IMG.durt, NULL, screen, &posBG);
      switch (getc(map)) {
        case 'w': SDL_BlitSurface(IMG.w1, NULL, screen, &posBG); break;
        case 'b': SDL_BlitSurface(IMG.w2, NULL, screen, &posBG); break;
        default:  /* RIEN */; break; }
      posBG.x += SCL; }
    posBG.x = 0;
    posBG.y += SCL;
  }
  // SDL_Flip(screen);

  fclose(map);
}