int control_key_menu(int continuer)
{
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    switch (event.type) {
      case SDL_QUIT: continuer = 0; break;
      case SDL_KEYDOWN: 
        switch (event.key.keysym.sym) {
          case SDLK_ESCAPE: 
            continuer = 0; 
            break;
          
          case SDLK_DOWN:
            break;
          
          case SDLK_UP:
            break;
          
          case SDLK_SPACE:
            break;

          default: /* NONE */;
        }
    }
  }
  return continuer;
}