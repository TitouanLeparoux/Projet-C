unsigned int SCL = 32;  // texture size in pixel
unsigned int L = 20;    // screen width in block of texture
unsigned int H = 15;    // screen height in block of texture

clock_t TIME_MEM[20];
int SPEED_TANK = 150000;
int PROBA_DIR_TANK = 3;

SDL_Surface *screen;

unsigned int CONTINUE;

unsigned int DIFFICULTY;
/*************************************************/

// Stuct image menu
imgMenu IMGMENU;
int posTankCursor;

/*************************************************/

// Struct image game
imgM IMGM;
imgT IMGT;
imgR IMGR;

// tab of struct block
int mLoad;
blockMap **MAP;

// make tank user
int tLoad;
tank *TK_user;
tank *FIRST_TK;

// make tank rocket
int rLoad;
rocket *FIRST_RK;