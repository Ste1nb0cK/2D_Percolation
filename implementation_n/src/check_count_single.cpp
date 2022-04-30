#include "check_count_single.hpp"

bool check_up_neighbor(int n, int m,
                       Eigen::Array<bool, Eigen::Dynamic, Eigen::Dynamic> A) {
  if (n == 0) {
    return 0;
  } else {
    return A(n - 1, m);
  }
}

bool check_down_neighbor(
    int n, int m, Eigen::Array<bool, Eigen::Dynamic, Eigen::Dynamic> A) {
  int L = A.rows();
  if (n == L - 1) {
    return 0;
  } else {
    return A(n + 1, m);
  }
}

bool check_right_neighbor(
    int n, int m, Eigen::Array<bool, Eigen::Dynamic, Eigen::Dynamic> A) {
  int L = A.cols();
  if (m == L - 1) {
    return 0;
  } else {
    return A(n, m + 1);
  }
}

bool check_left_neighbor(
    int n, int m, Eigen::Array<bool, Eigen::Dynamic, Eigen::Dynamic> A) {
  if (m == 0) {
    return 0;
  } else {
    return A(n, m - 1);
  }
}

int count_neighbors(int n, int m,
                    Eigen::Array<bool, Eigen::Dynamic, Eigen::Dynamic> A) {
  int up = check_up_neighbor(n, m, A);
  int down = check_down_neighbor(n, m, A);
  int left = check_left_neighbor(n, m, A);
  int right = check_right_neighbor(n, m, A);
  return up + down + left + right;
}
