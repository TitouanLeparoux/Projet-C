void control_key_mainMenu()
{
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    switch (event.type) {
     
      case SDL_QUIT: CONTINUE = 0; break;
      
      case SDL_KEYDOWN: switch (event.key.keysym.sym) {
        
        case SDLK_ESCAPE: 
          // CONTINUE = 0; 
          break;
        
        case SDLK_DOWN:
          posTankCursor = 1;
          break;
        
        case SDLK_UP:
          posTankCursor = 0;
          break;
        
        case SDLK_RETURN:
          if (posTankCursor == 0) { CONTINUE = 2; }
          if (posTankCursor == 1) { CONTINUE = 0; }
          break;

        default: /* NONE */;
      }
    }
  }
}

void control_key_difficultyMenu()
{
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    switch (event.type) {
     
      case SDL_QUIT: CONTINUE = 0; break;
      
      case SDL_KEYDOWN: switch (event.key.keysym.sym) {
        
        case SDLK_ESCAPE: 
          CONTINUE = 1; 
          break;
        
        case SDLK_DOWN:
          posTankCursor += 1;
          if (posTankCursor > 2) { posTankCursor = 2; }
          break;
        
        case SDLK_UP:
          posTankCursor -= 1;
          if (posTankCursor < 0) { posTankCursor = 0; }
          break;
        
        case SDLK_RETURN:
          if (posTankCursor == 0) { DIFFICULTY = 1; }
          if (posTankCursor == 1) { DIFFICULTY = 2; }
          if (posTankCursor == 2) { DIFFICULTY = 3; }
          
          CONTINUE = 3;
          mLoad = 0; tLoad = 0;
          free_tank_list();

          break;

        default: /* NONE */;
      }
    }
  }
}