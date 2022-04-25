#include <Eigen/Dense>
#include <cmath>
#include <iostream>
#include <random>
#include<cstdlib>

int main(int argc, char *argv[]) {

  std::random_device rd; 
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dis(0.0, 1.0);//Se declara distribución uniforme para generar números aleatorios entre 0 y 1.

  double P = std::atof(argv[1]);
  int L = std::atoi(argv[2]);


  Eigen::MatrixXd M(L, L); //Declaramosuna matriz de tamaño LxL.
  for (int ii = 0; ii < L; ++ii) {
    for (int jj = 0; jj < L; ++jj) { /*Comenzamos a recorrer la matriz, llenamos sus elementos con un número aleatorio entre 0 y 1,                                           si este es mayor que P asignamos un cero, y si este es menor asignamos un 1.*/ 

      double r = dis(gen);
      M(ii, jj) = r;
      if (M(ii, jj) <= P) {
        M(ii, jj) = 1.0;
      } else {

        M(ii, jj) = 0.0;
      }
    }
  }
  std::cout << M << std::endl; //Se imprime la matriz M.

  return 0;
}
