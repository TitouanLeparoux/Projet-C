void print_map()
{   
  // Rect for print txture block image
  SDL_Rect posBG; posBG.x = 0; posBG.y = 0;
 
  // Load only once in RAM texture image and text map
  if (IMGM.load == 0) { load_imgMap(); }
  if (mLoad == 0) { load_tabMap(); }
  
  // Print map
  for (unsigned int j = 0; j < H; j++) { 
    for (unsigned int i = 0; i < L; i++) {
      SDL_BlitSurface(IMGM.durt, NULL, screen, &posBG);
      switch (MAP[j][i].type) {
        case 'w': SDL_BlitSurface(IMGM.w1, NULL, screen, &posBG); break;
        case 'b': SDL_BlitSurface(IMGM.w2, NULL, screen, &posBG); break;
        default:  /* RIEN */; break; }
      posBG.x += SCL; }
    posBG.x = 0;
    posBG.y += SCL;
  }
}

void print_tanksList()
{
  if (tLoad == 0) { load_listTank(); }

  print_tank(TK_user);

  for (unsigned int i = 0; i < NBR_TK_MAX; i++) {
    if (TANKS[i].alive == 1) {
      print_tank(TANKS[i]);

      if (clock() > TIME_MEM[i] + SPEED_TANK) {
        
        int prob_actuel_dir = 0;
        switch(TANKS[i].direction) {
          case 2: if (MAP[(TANKS[i].posY+SCL)/SCL][TANKS[i].posX/SCL].type != 'w' )   { prob_actuel_dir = PROBA_DIR_TANK; } break;
          case 4: if (MAP[(TANKS[i].posY)/SCL][(TANKS[i].posX-SCL)/SCL].type != 'w' ) { prob_actuel_dir = PROBA_DIR_TANK; } break;
          case 6: if (MAP[(TANKS[i].posY)/SCL][(TANKS[i].posX+SCL)/SCL].type != 'w' ) { prob_actuel_dir = PROBA_DIR_TANK; } break;
          case 8: if (MAP[(TANKS[i].posY-SCL)/SCL][TANKS[i].posX/SCL].type != 'w' )   { prob_actuel_dir = PROBA_DIR_TANK; } break;
        }
        
        int size_possible = prob_actuel_dir;
        if (/*TANKS[i].direction = 2 et */ MAP[(TANKS[i].posY+SCL)/SCL][TANKS[i].posX/SCL].type != 'w')    { size_possible += 1; }
        if (MAP[(TANKS[i].posY)/SCL][(TANKS[i].posX-SCL)/SCL].type != 'w')  { size_possible += 1; }
        if (MAP[(TANKS[i].posY)/SCL][(TANKS[i].posX+SCL)/SCL].type != 'w')  { size_possible += 1; }
        if (MAP[(TANKS[i].posY-SCL)/SCL][TANKS[i].posX/SCL].type != 'w')    { size_possible += 1; }
        
        int tab_possible[size_possible];
        int posTabPoss = 0;
        if (MAP[(TANKS[i].posY+SCL)/SCL][TANKS[i].posX/SCL].type != 'w')    { tab_possible[posTabPoss] = 2; posTabPoss += 1; }
        if (MAP[(TANKS[i].posY)/SCL][(TANKS[i].posX-SCL)/SCL].type != 'w')  { tab_possible[posTabPoss] = 4; posTabPoss += 1; }
        if (MAP[(TANKS[i].posY)/SCL][(TANKS[i].posX+SCL)/SCL].type != 'w')  { tab_possible[posTabPoss] = 6; posTabPoss += 1; }
        if (MAP[(TANKS[i].posY-SCL)/SCL][TANKS[i].posX/SCL].type != 'w')    { tab_possible[posTabPoss] = 8; posTabPoss += 1; }
        for (int j = 0; j < prob_actuel_dir; j++) {
          tab_possible[posTabPoss] = TANKS[i].direction; 
          posTabPoss += 1;
        }
        
        int var_random = rand()%size_possible;
        int dirActualTank = tab_possible[var_random];
        
        int save_dir = 0;
        switch (dirActualTank) {
          case 2:
            TANKS[i].direction = 2;
            if(MAP[(TANKS[i].posY+SCL)/SCL][TANKS[i].posX/SCL].type != 'w' ) {
              TANKS[i].posY += SCL; }
            break;
          
          case 4:
            TANKS[i].direction = 4;
            if(MAP[(TANKS[i].posY)/SCL][(TANKS[i].posX-SCL)/SCL].type != 'w' ) {
              TANKS[i].posX -= SCL; }
            break;
          
          case 6:
            TANKS[i].direction = 6; 
            if(MAP[(TANKS[i].posY)/SCL][(TANKS[i].posX+SCL)/SCL].type != 'w' ) {
              TANKS[i].posX += SCL; }
            break;
          
          case 8:
            TANKS[i].direction = 8;
            if(MAP[(TANKS[i].posY-SCL)/SCL][TANKS[i].posX/SCL].type != 'w' ) {
              TANKS[i].posY -= SCL; }
            break;
        }

        int tmpPos;
        for (unsigned int i = 0; i < NBR_RK_MAX; i++) {
          if (ROCKETS[i].alive == 0) {
            tmpPos = i;
          }
        }
        ROCKETS[tmpPos].posX = TANKS[i].posX;
        ROCKETS[tmpPos].posY = TANKS[i].posY;
        ROCKETS[tmpPos].direction = TANKS[i].direction;
        ROCKETS[tmpPos].type = TANKS[i].type;
        ROCKETS[tmpPos].alive = 1;

        TIME_MEM[i] = clock();
      }
    }
  }
}

