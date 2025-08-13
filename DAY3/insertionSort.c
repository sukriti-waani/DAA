/*      Write a C program to:
Sort the array in ascending order using the Insertion Sort algorithm.
While sorting, count and display the total number of comparisons made between elements.

Example Input/Output:
Enter the number of elements: 5
Enter the elements: 5 2 9 1 6
Sorted array: 1 2 5 6 9
Number of comparisons made during sorting: 7
*/

#include <stdio.h>

void insertionSort(int arr[], int n, int *comparisons)
{
  for (int i = 1; i < n; i++)
  {
    int key = arr[i];
    int j = i - 1;

    // Each time we compare arr[j] > key, count it
    while (j >= 0)
    {
      (*comparisons)++; // Count the comparison
      if (arr[j] > key)
      {
        arr[j + 1] = arr[j];
        j--;
      }
      else
      {
        break; // No more shifting needed
      }
    }
    arr[j + 1] = key;
  }
}

int main()
{
  int n;
  printf("Enter the number of elements: ");
  scanf("%d", &n);

  int arr[n];
  printf("Enter the elements: ");
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }

  int comparisons = 0;
  insertionSort(arr, n, &comparisons);

  printf("Sorted array: ");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");

  printf("Number of comparisons made during sorting: %d\n", comparisons);

  return 0;
}
