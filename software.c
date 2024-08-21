#include <stdio.h>
#include <stdlib.h>


int read_data(const char *filename, double **data)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return -1;
    }
    int count = 0;
    double value;
    while (fscanf(file, "%lf", &value) != EOF)
    {
        count++;
    }
    rewind(file);

    *data = (double *)malloc(count * sizeof(double));
    for (int i = 0; i < count; i++)
    {
        fscanf(file, "%lf", &(*data)[i]);
    }

    fclose(file);
    return count;
}

// Function to find and print maxima and minima
void find_peaks(double *data, int length)
{
    printf("Maxima Peaks (Index):\n");
    for (int i = 1; i < length - 1; i++)
    {
        if (data[i] > data[i - 1] && data[i] > data[i + 1])
        {
            printf("%d\n", i);
        }
    }

    printf("\nMinima Peaks (Index):\n");
    for (int i = 1; i < length - 1; i++)
    {
        if (data[i] < data[i - 1] && data[i] < data[i + 1])
        {
            printf("%d\n", i);
        }
    }
}

int main()
{
    double *data1;
    double *data2;
    int length1, length2;

    // Reading Data Set 1
    length1 = read_data("Data_1.txt", &data1);
    if (length1 > 0)
    {
        printf("Data Set 1:\n");
        find_peaks(data1, length1);
    }

    // Reading Data Set 2
    length2 = read_data("Data_2.txt", &data2);
    if (length2 > 0)
    {
        printf("\nData Set 2:\n");
        find_peaks(data2, length2);
    }

    // Free allocated memory
    free(data1);
    free(data2);

    return 0;
}
