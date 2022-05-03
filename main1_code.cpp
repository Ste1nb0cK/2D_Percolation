#include <Eigen/Eigen>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <random>
#include <string>
/*Trataré de explicar todo para que se entienda lo mejor prosible, soy
 * consciente de que hay muchas mejoras de estilo en el código, obviamente esto
 * hay que corregirlo pero por ahora tenemos esto y creo que tenemos casi lista
 * la implementación para ponernos a hacer medidas y demás.*/

Eigen::Array<bool, Eigen::Dynamic, Eigen::Dynamic> fill(int L, double p,
                                                        int seed); /*Función
que llena el arreglo con las casillas abiertas (1) y cerradas (0).

void hood(const  Eigen::Ref<Eigen::MatrixXi> I,  Eigen::Ref<Eigen::MatrixXi> F,
int L, int ii, int jj, int target);/*Esta función a partir de una casilla (i,
j) de la matriz I, crea una matriz F con un clouster formado por casillas con
el valor de "target" y todas las demás casillas fuera del cluster particular
son ceros. */

Eigen::MatrixXi
Path(const Eigen::Ref<Eigen::MatrixXi> I, int L, int scanning,
     int target); /*Este método toma la matriz de entrada I y devuelve otra
                     matriz con todos los clusters del valor target
                     (percolantes o no) que inician en la arista izquierda si el
                     valor de scanning es 1, o desde la derecha si el valor de
                     scanning es 0. */

Eigen::MatrixXi clouster_matrix(
    const Eigen::Ref<Eigen::MatrixXi> I,
    int L); /*Este método toma la matriz I, y nos devuelve lo que llamé"la
               matriz de percolación, que estará llena con el número 2 en todas
               las casillas que hagan parte de un clouster percolante, los demás
               valores son ceros." */

bool Percolation(const Eigen::Ref<Eigen::MatrixXi> I,
                 int L); /*Este método recibe la matriz de percolación y nos
dice si existe un clouster percolante o no. */

/*EN la función main declaramos la probabilidad de llenado P, el tamaño de la
matriz L, y la semilla con la que crearemos los números aleatorios,
posteriormente declaramos la matrix M a la que le aplicamos el algoritmo de
llenado definido por la función fill(), luego, declaramos la función F a la que
le asignamos la matriz de percolación definida por la función clouster_matrix(),
se imprime la matriz original, la matriz de percolación, y si el sistema percola
o no, definido
por la función Percolation() aplicada a la matriz de percolación F. */

int main(int argc, char *argv[]) {

  const int L = std::atoi(argv[1]);
  const double p = std::atof(argv[2]);
  const double seed = std::atof(argv[3]);
  Eigen::Array<bool, Eigen::Dynamic, Eigen::Dynamic> M;
  M = fill(L, p, seed);
  // Eigen::MatrixXi F(L, L);
  // F = clouster_matrix(M, L);

  std::cout << "La matriz original es" << std::endl
            << M
            << std::endl;
      // << "La matriz de percolación es" << std::endl
      // << F << std::endl
      // << "¿EL sistema percola?" << std::endl
      // << Percolation(F, L) << std::endl;

      return 0;
}

//////////////////////////////////////////////////////////////////////////

Eigen::Array<bool, Eigen::Dynamic, Eigen::Dynamic> fill(int L, double p,
                                                         int seed) {

  std::mt19937 gen(seed);
  std::bernoulli_distribution dis(p);
  Eigen::Array<bool, Eigen::Dynamic, Eigen::Dynamic>
      M; // Declaramos un arreglo de tamaño LxL.
  M.resize(L, L);
  // for (int ii = 0; ii < L; ++ii) {
  // for (int jj = 0; jj < L;
  // ++jj) { /*Comenzamos a recorrer la matriz, llenamos sus elementos con
  // un número aleatorio entre 0 y 1, si este es mayor que P
  // asignamos un cero, y si este es menor asignamos un 1.*/

  // double r = dis(gen);

  // if (r <= P) {
  // M(ii, jj) = 1;
  // } else {

  // M(ii, jj) = 0;
  // }
  // }
  // }
  for (int n = 0; n < L; n++) {
    for (int m = 0; m < L; m++) {
      M(m, n) = dis(gen);
    }
  }

  return M;
}

///////////////////////////////////////////////////////////////////////

void hood(const Eigen::Ref<Eigen::MatrixXi> I, Eigen::Ref<Eigen::MatrixXi> F,
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
Eigen::MatrixXi Path(const Eigen::Ref<Eigen::MatrixXi> I, int L, int scanning,
                     int target) {

  Eigen::MatrixXi F(L,
                    L); /*Se crea una matriz de ceros F, la cual se llenará con
                         todos los clousters que nacen en la frontera izquierda
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
Eigen::MatrixXi clouster_matrix(const Eigen::Ref<Eigen::MatrixXi> I, int L) {

  Eigen::MatrixXi F(L, L); // Creamos F llena de ceros.

  F = Path(I, L, 1, 1); // Se crean los caminos de números 1 desde la izquierda
                        // de la matriz que hay en la matriz I.

  Eigen::MatrixXi H(L, L);
  H = I.transpose(); // Declaramos H, que será la transpuesta de I, esto para
                     // identificar los clousters verticales usando el mismo alg
                     // oritmo,

  Eigen::MatrixXi J(L, L);
  J = Path(H, L, 1,
           1); // Se crean los caminos de números desde la izquerda de la
               // transpuesta de I, lo cual es equivalente a crearlos de sde la
               // parte de arriba de I.

  Eigen::MatrixXi med(
      L, L); // Para crear la matriz percolante sumamos F y la transpuesta de F,
             // las casillas que hagan parte de un clous ter, al sumarlas, el
             // resultado debe ser 2, sin embargo esto no es suficiente, porque
             // aún pueden haber clou                             sters que no
             // son percolantes.
  med = F + J.transpose();

  Eigen::MatrixXi F1(
      L,
      L); // Para solucionar esto, creamos una matriz F1, que tomará la
          // matriz med y le creará los caminos buscando el número 2 pero
          // desde la derecha, grantizando que esos caminos solo pueden
          // corresponder a clousters percolan                            tes,
          // por ende F1 será la matriz de percolación, nótese que si el
          // sistema no percola, la matriz F1 será nula
  F1 = Path(med, L, 0, 2);

  return F1;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////

bool Percolation(const Eigen::Ref<Eigen::MatrixXi> I, int L) {

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
