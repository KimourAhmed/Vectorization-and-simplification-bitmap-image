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
#include"structure_Beziers.h"


int main(int argc, char ** argv) {
  if (argc != 3){
     printf(" nombre d'arguments insuffisants\n");}
  else { 
  FILE*f;
  f=fopen(argv[2],"w"); 
  Liste_tout_les_Beziers2 L;
  Image M;
  Image P;
  M=lire_fichier_image(argv[1]);
  P= creer_image_masque(M);
  P= parcours(M);
  Robot r;
  init_robot(&r, 0, 0, Est);
  L=calcul_plusieurs_contours(M, P, r, 3) ;
  format_eps( L, f, M);
  fclose(f);
  printf("fin\n");
  
  //Pour tester distance et approx
  Liste_Point test=creer_liste_Point_vide();
  test=ajouter_element_liste_Point(test, set_point(0,0));
  test=ajouter_element_liste_Point(test, set_point(1,0));
  test=ajouter_element_liste_Point(test, set_point(1,1));
  test=ajouter_element_liste_Point(test, set_point(1,2));
  test=ajouter_element_liste_Point(test, set_point(2,2));
  test=ajouter_element_liste_Point(test, set_point(3,2));
  test=ajouter_element_liste_Point(test, set_point(3,3));
  test=ajouter_element_liste_Point(test, set_point(4,3));
  test=ajouter_element_liste_Point(test, set_point(5,3));
  Tableau_Point test_tab= sequence_points_liste_vers_tableau(test);
  
  Beziers2 test_bez = approx_beziers2(test_tab, 0, test_tab.taille-1);
  printf("C0:(%lf,%lf)\n",test_bez.C0.x,test_bez.C0.y);
  printf("C1:(%lf,%lf)\n",test_bez.C1.x,test_bez.C1.y);
  printf("C2:(%lf,%lf)\n",test_bez.C2.x,test_bez.C2.y);
  for (int i=0; i<=test_tab.taille; i++){
      printf("dist= %lf \n", distance_point_beziers2(test_tab.tab[i], test_bez, i/test_tab.taille));
      
      }
      
      
  }
  
  }
