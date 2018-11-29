// MENU.C
int load_menu();
int menu(int continuer);

// MENU_CONTROLE_KEY.C
int control_key_menu(int continuer);

// MENU_PRINT_OBJ.C
void print_menu();

// MENU_LOAD.C
void load_imgMenu();
void deload_imgMenu();


/*************************************************/

// GAME.C
int load_game();
int game(int continuer);

// GAME_CONTROLE_KEY.C
int control_key(int continuer);

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

void create_roquet(int posX, int posY, char type, int direction);
void ajouter_liste_rocket(rocket *r);
void supprimer_rocket(rocket *r);

void load_imgMap();
void load_imgTank();
void load_imgRocket();

void deload_imgMap();
void deload_imgTank();
void deload_imgRocket();