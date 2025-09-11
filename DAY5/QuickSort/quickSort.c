/*      Aim of the program: Write a menu driven program to sort a list of elements in ascending order using Quick Sort technique. Each choice for the input data has its own disc file.  A separate output file can be used for sorted elements. After sorting display the content of the output file along with number of comparisons. Based on the partitioning position for each recursive call, conclude the input scenario is either best-case partitioning or worst-case partitioning.
Note#
  ●The worst-case behavior for quicksort occurs when the partitioning routine produces one subproblem with n-1 elements and one with 0 elements. The best-case behaviour occurred in most even possible split, PARTITION produces two subproblems, each of size no more than n/2.
  ●Number of elements in each input file should vary from 300 to 500 entries.
  ●For ascending order: Read data from a file “inAsce.dat” having content 10 20 30 40….., Store the result in “outQuickAsce.dat”.
  ●For descending order: Read data from a file “inDesc.dat” having content 90 80 70 60…., Store the result in “outQuickDesc.dat”.
  ●For random data: Read data from a file “inRand.dat” having content 55 66 33 11 44 …, Store the result in “outQuickRand.dat”

Sample Input from file:
MAIN MENU (QUICK SORT)
1. Ascending Data
2. Descending Data
3. Random Data
4. ERROR (EXIT)

Output:
Enter option: 1
Before Sorting: Content of the input file
After Sorting: Content of the output file
Number of Comparisons: Actual
Scenario: Best or Worst-case
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

long long comparisons = 0; // Global counter for comparisons

// Function to swap two elements
void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Partition function
int partition(int arr[], int p, int r)
{
  int pivot = arr[r];
  int i = p - 1;

  for (int j = p; j < r; j++)
  {
    comparisons++;
    if (arr[j] <= pivot)
    {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[r]);
  return i + 1;
}

// QuickSort function
void quickSort(int arr[], int p, int r)
{
  if (p < r)
  {
    int q = partition(arr, p, r);
    quickSort(arr, p, q - 1);
    quickSort(arr, q + 1, r);
  }
}

// Function to read numbers from a file into array
int readFile(const char *filename, int arr[])
{
  FILE *fp = fopen(filename, "r"); // Open file in read mode
  if (!fp)                         // If file could not be opened
  {
    printf("Error opening file %s\n", filename);
    return 0;
  }
  int n = 0;
  // Read integers from file until EOF(End Of File) or MAX limit is reached
  while (fscanf(fp, "%d", &arr[n]) != EOF && n < MAX)
    n++;
  fclose(fp); // Close the file
  return n;   // Return number of elements read
}

// Function to write sorted numbers into output file
void writeFile(const char *filename, int arr[], int n)
{
  FILE *fp = fopen(filename, "w"); // Open file in write mode
  if (!fp)                         // If file could not be opened
  {
    printf("Error opening output file %s\n", filename);
    return;
  }
  for (int i = 0; i < n; i++) // Write all elements into file
    fprintf(fp, "%d ", arr[i]);
  fclose(fp);
}

// Function to print array
void printArray(int arr[], int n)
{
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

int main()
{
  int choice, n;
  int arr[MAX];

  while (1)
  {
    printf("\nMAIN MENU (QUICK SORT)\n");
    printf("1. Ascending Data\n");
    printf("2. Descending Data\n");
    printf("3. Random Data\n");
    printf("4. ERROR (EXIT)\n");
    printf("Enter option: ");
    scanf("%d", &choice);

    if (choice == 4)
    {
      printf("Exiting...\n");
      break;
    }

    char inFile[100], outFile[100];
    if (choice == 1)
    {
      sprintf(inFile, "inAsce.dat");
      sprintf(outFile, "outQuickAsce.dat");
    }
    else if (choice == 2)
    {
      sprintf(inFile, "inDesc.dat");
      sprintf(outFile, "outQuickDesc.dat");
    }
    else if (choice == 3)
    {
      sprintf(inFile, "inRand.dat");
      sprintf(outFile, "outQuickRand.dat");
    }
    else
    {
      printf("Invalid choice! Try again.\n");
      continue;
    }

    // Read input from file
    n = readFile(inFile, arr);
    if (n == 0)
      continue;

    printf("\nBefore Sorting: \n");
    printArray(arr, n);

    comparisons = 0; // reset counter

    // Perform Quick Sort
    quickSort(arr, 0, n - 1);

    printf("\nAfter Sorting: \n");
    printArray(arr, n);

    printf("\nNumber of Comparisons: %lld\n", comparisons);

    // Write output to file
    writeFile(outFile, arr, n);
  }

  return 0;
}
