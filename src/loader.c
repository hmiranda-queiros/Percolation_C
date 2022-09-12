#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "loader.h"
#include "grid.h"

int get_shape (int argc, char *argv[], int* p_height, int* p_width) {
    // testing if a filename has been given
     if (argc != 2) {
        fprintf(stderr, "You must provide a file name!\n");
        exit(EXIT_FAILURE);
    }

    // open file. The filename is the first argument on the command
    // line, hence stored in argv[1]
    FILE *p_file = NULL;
    
	char my_string[100];
	
    sprintf (my_string, "./data/%s", argv[1]);
    
    p_file = fopen(my_string, "r");

    if (p_file == NULL) {
        fprintf(stderr, "Cannot read file %s!\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // read dimensions on first line
    int sscanf_result = 0;

    char first_line_buffer[100];
    fgets(first_line_buffer, 100, p_file);

    sscanf_result = sscanf(first_line_buffer, "%d %d", p_width, p_height);

    if (sscanf_result != 2) {
        fprintf(stderr, "First line is not syntactically correct!\n");
        exit(EXIT_FAILURE);
    }

    fclose(p_file);

    p_file = NULL;

    return EXIT_SUCCESS;
}


int build_struct(int argc, char *argv[], Grid test) {
    int height = test.height;
    int width = test.width;
    Cell* p_g = test.p_grid;

    FILE *p_file = NULL;

	char my_string[100];
	
    sprintf (my_string, "./data/%s", argv[1]);
    
    p_file = fopen(my_string, "r");
    
    if (p_file == NULL) {
        fprintf(stderr, "Cannot read file %s!\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    char first_line_buffer[100];
    fgets(first_line_buffer, 100, p_file);

    // read following lines
    // line_buffer contains a line and is a correct string
    // width + 2 is needed to get the carriage return symbol
    char line_buffer[width + 2];

    for (int i = 0; i < height; i++) {
        fgets(line_buffer, width + 2, p_file);
        for (int j = 0; j < width; j++){
            p_g[i*width + j].row = i;
            p_g[i*width + j].column = j;
            if (line_buffer[j]=='#') {
                p_g[i*width + j].open = false;
                p_g[i*width + j].visited = true;
                p_g[i*width + j].color = 'B';
            }
            else if (line_buffer[j]=='X') {
                p_g[i*width + j].open = true;
                p_g[i*width + j].visited = true;
                p_g[i*width + j].color = 'R';
            }
            else {
                p_g[i*width + j].open = true;
                p_g[i*width + j].visited = false;
                p_g[i*width + j].color = 'W';
            }

        }

    }

    fclose(p_file);

    p_file = NULL;

    return EXIT_SUCCESS;
}

