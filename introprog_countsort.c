#include <stddef.h>
#include "arrayio.h"
#include <stdio.h>
#include <stdlib.h>

int MAX_LAENGE = 1000;
int MAX_VALUE = 100;

void count_sort_calculate_counts(int input_array[], int len, int count_array[])
{
    int i, j;
    for (i = 0; i <= MAX_VALUE; i++) { count_array[i] = 0; }
    for (j = 0; j < len; j++) {
        count_array[input_array[j]] = count_array[input_array[j]] + 1;
    }
}

void count_sort_write_output_array(int output_array[], int len,
                                   int count_array[])
{
    int k = 0;
    int i, j;
    for (i = 0; i <= len; i++) {
        for (j = 1; j <= count_array[i]; j++) {
            output_array[k] = i;
            printf("%d ",i);
            k = k + 1;
        }
    }
}


int main(int argc, char *argv[])
{

    if (argc < 2) {
        printf("Aufruf: %s <Dateiname>\n", argv[0]);
        printf("Beispiel: %s zahlen.txt\n", argv[0]);
        exit(1);
    }

    char *filename = argv[1];

    int input_array[MAX_LAENGE];
    int len = read_array_from_file(input_array, MAX_LAENGE, filename);

    int count_array[MAX_LAENGE];
    printf("Unsortiertes Array:");
    print_array(input_array, len);
    count_sort_calculate_counts(input_array, len, count_array);


    int output_array[MAX_LAENGE];
    printf("Sortiertes Array:");
    count_sort_write_output_array(output_array, MAX_VALUE, count_array);
    return 0;
}
