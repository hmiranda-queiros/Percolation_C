/**
 * @file image_generator.h
 *
 * @brief Functions to generate a ppm image of a grid.
 *
 * @author Hugo MIRANDA
 *
 * This are functions to generate a ppm image of a grid.
 * The API of image_generator.h is defined as follows:
 *
 * - a function to generate a ppm image of a grid from a text file.
 * - a function to generate a ppm image of a grid from the Monte-Carlo simulation.
 */


#ifndef IMAGE_GENERATOR_H_INCLUDED
#define IMAGE_GENERATOR_H_INCLUDED

#include <stdbool.h>
#include "grid.h"

/**
 * @brief Generates a ppm image of a grid from a text file.
 *
 * @param argc
 * @param argv  a string containing the name of the text file.
 * @param p_struct_grid  a pointer to a Grid structure.
 *
 * @return an int corresponding to the success of the function.
 */
int image_generator(int argc, char *argv[], Grid* p_struct_grid);

/**
 * @brief Generates a ppm image of a grid from the Monte-Carlo simulation.
 *
 * @param p_struct_grid  a pointer to a Grid structure.
 * @param nb_simu  the number of the simulation of this grid.
 * @param seed  the seed used to initialize rand.
 *
 * @return an int corresponding to the success of the function.
 */
int image_generator_monte_carlo (Grid* p_struct_grid, int nb_simu, int seed);


#endif // IMAGE_GENERATOR_H_INCLUDED
