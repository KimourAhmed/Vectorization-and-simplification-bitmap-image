
#ifndef _GEOM2D_H_
#define _GEOM2D_H_

typedef struct {
	double x, y;
} Vecteur;

typedef struct {
	double x, y;
} Point;

/* Cree le point de coordonn\E9es (x,y) */
Point set_point(double x, double y);

/* Somme de deux vecteur V1 et V2 */
Vecteur add_vect(Vecteur V1, Vecteur V2);

/**Difference entre deux points P1 et P2 */
Point sub_point(Point P1, Point P2);

/* Somme de deux points P1 et P2 */
Point add_point(Point P1, Point P2);

/* Vecteur correspondant au bipoint AB */
Vecteur vect_bipoint(Point A, Point B);

/* Multiplication d'un vecteur V avec un scalaire r */
Vecteur produit_reel_vect(Vecteur P, double a);

/* Multiplication d'un Point P avec un scalaire r */
Point produit_reel_point(Point P, double a);

/*Produit scalaire entre deux vecteurs*/
double produit_scalaire (Vecteur A, Vecteur B);

/* Norme d'un vecteur V */
double norme_vecteur(Vecteur V);

/* Distance entre deux point A et B */
double distance_point(Point A, Point B);

/* Distance entre un point P et un segment AB */
double distance_point_segment(Point P, Point A, Point B);

#endif
