#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "grid.h"
#include "loader.h"
#include "image_generator.h"

int main(int argc, char *argv[]) {
    Grid test ;

    get_shape(argc, argv, &test.height, &test.width);

    create_pointer_Cell(&test);

    build_struct(argc, argv, test);

    image_generator(argc, argv, &test);

    free_grid(test);

    return 0;

}
