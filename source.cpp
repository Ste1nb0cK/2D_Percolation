#include <Eigen/Eigen>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <random>
#include <vector>

/*Trataré de explicar todo para que se entienda lo mejor prosible, soy
 * consciente de que hay muchas mejoras de estilo en el código, obviamente esto
 * hay que corregirlo pero por ahora tenemos esto y creo que tenemos casi lista
 * la implementación para ponernos a hacer medidas y demás.*/

Eigen::ArrayXXi fill(int L, double P,
                     double seed); /*Función que llena la matriz con las
                                      casillas abiertas (1) y cerradas (0). */

void hood(const Eigen::ArrayXXi &I, Eigen::ArrayXXi &F, int L, int ii, int jj,
          int target,
          int New); /*Esta función a partir de una casilla (i, j) de la matriz
                       I, crea una matriz F con un clouster formado por casillas
                       con el valor de "target" y todas las demás casillas fuera
                       del clouster particular son ceros. */

Eigen::ArrayXXi
Path(const Eigen::ArrayXXi &I, int L, int scanning, int target,
     int New); /*Este método toma la matriz de entrada I y devuelve otra matriz
                  con todos los clousters del valor target (percolantes o no)
                  que inician en la arista izquierda si el valor de scanning es
                  1, o desde la derecha si el valor de scanning es 0. */

Eigen::ArrayXXi clouster_matrix(
    const Eigen::ArrayXXi &I,
    int L); /*Este método toma la matriz I, y nos devuelve lo que llamé"la
               matriz de percolación, que estará llena con el número 2 en todas
               las casillas que hagan parte de un clouster percolante, los demás
               valores son ceros." */

bool Percolation(const Eigen::ArrayXXi &I, int L); /*Este método recibe la
matriz de percolación y nos dice si existe un clouster percolante o no. */

Eigen::ArrayXi sep(Eigen::ArrayXXi &I, int L);

Eigen::ArrayXXi index_matrix(Eigen::ArrayXXi &I, int L);

int Size_clouster(Eigen::ArrayXXi &I, int L);

/*EN la función main declaramos la probabilidad de llenado P, el tamaño de la
matriz L, y la semilla con la que crearemos los números aleatorios,
posteriormente declaramos la matrix M a la que le aplicamos el algoritmo de
llenado definido por la función fill(), luego, declaramos la función F a la que
le asignamos la matriz de percolación definida por la función clouster_matrix(),
se imprime la matriz original, la matriz de percolación, y si el sistema percola
o no, definido
por la función Percolation() aplicada a la matriz de percolación F. */

int main(int argc, char *argv[]) {

  double P = std::atof(argv[1]);
  int L = std::atoi(argv[2]);
  double seed = std::atof(argv[3]);

  Eigen::ArrayXXi M(L, L);
  M = fill(L, P, seed);
  M.resize(L, L);

  // Inicialización que usamos para hacer test con matrices puestas a mano
  /* for(int ii =0; ii<L; ++ii){
   for(int jj = 0; jj < L; ++jj){

     if( jj==5 || jj == 7 || jj==8 || jj==9 || jj==12) {M(ii, jj)= 1;}else{
   M(ii, jj)=0;}

   }
   }*/

  Eigen::ArrayXXi F(L, L);

  F = clouster_matrix(M, L); // Crea la matriz de percolación

  Eigen::ArrayXXi J = index_matrix(F, L); // Matriz de percolación indexada

  std::cout << "La matriz original es" << std::endl
            << M << std::endl
            << "La matriz de percolación es" << std::endl
            << F << std::endl
            << "¿EL sistema percola?" << std::endl
            << Percolation(F, L) << std::endl
            << sep(F, L) << std::endl
            << index_matrix(F, L) << std::endl;
  std::cout << Size_clouster(J, L);

  return 0;
}

//////////////////////////////////////////////////////////////////////////

Eigen::ArrayXXi fill(int L, double P, double seed) {

  std::mt19937 gen(seed);
  std::uniform_real_distribution<> dis(0.0, 1.0);

  Eigen::ArrayXXi M(L, L); // Declaramos una matriz de tamaño LxL.
  for (int ii = 0; ii < L; ++ii) {
    for (int jj = 0; jj < L;
         ++jj) { /*Comenzamos a recorrer la matriz, llenamos sus elementos con
                    un número aleatorio entre 0 y 1, si este es mayor que P
                    asignamos un cero, y si este es menor asignamos un 1.*/

      double r = dis(gen);

      if (r <= P) {
        M(ii, jj) = 1;
      } else {

        M(ii, jj) = 0;
      }
    }
  }

  return M;
}

///////////////////////////////////////////////////////////////////////

