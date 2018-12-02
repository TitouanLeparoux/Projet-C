void control_key()
{
  SDL_Event event;
  int save_dir = 0;

  while (SDL_PollEvent(&event)) {
    switch (event.type) {
      
      case SDL_QUIT: 
        posTankCursor = 0;
        CONTINUE = 1; break;
      
      case SDL_KEYDOWN: 
        switch (event.key.keysym.sym) {
        
        case SDLK_ESCAPE: 
          posTankCursor = 0;
          CONTINUE = 1; break;
        
        case SDLK_DOWN:

          if(TK_user->direction == 2 && MAP[(TK_user->posY+SCL)/SCL][TK_user->posX/SCL].type == ' ' ) {
            TK_user->posY += SCL; }
          TK_user->direction = 2;
          break;
        
        case SDLK_LEFT:
          if(TK_user->direction == 4 && MAP[(TK_user->posY)/SCL][(TK_user->posX-SCL)/SCL].type == ' ' ) {
            TK_user->posX -= SCL; }
          TK_user->direction = 4;
          break;
        
        case SDLK_RIGHT:
          if(TK_user->direction == 6 && MAP[(TK_user->posY)/SCL][(TK_user->posX+SCL)/SCL].type == ' ' ) {
            TK_user->posX += SCL; }
          TK_user->direction = 6; 
          break;
        
        case SDLK_UP:

          if(TK_user->direction == 8 && MAP[(TK_user->posY-SCL)/SCL][TK_user->posX/SCL].type == ' ' ) {
            TK_user->posY -= SCL; }
          TK_user->direction = 8;
          break;
        
        case SDLK_SPACE: ;
          create_roquet(TK_user->posX, TK_user->posY, TK_user->type, TK_user->direction);
          break;

        default: /* NONE */;
      }
    }
  }
}