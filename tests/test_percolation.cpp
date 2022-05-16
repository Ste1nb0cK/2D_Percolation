#include<Eigen/Eigen>
#include "clouster_matrix.hpp"
#include "percolation.hpp"
#include "index_matrix.hpp"
#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

TEST_CASE("Percolation test", "[Percolation]"){

  /*Matrices nulas (P=0)*/
  /////////////////////////////////////////////////////////////////////////////// 
  Eigen::ArrayXXi M1 = Eigen::ArrayXXi::Zero(10, 10);
  Eigen::ArrayXXi M2 = Eigen::ArrayXXi::Zero(50, 50);
  Eigen::ArrayXXi M3 = Eigen::ArrayXXi::Zero(100, 100);

  Eigen::ArrayXXi A1 = index_matrix(M1, 10);
  Eigen::ArrayXXi A2 = index_matrix(M2, 50);
  Eigen::ArrayXXi A3 = index_matrix(M3, 100);

  REQUIRE(Percolation(A1, 10)==0);
  REQUIRE(Percolation(A2, 50)==0);
  REQUIRE(Percolation(A3, 100)==0);
  
  /*Matrices de unos (P=1)*/
  ///////////////////////////////////////////////////////////////////////////////

  Eigen::ArrayXXi N1 = Eigen::ArrayXXi::Ones(10, 10);
  Eigen::ArrayXXi N2 = Eigen::ArrayXXi::Ones(50, 50);
  Eigen::ArrayXXi N3 = Eigen::ArrayXXi::Ones(100, 100);



  Eigen::ArrayXXi B1 = index_matrix(N1, 10);
  Eigen::ArrayXXi B2 = index_matrix(N2, 50);
  Eigen::ArrayXXi B3 = index_matrix(N3, 100);
  

  REQUIRE(Percolation(B1, 10)==1);
  REQUIRE(Percolation(B2, 50)==1);
  REQUIRE(Percolation(B3, 100)==1);


  /*Matriz de dos clousters percolantes horizontales de distinto tamaño con una isla*/
  /////////////////////////////////////////////////////////////////////////////
  Eigen::ArrayXXi P1= Eigen::ArrayXXi::Zero(30, 30);
  for(int ii=0; ii<30; ++ii){
    for(int jj =0; jj<30; ++jj){

      if((ii==3 || ii==7 || ii==8) || (ii==25 && jj==25)){ P1(ii, jj)=1;} else {P1(ii, jj)=0;}
      
    }
  }

  Eigen::ArrayXXi B4 = clouster_matrix(P1, 30);
  Eigen::ArrayXXi B5 = index_matrix(B4, 30);

  REQUIRE(Percolation(B5, 30)==1);





}
