#pragma once
#include <Eigen/Dense>
#include<fstream>
#include<iostream>
/*int count_vertical_subcluster_down(
*  int n, int m, Eigen::Array<bool, Eigen::Dynamic, Eigen::Dynamic> A);
*DESCRICPTION: Given a filled element it obtains the vertical down subcluster
*              to which it belong. It starts counting in the element itself
*              and counts downwards.
*INPUT: int n. Row position of the element
*       int m. Column position of the element.
*       Eigen::Dynamic, Eigen::Dynamic> A). Filled matrix to which the element
*                                           belongs.
*OUTPUT: int N, size of the down subcluster.
*/
int count_vertical_subcluster_down(
    int n, int m, Eigen::Array<bool, Eigen::Dynamic, Eigen::Dynamic> A);

void identify_vertical_subclusters(
  Eigen::Array<bool, Eigen::Dynamic, 1> column, std::string filename);