void hood(const Eigen::ArrayXXi &I, Eigen::ArrayXXi &F, int L, int ii, int jj,
          int target, int New) {

  if (ii >= L || ii < 0 || jj >= L || jj < 0) {
    return;
  }
  if (I(ii, jj) != target || F(ii, jj) == New) {
    return;
  }

  F(ii, jj) = New;

  hood(I, F, L, ii + 1, jj, target, New);
  hood(I, F, L, ii - 1, jj, target, New);
  hood(I, F, L, ii, jj + 1, target, New);
  hood(I, F, L, ii, jj - 1, target, New);
}
////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////
Eigen::ArrayXXi Path(const Eigen::ArrayXXi &I, int L, int scanning, int target,
                     int New) {

  Eigen::ArrayXXi F = Eigen::ArrayXXi::Zero(L, L);

  if (scanning == 1) {

    for (int ii = 0; ii < L; ++ii) {

      hood(I, F, L, ii, 0, target, New);
    }
  }

  if (scanning == 0) {

    for (int ii = 0; ii < L; ++ii) {

      hood(I, F, L, ii, L - 1, target, New);
    }
  }

  return F;
}
//////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////
Eigen::ArrayXXi clouster_matrix(const Eigen::ArrayXXi &I, int L) {

  Eigen::ArrayXXi F = Path(I, L, 1, 1, 1);
  Eigen::ArrayXXi H = I.transpose();
  Eigen::ArrayXXi J = Path(H, L, 1, 1, 1);
  H.resize(0, 0);
  Eigen::ArrayXXi med = F + J.transpose();
  int Vclouster_id = 0;
  int Hclouster_id = 0;
  for (int ii = 0; ii < L; ++ii) {

    if (F(ii, L - 1) != 0) {
      Vclouster_id = 1;
    }
    if (J(ii, L - 1) != 0) {
      Hclouster_id = 1;
    }
  }

  if (Vclouster_id == 0) {
    med = 2 * J;
    J.resize(0, 0);
    return Path(med, L, 0, 2, 1).transpose();
  }

  if (Hclouster_id == 0) {
    med = 2 * F;
    F.resize(0, 0);
    return Path(med, L, 0, 2, 1);
  }

  J.resize(0, 0);
  F.resize(0, 0);

  Eigen::ArrayXXi F1 = Path(med, L, 0, 2, 1);

  return F1;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////

bool Percolation(const Eigen::ArrayXXi &I, int L) {

  int Per =
      0; /* Esta función está pensada para que reciba una matriz de percolación
          I, para saber si el sistema percola, simplemente miramos una frontera
          vertical y una horizontal, si encontramos un número diferente de cero,
          el sistema tiene que ser uno percolante. */
  for (int ii = 0; ii < L; ++ii) {
    if (I(L - 1, ii) != 0 || I(ii, L - 1) != 0) {
      Per = 1;

      break;
    }
  }

  if (Per != 0) {
    return true;
  }

  else {
    return false;
  }
}

Eigen::ArrayXi sep(Eigen::ArrayXXi &I, int L) {

  Eigen::ArrayXXi F = Path(I, L, 1, 1, 1);
  Eigen::ArrayXXi H = I.transpose();
  Eigen::ArrayXXi J = Path(H, L, 1, 1, 1);
  H.resize(0, 0);

  int ver = 0;
  int hor = 0;
  int per = 0;
  Eigen::ArrayXi V(2);
  V(0) = 0;
  V(1) = 0;

  for (int ii = 0; ii < L; ++ii) {
    if (F(ii, L - 1) != 0) {
      V(0) = 1;

      break;
    }
  }
  F.resize(0, 0);

  for (int ii = 0; ii < L; ++ii) {
    if (J(ii, L - 1) != 0) {
      V(1) = 1;

      break;
    }
  }

  J.resize(0, 0);

  return V;
}

Eigen::ArrayXXi index_matrix(Eigen::ArrayXXi &I, int L) {

  Eigen::ArrayXi V_H_clouster_id = sep(I, L);

  Eigen::ArrayXXi F = I;

  if (V_H_clouster_id(0) == 1 && V_H_clouster_id(1) == 0) {
    int counterh = 1;

    for (int ii = 0; ii < L; ++ii) {

      if (F(ii, 0) == 1) {
        hood(I, F, L, ii, 0, 1, counterh);
        ++counterh;
      }
    }
  }

  if (V_H_clouster_id(0) == 0 && V_H_clouster_id(1) == 1) {
    F = I.transpose();
    Eigen::ArrayXXi H = I.transpose();
    int counterv = 1;
    for (int ii = 0; ii < L; ++ii) {

      if (F(ii, 0) == 1) {
        hood(H, F, L, ii, 0, 1, counterv);
        ++counterv;
      }
    }

    return F.transpose();
  }

  return F;
}

int Size_clouster(Eigen::ArrayXXi &I, int L) {

  std::vector<int> Elements;
  Elements.resize(L * L);
  std::vector<int> clousters_mass;
  clousters_mass.resize(L);
  for (int ii = 0; ii < L; ++ii) {
    for (int jj = 0; jj < L; ++jj) {

      Elements[ii * L + jj] = I(ii, jj);
    }
  }
  int target = 1;
  for (int ii = 0; ii < L; ++ii) {

    clousters_mass[ii] = std::count(Elements.begin(), Elements.end(), target);
    target++;
  }

  auto result = std::max_element(clousters_mass.begin(), clousters_mass.end());
  int index = std::distance(clousters_mass.begin(), result);
  return clousters_mass[index];
}
