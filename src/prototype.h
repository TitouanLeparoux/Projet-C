// MENU.C
/*
void load_menu();
void menu();
*/

// MENU_CONTROLE_KEY.C
void control_key_mainMenu();
void control_key_difficultyMenu();

// MENU_PRINT_OBJ.C
void print_mainMenu();
void print_difficultyMenu();

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
void malloc_tabMap();
void load_tabMap();

void load_listTank();
void create_tank(int posX, int posY, char type, int direction);
void ajouter_liste_tank(tank *t);
void free_tank_list();

void create_roquet(int posX, int posY, char type, int direction);
void ajouter_liste_rocket(rocket *r);
void supprimer_rocket(rocket *r);

void load_imgMap();
void load_imgTank();
void load_imgRocket();

void deload_imgMap();
void deload_imgTank();
void deload_imgRocket();