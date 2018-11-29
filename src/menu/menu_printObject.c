void print_menu()
{   
  SDL_Rect posBG; posBG.x = 0; posBG.y = 0;
  SDL_Rect posPlay; posPlay.x = 0; posPlay.y = SCL * 8;
  SDL_Rect posQuit; posQuit.x = 0; posQuit.y = SCL * 11;

  if (IMGM.load == 0) { load_imgMenu(); }

  SDL_BlitSurface(IMGMENU.backGround, NULL, screen, &posBG);

  SDL_BlitSurface(IMGMENU.play, NULL, screen, &posPlay);
  SDL_BlitSurface(IMGMENU.quit, NULL, screen, &posQuit);

/*
  for (unsigned int j = 0; j < H; j++) { 
    for (unsigned int i = 0; i < L; i++) {
      SDL_BlitSurface(IMGM.durt, NULL, screen, &posBG);
      posBG.x += SCL; 
    }
    posBG.x = 0;
    posBG.y += SCL;
  }
*/
}