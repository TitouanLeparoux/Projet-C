unsigned int SCL = 32;  // texture size in pixel
unsigned int L = 20;    // screen width in block of texture
unsigned int H = 15;    // screen height in block of texture

unsigned int NBR_TK_MAX = 5; // maximum number of simultaneous tank
unsigned int NBR_RK_MAX = 20; // maximum number of simultaneous rocket

SDL_Surface *screen;

// Struct image
imgM IMGM;
imgT IMGT;
imgR IMGR;

// tab of struct block
int mLoad;
blockMap **MAP;

// make tank user
tank TK_user;
int tLoad;
tank *TANKS;

clock_t TIME_MEM[5];
int SPEED_TANK = 150050;
int PROBA_DIR_TANK = 2;

// make tank rocket
int rLoad;
rocket *ROCKETS; 