unsigned int SCL = 32;  // texture size in pixel
unsigned int L = 20;  // screen width in block of texture
unsigned int H = 15;  // screen height in block of texture

SDL_Surface *screen;

// Struct image
imgM IMGM;
imgT IMGT;
imgR IMGR;

// tab of struct block
char *tabMap_type;
char *tabMap_life;
int mLoad;

// MODIF EL 
int ind;
blockMap **Map;
// FIN MODIF EL

// make tank user
tank *TK_user;

rocket *rocketN01;
