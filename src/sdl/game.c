int load_game()
{
  mLoad = 0;
  tLoad = 0;
  rLoad = 0;

  int continuer = 1; 
  while (continuer == 1) {
    continuer = game(continuer);
  }
  
  deload_imgMap();
  deload_imgTank();
  return 0;
}

int game(int continuer)
{
  continuer = control_key(continuer);

  print_map();
  print_tank(TK_user);
  print_rocketsList();
  
  SDL_Flip(screen);
  return continuer;
}