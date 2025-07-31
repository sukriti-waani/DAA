/*  Aim of the program: Given an array arr[] of size N, find the prefix sum of the array. A prefix sum array is another array prefixSum[] of the same size, such that the value of prefixSum[i] is arr[0] + arr[1] + arr[2] . . . arr[i].

Input Array: 	3 	4 	5 	1	 2
Output Array: 	3 	7 	12 	13 	15
*/

#include <stdio.h>

void PrefixSum(int a[], int pre[], int n)
{
  pre[0] = a[0];
  for (int i = 1; i < n; i++)
  {
    pre[i] = pre[i - 1] + a[i];
  }
}

int main()
{
  int n;
  printf("Enter size of array: ");
  scanf("%d", &n);

  int arr[n], pre[n];

  printf("Enter %d elements: ", n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }

  PrefixSum(arr, pre, n);

  printf("Prefix Sum Array: ");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", pre[i]);
  }
  printf("\n");

  return 0;
}
