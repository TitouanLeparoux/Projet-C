/*********************************************************/
// Load texte map in RAM with a struct tab

void malloc_tabMap()
{
  MAP = malloc(H * sizeof(double*));
  for (unsigned int i = 0; i < L; i++) { 
    MAP[i] = malloc(L * sizeof(double)); }
}

void load_tabMap()
{
  FILE *mapFile = fopen("map/map2.txt", "r");

  int i = 0, j = 0;
  char car_act;
  if (mapFile != NULL) {
    do {
      car_act = fgetc(mapFile);
      if (car_act == '\n') { i=0; j++; }
      else {
        MAP[j][i].type = car_act;
        switch(car_act) {
          case 'w': MAP[j][i].life = 1; break;
          default : MAP[j][i].life = 0; break;
        }
        i++;
      }
    } while (car_act != EOF);
    fclose(mapFile);
  }
  mLoad = 1;
}

/*********************************************************/

/*
void malloc_listTank() {
  TANKS = malloc(NBR_TK_MAX * sizeof(double)); }
*/

void load_listTank() {
/*
  for (unsigned int i = 0; i < (NBR_TK_MAX) ; i++) {
    TANKS[i].alive = 0; 
  }
*/
  
  create_tank(SCL * 1,        SCL * 1,    'E',    2);
  create_tank(SCL * (L-2),    SCL * 1,    'E',    2);
  create_tank(SCL * 1    ,    SCL * 8,    'E',    2);

/*
  TANKS[0].type = 'E'; // tank ENEMY
  TANKS[0].posX = SCL * 1; 
  TANKS[0].posY = SCL * 1;
  TANKS[0].direction = 2;
  TANKS[0].alive = 1;

  TANKS[1].type = 'E'; // tank ENEMY
  TANKS[1].posX = SCL * (L-2); 
  TANKS[1].posY = SCL * 1;
  TANKS[1].direction = 2;
  TANKS[1].alive = 1;

  TANKS[2].type = 'E'; // tank ENEMY
  TANKS[2].posX = SCL * 1; 
  TANKS[2].posY = SCL * 8;
  TANKS[2].direction = 2;
  TANKS[2].alive = 1;

  TANKS[3].type = 'E'; // tank ENEMY
  TANKS[3].posX = SCL * (L-2); 
  TANKS[3].posY = SCL * 8;
  TANKS[3].direction = 2;
  TANKS[3].alive = 1;
*/

  tLoad = 1;
}

void create_tank(int posX, int posY, char type, int direction) {
  // Initialise les tanks
  tank* t = malloc(sizeof(tank));

  t->posX = posX;
  t->posY = posY;
  t->type = type;
  t->direction = direction;
  t->alive = 1;
  t->next_tank = NULL;
  
  ajouter_liste_tank(t);
}

void ajouter_liste_tank(tank *t) {
  t->next_tank = FIRST_TK;
  FIRST_TK = t;
}

/*********************************************************/

/*
void malloc_listRocket() {
  ROCKETS = malloc(NBR_RK_MAX * sizeof(double)); }
*/

void load_listRocket()
{
  for (unsigned int i = 0; i < NBR_RK_MAX; i++) {
    ROCKETS[i].alive = 0; }
  rLoad = 1;
}

void create_roquet(int posX, int posY, char type, int direction) {
  // Initialise les tanks
  rocket* r = malloc(sizeof(rocket));

  r->posX = posX;
  r->posY = posY;
  r->type = type;
  r->direction = direction;
  r->alive = 1;
  r->next_rocket = NULL;
  
  ajouter_liste_rocket(r);
}

void ajouter_liste_rocket(rocket *r) {
  r->next_rocket = FIRST_RK;
  FIRST_RK = r;
}

void supprimer_rocket(rocket *r) {
  rocket *save_pos = FIRST_RK; 
  rocket *tmp;

  if(FIRST_RK == r){ // Si c'est le premier élément de la liste
    tmp = FIRST_RK; // Stock le pointeur du premier élément actuem
    FIRST_RK = FIRST_RK->next_rocket; // redefinir le premier élément de la liste sur le deuxième
    free(tmp); // supprime le premier élément grace au stockage de son pointeur
  }
  else {
    while(save_pos->next_rocket != r && save_pos != NULL){ // Parcourir la liste pour s'arrêter au tank précédent
      save_pos = save_pos->next_rocket; 
    }
    if (save_pos != NULL) { 
      tmp = save_pos->next_rocket; // sauvergarde la position du tank d'après celui que l'on veut supprimer
      save_pos->next_rocket = tmp->next_rocket; // on definir le pointeur sur le tank d'après comme celui que l'on veut supprimer
      free(tmp); // On supprime le tank
    }
  }
}

/*********************************************************/
// Load in RAM texture and tank image 

void load_imgMap() 
{
  IMGM.durt = IMG_Load("img/deep_durt.png");
  IMGM.w1 = IMG_Load("img/wall.png");
  IMGM.w2 = IMG_Load("img/wall_used.png");
  
  IMGM.load = 1;
}

void load_imgTank() 
{
  IMGT.TU2 = IMG_Load("img/tank/tankB_down.png");
  IMGT.TU4 = IMG_Load("img/tank/tankB_left.png");
  IMGT.TU6 = IMG_Load("img/tank/tankB_right.png");
  IMGT.TU8 = IMG_Load("img/tank/tankB_up.png");

  IMGT.TE2 = IMG_Load("img/tank/tankG_down.png");
  IMGT.TE4 = IMG_Load("img/tank/tankG_left.png");
  IMGT.TE6 = IMG_Load("img/tank/tankG_right.png");
  IMGT.TE8 = IMG_Load("img/tank/tankG_up.png");

  IMGT.load = 1;
}

void load_imgRocket() 
{
  IMGR.R2 = IMG_Load("img/rocket/rocket_down.png");
  IMGR.R4 = IMG_Load("img/rocket/rocket_left.png");
  IMGR.R6 = IMG_Load("img/rocket/rocket_right.png");
  IMGR.R8 = IMG_Load("img/rocket/rocket_up.png");

  IMGR.load = 1;
}

/*********************************************************/
// Free RAM

void deload_imgMap()
{
  SDL_FreeSurface(IMGM.durt);
  SDL_FreeSurface(IMGM.w1);
  SDL_FreeSurface(IMGM.w2);
}

void deload_imgTank()
{
  // free surface iamge tank USER
  SDL_FreeSurface(IMGT.TU2);
  SDL_FreeSurface(IMGT.TU4);
  SDL_FreeSurface(IMGT.TU6);
  SDL_FreeSurface(IMGT.TU8);
  // free surface iamge tank ENEMY
  SDL_FreeSurface(IMGT.TE2);
  SDL_FreeSurface(IMGT.TE4);
  SDL_FreeSurface(IMGT.TE6);
  SDL_FreeSurface(IMGT.TE8);
}

void deload_imgRocket()
{
  SDL_FreeSurface(IMGR.R2);
  SDL_FreeSurface(IMGR.R4);
  SDL_FreeSurface(IMGR.R6);
  SDL_FreeSurface(IMGR.R8);
}