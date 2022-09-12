/**
 * @file union_find.h
 *
 * @brief Simple definition of Cell_uf and Grid_uf.
 *
 * @author Hugo MIRANDA
 *
 * This is a simple definition of Cell_uf and Grid_uf and the functions that allow to create and find and merge them.
 * The API of union_find.h is defined as follows:
 *
 * - a function to create an union-find structure.
 * - a function to find the subset to which an cells belongs.
 * - a function to merge the subsets to which two cells belong.
 */


#ifndef UNION_FIND_H_INCLUDED
#define UNION_FIND_H_INCLUDED

#include <stdbool.h>

/**
 * @brief An alias to the structure representing the cells of a grid.
 */
typedef struct Cell_uf Cell_uf;

/**
 * @brief An alias to the structure representing the identity of a grid.
 */
typedef struct Grid_uf Grid_uf;

/**
 * @brief The structure representing the cells of a grid.
 */
struct Cell_uf {
	/** The rank of the subset of this cell */
    int rank_uf;
	/** The memory address of the representative of the subset of this cell */
    Cell_uf* p_cell_uf;
    /** The bool to know if the cell is opened or not */
    bool open;

};

/**
 * @brief The structure representing the identity of a grid.
 */
struct Grid_uf {
    /** The height of the grid */
    int height;
    /** The width of the grid */
    int width;
    /** The memory address of the grid */
    Cell_uf* p_grid_uf;
};

/**
 * @brief Creates an union-find structure.
 *
 * @param nb an int corresponding to the number of cells to create.
 *
 * @return The memory address of the grid.
 */
Cell_uf* create_uf(int nb);

/**
 * @brief Finds the subset to which a cell belongs.
 *
 * @param e the memory address of a cell.
 * 
 * @return The memory address of the representative of the subset of this cell.
 */
Cell_uf* find_uf(Cell_uf* e);

/**
 * @brief Merges the subsets to which two cells belong.
 *
 * @param e1 the memory address of a cell.
 * @param e2 the memory address of a cell.
 * 
 * @post After the call, the two subsets are merged.
 */
void merge_uf(Cell_uf* e1, Cell_uf* e2);


#endif // UNION_FIND_H_INCLUDED
