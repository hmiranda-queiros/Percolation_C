/**
 * @file grid.h
 *
 * @brief Simple definition of Cell and Grid.
 *
 * @author Hugo MIRANDA
 *
 * This is a simple definition of Cell and Grid and the functions that allow to create and print them.
 * The API of grid.h is defined as follows:
 *
 * - a function to create a grid of empty Cells.
 * - a function to print a grid.
 * - a function to deallocate a grid.
 */


#ifndef GRID_H_INCLUDED
#define GRID_H_INCLUDED

#include <stdbool.h>

/**
 * @brief An alias to the structure representing the cells of a grid.
 */
typedef struct Cell Cell;

/**
 * @brief An alias to the structure representing the identity of a grid.
 */
typedef struct Grid Grid;

/**
 * @brief The structure representing the cells of a grid.
 */
struct Cell {
    /** The row of a cell */
    int row;
    /** The column of a cell */
    int column;
    /** The bool to know if the cell is opened or not */
    bool open;
    /** The bool to know if the cell is visited or not */
    bool visited;
    /** The color of the cell : 'W', 'B' or 'R' */
    char color;
};

/**
 * @brief The structure representing the identity of a grid.
 */
struct Grid {
    /** The height of the grid */
    int height;
    /** The width of the grid */
    int width;
    /** The memory address of the grid */
    Cell* p_grid;
};

/**
 * @brief Allocates a memory address for the grid.
 *
 * @param p_struct_grid  a pointer to a Grid structure.
 *
 * @post After the call, the p_grid receives a memory address and so the grid is created.
 */
void create_pointer_Cell(Grid* p_struct_grid);

/**
 * @brief Prints the grid.
 *
 * @param test  a Grid structure.
 *
 * @post After the call, the grid is printed.
 */
void print_grid(Grid test);

/**
 * @brief Deallocates the grid.
 *
 * @param test  a Grid structure.
 *
 * @post After the call, the grid is deallocated.
 */
void free_grid(Grid test);


#endif // GRID_H_INCLUDED
