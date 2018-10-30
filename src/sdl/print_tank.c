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