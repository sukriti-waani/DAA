/*      Aim of the program: Write a menu driven program to sort list of array elements using Merge Sort technique and calculate the execution time only to sort the elements.  Count the number of comparisons.
Note#
  ●To calculate execution time, assume that single program is under execution in the CPU.
  ●Number of elements in each input file should vary from 300 to 500 entries.
  ●For ascending order: Read data from a file “inAsce.dat” having content 10 20 30 40….., Store the result in “outMergeAsce.dat”.
  ●For descending order: Read data from a file “inDesc.dat” having content 90 80 70 60…., Store the result in “outMergeDesc.dat”.
  ●For random data: Read data from a file “inRand.dat” having content 55 66 33 11 44 …, Store the result in “outMergeRand.dat”

Sample Input from file:
MAIN MENU (MERGE SORT)
1. Ascending Data
2. Descending Data
3. Random Data
4. ERROR (EXIT)

Output:
Enter option: 1
Before Sorting: Content of the input file
After Sorting: Content of the output file
Number of Comparisons: Actual
Execution Time: lapse time in nanosecond
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000

long long comparisons = 0; // Global counter for comparisons

void merge(int arr[], int l, int m, int r)
{
  int n1 = m - l + 1;
  int n2 = r - m;

  int L[n1], R[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[l + i];
  for (int j = 0; j < n2; j++)
    R[j] = arr[m + 1 + j];

  int i = 0, j = 0, k = l;

  while (i < n1 && j < n2)
  {
    comparisons++;
    if (L[i] <= R[j])
      arr[k++] = L[i++];
    else
      arr[k++] = R[j++];
  }

  while (i < n1)
    arr[k++] = L[i++];
  while (j < n2)
    arr[k++] = R[j++];
}

// MergeSort function
void mergeSort(int arr[], int l, int r)
{
  if (l < r)
  {
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
  }
}

// Function to read numbers from file
int readFile(const char *filename, int arr[])
{
  FILE *fp = fopen(filename, "r");
  if (!fp)
  {
    printf("Error opening file %s\n", filename);
    return 0;
  }
  int n = 0;
  while (fscanf(fp, "%d", &arr[n]) != EOF && n < MAX)
    n++;
  fclose(fp);
  return n;
}

// Function to write numbers to file
void writeFile(const char *filename, int arr[], int n)
{
  FILE *fp = fopen(filename, "w");
  for (int i = 0; i < n; i++)
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
  clock_t start, end;
  long long elapsed;

  while (1)
  {
    printf("\nMAIN MENU (MERGE SORT)\n");
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

    char inFile[50], outFile[50];
    if (choice == 1)
    {
      sprintf(inFile, "inAsce.dat");
      sprintf(outFile, "outMergeAsce.dat");
    }
    else if (choice == 2)
    {
      sprintf(inFile, "inDesc.dat");
      sprintf(outFile, "outMergeDesc.dat");
    }
    else if (choice == 3)
    {
      sprintf(inFile, "inRand.dat");
      sprintf(outFile, "outMergeRand.dat");
    }
    else
    {
      printf("Invalid choice! Try again.\n");
      continue;
    }

    // Read input
    n = readFile(inFile, arr);
    if (n == 0)
      continue;

    printf("\nBefore Sorting: \n");
    printArray(arr, n);

    comparisons = 0; // reset counter

    // Time calculation
    start = clock();
    mergeSort(arr, 0, n - 1);
    end = clock();

    elapsed = ((long long)(end - start) * 1000000000) / CLOCKS_PER_SEC;

    printf("\nAfter Sorting: \n");
    printArray(arr, n);

    printf("\nNumber of Comparisons: %lld", comparisons);
    printf("\nExecution Time: %lld nanoseconds\n", elapsed);

    // Write output
    writeFile(outFile, arr, n);
  }

  return 0;
}