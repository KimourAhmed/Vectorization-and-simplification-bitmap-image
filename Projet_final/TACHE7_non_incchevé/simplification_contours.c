#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "types_macros.h"
#include"geom2d.h"
#include"calcul_contour.h"
#include"simplification_contours.h"
#include"structure_Beziers.h"

Liste_Beziers2 simplification_douglas_peucker_bezier2(Tableau_Point CONT, UINT j1, UINT j2,double d){
   Liste_Beziers2 L;
   Liste_Beziers2 L1;
   Liste_Beziers2 L2;
   L = creer_liste_Beziers2_vide();
   L1= creer_liste_Beziers2_vide();
   L2= creer_liste_Beziers2_vide();
   int i=0;
   int n= j2-j1;
   double ti=0;
   double dj=0;
   Point Pj;
   Beziers2 B = approx_beziers2(CONT, j1, j2);   
   double dmax=0;
   UINT k=j1;
  
   for (UINT j=j1+1; j<=j2; j++){
       i=j-j1;
       ti=(double)i/(double)n;
       Pj=CONT.tab[j];
       dj=distance_point_beziers2(Pj, B, ti);
       if (dmax<dj){
          dmax=dj;
          k=j;}
          }

   if (dmax<=d){
       L=ajouter_element_liste_Beziers2 (L,B);}
   
   else{
   L1= simplification_douglas_peucker_bezier2(CONT, j1, k, d);
   L2= simplification_douglas_peucker_bezier2(CONT, k, j2, d);    
   
   L=concatener_liste_Beziers2(L1,L2);
   }
   
   return L;
   }

