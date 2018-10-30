void print_map()
{ 
  FILE *map = fopen("../map/map2.txt", "r");
  
  SDL_Rect posBG; posBG.x = 0; posBG.y = 0;
 
  if (IMGM.load == 0) { load_imgMap(); }
  if (mLoad == 0) { load_tabMap(); }
  
  for (int j = 0; j < H+1; j++) { 
    for (int i = 0; i < L+1; i++) {
      SDL_BlitSurface(IMGM.durt, NULL, screen, &posBG);
      switch (tabMap_type[j*L+i]) {
        case 'w': SDL_BlitSurface(IMGM.w1, NULL, screen, &posBG); break;
        case 'b': SDL_BlitSurface(IMGM.w2, NULL, screen, &posBG); break;
        default:  /* RIEN */; break; }
      posBG.x += SCL; }
    posBG.x = 0;
    posBG.y += SCL;
  }
  // SDL_Flip(screen);

  fclose(map);
}