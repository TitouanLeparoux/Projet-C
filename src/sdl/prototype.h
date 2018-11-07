// GAME.C
int load_game();
int lunch_game(int continuer);

// CONTROLE_KEY.C
int control_key(int continuer);

// PRINT_OBJ.C
void print_map();
void print_tank(tank *tankMove);
void print_rocket(rocket *rocketMove);

// LOAD.C
void malloc_tabMap();
void load_tabMap();
void load_imgMap();
void load_imgTank();
void load_imgRocket();
void deload_imgMap();
void deload_imgTank();
void deload_imgRocket();

// NEW_ROCKET.C
rocket* new_rocket(tank *tankShoot);