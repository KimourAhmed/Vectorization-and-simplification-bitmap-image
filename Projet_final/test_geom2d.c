#include "geom2d.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  if(argc!=1) {
    printf("Faux nombre d'arguments\n");
    return 0;  
  }


//test de la fonction set_point 
  Point P = set_point(5.0,6.0);
  printf("P: %0.1f, %0.1f;\n", P.x, P.y);

//test de la fonction add_vect
      
  Vecteur Vecteur1 = {1.0, 2.0};
  Vecteur Vecteur2 = {3.0, 4.0};
  printf("Vecteur1: %0.1f, %0.1f.\nVecteur2: %0.1f, %0.1f.\n", Vecteur1.x, Vecteur1.y, Vecteur2.x, Vecteur2.y);
  
  Vecteur Vecteur3 = add_vect(Vecteur1,Vecteur2); 
  printf("Addition de vecteur1 et 2 donne: %0.1f, %0.1f;\n", Vecteur3.x, Vecteur3.y);
 
  
//test de la fonction add_point
    
  Point Point1 = {5.0,6.0};
  Point Point2 = {7.0,8.0};
  printf("Point1: %0.1f, %0.1f.\nPoint2: %0.1f, %0.1f.\n", Point1.x, Point1.y, Point2.x, Point2.y);

  Point Point3 = add_point(Point1,Point2);
  printf("Addition de point1 et 2 donne: %0.1f, %0.1f;\n", Point3.x, Point3.y);

//test de la fonction vect_bipoint
  Vecteur Vecteur4 = vect_bipoint(Point1, Point2); 
  printf("Vecteur entre point 1 et 2: %0.1f, %0.1f;\n", Vecteur4.x, Vecteur4.y);
  

//test de la fonction produit_scalaire_vect
  Vecteur Vecteur5 = produit_scalaire_vect(Vecteur1, 2);
  printf("Vecteur5: %0.1f, %0.1f;\n", Vecteur5.x, Vecteur5.y);

//test de la fonction norme_vecteur
  double norme = norme_vecteur(Vecteur1);
  printf("norme Vecteur1: %0.1f\n", norme);

//test de la fonction distance_point 
  double distance  = distance_point(Point1, Point2);
  printf("distance entre point1 et 2: %0.1f\n", distance);


  return 0;
}

