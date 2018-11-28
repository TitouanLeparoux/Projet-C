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

void malloc_listTank() {
  TANKS = malloc(NBR_TK_MAX * sizeof(double)); }

void load_listTank() {
  for (unsigned int i = 0; i < (NBR_TK_MAX) ; i++) {
    // TANKS[i].alive = 0; 
  }

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

/*
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


void malloc_listRocket() {
  ROCKETS = malloc(NBR_RK_MAX * sizeof(double)); }

void load_listRocket()
{
  for (unsigned int i = 0; i < NBR_RK_MAX; i++) {
    ROCKETS[i].alive = 0; }
  rLoad = 1;
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