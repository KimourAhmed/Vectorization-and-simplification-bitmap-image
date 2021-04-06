
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"types_macros.h"
#include"calcul_contour.h"
#include"image.h"
#include"plus_contours.h"
#include"structure_Beziers.h"

void format_eps_contour(Tableau_Beziers2 Tab, FILE* f, Image I){
  fprintf(f,"%0.1f %0.1f %s",Tab.tab[0].C0.x,I.H-Tab.tab[0].C0.y, "moveto ");
  fprintf(f,"%0.1f %0.1f %s",Tab.tab[0].C1.x,I.H-Tab.tab[0].C1.y, "lineto ");
  fprintf(f,"%0.1f %0.1f %s",Tab.tab[0].C2.x,I.H-Tab.tab[0].C2.y, "lineto ");
  for(int i=1;i<Tab.taille;i++){
  fprintf(f,"%0.1f %0.1f %s",Tab.tab[i].C0.x,I.H-Tab.tab[i].C0.y, "lineto ");
  fprintf(f,"%0.1f %0.1f %s",Tab.tab[i].C1.x,I.H-Tab.tab[i].C1.y, "lineto ");
  fprintf(f,"%0.1f %0.1f %s",Tab.tab[i].C2.x,I.H-Tab.tab[i].C2.y, "lineto ");}
     }
  
 
void format_eps(Liste_tout_les_Beziers2 L, FILE* f, Image I){
  fprintf(f,"%s\n","%!PS-Adobe-3.0 EPSF-3.0");
  fprintf(f,"\n%s %d %d %d %d\n","%%BoundingBox:", 0, 0, I.L, I.H);
  Cellule_Liste_tout_les_Beziers2 *cel = malloc(sizeof(Cellule_Liste_tout_les_Beziers2));
  cel=L.first;
  while (cel!= NULL){
        format_eps_contour(cel->data, f, I);
        cel=cel->suiv;}
 
  fprintf(f,"\n%s\n","0.00001 setlinewidth") ;
  fprintf(f,"\n%s\n","fill");
  fprintf(f,"%s\n","showpage");}

   
    
 
  
