#include <stdio.h>
#include <stdlib.h>


double aireRectangle(double largeur, double hauteur);

int main(int agrc, char *argv[])
{
  int age = 10;

  printf("Variable age : %d \n", age);
  printf("L'adresse de la variable age : %p \n", &age);

  int *pointeur = NULL;
  int *pointeurSurAge = &age;

  printf("%d\n", pointeurSurAge);
  printf("%d", *pointeurSurAge);

    return 0;
}


double aireRectangle(double largeur, double hauteur)
{
    return largeur * hauteur;
}