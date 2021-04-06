/****************************************************************************** 
  Interface du module procedure_ecrire_contour
******************************************************************************/
#ifndef _SIMPLIFICATION_CONTOURS_H_
#define _SIMPLIFICATION_CONTOURS_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "types_macros.h"
#include"geom2d.h"
#include"calcul_contour.h"

typedef struct {
	Point A, B;
} Segment;

typedef struct Tableau_Segments_{ 
  unsigned int taille;
  Segment *tab;
}Tableau_Segments;


typedef struct Cellule_Liste_segments_{
  Segment data;
  struct Cellule_Liste_segments_* suiv;
} Cellule_Liste_segments ;

typedef struct Liste_segments_{
  unsigned int taille;
  Cellule_Liste_segments *first;
  Cellule_Liste_segments *last;
}Liste_segments;

//_____________________________________________________________

typedef struct Cellule_Liste_tout_les_segments_{
  Tableau_Segments data;
  struct Cellule_Liste_tout_les_segments_* suiv;
} Cellule_Liste_tout_les_segments ;

typedef struct Liste_tout_les_segments_{
  unsigned int taille;
  Cellule_Liste_tout_les_segments *first;
  Cellule_Liste_tout_les_segments *last;
}Liste_tout_les_segments;



Cellule_Liste_segments *creer_element_liste_segments(Segment v);
Liste_segments creer_liste_segments_vide();
Liste_segments ajouter_element_liste_segments(Liste_segments L, Segment v);
Liste_segments concatener_liste_segments(Liste_segments L1, Liste_segments L2);
Tableau_Segments sequence_segments_liste_vers_tableau(Liste_segments L);

Liste_segments simplification_douglas_peucker(Tableau_Point C, UINT j1, UINT j2,double d);

Liste_tout_les_segments creer_liste_tout_les_segments_vide();
Cellule_Liste_tout_les_segments *creer_element_liste_tout_les_segments(Tableau_Segments v);
Liste_tout_les_segments ajouter_element_liste_tout_les_segmments (Liste_tout_les_segments L, Tableau_Segments e);

#endif /* _SIMPLIFICATION_CONTOURS_H_ */
