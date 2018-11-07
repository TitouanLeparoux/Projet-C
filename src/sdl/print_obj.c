void print_map()
{   
  // Rect for print txture block image
  SDL_Rect posBG; posBG.x = 0; posBG.y = 0;
 
  // Load only once in RAM texture image and text map
  if (IMGM.load == 0) { load_imgMap(); }
  if (mLoad == 0) { /*load_tabMap();*/ load_tabMap(); }
  
  // Print map
  for (int j = 0; j < H; j++) { 
    for (int i = 0; i < L; i++) {
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

void print_tank(tank *tankMove)
{
  SDL_Rect posTK;
  posTK.x = tankMove->posX;
  posTK.y = tankMove->posY;
  
  if (IMGT.load == 0) { load_imgTank(); }

  if(tankMove->type =='U') {
    switch (tankMove->direction) {
      case 2: SDL_BlitSurface(IMGT.TU2, NULL, screen, &posTK); break;
      case 4: SDL_BlitSurface(IMGT.TU4, NULL, screen, &posTK); break;
      case 6: SDL_BlitSurface(IMGT.TU6, NULL, screen, &posTK); break;
      case 8: SDL_BlitSurface(IMGT.TU8, NULL, screen, &posTK); break;
    }
  }
  else {
    switch (tankMove->direction) {
      case 2: SDL_BlitSurface(IMGT.TE2, NULL, screen, &posTK); break;
      case 4: SDL_BlitSurface(IMGT.TE4, NULL, screen, &posTK); break;
      case 6: SDL_BlitSurface(IMGT.TE6, NULL, screen, &posTK); break;
      case 8: SDL_BlitSurface(IMGT.TE8, NULL, screen, &posTK); break;
    }
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