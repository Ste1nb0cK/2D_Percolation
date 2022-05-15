#pragma once
#include "hood.hpp"
#include "Eigen/Eigen"

Eigen::ArrayXXi Path(const Eigen::ArrayXXi &I, int L, int scanning, int target, int New);
