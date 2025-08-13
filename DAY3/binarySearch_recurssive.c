/*      Aim of the program: Write a program to implement Binary Search to give the position of leftmost appearance of the element in the array being searched. Display the number of comparisons made while searching.

Input:
Enter size of array: 10
Enter elements of the array: 2 3 7 7 7 11 12 12 20 50
Enter the key to be searched: 7
Output:
7 found at index position 2
Number of comparisons: 3
*/

#include <stdio.h>

// Recursive Binary Search for leftmost occurrence
int binarySearchLeftmost(int arr[], int left, int right, int key, int *comparisons)
{
  if (left > right)
  {
    return -1;
  }

  (*comparisons)++; // Count each comparison with arr[mid]
  int mid = left + (right - left) / 2;

  if (arr[mid] == key)
  {
    // Even if found, check if it's the first occurrence
    int leftIndex = binarySearchLeftmost(arr, left, mid - 1, key, comparisons);

    if (leftIndex != -1)
    {
      return leftIndex; // Found an earlier occurrence
    }
    else
    {
      return mid; // This is the first occurrence
    }
  }
  else if (arr[mid] > key)
  {
    return binarySearchLeftmost(arr, left, mid - 1, key, comparisons);
  }
  else
  {
    return binarySearchLeftmost(arr, mid + 1, right, key, comparisons);
  }
}

int main()
{
  int n;
  printf("Enter size of array: ");
  scanf("%d", &n);

  int arr[n];
  printf("Enter elements of the array (sorted): ");
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }

  int key;
  printf("Enter the key to be searched: ");
  scanf("%d", &key);

  int comparisons = 0;
  int res = binarySearchLeftmost(arr, 0, n - 1, key, &comparisons);

  if (res != -1)
    printf("%d found at index position %d\n", key, res);
  else
    printf("Element not found\n");

  printf("Number of comparisons: %d\n", comparisons);

  return 0;
}
