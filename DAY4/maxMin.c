// Write a program to find the minimum and maximum values in an array using Divide and Conquer approach.

#include <stdio.h>

void findMinMax(int arr[], int i, int j, int *min, int *max)
{
  int mid, min1, max1, min2, max2;

  // Only one element
  if (i == j)
  {
    *min = arr[i];
    *max = arr[i];
    return;
  }

  // Two elements
  if (i == j - 1)
  {
    if (arr[i] < arr[j])
    {
      *min = arr[i];
      *max = arr[j];
    }
    else
    {
      *min = arr[j];
      *max = arr[i];
    }
    return;
  }

  // More than two elements
  // Division
  mid = (i + j) / 2;

  // Conquer
  findMinMax(arr, i, mid, &min1, &max1);
  findMinMax(arr, mid + 1, j, &min2, &max2);

  // Combining the results
  if (max1 > max2)
    *max = max1;
  else
    *max = max2;

  if (min1 < min2)
    *min = min1;
  else
    *min = min2;
}

int main()
{
  int n;
  printf("Enter number of elements: ");
  scanf("%d", &n);

  int arr[n];
  printf("Enter elements:\n");
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }

  int min, max;
  findMinMax(arr, 0, n - 1, &min, &max);

  printf("Minimum element: %d\n", min);
  printf("Maximum element: %d\n", max);

  return 0;
}
