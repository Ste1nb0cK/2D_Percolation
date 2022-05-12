#include <Eigen/Eigen>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <random>
#include "percolation_routines.h"
#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"


TEST_CASE("Percolation test", "[Percolation]"){

  /*Matrices nulas (P=0)*/
  /////////////////////////////////////////////////////////////////////////////// 
  Eigen::ArrayXXi M1 = Eigen::ArrayXXi::Zero(10, 10);
  Eigen::ArrayXXi M2 = Eigen::ArrayXXi::Zero(100, 100);
  Eigen::ArrayXXi M3 = Eigen::ArrayXXi::Zero(200, 200);
  //////////////////////////////////////////////////////////////////////////////

  /*Matrices unitarias (P=1)*/
  /////////////////////////////////////////////////////////////////////////////// 
  Eigen::ArrayXXi N1 = Eigen::ArrayXXi::Ones(10, 10);
  Eigen::ArrayXXi N2 = Eigen::ArrayXXi::Ones(100, 100);
  Eigen::ArrayXXi N3 = Eigen::ArrayXXi::Ones(200, 200);
  //////////////////////////////////////////////////////////////////////////////

  /*Matrices de prueba*/
  //////////////////////////////////////////////////////////////////////////////
  
  Eigen::ArrayXXi F1;
  for (int ii=0; ii<30; ++ii){
    for (int jj=0; jj<30; ++jj){

      if(ii==5 || ii ==6 || ii == 10){ F1(ii, jj)=1;} else{F1(ii, jj)=0;}


    }
}
  /////////////////////////////////////////////////////////////////////////////// 
  
  Eigen::ArrayXXi F2;
  for (int ii=0; ii<30; ++ii){
    for (int jj=0;jj <30; ++jj){

      if(jj==5 || jj ==6 || jj == 10){ F2(ii, jj)=1;} else{F2(ii, jj)=0;}


    }
}
  /////////////////////////////////////////////////////////////////////////



  Eigen::ArrayXXi F3;
  for (int ii=0; ii<30; ++ii){
    for (int jj=0; jj<30; ++jj){

      if((ii==5 || ii ==6 || jj == 10) || (ii==2 && jj==2)){ F3(ii, jj)=1;} else{F3(ii, jj)=0;}


    }
}

  //////////////////////////////////////////////////////////////////////////






 


  Eigen::ArrayXXi A1 = index_matrix(M1, 10);
  Eigen::ArrayXXi A2 = index_matrix(M2, 100);
  Eigen::ArrayXXi A3 = index_matrix(M3, 200);
  Eigen::ArrayXXi A4 = index_matrix(N1, 10);
  Eigen::ArrayXXi A5 = index_matrix(N2, 100);
  Eigen::ArrayXXi A6 = index_matrix(N3, 200);
  Eigen::ArrayXXi A7 = index_matrix(F1, 30);
  Eigen::ArrayXXi A8 = index_matrix(F2, 30);
  Eigen::ArrayXXi A9 = clouster_matrix(F3, 30);
  Eigen::ArrayXXi A10 = index_matrix(A9, 30);
  

  
  
  
  REQUIRE(Size_clouster(A1, 10)==0);
  A1.resize(0,0);

  REQUIRE(Size_clouster(A2, 100)==0);
  A2.resize(0,0);

  REQUIRE(Size_clouster(A3, 200)==0);
   A3.resize(0,0);

  REQUIRE(Size_clouster(A4, 10)==100);
   A4.resize(0,0);
 

  REQUIRE(Size_clouster(A5, 100)==10000);
   A5.resize(0,0);

  REQUIRE(Size_clouster(A6, 200)==40000);
 A6.resize(0,0);
 
  REQUIRE(Size_clouster(A7, 30)==60);
 A7.resize(0,0);
 
  REQUIRE(Size_clouster(A8, 30)==60);
 A8.resize(0,0);

  REQUIRE(Size_clouster(A10, 30)==60);
  A10.resize(0,0);









}
