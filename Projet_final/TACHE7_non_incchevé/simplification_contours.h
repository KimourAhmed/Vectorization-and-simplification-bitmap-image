/****************************************************************************** 
  Interface du module simplification_contours
******************************************************************************/
#ifndef _SIMPLIFICATION_CONTOURS_H_
#define _SIMPLIFICATION_CONTOURS_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "types_macros.h"
#include"geom2d.h"
#include"calcul_contour.h"
#include"structure_Beziers.h"

Liste_Beziers2 simplification_douglas_peucker_bezier2(Tableau_Point C, UINT j1, UINT j2,double d);


#endif /* _SIMPLIFICATION_CONTOURS_H_ */