void print_tank(tank tankMove)
{
  SDL_Rect posTK;
  posTK.x = tankMove.posX;
  posTK.y = tankMove.posY;
  
  if (IMGT.load == 0) { load_imgTank(); }

  if(tankMove.type =='U') {
    if (TK_user.alive == 1) {
      switch (tankMove.direction) {
        case 2: SDL_BlitSurface(IMGT.TU2, NULL, screen, &posTK); break;
        case 4: SDL_BlitSurface(IMGT.TU4, NULL, screen, &posTK); break;
        case 6: SDL_BlitSurface(IMGT.TU6, NULL, screen, &posTK); break;
        case 8: SDL_BlitSurface(IMGT.TU8, NULL, screen, &posTK); break;
      }
    }
  }
  else {
    switch (tankMove.direction) {
      case 2: SDL_BlitSurface(IMGT.TE2, NULL, screen, &posTK); break;
      case 4: SDL_BlitSurface(IMGT.TE4, NULL, screen, &posTK); break;
      case 6: SDL_BlitSurface(IMGT.TE6, NULL, screen, &posTK); break;
      case 8: SDL_BlitSurface(IMGT.TE8, NULL, screen, &posTK); break;
    }
  }
}

void print_rocketsList()
{
  if (rLoad == 0) { load_listRocket(); }

  for (unsigned int i = 0; i < NBR_RK_MAX; i++) {
    if (ROCKETS[i].alive == 1) {
      if (MAP[ROCKETS[i].posY/SCL][ROCKETS[i].posX/SCL].type == 'w') {
         MAP[ROCKETS[i].posY/SCL][ROCKETS[i].posX/SCL].type = ' ';
        ROCKETS[i].alive = 0;
      }
      else {
        for (unsigned int j = 0; j < NBR_TK_MAX; j++) {
          if (ROCKETS[i].posX == TANKS[j].posX && ROCKETS[i].posY == TANKS[j].posY && ROCKETS[i].type == 'U' && TANKS[j].alive == 1) {
            TANKS[j].alive = 0;
            ROCKETS[i].alive = 0;    
          }
          else if (ROCKETS[i].posX == TK_user.posX && ROCKETS[i].posY == TK_user.posY && ROCKETS[i].type == 'E') {
            TK_user.alive = 0;
            ROCKETS[i].alive = 0;
          }
        }
      } 
    }

    if (ROCKETS[i].alive == 1) {
      switch (ROCKETS[i].direction) {
        case 2: ROCKETS[i].posY += SCL; break;
        case 4: ROCKETS[i].posX -= SCL; break;
        case 6: ROCKETS[i].posX += SCL; break;
        case 8: ROCKETS[i].posY -= SCL; break;
      }
      if (ROCKETS[i].posY > SCL * (H-1)-1 || ROCKETS[i].posY < SCL * (0+1) ||
          ROCKETS[i].posX > SCL * (L-1)-1 || ROCKETS[i].posX < SCL * (0+1)) {
        ROCKETS[i].alive = 0;
      }
      else {
        print_rocket(ROCKETS[i]);
      }
    }
  }
}

void print_rocket(rocket rocketMove)
{
  SDL_Rect posRK;
  posRK.x = rocketMove.posX;
  posRK.y = rocketMove.posY;
  
  if (IMGR.load == 0) { load_imgRocket(); }

  switch (rocketMove.direction) {
    case 2: SDL_BlitSurface(IMGR.R2, NULL, screen, &posRK); break;
    case 4: SDL_BlitSurface(IMGR.R4, NULL, screen, &posRK); break;
    case 6: SDL_BlitSurface(IMGR.R6, NULL, screen, &posRK); break;
    case 8: SDL_BlitSurface(IMGR.R8, NULL, screen, &posRK); break;
  }
}