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
