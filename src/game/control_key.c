int control_key(int continuer)
{
  SDL_Event event;
  int save_dir = 0;

  while (SDL_PollEvent(&event)) {
    switch (event.type) {
      case SDL_QUIT: continuer = 0; break;
      case SDL_KEYDOWN: 
        save_dir = TK_user.direction;
        switch (event.key.keysym.sym) {
        
        case SDLK_ESCAPE: continuer = 0; break;
        
        case SDLK_DOWN:
          TK_user.direction = 2;
          if(save_dir == TK_user.direction && MAP[(TK_user.posY+SCL)/SCL][TK_user.posX/SCL].type != 'w' ) {
            TK_user.posY += SCL; }
          break;
        
        case SDLK_LEFT:
          TK_user.direction = 4;
          if(save_dir == TK_user.direction && MAP[(TK_user.posY)/SCL][(TK_user.posX-SCL)/SCL].type != 'w' ) {
            TK_user.posX -= SCL; }
          break;
        
        case SDLK_RIGHT:
          TK_user.direction = 6; 
          if(save_dir == TK_user.direction && MAP[(TK_user.posY)/SCL][(TK_user.posX+SCL)/SCL].type != 'w' ) {
            TK_user.posX += SCL; }
          break;
        
        case SDLK_UP:
          TK_user.direction = 8;
          if(save_dir == TK_user.direction && MAP[(TK_user.posY-SCL)/SCL][TK_user.posX/SCL].type != 'w' ) {
            TK_user.posY -= SCL; }
          break;
        
        case SDLK_SPACE: ;
          int tmpPos;
          for (unsigned int i = 0; i < NBR_RK_MAX; i++) {
            if (ROCKETS[i].alive == 0) {
              tmpPos = i;
              break;
            }
          }
          ROCKETS[tmpPos].posX = TK_user.posX;
          ROCKETS[tmpPos].posY = TK_user.posY;
          ROCKETS[tmpPos].direction = TK_user.direction;
          ROCKETS[tmpPos].type = TK_user.type;
          ROCKETS[tmpPos].alive = 1;
          break;

        default: /* NONE */;
      }
    }
  }
  
  return continuer;
}