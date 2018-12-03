// MENU_CONTROLE_KEY.C
void control_key_mainMenu();
void control_key_difficultyMenu();
void control_key_endMenu();

// MENU_PRINT_OBJ.C
void print_mainMenu();
void print_difficultyMenu();
void print_endMenu();

// MENU_LOAD.C
void load_imgMenu();
void deload_imgMenu();


/*************************************************/

// GAME.C
void load_game();
void game(/*int continuer*/);

// GAME_CONTROLE_KEY.C
void control_key(/*int continuer*/);

// GAME_PRINT_OBJ.C
void print_map();
void print_tanksList();
void print_tank(tank *tankMove);
void print_rocketsList();
void print_rocket(rocket *rocketMove);


// GAME_LOAD.C
void init_game();

void malloc_tabMap();
void load_tabMap();

void load_listTank();
void create_tank(int posX, int posY, char type, int direction);
void create_list_tank(tank *t);
void delete_tank(tank *t);
void free_tank_list();

void create_roquet(int posX, int posY, char type, int direction);
void create_list_rocket(rocket *r);
void delete_rocket(rocket *r);

void load_imgMap();
void load_imgTank();
void load_imgRocket();

void deload_imgMap();
void deload_imgTank();
void deload_imgRocket();