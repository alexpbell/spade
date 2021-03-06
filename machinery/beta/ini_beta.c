// Copyright 2016 State of Queensland
// This file is part of SPADE
// See spade.c, COPYING, COPYING.LESSER

#include <math.h>
#include "../../meschach/matrix.h"
#include "../../common.h"
#include "../../parameters.h"

VEC *ini_beta(

	      Parameters *parameters,
	      VEC *x,
	      VEC *p

	      )
{

  x->ve[x->dim-1] -= 1e-5;

  Real a = parameters->alpha.value;
  Real b = parameters->beta.value;
  Real g = parameters->gamma.value*1e-7;
  Real k = parameters->kappa.value;
  Real w = parameters->omega.value;

  Real zeta = sqrt( 81*k*k*w*w*pow(a*A1+2*a*A2*w,2.) - 12*k*pow(a*A1*w+k,3.) );
  Real eta = 9*a*A1*k*k*w + 18*a*A2*k*k*w*w + k*zeta;
  Real Z = pow(eta,1./3) / (3*pow(2./3,1./3)) + pow(2./3,1./3)*k*(a*A1*w+k) / pow(eta,1./3);

  for (int j=0;j<x->dim;j++)
    p->ve[j] = -pow(1-x->ve[j]/w,Z/k - 2.) * (1/(g*Z)) * (a*A1 + 2*a*A2*k*w/(Z+k));

}
