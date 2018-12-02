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
	char type;
	int	 life;
}blockMap;


typedef struct {
	int 		load;
	// TANK USER
	SDL_Surface *TU2;
	SDL_Surface *TU4;
	SDL_Surface *TU6;
	SDL_Surface *TU8;
	// TANK ENEMY
	SDL_Surface *TE2;
	SDL_Surface *TE4;
	SDL_Surface *TE6;
	SDL_Surface *TE8;
}imgT;

typedef struct {
	int 		load;
	SDL_Surface *durt;
	SDL_Surface *w1;
	SDL_Surface *w2;
}imgM;

typedef struct {
	int 		load;
	SDL_Surface *R2;
	SDL_Surface *R4;
	SDL_Surface *R6;
	SDL_Surface *R8;
}imgR;