#pragma once
#include <Eigen/Dense>
//This functions interact with only one element of the matrix

bool check_up_neighbor(int n, int m,
                       Eigen::Array<bool, Eigen::Dynamic, Eigen::Dynamic> A);
/* check_up_neighbor( int n, int m,
 *                     Eigen::Array<bool, Eigen::Dynamic, Eigen::Dynamic>);
 *DESCRIPTION: Checks if the down neighbor for a determined element of a given
 *            matrix is filled.
 *INPUT: int n. Column coordinate of the element.
 *
 *      int m. Row coordinate of the element.
 *
 *      Eigen::Array<bool, Eigen::Dynamic, Eigen::Dynamic> A. The matrix to
 *      which the element belongs.
 *
 *Output: Returns a bool true in case it is filled, and false if it is not
 *        or there is no down neighbor.
 *
 */
bool check_down_neighbor(int n, int m,
                         Eigen::Array<bool, Eigen::Dynamic, Eigen::Dynamic> A);
/* check_up_neighbor( int n, int m,
 *                    Eigen::Array<bool, Eigen::Dynamic, Eigen::Dynamic>);
 *DESCRIPTION: Checks if the right neighbor for a determined element of a given
 *             matrix is filled.
 *INPUT: int n. Column coordinate of the element.
 *
 *      int m. Row coordinate of the element.
 *
 *      Eigen::Array<bool, Eigen::Dynamic, Eigen::Dynamic> A. The matrix to
 *      which the element belongs.
 *
 *Output: Returns a bool true in case it is filled, and false if it is not
 *        or there is no right neighbor.
 *
 */
bool check_right_neighbor(
    int n, int m, Eigen::Array<bool, Eigen::Dynamic, Eigen::Dynamic> A);
/* check_up_neighbor( int n, int m,
 *                     Eigen::Array<bool, Eigen::Dynamic, Eigen::Dynamic>);
 *DESCRIPTION: Checks if the left neighbor for a determined element of a given
 *              matrix is filled.
 *INPUT: int n. Column coordinate of the element.
 *
 *      int m. Row coordinate of the element.
 *
 *      Eigen::Array<bool, Eigen::Dynamic, Eigen::Dynamic> A. The matrix to
 *      which the element belongs.
 *
 *Output: Returns a bool true in case it is filled, and false if it is not
 *        or there is no right neighbor.
 *
 */
bool check_left_neighbor(int n, int m,
                         Eigen::Array<bool, Eigen::Dynamic, Eigen::Dynamic> A);
/*count_neighbors(int n, int
                         Eigen::Array<bool, Eigen::Dynamic, Eigen::Dynamic> A);
* DESCRIPTION: Determine how many of the neighbors for a determined element of
*              of a given matrix are filled.
*
* INPUT: int n. Column coordinate of the element.
*
*        int m. Row coordinate of the element.
*
*       Eigen::Array<bool, Eigen::Dynamic, Eigen::Dynamic> A. The matrix to
*       which the element belongs.
*
* OUTPUT: int N_nm. Amount of neighbors of A(n,m) that are filled.
*
*/
int count_neighbors(int n, int m,
                    Eigen::Array<bool, Eigen::Dynamic, Eigen::Dynamic> A);
