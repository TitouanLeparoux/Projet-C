#include "move_tank.c"

int game()
{
  TK_user = malloc(sizeof(tank)); // make user tank
  TK_user->type = 'U'; // make tank an user and not an enemy
  TK_user->posX = L / 2 * SCL; 
  TK_user->posY = 10 * SCL;
  TK_user->direction = 2;
  
  int continuer = 1;
  mLoad = 0;
  while (continuer) {
    continuer = key_action(continuer);
  }
  
  deload_imgMap();
  deload_imgTank();
  return 0;
}
