/*********************************************************/
// Load texte map in RAM with a struct tab

void malloc_tabMap()
{
  MAP = malloc(H * sizeof(double*));
  for (int i = 0; i < L; i++) { 
    MAP[i] = malloc(L * sizeof(double)); }
}

void load_tabMap()
{
  FILE *mapFile = fopen("../map/map2.txt", "r");

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

void malloc_listRocket()
{
  ROCKETS = malloc(NBR_RK_MAX * sizeof(double));
}


/*
rocket* malloc_rocket(rocket *newRocket)
{
  newRocket = malloc(H * sizeof(rocket));
  return newRocket;
}
*/

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