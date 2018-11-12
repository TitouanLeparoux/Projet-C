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
//        if(tabMap_type[ ((TK_user->posY+SCL+1)/SCL)*L + ((TK_user->posX)/SCL)] != 'w' ) {
        if(MAP[(TK_user->posY+SCL)/SCL][TK_user->posX/SCL].type != 'w' ) {
          TK_user->posY += SCL;
        }
        break;
      case SDLK_LEFT:
        TK_user->direction = 4;
//        if(tabMap_type[ ((TK_user->posY)/SCL)*L + ((TK_user->posX-1)/SCL)] != 'w' ){
        if(MAP[(TK_user->posY)/SCL][(TK_user->posX-SCL)/SCL].type != 'w' ) {
          TK_user->posX -= SCL;
        }
        break;
      case SDLK_RIGHT:
        TK_user->direction = 6; 
//        if(tabMap_type[ ((TK_user->posY)/SCL)*L + ((TK_user->posX+SCL+1)/SCL)] != 'w' ){
        if(MAP[(TK_user->posY)/SCL][(TK_user->posX+SCL)/SCL].type != 'w' ) {
          TK_user->posX += SCL;
        }
        break;
      case SDLK_UP:
        TK_user->direction = 8;
//        if(tabMap_type[ ((TK_user->posY-1)/SCL)*L + ((TK_user->posX)/SCL)] != 'w' ) {
        if(MAP[(TK_user->posY-SCL)/SCL][TK_user->posX/SCL].type != 'w' ) {
          TK_user->posY -= SCL;
        }
        break;
      case SDLK_SPACE:
        /*
        NBR_RK += 1;
        ROCKETS = realloc(ROCKETS, NBR_RK * sizeof(rocket));
        new_rocket(TK_user, &ROCKETS[NBR_RK]);
        printf("\nNBR_RK : %d", NBR_RK);
        */
        

        // rocketN01 = malloc(sizeof(rocket));
        // &rocketN01 = new_rocket(TK_user);
        // print_rocket(rocketN02);
        
        
        //rocketN01 = malloc_rocket(rocketN01);
        
        // rocketN01 = malloc(sizeof(rocket));
        
        rocketN01->posX = TK_user->posX;
        rocketN01->posY = TK_user->posY;
        switch (TK_user->direction) {
          case 2: rocketN01->posY = TK_user->posY+SCL; break;
          case 4: rocketN01->posX = TK_user->posX-SCL; break;
          case 6: rocketN01->posX = TK_user->posX+SCL; break;
          case 8: rocketN01->posY = TK_user->posY-SCL; break;
        }
        rocketN01->direction = TK_user->direction;
        rocketN01->type = TK_user->type;
        // print_rocket(rocketN01);

        break;
      default: /* NONE */; break;
    }
  }
  return continuer;
}