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
        save_dir = TK_user->direction;
        switch (event.key.keysym.sym) {
        
        case SDLK_ESCAPE: 
          posTankCursor = 0;
          CONTINUE = 1; break;
        
        case SDLK_DOWN:
          TK_user->direction = 2;
          if(save_dir == TK_user->direction && MAP[(TK_user->posY+SCL)/SCL][TK_user->posX/SCL].type != 'w' ) {
            TK_user->posY += SCL; }
          break;
        
        case SDLK_LEFT:
          TK_user->direction = 4;
          if(save_dir == TK_user->direction && MAP[(TK_user->posY)/SCL][(TK_user->posX-SCL)/SCL].type != 'w' ) {
            TK_user->posX -= SCL; }
          break;
        
        case SDLK_RIGHT:
          TK_user->direction = 6; 
          if(save_dir == TK_user->direction && MAP[(TK_user->posY)/SCL][(TK_user->posX+SCL)/SCL].type != 'w' ) {
            TK_user->posX += SCL; }
          break;
        
        case SDLK_UP:
          TK_user->direction = 8;
          if(save_dir == TK_user->direction && MAP[(TK_user->posY-SCL)/SCL][TK_user->posX/SCL].type != 'w' ) {
            TK_user->posY -= SCL; }
          break;
        
        case SDLK_SPACE: ;
          create_roquet(TK_user->posX, TK_user->posY, TK_user->type, TK_user->direction);
          break;

        default: /* NONE */;
      }
    }
  }
}