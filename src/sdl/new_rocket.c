rocket* new_rocket(tank *tankShoot) {
	rocket *newRocket = malloc(sizeof(rocket));

	newRocket->posX = tankShoot->posX;
  newRocket->posY = tankShoot->posY;
  switch (tankShoot->direction) {
  	  case 2: newRocket->posY = tankShoot->posY+SCL; break;
      case 4: newRocket->posX = tankShoot->posX-SCL; break;
      case 6: newRocket->posX = tankShoot->posX+SCL; break;
      case 8: newRocket->posY = tankShoot->posY-SCL; break;
    }
  newRocket->direction = tankShoot->direction;
  newRocket->type = tankShoot->type;

  return newRocket;
}