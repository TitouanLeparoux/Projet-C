int key_action(int continuer)
{
  continuer = control_key(continuer);

  print_map();
  print_tank(TK_user);
  SDL_Flip(screen);

  return continuer;
}

int game()
{
  mLoad = 0;
  int continuer = 1;
  
  while (continuer == 1) {
    continuer = key_action(continuer);
  }
  
  deload_imgMap();
  deload_imgTank();
  return 0;
}
