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
}rocket;

typedef struct {
	char type;
	int	 life;
}blockMap;

typedef struct {
	int 		load;
	SDL_Surface *durt;
	SDL_Surface *w1;
	SDL_Surface *w2;
}img;