void print_map()
{   
  // Rect for print txture block image
  SDL_Rect posBG; posBG.x = 0; posBG.y = 0;
  SDL_Rect posTiti; posTiti.x = TITI->posX-(SCL/2); posTiti.y = TITI->posY;
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

  SDL_BlitSurface(IMGM.titi, NULL, screen, &posTiti);
}

void print_tanksList()
{
  if (tLoad == 0) { load_listTank(); }

  print_tank(TK_user);

  if (FIRST_TK == NULL) {
    CONTINUE = 4;
  }

  tank *crt_tk = FIRST_TK; int i = 0; // crt_tk = current tank
  while (crt_tk != NULL) {

    if (crt_tk->alive > 0) {
      print_tank(crt_tk);

      if (clock() > TIME_MEM[i] + SPEED_TANK) {
        
        int prob_actuel_dir = 0;
        switch(crt_tk->direction) {
          case 2: if (MAP[(crt_tk->posY+SCL)/SCL][crt_tk->posX/SCL].type == ' ' )   { prob_actuel_dir = PROBA_DIR_TANK; } break;
          case 4: if (MAP[(crt_tk->posY)/SCL][(crt_tk->posX-SCL)/SCL].type == ' ' ) { prob_actuel_dir = PROBA_DIR_TANK; } break;
          case 6: if (MAP[(crt_tk->posY)/SCL][(crt_tk->posX+SCL)/SCL].type == ' ' ) { prob_actuel_dir = PROBA_DIR_TANK; } break;
          case 8: if (MAP[(crt_tk->posY-SCL)/SCL][crt_tk->posX/SCL].type == ' ' )   { prob_actuel_dir = PROBA_DIR_TANK; } break;
        }
        
        int size_possible = prob_actuel_dir;
        if (MAP[(crt_tk->posY+SCL)/SCL][crt_tk->posX/SCL].type == ' ')    { size_possible += 1; }
        if (MAP[(crt_tk->posY)/SCL][(crt_tk->posX-SCL)/SCL].type == ' ')  { size_possible += 1; }
        if (MAP[(crt_tk->posY)/SCL][(crt_tk->posX+SCL)/SCL].type == ' ')  { size_possible += 1; }
        if (MAP[(crt_tk->posY-SCL)/SCL][crt_tk->posX/SCL].type == ' ')    { size_possible += 1; }
        
        int tab_possible[size_possible];
        int posTabPoss = 0;
        if (MAP[(crt_tk->posY+SCL)/SCL][crt_tk->posX/SCL].type == ' ')    { tab_possible[posTabPoss] = 2; posTabPoss += 1; }
        if (MAP[(crt_tk->posY)/SCL][(crt_tk->posX-SCL)/SCL].type == ' ')  { tab_possible[posTabPoss] = 4; posTabPoss += 1; }
        if (MAP[(crt_tk->posY)/SCL][(crt_tk->posX+SCL)/SCL].type == ' ')  { tab_possible[posTabPoss] = 6; posTabPoss += 1; }
        if (MAP[(crt_tk->posY-SCL)/SCL][crt_tk->posX/SCL].type == ' ')    { tab_possible[posTabPoss] = 8; posTabPoss += 1; }
        
        for (int j = 0; j < prob_actuel_dir; j++) {
          tab_possible[posTabPoss] = crt_tk->direction; 
          posTabPoss += 1;
        }
        
        int var_random = rand()%size_possible;
        int dirActualTank = tab_possible[var_random];
        
        int save_dir = 0;
        switch (dirActualTank) {
          case 2:
            if(crt_tk->direction == 2 && MAP[(crt_tk->posY+SCL)/SCL][crt_tk->posX/SCL].type == ' ' ) {
              crt_tk->posY += SCL; }
            crt_tk->direction = 2;
            break;
          
          case 4:
            if(crt_tk->direction == 4 && MAP[(crt_tk->posY)/SCL][(crt_tk->posX-SCL)/SCL].type == ' ' ) {
              crt_tk->posX -= SCL; }
            crt_tk->direction = 4;
            break;
          
          case 6:
            if(crt_tk->direction == 6 && MAP[(crt_tk->posY)/SCL][(crt_tk->posX+SCL)/SCL].type == ' ' ) {
              crt_tk->posX += SCL; }
            crt_tk->direction = 6; 
            break;
          
          case 8:
            if(crt_tk->direction == 8 && MAP[(crt_tk->posY-SCL)/SCL][crt_tk->posX/SCL].type == ' ' ) {
              crt_tk->posY -= SCL; }
            crt_tk->direction = 8;
            break;
        }
        TIME_MEM[i] = clock();
        create_roquet(crt_tk->posX, crt_tk->posY, crt_tk->type, crt_tk->direction);
      }
    }
  crt_tk = crt_tk->next_tank; i++;
  }
}

