/*********************************************************/
// Load in RAM menu image

void load_imgMenu()
{
	IMGMENU.backGround = IMG_Load("img/menu/background.png");
  IMGMENU.play = IMG_Load("img/menu/button_play.png"); 
  IMGMENU.quit = IMG_Load("img/menu/button_quit.png");
  IMGMENU.easy = IMG_Load("img/menu/button_level_easy.png"); 
  IMGMENU.medium = IMG_Load("img/menu/button_level_medium.png");
  IMGMENU.hard = IMG_Load("img/menu/button_level_hard.png"); 
  
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
}