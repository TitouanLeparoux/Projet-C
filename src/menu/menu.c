int load_menu()
{
  mLoad = 0;

  // GAME LOOP
  int continuer = 1; 
  while (continuer == 1) {
    continuer = menu(continuer);
  }
  
  deload_imgMenu();
  return 0;
}


// GAME LOOP
int menu(int continuer)
{
  continuer = control_key_menu(continuer);

  print_menu();
  
  SDL_Flip(screen);
  return continuer;
}