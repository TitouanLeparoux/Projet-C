int load_game()
{
  mLoad = 0; tLoad = 0; rLoad = 0;

  malloc_tabMap();
  // malloc_listTank();
  // malloc_listRocket();

  TK_user = malloc(sizeof(tank));
  TK_user->type = 'U'; // tank USER
  TK_user->posX = SCL * L/2; 
  TK_user->posY = SCL * 10;
  TK_user->direction = 2;
  TK_user->alive = 1;
  TK_user->next_tank = NULL;

  // GAME LOOP
  int continuer = 1; 
  while (continuer == 1) {
    continuer = game(continuer);
  }
  
  deload_imgMap();
  deload_imgTank();
  deload_imgRocket();
  return 0;
}


// GAME LOOP
int game(int continuer)
{
  continuer = control_key(continuer);

  print_map();
  print_tanksList();
  print_rocketsList();
  
  SDL_Flip(screen);
  return continuer;
}