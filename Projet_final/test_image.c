#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"types_macros.h"
#include"image.h"

int main(int argc,char **argv){
  if (argc != 2){
     printf(" nombre d'arguments insuffisants");}
  Image I;
  I=lire_fichier_image(argv[1]);
  ecrire_image(I);
}