void print_tank(tank *tankMove)
{
  SDL_Rect posTK;
  posTK.x = tankMove->posX;
  posTK.y = tankMove->posY;
  
  if (IMGT.load == 0) { load_imgTank(); }

  if(tankMove->type =='U') {
    if (tankMove->alive > 0) {
      if (tankMove->direction == 2) {
        switch(tankMove->alive) {
          case 1: SDL_BlitSurface(IMGT.TU12, NULL, screen, &posTK); break;
          case 2: SDL_BlitSurface(IMGT.TU22, NULL, screen, &posTK); break;
          case 3: SDL_BlitSurface(IMGT.TU32, NULL, screen, &posTK); break;
        }
      }
      else if (tankMove->direction == 4) {
        switch(tankMove->alive) {
          case 1: SDL_BlitSurface(IMGT.TU14, NULL, screen, &posTK); break;
          case 2: SDL_BlitSurface(IMGT.TU24, NULL, screen, &posTK); break;
          case 3: SDL_BlitSurface(IMGT.TU34, NULL, screen, &posTK); break;
        }
      }
      else if (tankMove->direction == 6) {
        switch(tankMove->alive) {
          case 1: SDL_BlitSurface(IMGT.TU16, NULL, screen, &posTK); break;
          case 2: SDL_BlitSurface(IMGT.TU26, NULL, screen, &posTK); break;
          case 3: SDL_BlitSurface(IMGT.TU36, NULL, screen, &posTK); break;
        }
      }
      else if (tankMove->direction == 8) {
        switch(tankMove->alive) {
          case 1: SDL_BlitSurface(IMGT.TU18, NULL, screen, &posTK); break;
          case 2: SDL_BlitSurface(IMGT.TU28, NULL, screen, &posTK); break;
          case 3: SDL_BlitSurface(IMGT.TU38, NULL, screen, &posTK); break;
        }
      }
    }
  }
  else {
    if (tankMove->direction == 2) {
      switch(tankMove->alive) {
        case 1: SDL_BlitSurface(IMGT.TE12, NULL, screen, &posTK); break;
        case 2: SDL_BlitSurface(IMGT.TE22, NULL, screen, &posTK); break;
        case 3: SDL_BlitSurface(IMGT.TE32, NULL, screen, &posTK); break;
      }
    }
    else if (tankMove->direction == 4) {
      switch(tankMove->alive) {
        case 1: SDL_BlitSurface(IMGT.TE14, NULL, screen, &posTK); break;
        case 2: SDL_BlitSurface(IMGT.TE24, NULL, screen, &posTK); break;
        case 3: SDL_BlitSurface(IMGT.TE34, NULL, screen, &posTK); break;
      }
    }
    else if (tankMove->direction == 6) {
      switch(tankMove->alive) {
        case 1: SDL_BlitSurface(IMGT.TE16, NULL, screen, &posTK); break;
        case 2: SDL_BlitSurface(IMGT.TE26, NULL, screen, &posTK); break;
        case 3: SDL_BlitSurface(IMGT.TE36, NULL, screen, &posTK); break;
      }
    }
    else if (tankMove->direction == 8) {
      switch(tankMove->alive) {
        case 1: SDL_BlitSurface(IMGT.TE18, NULL, screen, &posTK); break;
        case 2: SDL_BlitSurface(IMGT.TE28, NULL, screen, &posTK); break;
        case 3: SDL_BlitSurface(IMGT.TE38, NULL, screen, &posTK); break;
      }
    }
  }
}

