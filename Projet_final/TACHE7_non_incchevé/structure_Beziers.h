/****************************************************************************** 
  Interface du module structure_Beziers
******************************************************************************/
#ifndef _STRUCTURE_BEZIERS_H_
#define _STRUCTURE_BEZIERS_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "types_macros.h"
#include"geom2d.h"
#include"calcul_contour.h"

typedef enum {
  OK,
  ERREUR_FICHIER,
  ERREUR_VALEUR_DE_t
} erreur_Beziers;

typedef struct {
	Point C0, C1, C2;
} Beziers2;

typedef struct {
	Point C0, C1, C2, C3 ;
} Beziers3;

typedef struct Tableau_Beziers2_{ 
  unsigned int taille;
  Beziers2 *tab;
}Tableau_Beziers2;


typedef struct Cellule_Liste_Beziers2_{
  Beziers2 data;
  struct Cellule_Liste_Beziers2_* suiv;
} Cellule_Liste_Beziers2 ;

typedef struct Liste_Beziers2_{
  unsigned int taille;
  Cellule_Liste_Beziers2 *first;
  Cellule_Liste_Beziers2 *last;
}Liste_Beziers2;

//_______________________________________________________________________________

typedef struct Cellule_Liste_tout_les_Beziers2_{
  Tableau_Beziers2 data;
  struct Cellule_Liste_tout_les_Beziers2_* suiv;
} Cellule_Liste_tout_les_Beziers2;

typedef struct Liste_tout_les_Beziers2_{
  unsigned int taille;
  Cellule_Liste_tout_les_Beziers2 *first;
  Cellule_Liste_tout_les_Beziers2 *last;
}Liste_tout_les_Beziers2;

//______________________________________________________________________________

Liste_Beziers2 creer_liste_Beziers2_vide();
Cellule_Liste_Beziers2 *creer_element_liste_Beziers2( Beziers2 B);
Liste_Beziers2 ajouter_element_liste_Beziers2 (Liste_Beziers2 L, Beziers2 v);
Tableau_Beziers2 sequence_Beziers2_liste_vers_tableau(Liste_Beziers2 L);
Liste_Beziers2 concatener_liste_Beziers2(Liste_Beziers2 L1, Liste_Beziers2 L2);

//______________________________________________________________________________

Liste_tout_les_Beziers2 creer_liste_tout_les_Beziers2_vide();
Cellule_Liste_tout_les_Beziers2 *creer_element_liste_tout_les_Beziers2(Tableau_Beziers2 v);
Liste_tout_les_Beziers2 ajouter_element_liste_tout_les_Beziers2 (Liste_tout_les_Beziers2 L, Tableau_Beziers2 e);


//_______________________________________________________________________________

Point calcul_point_beziers2(Beziers2 C, double t);
Beziers2 approx_beziers2(Tableau_Point Cont, int j1, int j2);
double distance_point_beziers2(Point Pi, Beziers2 B, double ti);
#endif /*_STRUCTURE_BEZIERS_H_*/ 




