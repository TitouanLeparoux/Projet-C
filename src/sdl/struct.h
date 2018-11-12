typedef struct {
	int   direction;
	int   posX;
	int   posY;
	int   life;
	int   life_origin;
	int   touches;
	char  type; // (U)ser - (E)nemy
	int   etat;
	int   destruction;
}tank;

typedef struct {
	int   direction;
	int   posX;
	int   posY;
	char  type; // (U)ser - (E)nemy
	int   destruction;
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