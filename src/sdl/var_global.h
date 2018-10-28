unsigned int SCL = 32;  // texture size in pixel
unsigned int L = 20;    // screen width in block of texture
unsigned int H = 15;    // screen height in block of texture
SDL_Surface *screen;

typedef struct {
	int   direction;
	int   posX;
	int   posY;
	int   blindage;
	int   blindage_origin;
	int   touches;
	char  type;
	int   etat;
	int   destruction;
}tank;

typedef struct {
	char type;
	char life;
}blockMap;

typedef struct {
	int 		load;
	SDL_Surface *durt;
	SDL_Surface *w1;
	SDL_Surface *w2;
}img;

// Struct image map
img IMG;