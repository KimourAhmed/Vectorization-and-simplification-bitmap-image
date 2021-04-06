#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include"geom2d.h"

Point set_point(double x, double y){
  Point P= {x,y};
  return P;
  }
  
Vecteur add_vect(Vecteur U, Vecteur V){
  Vecteur w={U.x+V.x,U.y+V.y};
  return w;
  }
  
Point add_point(Point P1, Point P2){ 
  return set_point(P1.x+P2.x,P1.y+P2.y);
  }
  
Point sub_point(Point P1, Point P2){ 
  return set_point(P1.x-P2.x,P1.y-P2.y);
  }
  
Vecteur vect_bipoint(Point A, Point B){
  Vecteur V={B.x-A.x,B.y-A.y};
  return V;
  }
  
double produit_scalaire (Vecteur A, Vecteur B){
   return A.x * B.x + A.y * B.y;
}

Point produit_reel_point(Point P, double a){
   return (Point){a*P.x, a* P.y};
}
  
Vecteur produit_reel_vect (Vecteur V, double r){
  return (Vecteur){V.x * r, V.y * r};
}
    
  
double norme_vecteur(Vecteur V){
  return sqrt(V.x * V.x + V.y * V.y);
}

double distance_point(Point A, Point B){
  return norme_vecteur(vect_bipoint(A,B));
}   

double distance_point_segment(Point P, Point A, Point B){
     double dist=0;
     //Cas 1
     if ((A.x==B.x) && (A.y==B.y)){
        dist=distance_point(A, P);}
     
     //Cas 2  
     else{ 
        Vecteur AB=vect_bipoint(A,B);
        Vecteur AP=vect_bipoint(A,P);
        double pro_scal_AB= produit_scalaire (AB, AB);
	double pro_scal_AP= produit_scalaire (AP, AB);
        
        double landa= pro_scal_AP / pro_scal_AB;
        
        if (landa<0){
           dist=distance_point(A, P);}
       
        else if ((landa >= 0 ) && (landa <= 1)){
           Point W= sub_point(B,A);
           Point H= produit_reel_point(W, landa);
           Point Q= add_point(A,H);
           dist= distance_point(Q, P);
           }
        
        else if (landa > 1){ 
           dist=distance_point(B, P);}
           
          }
        return dist;
          }
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
