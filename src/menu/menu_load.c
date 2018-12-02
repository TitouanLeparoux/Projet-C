/*********************************************************/
// Load in RAM menu image

void load_imgMenu()
{
	IMGMENU.backGround 	= IMG_Load("img/menu/background.png");
  IMGMENU.play 				= IMG_Load("img/menu/button_play.png"); 
  IMGMENU.quit 				= IMG_Load("img/menu/button_quit.png");
  IMGMENU.easy 				= IMG_Load("img/menu/button_level_easy.png"); 
  IMGMENU.medium 			= IMG_Load("img/menu/button_level_medium.png");
  IMGMENU.hard 				= IMG_Load("img/menu/button_level_hard.png");
  IMGMENU.TKRight 		= IMG_Load("img/menu/tank_right.png");
  IMGMENU.TKLeft 			= IMG_Load("img/menu/tank_left.png");
  IMGMENU.win		 			= IMG_Load("img/menu/win.png");
	IMGMENU.gameOver		= IMG_Load("img/menu/game_over.png");

  IMGMENU.load = 1;
}

/*********************************************************/
// Free RAM

void deload_imgMenu()
{
	SDL_FreeSurface(IMGMENU.backGround);
  SDL_FreeSurface(IMGMENU.play);
  SDL_FreeSurface(IMGMENU.quit);
  SDL_FreeSurface(IMGMENU.easy);
  SDL_FreeSurface(IMGMENU.medium);
  SDL_FreeSurface(IMGMENU.hard);
	SDL_FreeSurface(IMGMENU.TKRight);
	SDL_FreeSurface(IMGMENU.TKLeft);  
	SDL_FreeSurface(IMGMENU.win);
	SDL_FreeSurface(IMGMENU.gameOver);
  
}