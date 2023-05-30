//First program

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* arrayInitialisation(int* arrayElements);
int meniu(int n);
void displayElementsArray(int arrayElements, int *array);
void freeArray(int** array);
void selectionSort(int *array, int arrayElements);
void quickSort(int arr[], int low, int high);

int main()
{
    char userAnswer;
    int n, m, *array = NULL;
    begin:
    n = meniu(n);
    switch (n)
    {
    case 1:
        array = arrayInitialisation(&m);
    break;

    case 2:
        displayElementsArray(m, array);
    break;

    case 3:
        freeArray(&array);
    break;
    
    case 4:
    {
        double time_taken;   
        if (array == NULL)
            printf("The array is empty!\n");
        else
        {
            clock_t start = clock();
            selectionSort(array, m);
            clock_t end = clock();
            time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
            printf("Time taken by selection sort: %f seconds\n", time_taken);
        }    
        break;
    }

    case 5:
    {
        double time_taken;   
        if (array == NULL)
            printf("The array is empty!\n");
        else
        {
            clock_t start = clock();
            quickSort(array, 0, m - 1);
            printf("After sorting:\n");
            for (int i = 0; i < m; i++)
                printf("%d ", array[i]);
            printf("\n");
            clock_t end = clock();
            time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
            printf("Time taken by quick sort: %f seconds\n", time_taken);
        }
        break;
    }

    default:
        break;
    }

    printf("\nOther option:(y/n): ");
    scanf(" %c", &userAnswer);
    if (userAnswer == 'y')
    {
        // system("cls");
        goto begin;
    }
    scanf("%d", &n);
    return 0;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high) {
        // Partition the array by selecting a pivot element
        int pivot = arr[high];
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        // Recursively sort the sub-arrays
        quickSort(arr, low, i);
        quickSort(arr, i + 2, high);
    }
}


void selectionSort(int* array, int arrayElements)
{
    int i, j, min, temp;
    for (i = 0; i < arrayElements - 1; i++) 
    {
        min = i;
        for (j = i + 1; j < arrayElements; j++) 
        {
            if (array[j] < array[min])
                min = j;
        }
        // swap array[i] and array[min]
        temp = array[i];
        array[i] = array[min];
        array[min] = temp;
    }
    printf("After sorting:\n");
    for (int i = 0; i < arrayElements; i++)
        printf("%d ", array[i]);
    printf("\n");
}

void freeArray(int** array)
{
    if (*array == NULL)
        printf("The array is already empty!\n");
    else 
    {
        free(*array);
        *array = NULL;
        printf("The array is empty!\n");
    }
}

void displayElementsArray(int arrayElements, int *array)
{
    if (array == NULL)
        printf("The array is empty!\n");
    else
    {
        for (int i = 0; i < arrayElements; i++)
            printf("%d ", array[i]);
        printf("\n");
    }
}

int* arrayInitialisation(int* arrayElements)
{
    printf("Enter the elements of array: ");
    scanf("%d", arrayElements);
    int* array = (int*) malloc(*arrayElements* sizeof(int*));
    return array;
}

int meniu(int n) 
{
    printf ("The menu:\n"); 
    printf("1 - Initializing the array with random numbers\n");
    printf("2 - Displaying the array\n");
    printf("3 - Freeing the memory allocated to the array\n");
    printf("4 - Sorting the array using selection sort and displaying the time it took to execute the sorting\n");
    printf("5 - Sorting the array using quick sort and displaying the time it took to execute the sorting\n");
    printf("Enter the desired option: ");
    scanf ("%d" , &n);
    printf ("\n"); 
    while (n > 5 || n < 1)
    {
        printf ("Insert other option: "); 
        scanf ("%d" , &n);
    }
    return n;
}

