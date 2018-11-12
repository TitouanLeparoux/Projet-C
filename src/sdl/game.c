int key_action(int continuer)
{
  continuer = control_key(continuer);

  print_map();

  /*
  for (int i = 0; i < NBR_RK; i++) {
    print_rocket(ROCKETS+i);
  }
  */
  
  /*
  if(rocketN01->type != 'A') 
    { 
      (print_rocket(rocketN01);
    }
  print_tank(TK_user);
  SDL_Flip(screen);

  return continuer;
  */
}

int game()
{
  mLoad = 0;
  int continuer = 1;
  
    while (continuer == 1) 
  {
    continuer = key_action(continuer);
  }
  
  deload_imgMap();
  deload_imgTank();
  return 0;
}
