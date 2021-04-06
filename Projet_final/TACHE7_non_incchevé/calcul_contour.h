/****************************************************************************** 
  Interface du module calcul_cotour
******************************************************************************/
#ifndef _CALCUL_CONTOUR_H_
#define _CALCUL_CONTOUR_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"types_macros.h"
#include"calcul_contour.h"
#include"image.h"
#include"geom2d.h"

typedef enum {Nord,Est,Sud,Ouest} Orientation;
typedef struct {
  UINT x, y;
  Orientation o;
} Robot;
/*--------le type Point et la fonction set_point -----*/

typedef struct Cellule_Liste_Point_{
  Point data;
  struct Cellule_Liste_Point_* suiv;
} Cellule_Liste_Point ;

typedef struct Liste_Point_{
  unsigned int taille;
  Cellule_Liste_Point *first;
  Cellule_Liste_Point *last;
}Liste_Point;

typedef Liste_Point Contour;


typedef struct Tableau_Point_{ 
  unsigned int taille;
  Point *tab;
}Tableau_Point;

Pixel pixel_gauche(Image I,Robot *r);
Pixel pixel_droit(Image I,Robot *r);
void trouver_pixel_depart(Image I,UINT *x,UINT *y);
void memoriser_position(Robot r);
void avancer(Robot *r);
void tourner_a_gauche(Robot *r);
void tourner_a_droite(Robot *r);
void nouvelle_orientation(Image I, Robot *r);
void calcul_contour_B1(Image I, Robot r);

//Initialiser la position du robot
void init_robot(Robot * r, int x, int y, Orientation o);

Point set_point(double x, double y);
Cellule_Liste_Point *creer_element_liste_Point(Point v);
Liste_Point creer_liste_Point_vide();
Liste_Point ajouter_element_liste_Point(Liste_Point L, Point e);
Liste_Point ajouter_element_liste_Point(Liste_Point L, Point e);
Liste_Point supprimer_liste_Point(Liste_Point L);
Liste_Point concatener_liste_Point(Liste_Point L1, Liste_Point L2);
Tableau_Point sequence_points_liste_vers_tableau(Liste_Point L);
void ecrire_contour(Liste_Point L);
Contour calcul_contour_B2(Image I, Robot r);
void ecrire_contour_fich(Liste_Point L, FILE*f);

#endif /* _CALCUL_CONTOUR_H_ */
