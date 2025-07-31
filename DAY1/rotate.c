/*  Aim of the program: Write a function to ROTATE_RIGHT(p1, p2 ) right an array for first p2 elements by 1 position using EXCHANGE(p, q) function that swaps/exchanges the numbers p & q. Parameter p1 be the starting address of the array and p2 be the number of elements to be rotated.
Input:
Enter an array A of size N (9): 11 22 33 44 55 66 77 88 99
Call the function ROTATE_RIGHT(A, 5)
Output:
Before ROTATE: 	11 22 33 44 55 66 77 88 99
After   ROTATE: 	55 11 22 33 44 66 77 88 99
*/

#include <stdio.h>

void EXCHANGE(int *p, int *q)
{
  int temp = *p;
  *p = *q;
  *q = temp;
}

void ROTATE_RIGHT(int *p1, int p2)
{

  for (int i = p2 - 1; i > 0; i--)
  {
    EXCHANGE(&p1[i], &p1[i - 1]);
  }
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

  int x;
  printf("Enter how many elements to rotate from the start\n");
  scanf("%d", &x);

  ROTATE_RIGHT(arr, x);

  printf("\nAfter ROTATE:\t");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }

  return 0;
}