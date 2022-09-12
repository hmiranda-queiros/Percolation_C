/**
 * @file monte_carlo_uf.h
 *
 * @brief A function that runs the Monte-Carlo simulation with the union-find structure.
 *
 * @author Hugo MIRANDA
 *
 * This is a function that runs the Monte-Carlo simulation with the union-find structure.
 * The API of monte_carlo_uf.h is defined as follows:
 *
 * - a function that runs the Monte-Carlo simulation with the union-find structure.
 *
 */


#ifndef MONTE_CARLO_UF_H_INCLUDED
#define MONTE_CARLO_UF_H_INCLUDED

#include <stdbool.h>
#include "union_find.h"

/**
 * @brief Runs the Monte-Carlo simulation with the union-find structure.
 *
 * @param p_struct_grid  a pointer to a Grid structure.
 * @param height  the height of the grids.
 * @param width  the width of the grids.
 * @param seed the seed used to initialize rand.
 * @param nb_tot_simu the number total of all the Monte-Carlo simulations that we want.
 *
 */
void monte_carlo_uf(Grid_uf* p_struct_grid, int height, int width, int seed, int nb_tot_simu);

#endif // MONTE_CARLO_UF_H_INCLUDED
