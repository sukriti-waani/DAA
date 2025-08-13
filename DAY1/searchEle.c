/*  Write a C program to perform a linear search on an array to find a given element and count the maximum number of comparisons made during the search.

Input:
Enter the number of elements in the array: 6
Enter the elements of the array: 5 10 15 20 25 30
Enter the element you want to search: 20

Output:
Maximum number of comparisons is: 4
*/

#include <stdio.h>

int search(int arr[], int n, int x)
{
  int comp = 0;

  for (int i = 0; i < n; i++)
  {
    comp++;
    if (arr[i] == x)
    {
      return comp;
    }
  }
  return comp;
}

int main()
{
  int arr[100], n, element;

  printf("Enter the number of elements in the array: ");
  scanf("%d", &n);

  printf("Enter the elements of the array: ");
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }

  printf("\nEnter the element you want to search: ");
  scanf("%d", &element);

  int maxComparisons = search(arr, n, element);

  printf("Maximum number of comparisons is: %d\n", maxComparisons);

  return 0;
}
