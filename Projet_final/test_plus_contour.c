#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "types_macros.h"
#include"geom2d.h"
#include"calcul_contour.h"
#include"simplification_contours.h"
#include"image.h"
#include"plus_contours.h"
#include"converttoeps.h"


int main(int argc, char ** argv) {
  if (argc != 3){
     printf(" nombre d'arguments insuffisants\n");}
  else { 
  FILE*f;
  f=fopen(argv[2],"w"); 
  Liste_tout_les_segments L;
  Image M;
  Image P;
  M=lire_fichier_image(argv[1]);
  P= creer_image_masque(M);
  P= parcours(M);
  Robot r;
  init_robot(&r, 0, 0, Est);
  L=calcul_plusieurs_contours(M, P, r, 1) ;
  format_eps( L, f, M);
  fclose(f);
  printf("fini");
   
  
  }
  
  }
