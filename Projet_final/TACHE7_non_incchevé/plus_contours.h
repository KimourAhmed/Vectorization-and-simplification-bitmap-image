#ifndef _PLUS_CONTOURS_H
#define _PLUS_CONTOURS_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"types_macros.h"
#include"calcul_contour.h"
#include"image.h"
#include"geom2d.h"
#include"simplification_contours.h"
#include"structure_Beziers.h"

typedef struct Cellule_Liste_Contour_{
  Tableau_Point data;
  struct Cellule_Liste_Contour_* suiv;
} Cellule_Liste_Contour ;

typedef struct Liste_Contours_{
  unsigned int taille;
  Cellule_Liste_Contour *first;
  Cellule_Liste_Contour *last;
}Liste_Contours;

typedef Liste_Contours Plus_contours;

Liste_Contours creer_liste_Contours_vide();
Cellule_Liste_Contour *creer_element_liste_Contour(Tableau_Point v);
Liste_Contours ajouter_element_liste_Contours(Liste_Contours L, Tableau_Point e);

Image creer_image_masque(Image M);
Image parcours(Image M);
int trouver_pixel_noir(Image I,UINT *x,UINT *y);
Contour calcul_seul_contour(Image I,Image P, Robot r,UINT *x,UINT *y, int *nombre_de_segments);
Liste_tout_les_Beziers2  calcul_plusieurs_contours(Image I, Image P, Robot r, double d);


#endif /* _PLUS_CONTOURS_H */
