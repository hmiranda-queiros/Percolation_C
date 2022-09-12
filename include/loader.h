/**
 * @file loader.h
 *
 * @brief Functions to read a text file in order to fill a grid and its corresponding structure.
 *
 * @author Hugo MIRANDA
 *
 * This are functions to read a text file in order to fill a grid and its corresponding structure.
 * The API of loader.h is defined as follows:
 *
 * - a function to read the shape of a grid from a text file.
 * - a function to fill a grid from a text file.
 */


#ifndef LOADER_H_INCLUDED
#define LOADER_H_INCLUDED

#include <stdbool.h>
#include "grid.h"

/**
 * @brief Reads the shape of a grid from a text file and puts it into the Grid structure.
 *
 * @param argc
 * @param argv  a string containing the name of the text file.
 * @param p_height  a pointer to the height of a Grid structure.
 * @param p_width  a pointer to the width of a Grid structure.
 *
 * @return an int corresponding to the success of the function.
 */
int get_shape (int argc, char *argv[], int* p_height, int* p_width);

/**
 * @brief Fills a grid from a text file.
 *
 * @param argc
 * @param argv  a string containing the name of the text file.
 * @param test  a Grid structure.
 *
 * @return an int corresponding to the success of the function.
 */
int build_struct(int argc, char *argv[], Grid test);


#endif // LOADER_H_INCLUDED
