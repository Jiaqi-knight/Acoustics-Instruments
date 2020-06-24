#ifndef LATTICEBOLTZMANN_H
#define LATTICEBOLTZMANN_H

#include <iostream>
#include <fstream>
#include <cmath>
#include "omp.h"
#include <iostream>
#include <cmath>
/*
  Para proportion=12 se manejaron valores de lambda=20 y A=150.
  Además de que se comienza a graficar en x=5, para no ver la fuente inicial.
*/
const int proportion = 1;
const int Lx = 500*proportion, Ly = 50*proportion;
const int LFx = 330*(proportion), LFy = 14*(proportion);

const double k1 = 0, k2 = 0, kF = 0;
const double Aperture_x = 2*proportion;
const double Hole_pos = LFx/3;

const int Q = 5;
const double W0 = 1.0 / 3;
const double k = 1; //Constante de reflexión

const double C = 0.5; // C<0.707 celdas/click
const double TresC2 = 3 * C * C;
const double AUX0 = 1 - TresC2 * (1 - W0);

const double tau = 0.5;
const double Utau = 1.0 / tau;
const double UmUtau = 1 - Utau;

class LatticeBoltzmann
{
private:
  double w[Q];
  int V[2][Q]; // V[0][i]=V_ix,  V[1][i]=V_iy
  double f[Lx][Ly][Q], fnew[Lx][Ly][Q]; // f[ix][iy][i]
public:
  LatticeBoltzmann(void);
  double rho(int ix, int iy, bool UseNew);
  double Jx(int ix, int iy, bool UseNew);
  double Jy(int ix, int iy, bool UseNew);
  double Jz(int ix, int iy, bool UseNew);
  double feq(double rho0, double Jx0, double Jy0, int i);
  void Colisione(void);
  void Adveccione(void);
  void Inicie(double rho0, double Jx0, double Jy0);
  void ImponerCampos(int t);
  void Imprimase(const char * NombreArchivo, double t);
  void Imprimir(int t, int ix, int iy, const char * NombreArchivo);
};

#endif // LATTICEBOLTZMANN_H
