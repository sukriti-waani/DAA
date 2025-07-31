/*  Aim of the program: Write a program to find out the second smallest and second largest element stored in an array of n integers.
Input: Size of the array is ‘n’ and read ‘n’ number of elements from a disc file.
Output: Second smallest, Second largest
*/

#include <stdio.h>
#include <limits.h>

int secSm(int a[], int n)
{
  int s = INT_MAX;
  int ss = INT_MAX;

  for (int i = 0; i < n; i++)
  {
    if (a[i] < s)
    {
      ss = s;
      s = a[i];
    }
    else
    {
      if (a[i] < ss && a[i] != s)
      {
        ss = a[i];
      }
    }
  }
  return ss;
}

int secLg(int a[], int n)
{
  int l = INT_MIN;
  int sl = INT_MIN;

  for (int i = 0; i < n; i++)
  {
    if (a[i] > l)
    {
      sl = l;
      l = a[i];
    }
    else
    {
      if (a[i] > sl && a[i] != l)
      {
        sl = a[i];
      }
    }
  }

  return sl;
}

int main()
{
  int n;
  int a[100];

  printf("Enter size of array: ");
  scanf("%d", &n);

  printf("Enter %d elements: ", n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }

  int ss = secSm(a, n);
  int sl = secLg(a, n);

  printf("The second smallest element is: %d\n", ss);
  printf("The second largest element is: %d\n", sl);

  return 0;
}
