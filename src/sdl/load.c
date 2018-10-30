/*********************************************************/
// Load texte map in RAM with a tab

void load_tabMap()
{
  tabMap_type = malloc(H * L * sizeof(char));
  tabMap_life = malloc(H * L * sizeof(char));

  FILE *map = fopen("../map/map2.txt", "r");

  for (int j = 0; j < H+1; j++) { 
    for (int i = 0; i < L+1; i++) {
      switch (getc(map)) {
        case 'w':
          tabMap_type [j*L+i] = 'w';
          tabMap_life [j*L+i] = 1;
          break; 
        default: /* NONE */ ; break; 
      }
    }
  }
  fclose(map);
  mLoad = 1;
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
  IMGT.TU4 = IMG_Load("img/tank/tankB_right.png");
  IMGT.TU6 = IMG_Load("img/tank/tankB_left.png");
  IMGT.TU8 = IMG_Load("img/tank/tankB_up.png");

  IMGT.TE2 = IMG_Load("img/tank/tankG_down.png");
  IMGT.TE4 = IMG_Load("img/tank/tankG_right.png");
  IMGT.TE6 = IMG_Load("img/tank/tankG_left.png");
  IMGT.TE8 = IMG_Load("img/tank/tankG_up.png");

  IMGT.load = 1;
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