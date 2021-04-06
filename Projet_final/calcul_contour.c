
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"types_macros.h"
#include"calcul_contour.h"
#include"image.h"
#include"geom2d.h"

void trouver_pixel_depart(Image I,UINT *x,UINT *y){
       UINT i=1;
       UINT j=1;
       bool tout_blanc= true; 
       Pixel pix, pix_haut;
       do{
         pix=get_pixel_image(I,i,j);
         pix_haut=get_pixel_image(I,i,j-1);
         if (pix==NOIR && pix_haut==BLANC){
             *x=i;
             *y=j;
             tout_blanc=false;
             break;}
         i++;
         if (i>I.L){
            i=1;
	    j++;
            if (j>I.H){
            	break; }
 	    }
         

       }while(pix==BLANC || pix_haut==NOIR);
       if (tout_blanc){ ERREUR_FATALE("Image toute Blanche pas de contours\n");}
       }
    	    
Pixel pixel_gauche(Image I,Robot *r){ 
	Pixel res;
	switch (r->o){
	  case Nord: res=get_pixel_image(I,r->x,r->y);break;
  	  case Est: res=get_pixel_image(I,r->x+1,r->y);break;	  
  	  case Sud: res=get_pixel_image(I,r->x+1,r->y+1);break;
	  case Ouest: res=get_pixel_image(I,r->x,r->y+1);break;	  
	  default:exit(1);break;}
        return res; }

Pixel pixel_droit(Image I,Robot *r){ 
	Pixel res;
	switch (r->o){
	  case Nord: res=get_pixel_image(I,r->x+1,r->y);break;
  	  case Est: res=get_pixel_image(I,r->x+1,r->y+1);break;
	  case Sud: res=get_pixel_image(I,r->x,r->y+1);break;
  	  case Ouest: res=get_pixel_image(I,r->x,r->y);break;
	  default:exit(1);break;}
        return res;}

void memoriser_position(Robot r) {
     printf("abscisse: %d ordonnées:%d \n", r.x, r.y);}

void init_robot(Robot * r, int x, int y, Orientation o) {
  r->x = x;
  r->y = y;
  r->o = o;
}

void avancer(Robot *r){
     switch (r->o){
          case Nord: r->y=r->y-1;break;
  	  case Est: r->x=r->x+1 ;break;
	  case Sud: r->y=r->y+1;break;
  	  case Ouest: r->x=r->x-1; break;}
}
void nouvelle_orientation(Image I, Robot *r){
    Pixel pG, pD;
    pG= pixel_gauche(I, r);
    pD= pixel_droit(I, r);
    if (pG==NOIR) { tourner_a_gauche(r);}  
    else if(pD==BLANC){tourner_a_droite(r);}   
}


void tourner_a_gauche(Robot *r){
     switch (r->o){
          case Nord: r->o=Ouest;break;
  	  case Est: r->o=Nord; break;
	  case Sud: r->o=Est;break;
  	  case Ouest: r->o=Sud ;break;} 
         }     
void tourner_a_droite(Robot *r) {    
    switch (r->o){
          case Nord: r->o=Est;break;
  	  case Est: r->o=Sud ;break;
	  case Sud: r->o=Ouest;break;
  	  case Ouest: r->o=Nord ;break;} 
         } 

//_______________PARTIE2__________________________    

Cellule_Liste_Point *creer_element_liste_Point(Point v){
   Cellule_Liste_Point *el;
   el = (Cellule_Liste_Point *)malloc(sizeof(Cellule_Liste_Point));
   if (el==NULL)
   {
      fprintf(stderr, "creer_element_liste_Point : allocation impossible \n");
      exit(-1);
   }
   el->data = v;
   el->suiv = NULL;
   return el;
}

Liste_Point creer_liste_Point_vide(){
   Liste_Point L = {0, NULL, NULL};
   return L;
}

Liste_Point ajouter_element_liste_Point(Liste_Point L, Point e){
   Cellule_Liste_Point *el;
   
   el = creer_element_liste_Point(e);
   if (L.taille == 0){
    
       L.first = L.last = el;}
   else {
       L.last->suiv = el;
       L.last = el;}
   L.taille++;
   return L; }

Liste_Point supprimer_liste_Point(Liste_Point L){
    Cellule_Liste_Point *el=L.first;

    while (el){
       Cellule_Liste_Point *suiv=el->suiv;
       free(el);
       el = suiv;}
   L.first = L.last = NULL; L.taille = 0;
   return L;}

Liste_Point concatener_liste_Point(Liste_Point L1, Liste_Point L2){
   if(L1.taille ==0) return L2;
   if(L2.taille ==0) return L1;

   L1.last ->suiv= L2.first;
   L1.last = L2.last;
   L1.taille += L2.taille;
   return L1;
}

Tableau_Point sequence_points_liste_vers_tableau(Liste_Point L){
  Tableau_Point T;
  T.taille = L.taille;
  T.tab= malloc(sizeof(Point) *T.taille);
  if (T.tab == NULL){
     fprintf(stderr, "sequence_points_liste_vers_tableau : ");
     fprintf(stderr, "allocation impossible : ");             
     exit(-1);}
  
  int k = 0;
  Cellule_Liste_Point *el = L.first;
  while(el){
    T.tab[k]=el->data;
    k++;
    el= el->suiv;}
  return T;}

void ecrire_contour(Liste_Point L){
  Tableau_Point TP = sequence_points_liste_vers_tableau(L);
  int k;
  int nP = TP.taille; 

  printf("%d points : [", nP);
  for (k=0; k< nP; k++){
     Point P= TP.tab[k];
     printf(" (%5.1f, %5.1f)", P.x, P.y);}
  printf("]\n");
  
  free(TP.tab);}
  
void ecrire_contour_fich(Liste_Point L, FILE*f){
  Cellule_Liste_Point *cel = malloc(sizeof(Cellule_Liste_Point));  
  fprintf(f,"%d\n\n",1);
  fprintf(f,"%d\n",L.taille);
  cel=L.first;
  while (cel!= NULL){
    fprintf(f,"%5.1f %5.1f\n",cel->data.x,cel->data.y);
    cel=cel->suiv;}
  
}


//Fonction pour ecrire le contour dans un fichier

Contour calcul_contour_B2(Image I, Robot r){
  int k=1;
  Contour Liste_des_points_de_contour;
  UINT x=0;
  UINT y=0; 
  UINT pos_x,pos_y;
  trouver_pixel_depart(I,&x,&y);
  printf("Pixel de départ x=%d y=%d \n",x,y);
  Liste_des_points_de_contour= creer_liste_Point_vide();
  r.x=x-1;
  r.y=y-1;
  r.o=Est;
  pos_x=r.x;
  pos_y=r.y;
  bool boucle= true;
  while (boucle){
      k++;
      
      Liste_des_points_de_contour=ajouter_element_liste_Point(Liste_des_points_de_contour, set_point(r.x,r.y));
      avancer(&r);
      nouvelle_orientation(I, &r);
      
      if ( (pos_x==r.x && pos_y==r.y) && r.o==Est){
         boucle= false;}
              }
  
  Liste_des_points_de_contour=ajouter_element_liste_Point(Liste_des_points_de_contour, set_point(r.x,r.y));
  return Liste_des_points_de_contour;
  }
    

  