void print_rocketsList()
{
  // if (rLoad == 0) { load_listRocket(); }

  rocket *crt_rk = FIRST_RK; int i = 0; // crt_rk = current rocket //
  // for (unsigned int i = 0; i < NBR_RK_MAX; i++) {
  while (crt_rk != NULL) {

    if (crt_rk->alive == 1) {
      if (MAP[crt_rk->posY/SCL][crt_rk->posX/SCL].type != ' ') 
      {
        switch (MAP[crt_rk->posY/SCL][crt_rk->posX/SCL].type ) {
        case 'w': MAP[crt_rk->posY/SCL][crt_rk->posX/SCL].type = 'b'; crt_rk->alive = 0; break;
        case 'b': MAP[crt_rk->posY/SCL][crt_rk->posX/SCL].type = ' '; crt_rk->alive = 0; break;
        }
      }  
      else {

        tank *crt_tk = FIRST_TK; int j = 0;
        //for (unsigned int j = 0; j < NBR_TK_MAX; j++) {
        while (crt_tk != NULL) {
          if (crt_rk->posX == crt_tk->posX && crt_rk->posY == crt_tk->posY && crt_rk->type == 'U' && crt_tk->alive > 0) {
            crt_tk->alive -= 1;
            if (crt_tk->alive <= 0) {
              delete_tank(crt_tk);
              delete_rocket(crt_rk);
            }
          }
          else if (crt_rk->posX == TK_user->posX && crt_rk->posY == TK_user->posY && crt_rk->type == 'E') {
            TK_user->alive -= 1;
            if(TK_user->alive <= 0) {
              CONTINUE = 4;
              delete_rocket(crt_rk);
            }
          }
          else if (crt_rk->posX == TITI->posX && crt_rk->posY == TITI->posY && crt_rk->type == 'E' 
          || crt_rk->posX == TITI->posX-SCL && crt_rk->posY == TITI->posY && crt_rk->type == 'E') {
            TITI->alive = 0;
            TK_user->alive = 0;
            CONTINUE = 4;
            delete_rocket(crt_rk);
          }
        crt_tk = crt_tk->next_tank; j++;
        }
      } 
    }

    if (crt_rk->alive == 1) {
      switch (crt_rk->direction) {
        case 2: crt_rk->posY += SCL; break;
        case 4: crt_rk->posX -= SCL; break;
        case 6: crt_rk->posX += SCL; break;
        case 8: crt_rk->posY -= SCL; break;
      }
      if (crt_rk->posY > SCL * (H-1)-1 || crt_rk->posY < SCL * (0+1) ||
          crt_rk->posX > SCL * (L-1)-1 || crt_rk->posX < SCL * (0+1)) {
        crt_rk->alive = 0;
      }
      else {
        print_rocket(crt_rk);
      }
    }
  crt_rk = crt_rk->next_rocket; i++;
  }
}

void print_rocket(rocket *rocketMove)
{
  SDL_Rect posRK;
  posRK.x = rocketMove->posX;
  posRK.y = rocketMove->posY;
  
  if (IMGR.load == 0) { load_imgRocket(); }

  switch (rocketMove->direction) {
    case 2: SDL_BlitSurface(IMGR.R2, NULL, screen, &posRK); break;
    case 4: SDL_BlitSurface(IMGR.R4, NULL, screen, &posRK); break;
    case 6: SDL_BlitSurface(IMGR.R6, NULL, screen, &posRK); break;
    case 8: SDL_BlitSurface(IMGR.R8, NULL, screen, &posRK); break;
  }
}