#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"types_macros.h"
#include"geom2d.h"
#include"calcul_contour.h"
#include"image.h"
#include"plus_contours.h"
#include"simplification_contours.h"
#include"structure_Beziers.h"

//TACHE5

Liste_Contours creer_liste_Contours_vide(){
   Liste_Contours  L = {0, NULL, NULL};
   return L;
}

Cellule_Liste_Contour *creer_element_liste_Contour(Tableau_Point v){
   Cellule_Liste_Contour *el;
   el = (Cellule_Liste_Contour *)malloc(sizeof(Cellule_Liste_Contour));
   if (el==NULL)
   {
      fprintf(stderr, "creer_element_liste_Contour : allocation impossible \n");
      exit(-1);
   }
   el->data = v;
   el->suiv = NULL;
   return el;
}


Liste_Contours ajouter_element_liste_Contours(Liste_Contours L, Tableau_Point e){
   Cellule_Liste_Contour*el;
   
   el = creer_element_liste_Contour(e);
   if (L.taille == 0){
    
       L.first = L.last = el;}
   else {
       L.last->suiv = el;
       L.last = el;}
   L.taille++;
   return L; }

//ETAPE1
//a
//creer une image toute blanche
Image creer_image_masque(Image M){
  Image P= creer_image(M.L,M.H);
  return P;}
//b

Image parcours(Image M){
  Pixel pixelxy, pixeln;
  UINT x;
  UINT y;
  Image P = creer_image_masque(M);
  for (y=1;y<=M.H;y++){
    for (x=1;x<=M.L;x++){
      pixelxy=get_pixel_image(M, x, y);
      pixeln= get_pixel_image(M, x, y-1);
      if ((pixelxy== NOIR) && (pixeln==BLANC)){
         set_pixel_image(P,x,y,NOIR);}
                    }
                      }
  return P;
                       }

//Etape2
//a
int trouver_pixel_noir(Image P,UINT *x,UINT *y){
       
       UINT i=0;
       UINT j=0;
       int tout_blanc=1;
       Pixel pix;
       while(j<=P.H){
         pix=get_pixel_image(P,i,j);
         if (pix==NOIR){
             *x=i;
             *y=j;
             tout_blanc=0;
             break;}
         i++;
         if (i>P.L){
            i=1;
	    j++;}
       }
       return tout_blanc;
       
        }

Contour calcul_seul_contour(Image I,Image P, Robot r,UINT *x,UINT *y, int *nombre_de_segments){
  Contour Liste_des_points_de_contour;
  UINT pos_x,pos_y;
  Liste_des_points_de_contour= creer_liste_Point_vide();
  r.x=*x-1;
  r.y=*y-1;
  r.o=Est;
  pos_x=r.x;
  pos_y=r.y;
  bool boucle= true;
  while (boucle){
      if (r.o==Est){
        set_pixel_image(P,r.x+1,r.y+1,BLANC);
        }
 
      Liste_des_points_de_contour=ajouter_element_liste_Point(Liste_des_points_de_contour, set_point(r.x,r.y));
      avancer(&r);
      *nombre_de_segments=*nombre_de_segments+1;
      nouvelle_orientation(I, &r);
      if ( (pos_x==r.x && pos_y==r.y) && r.o==Est){
         boucle= false;}
              }
  
  Liste_des_points_de_contour=ajouter_element_liste_Point(Liste_des_points_de_contour, set_point(r.x,r.y));
  
  return Liste_des_points_de_contour; }


 
Liste_tout_les_Beziers2  calcul_plusieurs_contours(Image I, Image P, Robot r, double d){
  UINT x;
  UINT y;  
  int nombre_de_segments=0;
  int nombre_de_courbes=0;
  Liste_tout_les_Beziers2 Beziers2_simpl= creer_liste_tout_les_Beziers2_vide();
  Plus_contours Liste_des_points_de_contour=creer_liste_Contours_vide();
  
  Contour contour_seq;
  
  Liste_Beziers2 liste_Beziers2_un_seul_contour=creer_liste_Beziers2_vide();
  
  Tableau_Point contour_tab; 
  Tableau_Beziers2 contour_simpl_tab;

  contour_seq = creer_liste_Point_vide();  
  
  int tout_blanc= trouver_pixel_noir(P,&x,&y); 
  while(tout_blanc==0){
    
     contour_seq= calcul_seul_contour(I, P, r, &x, &y,  &nombre_de_segments);
     contour_tab= sequence_points_liste_vers_tableau (contour_seq);
     
     Liste_des_points_de_contour= ajouter_element_liste_Contours(Liste_des_points_de_contour, contour_tab);
     
     liste_Beziers2_un_seul_contour=simplification_douglas_peucker_bezier2(contour_tab,0 , contour_tab.taille-1 , d);
     
     contour_simpl_tab=sequence_Beziers2_liste_vers_tableau(liste_Beziers2_un_seul_contour);
    
     nombre_de_courbes = nombre_de_courbes+contour_simpl_tab.taille;
     
     Beziers2_simpl=ajouter_element_liste_tout_les_Beziers2 (Beziers2_simpl, contour_simpl_tab);
     
     tout_blanc= trouver_pixel_noir(P,&x,&y); 
     }
  
  printf("nombre de contours:%d\n",Liste_des_points_de_contour.taille);
  printf("nombre de courbes:%d\n",nombre_de_courbes);

  return Beziers2_simpl;
}



