/**
 * @file percolate_dfs.h
 *
 * @brief Functions to test if a grid percolates or not by using the depth-first-search naive algorithm.
 *
 * @author Hugo MIRANDA
 *
 * This are functions to generate a ppm image of a grid.
 * The API of percolate_dfs.h is defined as follows:
 *
 * - a function to test the depth-first-search naive algorithm on a grid.
 * - a function corresponding to the depth-first-search naive algorithm programmed recursively.
 */


#ifndef PERCOLATE_DFS_H_INCLUDED
#define PERCOLATE_DFS_H_INCLUDED

#include <stdbool.h>
#include "grid.h"

/**
 * @brief Tests the depth-first-search naive algorithm on a grid.
 *
 * @param test  a Grid structure.
 *
 * @return a bool saying if the grid percolates or not.
 */
bool test_percolate_dfs (Grid test);

/**
 * @brief The depth-first-search naive algorithm programmed recursively.
 *
 * @param test  a Grid structure.
 * @param p_g  a pointer to the grid.
 * @param i  the row of the cell to test
 * @param j  the column of the cell to test
 *
 * @return a bool saying if the grid percolates or not.
 */
bool percolate_dfs (Grid test, Cell* p_g, int i, int j);


#endif // PERCOLATE_DFS_H_INCLUDED
