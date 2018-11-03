int control_key(int continuer)
{
  SDL_EnableKeyRepeat(10, 10);
  SDL_Event event;
  SDL_WaitEvent(&event);

  switch (event.type) {
    case SDL_QUIT: continuer = 0; break;
    case SDL_KEYDOWN: switch (event.key.keysym.sym) {
      case SDLK_ESCAPE: continuer = 0; break;
      // Mouvement Char
      case SDLK_DOWN:
        TK_user->direction = 2;
        if(tabMap_type[ ((TK_user->posY+SCL+1)/SCL)*L + ((TK_user->posX)/SCL)] != 'w' ) {
          TK_user->posY += SCL;
        }
        break;
      case SDLK_RIGHT:
        TK_user->direction = 4; 
        if(tabMap_type[ ((TK_user->posY)/SCL)*L + ((TK_user->posX+SCL+1)/SCL)] != 'w' ){
          TK_user->posX += SCL;
        }
        break;
      case SDLK_LEFT:
        TK_user->direction = 6;
        if(tabMap_type[ ((TK_user->posY)/SCL)*L + ((TK_user->posX-1)/SCL)] != 'w' ){
          TK_user->posX -= SCL;
        }
        break;
      case SDLK_UP:
        TK_user->direction = 8;
        if(tabMap_type[ ((TK_user->posY-1)/SCL)*L + ((TK_user->posX)/SCL)] != 'w' ) {
          TK_user->posY -= SCL;
        }
        break;
      // case SDLK_SPACE:  direction = 5; break; 
    }
  }
  return continuer;
}