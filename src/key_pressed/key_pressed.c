#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

char key_pressed()
{
  struct termios oldterm, newterm;
  int oldfd; char c, result = 0;
  tcgetattr (STDIN_FILENO, &oldterm);
  newterm = oldterm; newterm.c_lflag &= ~(ICANON | ECHO);
  tcsetattr (STDIN_FILENO, TCSANOW, &newterm);
  oldfd = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl (STDIN_FILENO, F_SETFL, oldfd | O_NONBLOCK);
  c = getchar();
  tcsetattr (STDIN_FILENO, TCSANOW, &oldterm);
  fcntl (STDIN_FILENO, F_SETFL, oldfd);
  if (c != EOF) 
  {
    ungetc(c, stdin);
    result = getchar();
  }
  return result;
}

int main ()
{
  char c;
  while ((c=key_pressed()) != 'q')
  { 
    switch(c) {
        case 'A':
          printf("Avancer\n");
          break; 
        case 'B':
          printf("Reculer\n");
          break;
        case 'C':
          printf("Droite\n");
          break; 
        case 'D':
          printf("Gauche\n");
          break;
        case 32:
          printf("Fire\n");
          break;
    }
  }
  return 0;
}
