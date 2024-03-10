#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    // file variables
    char *file_name;
    FILE *input_file;
    FILE *output_file;
    char BUFF[5000];

    // functionality variables
    int **first_matrix;
    int **second_matrix;
    int **result_matrix;

    int first_matrix_dimensions[2];
    int second_matrix_dimensions[2];

    int opcode;
    char data_type[10];

    time_t time_elapsed;

    int x, y, z;
    char chr = '\0';

    // Read the file name

    if (argc == 2)
    {
        file_name = (char *)calloc(strlen(argv[1]), sizeof(char));
        strcpy(file_name, argv[1]);
    }
    else
    {
        printf("Invalid arguments! Pass the input file.\n");
        exit(0);
    }

    input_file = fopen(file_name, "r");

    if (!input_file)
    {
        printf("Unable to open file for read.\n");
        exit(0);
    }

    // Load the data

    fgets(BUFF, 5000, input_file);
    opcode = atoi(BUFF);

    fgets(BUFF, 5000, input_file);
    memset(data_type, '\0', 10);
    strcpy(data_type, BUFF);

    // Load first matrix

    first_matrix_dimensions[0] = first_matrix_dimensions[1] = 0;

    while (chr != 'x')
    {
        chr = fgetc(input_file);
        if (chr == 'x')
            break;
        first_matrix_dimensions[0] *= 10;
        first_matrix_dimensions[0] += chr - '0';
    }

    while (chr != '\n')
    {
        chr = fgetc(input_file);
        if (chr == '\n')
            break;
        first_matrix_dimensions[1] *= 10;
        first_matrix_dimensions[1] += chr - '0';
    }

    first_matrix = (int **)calloc(first_matrix_dimensions[0], sizeof(int *));

    for (x = 0; x < first_matrix_dimensions[0]; x++)
    {
        first_matrix[x] = (int *)calloc(first_matrix_dimensions[1], sizeof(int));
    }

    for (x = 0; x < first_matrix_dimensions[0]; x++)
    {
        for (y = 0; y < first_matrix_dimensions[1]; y++)
        {
            first_matrix[x][y] = fgetc(input_file) - '0';
            fgetc(input_file);
        }
        fgetc(input_file);
    }

    // Load second matrix

    second_matrix_dimensions[0] = second_matrix_dimensions[1] = 0;

    while (chr != 'x')
    {
        chr = fgetc(input_file);
        if (chr == 'x')
            break;
        second_matrix_dimensions[0] *= 10;
        second_matrix_dimensions[0] += chr - '0';
    }
    
    while (chr != '\n')
    {
        chr = fgetc(input_file);
        if (chr == '\n')
            break;
        second_matrix_dimensions[1] *= 10;
        second_matrix_dimensions[1] += chr - '0';
    }

    second_matrix = (int **)calloc(second_matrix_dimensions[0], sizeof(int *));

    for (x = 0; x < second_matrix_dimensions[0]; x++)
    {
        second_matrix[x] = (int *)calloc(second_matrix_dimensions[1], sizeof(int));
    }

    for (x = 0; x < second_matrix_dimensions[0]; x++)
    {
        for (y = 0; y < second_matrix_dimensions[1]; y++)
        {
            second_matrix[x][y] = fgetc(input_file) - '0';
            fgetc(input_file);
        }
        fgetc(input_file);
    }

    fclose(input_file);

    result_matrix = (int **)calloc(first_matrix_dimensions[0], sizeof(int *));

    for (x = 0; x < first_matrix_dimensions[0]; x++)
    {
        result_matrix[x] = (int *)calloc(second_matrix_dimensions[1], sizeof(int));
    }

    // ---------------------------------------------------- CALCULATIONS ----------------------------------------------------

    time_elapsed = time(NULL);

    // Calculate result

    for (x = 0; x < first_matrix_dimensions[0]; x++)
    {
        for (y = 0; y < second_matrix_dimensions[1]; y++)
        {
            for (z = 0; z < second_matrix_dimensions[0]; z++)
            {
                result_matrix[x][y] += first_matrix[x][z] * second_matrix[z][y];
            }
        }
    }

    time_elapsed = time(NULL) - time_elapsed;

    // Write the result to the file

    output_file = fopen("result.txt", "w");

    // Write datatype
    fprintf(output_file, "%s", data_type);

    // Write dimensions
    fprintf(output_file, "%dx%d\n", first_matrix_dimensions[0], second_matrix_dimensions[1]);

    for (x = 0; x < first_matrix_dimensions[0]; x++)
    {
        for (y = 0; y < second_matrix_dimensions[1]; y++)
        {
            fprintf(output_file, "%d\t", result_matrix[x][y]);
        }
        fprintf(output_file, "\n");
    }

    fclose(output_file);

    printf("Results Written.\n");
    printf("Time taken: %ld seconds.\n", time_elapsed);

    return 0;
}
