#include <Eigen/Eigen>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <random>
#include "clouster_matrix.hpp"
#include "index_matrix.hpp"
#include "fill.hpp"
#include "percolation.hpp"
#include "size_clouster.hpp"


int main(int argc, char *argv[]) {

   const int L = std::atoi(argv[1]);
   const double p = std::atof(argv[2]);
   const double seed = std::atof(argv[3]);
   
   auto start = std::chrono::steady_clock::now();
  
  
  Eigen::ArrayXXi M = Eigen::ArrayXXi::Zero(L,L);
  fill_array(M, L, p, seed);
 
  
   
  

  Eigen::ArrayXXi F = Eigen::ArrayXXi::Zero(L, L) ;
  F = clouster_matrix(M, L);


  Eigen::ArrayXXi G = Eigen::ArrayXXi::Zero(L, L) ;

  G = index_matrix(F, L);
  F.resize(0,0);

  

  /* std::cout << "La matriz original es" << std::endl << M << std::endl
   << "La matriz de percolación indexada es" << std::endl
   << G << std::endl
   << "¿EL sistema percola?" << std::endl
   << Percolation(G, L) << std::endl
   <<"EL tamaño del clouster percolante más grande es"<<std::endl;
   <<Size_clouster(G, L)<<std::endl; */
   
   std::cout << Percolation(G, L) << "\n" << Size_clouster(G, L) << "\n";
   
   auto end = std::chrono::steady_clock::now();
   std::chrono::duration<double> elapsed_seconds = end-start;
   std::cout << "Tiempo de computo: "<< elapsed_seconds.count() << " segundos"<<std::endl;


  return 0;
}
