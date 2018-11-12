unsigned int SCL = 32;  // texture size in pixel
unsigned int L = 20;  // screen width in block of texture
unsigned int H = 15;  // screen height in block of texture

SDL_Surface *screen;

// Struct image
imgM IMGM;
imgT IMGT;
imgR IMGR;

// tab of struct block
// char *tabMap_type;
// char *tabMap_life;
blockMap **MAP;
int mLoad;

// make tank user
tank *TK_user;

// make tank rocket
rocket *rocketN01;
rocket *rocketN02;

rocket *ROCKETS;
int NBR_RK;
int NBR_RK_MAX = 100;