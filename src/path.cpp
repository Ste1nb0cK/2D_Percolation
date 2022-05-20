#include<Eigen/Eigen>
#include "path.hpp"

//Se recibe la amtriz de estudio, un entero "scanning" el valor del target y el valor de New.
Eigen::ArrayXXi Path(const Eigen::ArrayXXi &I, int L, int scanning, int target,
                     int New) {

  Eigen::ArrayXXi F = Eigen::ArrayXXi::Zero(L, L); //Se declara F como una matriz nula.

  if (scanning == 1) { //Si scanning es 1 se llama hood para que actúe en todos los elementos de la primera columna (barremos de izquierda a derecha) 
   
    for (int ii = 0; ii < L; ++ii) {

      hood(I, F, L, ii, 0, target, New);
    }
  }

  if (scanning == 0) { //Si  scanning es 0 barremos de derecha a izquierda. 

    for (int ii = 0; ii < L; ++ii) {

      hood(I, F, L, ii, L - 1, target, New);
    }
  }
  return F;  
}
