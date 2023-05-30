//Sencond Program

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* arrayInitialisation(int* arrayElements);
int meniu(int n);
void displayElementsArray(int arrayElements, int *array);
void freeArray(int** array);
int linearSearch(int *arr, int n, int x);
int binarySearch(int *arr, int n, int x);



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
            int searchElement;
            printf("Insert the searched element from array: ");
            scanf("%d", &searchElement);
            clock_t start = clock();
            int result = linearSearch(array, n, searchElement);
            if(result == -1)
                printf("Element not found in array.\n");
            else 
                printf("Element found at index %d.\n", result);
            clock_t end = clock();
            time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
            printf("Time taken by linear search: %f seconds\n", time_taken);
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
            int searchElement;
            printf("Insert the searched element from array: ");
            scanf("%d", &searchElement);
            clock_t start = clock();
            int result = binarySearch(array, n, searchElement);
            if(result == -1)
                printf("Element not found in array.\n");
            else
                printf("Element found at index %d.\n", result);  
            clock_t end = clock();
            time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
            printf("Time taken by binary search: %f seconds\n", time_taken);
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

int binarySearch(int *arr, int n, int x) 
{
    int start = 0;
    int end = n - 1;
    while(start <= end) 
    {
        int mid = (start + end) / 2;
        if(arr[mid] == x)
            return mid; // element found, return index
        else if(arr[mid] > x)
            end = mid - 1; // search in left half
        else 
            start = mid + 1; // search in right half
    }
    return -1; // element not found
}

int linearSearch(int *arr, int n, int x) 
{
    int i;
    for(i = 0; i < n; i++) 
    {
        if(arr[i] == x) 
            return i; // element found, return index
    }
    return -1; // element not found
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
    printf("4 - Searching the array using linear search and displaying the time it took to execute the sorting\n");
    printf("5 - Searching the array using binary search and displaying the time it took to execute the sorting\n");
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

