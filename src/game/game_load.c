/*********************************************************/
// Load texte map in RAM with a struct tab

void malloc_tabMap()
{
  MAP = malloc(H * sizeof(blockMap));
  for (unsigned int i = 0; i < L; i++) { 
    MAP[i] = malloc(L * sizeof(blockMap)); }
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
          case 'w': MAP[j][i].life = 2; break;
          case 'b': MAP[j][i].life = 1; break;
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

void load_listTank() {

    // LEVEL EASY
    if (DIFFICULTY >= 1) {
      create_tank(SCL * 1    , SCL*1, 'E', 2); }
    
    // LEVEL MEDIUM
    if (DIFFICULTY >= 2) { 
      create_tank(SCL * (L-2), SCL*1, 'E', 2); }
    
    // LEVEL HARD
    if (DIFFICULTY >= 3) { 
      create_tank(SCL * 1    , SCL*8, 'E', 2); 
      create_tank(SCL * (L-2), SCL*8, 'E', 2); }

  tLoad = 1;
}

void create_tank(int posX, int posY, char type, int direction) {
  // Initialise les tanks
  tank* t = malloc(sizeof(tank));

  t->posX = posX;
  t->posY = posY;
  t->type = type;
  t->direction = direction;
  t->alive = 3;
  t->next_tank = NULL;
  
  create_list_tank(t);
}

void create_list_tank(tank *t) {
  t->next_tank = FIRST_TK;
  FIRST_TK = t;
}

void delete_tank(tank *t) {
  tank *save_pos = FIRST_TK; 
  tank *tmp;

  if(FIRST_TK == t){ 
    tmp = FIRST_TK; 
    FIRST_TK = FIRST_TK->next_tank; 
    free(tmp); 
  }
  else {
    while(save_pos->next_tank != t && save_pos != NULL){ 
      save_pos = save_pos->next_tank; 
    }
    if (save_pos != NULL) { 
      tmp = save_pos->next_tank; 
      save_pos->next_tank = tmp->next_tank; 
      free(tmp); 
    }
  }
}

void free_tank_list() {
  
  tank *save_pos = FIRST_TK;
  tank *tmp;

  while(save_pos != NULL) {
    
    tmp = save_pos->next_tank; 
    free(save_pos); 
    save_pos = tmp; 
  }
  FIRST_TK = NULL;
}

/*********************************************************/

void create_roquet(int posX, int posY, char type, int direction) {
  
  rocket* r = malloc(sizeof(rocket));

  r->posX = posX;
  r->posY = posY;
  r->type = type;
  r->direction = direction;
  r->alive = 1;
  r->next_rocket = NULL;
  
  create_list_rocket(r);
}

void create_list_rocket(rocket *r) {
  r->next_rocket = FIRST_RK;
  FIRST_RK = r;
}

void delete_rocket(rocket *r) {
  rocket *save_pos = FIRST_RK; 
  rocket *tmp;

  if(FIRST_RK == r){ 
    tmp = FIRST_RK; 
    FIRST_RK = FIRST_RK->next_rocket; 
    free(tmp); 
  }
  else {
    while(save_pos->next_rocket != r && save_pos != NULL){ 
      save_pos = save_pos->next_rocket; 
    }
    if (save_pos != NULL) { 
      tmp = save_pos->next_rocket; 
      save_pos->next_rocket = tmp->next_rocket; 
      free(tmp); 
    }
  }
}

/*********************************************************/
// Load in RAM texture and tank image 

void load_imgMap() 
{
  IMGM.durt = IMG_Load("img/wall/deep_durt.png");
  IMGM.w1 = IMG_Load("img/wall/wall.png");
  IMGM.w2 = IMG_Load("img/wall/wall_used.png");
  IMGM.titi = IMG_Load("img/titi/titi.png");
  
  IMGM.load = 1;
}

void load_imgTank() 
{
  IMGT.TU12 = IMG_Load("img/tank/tankB_1_down.png");
  IMGT.TU14 = IMG_Load("img/tank/tankB_1_left.png");
  IMGT.TU16 = IMG_Load("img/tank/tankB_1_right.png");
  IMGT.TU18 = IMG_Load("img/tank/tankB_1_up.png");
  
  IMGT.TU22 = IMG_Load("img/tank/tankB_2_down.png");
  IMGT.TU24 = IMG_Load("img/tank/tankB_2_left.png");
  IMGT.TU26 = IMG_Load("img/tank/tankB_2_right.png");
  IMGT.TU28 = IMG_Load("img/tank/tankB_2_up.png");
  
  IMGT.TU32 = IMG_Load("img/tank/tankB_3_down.png");
  IMGT.TU34 = IMG_Load("img/tank/tankB_3_left.png");
  IMGT.TU36 = IMG_Load("img/tank/tankB_3_right.png");
  IMGT.TU38 = IMG_Load("img/tank/tankB_3_up.png");

  
  IMGT.TE12 = IMG_Load("img/tank/tankG_1_down.png");
  IMGT.TE14 = IMG_Load("img/tank/tankG_1_left.png");
  IMGT.TE16 = IMG_Load("img/tank/tankG_1_right.png");
  IMGT.TE18 = IMG_Load("img/tank/tankG_1_up.png");
  
  IMGT.TE22 = IMG_Load("img/tank/tankG_2_down.png");
  IMGT.TE24 = IMG_Load("img/tank/tankG_2_left.png");
  IMGT.TE26 = IMG_Load("img/tank/tankG_2_right.png");
  IMGT.TE28 = IMG_Load("img/tank/tankG_2_up.png");
  
  IMGT.TE32 = IMG_Load("img/tank/tankG_3_down.png");
  IMGT.TE34 = IMG_Load("img/tank/tankG_3_left.png");
  IMGT.TE36 = IMG_Load("img/tank/tankG_3_right.png");
  IMGT.TE38 = IMG_Load("img/tank/tankG_3_up.png");

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
  SDL_FreeSurface(IMGM.titi);
}

void deload_imgTank()
{
  // free surface image tank USER
  SDL_FreeSurface(IMGT.TU12);
  SDL_FreeSurface(IMGT.TU14);
  SDL_FreeSurface(IMGT.TU16);
  SDL_FreeSurface(IMGT.TU18);
  SDL_FreeSurface(IMGT.TU22);
  SDL_FreeSurface(IMGT.TU24);
  SDL_FreeSurface(IMGT.TU26);
  SDL_FreeSurface(IMGT.TU28);
  SDL_FreeSurface(IMGT.TU32);
  SDL_FreeSurface(IMGT.TU34);
  SDL_FreeSurface(IMGT.TU36);
  SDL_FreeSurface(IMGT.TU38);
  // free surface image tank ENEMY
  SDL_FreeSurface(IMGT.TE12);
  SDL_FreeSurface(IMGT.TE14);
  SDL_FreeSurface(IMGT.TE16);
  SDL_FreeSurface(IMGT.TE18);
  SDL_FreeSurface(IMGT.TE22);
  SDL_FreeSurface(IMGT.TE24);
  SDL_FreeSurface(IMGT.TE26);
  SDL_FreeSurface(IMGT.TE28);
  SDL_FreeSurface(IMGT.TE32);
  SDL_FreeSurface(IMGT.TE34);
  SDL_FreeSurface(IMGT.TE36);
  SDL_FreeSurface(IMGT.TE38);
}

void deload_imgRocket()
{
  SDL_FreeSurface(IMGR.R2);
  SDL_FreeSurface(IMGR.R4);
  SDL_FreeSurface(IMGR.R6);
  SDL_FreeSurface(IMGR.R8);
}