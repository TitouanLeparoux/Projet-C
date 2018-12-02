void print_mainMenu()
{   
  SDL_Rect posBG; posBG.x = 0; posBG.y = 0;                // BackGround
  SDL_Rect posPlay; posPlay.x = 0; posPlay.y  = SCL * 8;   // Button Play
  SDL_Rect posQuit; posQuit.x = 0; posQuit.y  = SCL * 11;  // Button Quit
  SDL_Rect posTCR; posTCR.x = SCL * 2 ; posTCR.y  = SCL * (8 + (posTankCursor * 3));  // Tank Cursor RIGHT
  SDL_Rect posTCL; posTCL.x = SCL * 16; posTCL.y  = SCL * (8 + (posTankCursor * 3));  // Tank Cursor LEFT

  if (IMGM.load == 0) { load_imgMenu(); }

  SDL_BlitSurface(IMGMENU.backGround, NULL, screen, &posBG);
  SDL_BlitSurface(IMGMENU.play, NULL, screen, &posPlay);
  SDL_BlitSurface(IMGMENU.quit, NULL, screen, &posQuit);
  
  SDL_BlitSurface(IMGMENU.TKRight, NULL, screen, &posTCR);
  SDL_BlitSurface(IMGMENU.TKLeft, NULL, screen, &posTCL);
}

void print_difficultyMenu()
{   
  SDL_Rect posBG; posBG.x = 0; posBG.y = 0;                // BackGround
  SDL_Rect posEasy;   posEasy.x   = 0; posEasy.y    = SCL * 6;  // Button difficulty easy
  SDL_Rect posMedium; posMedium.x = 0; posMedium.y  = SCL * 9;  // Button difficulty medium
  SDL_Rect posHard;   posHard.x   = 0; posHard.y    = SCL * 12; // Button difficulty hard
  SDL_Rect posTCR; posTCR.x = SCL * 2 ; posTCR.y  = SCL * (6 + (posTankCursor * 3));  // Tank Cursor RIGHT
  SDL_Rect posTCL; posTCL.x = SCL * 16; posTCL.y  = SCL * (6 + (posTankCursor * 3));  // Tank Cursor LEFT

  if (IMGM.load == 0) { load_imgMenu(); }

  SDL_BlitSurface(IMGMENU.backGround, NULL, screen, &posBG);
  SDL_BlitSurface(IMGMENU.easy,   NULL, screen, &posEasy);
  SDL_BlitSurface(IMGMENU.medium, NULL, screen, &posMedium);
  SDL_BlitSurface(IMGMENU.hard,   NULL, screen, &posHard);
  
  SDL_BlitSurface(IMGMENU.TKRight, NULL, screen, &posTCR);
  SDL_BlitSurface(IMGMENU.TKLeft, NULL, screen, &posTCL);
}

void print_endMenu()
{   
  SDL_Rect posBG; posBG.x = 0; posBG.y = 0;                // BackGround

  SDL_Rect posQuit; posQuit.x = 0; posQuit.y  = SCL * 11;  // Button Quit
  SDL_Rect posWin;      posWin.x      = 0; posWin.y      = SCL * 2; // Win
  SDL_Rect posGameOver; posGameOver.x = 0; posGameOver.y = 0; // Game Over
  SDL_Rect posTCR; posTCR.x = SCL * 2 ; posTCR.y  = SCL * (11 + (posTankCursor * 3));  // Tank Cursor RIGHT
  SDL_Rect posTCL; posTCL.x = SCL * 16; posTCL.y  = SCL * (11 + (posTankCursor * 3));  // Tank Cursor LEFT

  if (IMGM.load == 0) { load_imgMenu(); }

  SDL_BlitSurface(IMGMENU.backGround, NULL, screen, &posBG);

  if (TK_user->alive == 0) {
    SDL_BlitSurface(IMGMENU.gameOver, NULL, screen, &posGameOver); } 
  else {
    SDL_BlitSurface(IMGMENU.win, NULL, screen, &posWin);}

  SDL_BlitSurface(IMGMENU.quit, NULL, screen, &posQuit);
  
  SDL_BlitSurface(IMGMENU.TKRight, NULL, screen, &posTCR);
  SDL_BlitSurface(IMGMENU.TKLeft, NULL, screen, &posTCL);
}