/**
 * @file monte_carlo_dfs.h
 *
 * @brief A function that runs the Monte-Carlo simulation with the depth-first-search naive algorithm.
 *
 * @author Hugo MIRANDA
 *
 * This is a function that runs the Monte-Carlo simulation with the depth-first-search naive algorithm.
 * The API of monte_carlo_dfs.h is defined as follows:
 *
 * - a function that runs the Monte-Carlo simulation with the depth-first-search naive algorithm..
 *
 */


#ifndef MONTE_CARLO_DFS_H_INCLUDED
#define MONTE_CARLO_DFS_H_INCLUDED

#include <stdbool.h>
#include "grid.h"

/**
 * @brief Runs the Monte-Carlo simulation with the depth-first-search naive algorithm.
 *
 * @param p_struct_grid  a pointer to a Grid structure.
 * @param height  the height of the grids.
 * @param width  the width of the grids.
 * @param seed the seed used to initialize rand.
 * @param nb_tot_simu the number total of all the Monte-Carlo simulations that we want.
 *
 */
void monte_carlo (Grid* p_struct_grid, int height, int width, int seed, int nb_tot_simu);

#endif // MONTE_CARLO_DFS_H_INCLUDED
