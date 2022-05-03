#include "percolation_routines.h"

///////////////////////////////////////////////////////////////////////

void hood(const Eigen::Ref<Eigen::ArrayXXi> I, Eigen::Ref<Eigen::ArrayXXi> F,
          int L, int ii, int jj, int target) {

  if (ii >= L || ii < 0 || jj >= L || jj < 0 || I(ii, jj) != target ||
      F(ii, jj) == target) {
    return;
  } /*Si el índice está fuera de los límites, si
      la matriz I no tiene el valor del target, o si F ya tiene el valor del
      target, acabamos la función, si no es así, llenamos F con el valor del
      target, y luego llamamos a la función para sus vecinos garantizando la
      creación del clouster.  */

  F(ii, jj) = target;

  hood(I, F, L, ii + 1, jj, target);
  hood(I, F, L, ii - 1, jj, target);
  hood(I, F, L, ii, jj + 1, target);
  hood(I, F, L, ii, jj - 1, target);
}
////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////
Eigen::ArrayXXi Path(const Eigen::Ref<Eigen::ArrayXXi> I, int L, int scanning,
                     int target) {

  Eigen::ArrayXXi F(L,
                    L); /*Se crea una matriz de ceros F, la cual se llenará con
                         todos los clusters que nacen en la frontera izquierda
                         si scanning==1, para eso se usa la función hood, si
                         scanning==0 se hace los mismo pero desde la derecha. */

  if (scanning == 1) {

    for (int ii = 0; ii < L; ++ii) {

      hood(I, F, L, ii, 0, target);
    }
  }

  if (scanning == 0) {

    for (int ii = 0; ii < L; ++ii) {

      hood(I, F, L, ii, L - 1, target);
    }
  }

  return F;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////
Eigen::ArrayXXi cluster_matrix(const Eigen::Ref<Eigen::ArrayXXi> I, int L) {

  Eigen::ArrayXXi F(L, L); // Creamos F llena de ceros.

  F = Path(I, L, 1, 1); // Se crean los caminos de números 1 desde la izquierda
                        // de la matriz que hay en la matriz I.

  Eigen::ArrayXXi H(L, L);
  H = I.transpose(); // Declaramos H, que será la transpuesta de I, esto para
                     // identificar los clusters verticales usando el mismo alg
                     // oritmo,

  Eigen::ArrayXXi J(L, L);
  J = Path(H, L, 1,
           1); // Se crean los caminos de números desde la izquerda de la
               // transpuesta de I, lo cual es equivalente a crearlos de sde la
               // parte de arriba de I.

  Eigen::ArrayXXi med(
      L, L); // Para crear la matriz percolante sumamos F y la transpuesta de F,
             // las casillas que hagan parte de un cluster, al sumarlas, el
             // resultado debe ser 2, sin embargo esto no es suficiente, porque
             // aún pueden haber clou                             sters que no
             // son percolantes.
  med = F + J.transpose();

  Eigen::ArrayXXi F1(
      L,
      L); // Para solucionar esto, creamos una matriz F1, que tomará la
          // matriz med y le creará los caminos buscando el número 2 pero
          // desde la derecha, grantizando que esos caminos solo pueden
          // corresponder a clusters percolan                            tes,
          // por ende F1 será la matriz de percolación, nótese que si el
          // sistema no percola, la matriz F1 será nula
  F1 = Path(med, L, 0, 2);

  return F1;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////

bool Percolation(const Eigen::Ref<Eigen::ArrayXXi> I, int L) {

  int cont =
      0; /* Esta función está pensada para que reciba una matriz de percolación
         I, para saber si el sistema percola, simplemente miramos una frontera
         vertical y una horizontal, si encontramos un número diferente de cero,
         el sistema tiene que ser uno percolante. */
  for (int ii = 0; ii < L; ++ii) {
    if (I(L - 1, ii) != 0 || I(ii, L - 1) != 0) {
      cont = 1;

      break;
    }
  }

  if (cont != 0) {
    return true;
  }

  else {
    return false;
  }
}