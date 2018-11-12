int key_action(int continuer)
{
  continuer = control_key(continuer);

  print_map();
  print_tank(TK_user);

  if (NBR_RK > 0) {
    for (int i = 0; i < NBR_RK; i++) {
      if (ROCKETS[i].alive == 1) {
        if(MAP[ROCKETS[i].posY/SCL][ROCKETS[i].posX/SCL].type == 'w') {
          MAP[ROCKETS[i].posY/SCL][ROCKETS[i].posX/SCL].type = ' ';
          ROCKETS[i].alive = 0;
        }
        else {
          switch (ROCKETS[i].direction) {
            case 2: ROCKETS[i].posY += SCL; break;
            case 4: ROCKETS[i].posX -= SCL; break;
            case 6: ROCKETS[i].posX += SCL; break;
            case 8: ROCKETS[i].posY -= SCL; break;
          }
          if (ROCKETS[i].posY > SCL * H || ROCKETS[i].posY < 0 ||
              ROCKETS[i].posX > SCL * L || ROCKETS[i].posX < 0) {
            ROCKETS[i].alive = 0;
          }
          else {
            print_rocket(ROCKETS[i]);
          }
        }
      }
    }
  }
  // for (int i = 0; i < NBR_RK; i++) { print_rocket(ROCKETS+i); }
  // if  (rocketN01->type != 'A') { print_rocket(rocketN01); }
  
  
  SDL_Flip(screen);
  return continuer;
}

int game()
{
  mLoad = 0;
  int continuer = 1;
  
  while (continuer == 1) {
    continuer = key_action(continuer);
  }
  
  deload_imgMap();
  deload_imgTank();
  return 0;
}
