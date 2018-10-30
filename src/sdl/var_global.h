unsigned int SCL = 32;  // texture size in pixel
unsigned int L = 20;    // screen width in block of texture
unsigned int H = 15;    // screen height in block of texture

SDL_Surface *screen;

// Struct image
imgM IMGM;
imgT IMGT;

// tab of struct block
char *tabMap_type;
char *tabMap_life;
int mLoad;

// make tank user
tank *TK_user;