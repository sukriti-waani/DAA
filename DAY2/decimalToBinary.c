/*  Write a program in C to convert the first n decimal numbers entered by the user into their 16-bit binary representation using recursion.
Display the decimal numbers and their equivalent binary numbers as output.

Input:
Enter how many numbers you want to convert: 3
Enter 3 decimal numbers: 30 75 2564

Output:
The binary equivalent of 30 is 0000000000011110
The binary equivalent of 75 is 0000000001001011
The binary equivalent of 2564 is 0000101000000100
*/

#include <stdio.h>

void decToBin(int num, int bin[], int index)
{
  if (index < 0)
    return;
  bin[index] = num % 2;
  decToBin(num / 2, bin, index - 1);
}

int main()
{
  int n;

  printf("Enter how many numbers you want to convert: ");
  scanf("%d", &n);

  int arr[n];
  printf("Enter %d decimal numbers: ", n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }

  printf("\nThe decimal numbers and their equivalent 16-bit binary:\n");
  for (int i = 0; i < n; i++)
  {
    int bin[16] = {0};
    decToBin(arr[i], bin, 15);

    printf("The binary equivalent of %d is ", arr[i]);
    for (int j = 0; j < 16; j++)
    {
      printf("%d", bin[j]);
    }
    printf("\n");
  }

  return 0;
}
