void load_game()
{
  // MENU
  // menuLoad = 0;

  // GAME
  mLoad = 0; tLoad = 0;
  malloc_tabMap();
  TK_user = malloc(sizeof(tank));
  TK_user->type = 'U'; // tank USER
  TK_user->posX = SCL * L/2; 
  TK_user->posY = SCL * 10;
  TK_user->direction = 2;
  TK_user->alive = 3;
  TK_user->next_tank = NULL;

  // >>> GAME LOOP
  CONTINUE = 1; 
  while (CONTINUE != 0) {
    game();
  }
  
  // MENU
  deload_imgMenu();

  // GAME
  deload_imgMap();
  deload_imgTank();
  deload_imgRocket();
}


// GAME LOOP
void game()
{

  switch (CONTINUE) {
    // case 0 --> QUIT PROGRAM

    case 1: // MAIN MENU
      control_key_mainMenu();
      print_mainMenu();
      break;

    case 2: // DIFFICULTY MENU
      control_key_difficultyMenu();
      print_difficultyMenu();
      break;

    case 3: // GAME
      control_key();
      print_map();
      print_tanksList();
      print_rocketsList();
      break;

    case 4: // WIN or GAME OVER
      control_key_endMenu();
      print_endMenu();
      break;
  }

  SDL_Flip(screen);
}