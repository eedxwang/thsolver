/******************************************************************************
* File      : initRes.c                                                       *
* Author    : Carlos Rosales Fernandez (carlos@ihpc.a-star.edu.sg)            *
* Date      : 01-09-2006                                                      *
* Revision  : 1.0                                                             *
*******************************************************************************
* DESCRIPTION                                                                 *
* Computes the initial residual vector r for the GMRES solver                 *
******************************************************************************/

/******************************************************************************
* COPYRIGHT & LICENSE INFORMATION                                             *
*                                                                             *
* Copyright 2006 Carlos Rosales Fernandez and The Institute of High           *
* Performance Computing (A*STAR)                                              *
*                                                                             *
* This file is part of thSolver.                                              *
*                                                                             *
* thSolver is free software; you can redistribute it and/or modify            *
* it under the terms of the GNU General Public License as published by        *
* the Free Software Foundation; either version 2 of the License, or           *
* (at your option) any later version.                                         *
*                                                                             *
* thSolver is distributed in the hope that it will be useful,                 *
* but WITHOUT ANY WARRANTY; without even the implied warranty of              *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the               *
* GNU General Public License for more details.                                *
*                                                                             *
* You should have received a copy of the GNU General Public License           *
* along with thSolver; if not, write to the Free Software                     *
* Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA  *
******************************************************************************/

#include "initRes.h"

void initRes(unsigned int size, double **A, double *x, double *B, double *r)
{
    unsigned int i;
    double norm;
    double *y;

    y = doubleVector(size,0);
    norm = L2Norm(size,x); 

    /* Given initial guess */
    if(norm != 0.0){
        matVectProd(size,A,x,y);
        for(i = 0; i < size; i++) r[i] = B[i] - y[i];
    }
    /* Initial guess is zero */     
    else for(i = 0; i < size; i++) r[i] = B[i];

    free(y);
}

