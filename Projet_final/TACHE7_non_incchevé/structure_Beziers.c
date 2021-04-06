 #include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <math.h>
#include "types_macros.h"
#include"geom2d.h"
#include"calcul_contour.h"
#include"structure_Beziers.h"



  
Liste_Beziers2 creer_liste_Beziers2_vide(){
   Liste_Beziers2 B = {0, NULL, NULL};
   return B;
}  
Cellule_Liste_Beziers2 *creer_element_liste_Beziers2(Beziers2 B){
   Cellule_Liste_Beziers2 *el;
   el = (Cellule_Liste_Beziers2 *)malloc(sizeof(Cellule_Liste_Beziers2));
   if (el==NULL)
   {
      fprintf(stderr, "creer_element_liste_segments : allocation impossible \n");
      exit(-1);
   }
   el->data = B;
   el->suiv = NULL;
   return el; }
   
   
Liste_Beziers2 ajouter_element_liste_Beziers2 (Liste_Beziers2 L, Beziers2 B){
   Cellule_Liste_Beziers2  *el;
   
   el = creer_element_liste_Beziers2(B);
   if (L.taille == 0){
    
       L.first = L.last = el;}
   else {
       L.last->suiv = el;
       L.last = el;}
   L.taille++;
   return L; }

Liste_Beziers2 concatener_liste_Beziers2(Liste_Beziers2 L1, Liste_Beziers2 L2){
   if(L1.taille ==0) return L2;
   if(L2.taille ==0) return L1;

   L1.last ->suiv= L2.first;
   L1.last = L2.last;
   L1.taille += L2.taille;
   return L1;
}

Tableau_Beziers2 sequence_Beziers2_liste_vers_tableau(Liste_Beziers2 L){
  Tableau_Beziers2 T;
  T.taille = L.taille;
  T.tab= malloc(sizeof(Beziers2) *T.taille);
  if (T.tab == NULL){
     fprintf(stderr, "sequence_points_liste_vers_tableau : ");
     fprintf(stderr, "allocation impossible : ");             
     exit(-1);}
  
  int k = 0;
  Cellule_Liste_Beziers2 *el = L.first;
  while(el){
    T.tab[k]=el->data;
    k++;
    el= el->suiv;}
  return T;}
  
//__________________________________________________________________________________________  
  
Liste_tout_les_Beziers2 creer_liste_tout_les_Beziers2_vide(){
   Liste_tout_les_Beziers2  L = {0, NULL, NULL};
   return L;
}
Cellule_Liste_tout_les_Beziers2 *creer_element_liste_tout_les_Beziers2(Tableau_Beziers2 v){
   Cellule_Liste_tout_les_Beziers2 *el;
   el = (Cellule_Liste_tout_les_Beziers2 *)malloc(sizeof(Cellule_Liste_tout_les_Beziers2));
   if (el==NULL)
   {
      fprintf(stderr, "creer_element_liste_Contour : allocation impossible \n");
      exit(-1);
   }
   el->data = v;
   el->suiv = NULL;
   return el;
}


Liste_tout_les_Beziers2 ajouter_element_liste_tout_les_Beziers2 (Liste_tout_les_Beziers2 L, Tableau_Beziers2 e){
   Cellule_Liste_tout_les_Beziers2 *el;
   
   el = creer_element_liste_tout_les_Beziers2(e);
   if (L.taille == 0){
    
       L.first = L.last = el;}
   else {
       L.last->suiv = el;
       L.last = el;}
   L.taille++;
   return L; }
 
//__________________________________________________________________________________________     

Point calcul_point_beziers2(Beziers2 C, double t){
    
     Point Ct;   

     Point C_inter= add_point(produit_reel_point(C.C0, (1-t)*(1-t)),  produit_reel_point(C.C1, 2*t*(1-t))); 
     Ct= add_point(C_inter,  produit_reel_point(C.C2, t*t));
     return Ct;
     }

Beziers2 approx_beziers2(Tableau_Point Cont, int j1, int j2){
    
    Beziers2 res;
    Point P0=Cont.tab[j1];
    Point P1=Cont.tab[j1+1];
    Point Pn=Cont.tab[j2];   
    
    int n=j2-j1;
    double reel_n=(double)n;

    res.C0=P0;
    res.C2=Pn;
    
    //	Determination de C1
    
    //CAS_____1
    if (n == 1){
       res.C1.x= (P0.x+P1.x)/2;
       res.C1.y= (P0.y+P1.y)/2; }
    
    //CAS_____2   
    else{
         double x=0;
    	 double y=0;
    	
    	 for(int i=1; i<=n-1; i++){
       		x=x+Cont.tab[i].x;} 
       		
    	 for(int i=1; i<=n-1; i++){
       		y=y+Cont.tab[i].y;}  
       		    
        Point Pi;
        Pi.x=x;
        Pi.y=y;
   	double alpha= 3*reel_n/((reel_n*reel_n)-1);
   	double beta= (1-2*reel_n)/(2*(reel_n+1));
   	res.C1.x= alpha*Pi.x + beta*(P0.x+Pn.x);
   	res.C1.y= alpha*Pi.y + beta*(P0.y+Pn.y); }
     return res;
   	  }
 
double distance_point_beziers2(Point Pi, Beziers2 B, double ti){    
     double dist=0;
     Point Ct;
     Ct=calcul_point_beziers2(B, ti);
     dist= distance_point(Pi, Ct);
     return dist; }
   
   	
   	
   	
   	
   	
