#include <stdio.h>

int binarySearch(int arr[], int n, int key, int *comparisons)
{
  int left = 0, right = n - 1;

  while (left <= right)
  {
    (*comparisons)++; // Count each mid-element comparison

    int mid = (right - left) / 2;

    if (arr[mid] == key)
    {
      return mid;
    }
    else if (arr[mid] < key)
    {
      left = mid + 1;
    }
    else
    {
      right = mid - 1;
    }
  }
  return -1;
}

int main()
{
  int n;
  printf("Enter the number of elements in the array: ");
  scanf("%d", &n);

  int arr[n];
  printf("Enter the elements of the array (sorted): ");
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }

  int key;
  printf("Enter the key to search: ");
  scanf("%d", &key);

  int comparisons = 0;
  int res = binarySearch(arr, n, key, &comparisons);

  if (res != -1)
    printf("Element found at index %d\n", res);
  else
    printf("Element not found\n");

  printf("Number of comparisons made: %d\n", comparisons);

  return 0;
}
