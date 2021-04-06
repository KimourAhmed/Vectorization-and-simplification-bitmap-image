#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "types_macros.h"
#include"geom2d.h"
#include"calcul_contour.h"
#include"simplification_contours.h"

Cellule_Liste_segments *creer_element_liste_segments(Segment v){
   Cellule_Liste_segments *el;
   el = (Cellule_Liste_segments *)malloc(sizeof(Cellule_Liste_segments));
   if (el==NULL)
   {
      fprintf(stderr, "creer_element_liste_segments : allocation impossible \n");
      exit(-1);
   }
   el->data = v;
   el->suiv = NULL;
   return el; }
   
Liste_segments creer_liste_segments_vide(){
   Liste_segments L = {0, NULL, NULL};
   return L;
}
   
Liste_segments ajouter_element_liste_segments(Liste_segments L, Segment v){
   Cellule_Liste_segments *el;
   
   el = creer_element_liste_segments(v);
   if (L.taille == 0){
    
       L.first = L.last = el;}
   else {
       L.last->suiv = el;
       L.last = el;}
   L.taille++;
   return L; }

Liste_segments concatener_liste_segments(Liste_segments L1, Liste_segments L2){
   if(L1.taille ==0) return L2;
   if(L2.taille ==0) return L1;

   L1.last ->suiv= L2.first;
   L1.last = L2.last;
   L1.taille += L2.taille;
   return L1;
}

Tableau_Segments sequence_segments_liste_vers_tableau(Liste_segments L){
  Tableau_Segments T;
  T.taille = L.taille;
  T.tab= malloc(sizeof(Segment) *T.taille);
  if (T.tab == NULL){
     fprintf(stderr, "sequence_points_liste_vers_tableau : ");
     fprintf(stderr, "allocation impossible : ");             
     exit(-1);}
  
  int k = 0;
  Cellule_Liste_segments *el = L.first;
  while(el){
    T.tab[k]=el->data;
    k++;
    el= el->suiv;}
  return T;}
//_____________________________________________________________________________________________________________



Liste_tout_les_segments creer_liste_tout_les_segments_vide(){
   Liste_tout_les_segments  L = {0, NULL, NULL};
   return L;
}

Cellule_Liste_tout_les_segments *creer_element_liste_tout_les_segments(Tableau_Segments v){
   Cellule_Liste_tout_les_segments *el;
   el = (Cellule_Liste_tout_les_segments *)malloc(sizeof(Cellule_Liste_tout_les_segments));
   if (el==NULL)
   {
      fprintf(stderr, "creer_element_liste_Contour : allocation impossible \n");
      exit(-1);
   }
   el->data = v;
   el->suiv = NULL;
   return el;
}


Liste_tout_les_segments ajouter_element_liste_tout_les_segmments (Liste_tout_les_segments L, Tableau_Segments e){
   Cellule_Liste_tout_les_segments *el;
   
   el = creer_element_liste_tout_les_segments(e);
   if (L.taille == 0){
    
       L.first = L.last = el;}
   else {
       L.last->suiv = el;
       L.last = el;}
   L.taille++;
   return L; }




Liste_segments simplification_douglas_peucker(Tableau_Point C, UINT j1, UINT j2,double d){
   Liste_segments L,L1,L2;
   L=creer_liste_segments_vide();
   L1=creer_liste_segments_vide();
   L2=creer_liste_segments_vide();
   Segment S;
   double dmax=0;
   UINT k=j1;
   Point Pj1=C.tab[j1];
   Point Pj2=C.tab[j2];
   
   
   for (UINT j=j1+1; j<=j2; j++){
       Point Pj=C.tab[j];
       double dj= distance_point_segment(Pj, Pj1, Pj2);
       
       if (dmax<dj){
          dmax=dj;
          k=j;}
          }
      
   if (dmax<=d){
       S.A=Pj1;
       S.B=Pj2;
       L=ajouter_element_liste_segments(L, S);}
   
   else{
   L1= simplification_douglas_peucker(C, j1, k, d);
   L2= simplification_douglas_peucker(C, k, j2, d);    
   
   L=concatener_liste_segments(L1, L2);
   }
   
   return L;
   }

