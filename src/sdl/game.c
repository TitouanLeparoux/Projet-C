#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <SDL/SDL.h>

typedef struct {
  int   direction;
  int   posX;
  int   posY;
  int   blindage;
  int   blindage_origin;
  int   touches;
  char  type;
  int   etat;
  int   destruction;
}tank;

void move_tank(tank *TK_user)
{
  SDL_Surface *durt, *img_up, *img_down, *img_right, *img_left;
  SDL_Rect posTK; posTK.x = TK_user->posX; posTK.y = TK_user->posY;
  
  img_up    = IMG_Load("img/tank/tankB_up.png");
  img_down  = IMG_Load("img/tank/tankB_down.png");
  img_right = IMG_Load("img/tank/tankB_right.png");
  img_left  = IMG_Load("img/tank/tankB_left.png");

  load_map();

  switch (TK_user->direction) {
    case 8: SDL_BlitSurface(img_up,    NULL, screen, &posTK); break;
    case 2: SDL_BlitSurface(img_down,  NULL, screen, &posTK); break;
    case 4: SDL_BlitSurface(img_right, NULL, screen, &posTK); break;
    case 6: SDL_BlitSurface(img_left,  NULL, screen, &posTK); break;
    // case 5: /*Space*/
  }

  SDL_Flip(screen);

  SDL_FreeSurface(img_up);
  SDL_FreeSurface(img_down);
  SDL_FreeSurface(img_right);
  SDL_FreeSurface(img_left);
}

int key_action(int continuer, tank *TK_user)
{
  SDL_EnableKeyRepeat(1, 1);
  SDL_Event event;
  SDL_WaitEvent(&event);

  switch (event.type) {
    case SDL_QUIT:    continuer = 0; break;
    case SDL_KEYDOWN: switch (event.key.keysym.sym) {
      case SDLK_ESCAPE: continuer = 0; break;
      // Mouvement Char
      case SDLK_UP:     TK_user->direction = 8; TK_user->posY -= SCL; break;
      case SDLK_DOWN:   TK_user->direction = 2; TK_user->posY += SCL; break;
      case SDLK_RIGHT:  TK_user->direction = 4; TK_user->posX += SCL; break;
      case SDLK_LEFT:   TK_user->direction = 6; TK_user->posX -= SCL; break;
      // case SDLK_SPACE:  direction = 5; break; 
    }
  }
  move_tank(TK_user);

  return continuer;
}

int game()
{
  tank *TK_user;
  TK_user = malloc(sizeof(tank)); // declare user tank
  TK_user->posX = L / 2 * SCL; 
  TK_user->posY = H / 2 * SCL;
  TK_user->direction = 2;
  
  int continuer = 1;
  while (continuer) {
    continuer = key_action(continuer, TK_user);
  }
  return 0;
}
