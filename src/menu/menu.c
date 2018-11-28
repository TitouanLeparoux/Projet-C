int load_menu()
{
  // GAME LOOP
  int continuer = 1; 
  while (continuer == 1) {
    continuer = game(continuer);
  }
  
  return 0;
}


// GAME LOOP
int menu(int continuer)
{
  continuer = control_key(continuer);

  print_map();
  
  SDL_Flip(screen);
  return continuer;
}