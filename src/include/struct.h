typedef struct {
	int 		load;
	SDL_Surface *backGround;
	SDL_Surface *play;
	SDL_Surface *quit;
	SDL_Surface *easy;
	SDL_Surface *medium;
	SDL_Surface *hard;
	SDL_Surface *TKRight;
	SDL_Surface *TKLeft;
	SDL_Surface *win;
	SDL_Surface *gameOver;
}imgMenu;

/*************************************************/

typedef struct _tank {
	int   direction;
	int   posX;
	int   posY;
	char  type; // (U)ser - (E)nemy
	int   alive;
	struct _tank *next_tank;
}tank;

typedef struct _rocket{
	int   direction;
	int   posX;
	int   posY;
	char  type; // (U)ser - (E)nemy
	int   alive;
	struct _rocket *next_rocket;
}rocket;

typedef struct {
	int   posX;
	int   posY;
	int   alive;
}titi;

typedef struct {
	char type;
	int	 life;
}blockMap;


typedef struct {
	int 		load;
	// TANK USER
	SDL_Surface *TU12;
	SDL_Surface *TU14;
	SDL_Surface *TU16;
	SDL_Surface *TU18;

	SDL_Surface *TU22;
	SDL_Surface *TU24;
	SDL_Surface *TU26;
	SDL_Surface *TU28;
	
	SDL_Surface *TU32;
	SDL_Surface *TU34;
	SDL_Surface *TU36;
	SDL_Surface *TU38;
	
	// TANK ENEMYe
	SDL_Surface *TE12;
	SDL_Surface *TE14;
	SDL_Surface *TE16;
	SDL_Surface *TE18;
	
	SDL_Surface *TE22;
	SDL_Surface *TE24;
	SDL_Surface *TE26;
	SDL_Surface *TE28;
	
	SDL_Surface *TE32;
	SDL_Surface *TE34;
	SDL_Surface *TE36;
	SDL_Surface *TE38;
}imgT;

typedef struct {
	int 		load;
	SDL_Surface *durt;
	SDL_Surface *w1;
	SDL_Surface *w2;
	SDL_Surface *titi;
}imgM;

typedef struct {
	int 		load;
	SDL_Surface *R2;
	SDL_Surface *R4;
	SDL_Surface *R6;
	SDL_Surface *R8;
}imgR;