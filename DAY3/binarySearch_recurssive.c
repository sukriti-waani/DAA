#include <stdio.h>

int binarySearch(int arr[], int left, int right, int key)
{
  if (left > right)
  {
    return -1;
  }

  int mid = left + (right - left) / 2;

  if (arr[mid] == key)
  {
    return mid;
  }
  else if (arr[mid] > key)
  {
    return binarySearch(arr, mid + 1, right, key);
  }
  else
  {
    return binarySearch(arr, left, mid - 1, key);
  }
}

int main()
{
  int n;
  printf("Enter the number of elements in the array: ");
  scanf("%d", &n);

  int arr[n];
  printf("Enter the elements of the array: ");
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }

  int key;
  printf("Enter the key to search: ");
  scanf("%d", &key);

  int res = binarySearch(arr, 0, n - 1, key);

  if (res != -1)
    printf("Element found at index %d\n", res);
  else
    printf("Element not found\n");

  return 0;
}