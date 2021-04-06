#include "geom2d.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  if(argc!=1) {
    printf("Faux nombre d'arguments\n");
    return 0;  
  }
  
  Point P,A,B;
  double x=0;
  double y=0;
  
  
  printf("Entrez P.x \n"); 
  scanf("%lf",&x);
  printf("Entrez P.y \n"); 
  scanf("%lf",&y);
  P = set_point(x,y);
  printf("P: %lf, %lf;\n", P.x, P.y);
  
  
  
  
  printf("Entrez A.x \n"); 
  scanf("%lf",&x);
  printf("Entrez A.y \n"); 
  scanf("%lf",&y);
  A = set_point(x,y);
  printf("A: %lf, %lf;\n", A.x, A.y);
  
  
  
  printf("Entrez B.x \n"); 
  scanf("%lf",&x);
  printf("Entrez B.y \n"); 
  scanf("%lf",&y);
  B = set_point(x,y);
  printf("B: %lf, %lf;\n", B.x, B.y);

  

  double dist= distance_point_segment(P, A, B);
  printf("distance entre le point P et le segment AB: %lf .\n", dist);
  
  printf("attendu: %lf .\n", distance_point(A, P));
  }
