// GAME.C
int load_game();
int game(int continuer);

// CONTROLE_KEY.C
int control_key(int continuer);

// PRINT_OBJ.C
void print_map();
void print_tanksList();
void print_tank(tank *tankMove);
void print_rocketsList();
void print_rocket(rocket *rocketMove);


// LOAD.C
void malloc_tabMap();
void load_tabMap();

// void malloc_listTank();
void load_listTank();
void create_tank(int posX, int posY, char type, int direction);
void ajouter_liste_tank(tank *t);

// void malloc_listRocket();
void load_listRocket();
void create_roquet(int posX, int posY, char type, int direction);
void ajouter_liste_rocket(rocket *r);
void supprimer_rocket(rocket *r);

void load_imgMap();
void load_imgTank();
void load_imgRocket();

void deload_imgMap();
void deload_imgTank();
void deload_imgRocket();