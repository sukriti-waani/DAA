/*   Write a C program to find the GCD (Greatest Common Divisor) of two numbers using recursion.
The program should be able to handle multiple pairs of numbers and display the GCD for each pair.

Input:
Enter number of pairs: 3
Enter 3 pairs of numbers:
8 12
20 45
30 80

Output:
The GCD of 8 and 12 is 4
The GCD of 20 and 45 is 5
The GCD of 30 and 80 is 10
*/

#include <stdio.h>

int gcd(int a, int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

int main()
{
  int n;

  printf("Enter number of pairs: ");
  scanf("%d", &n);

  int a[n], b[n];
  printf("Enter %d pairs of numbers:\n", n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d %d", &a[i], &b[i]);
  }

  printf("\nThe GCDs are:\n");
  for (int i = 0; i < n; i++)
  {
    int result = gcd(a[i], b[i]);
    printf("The GCD of %d and %d is %d\n", a[i], b[i], result);
  }

  return 0;
}
