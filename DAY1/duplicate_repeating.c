#include <stdio.h>

int countDuplicates(int arr[], int n)
{
  int dupCount = 0;

  for (int i = 0; i < n; i++)
  {
    int count = 1;
    int isCounted = 0;

    for (int k = 0; k < i; k++)
    {
      if (arr[i] == arr[k])
      {
        isCounted = 1;
        break;
      }
    }
    if (isCounted)
      continue;

    for (int j = i + 1; j < n; j++)
    {
      if (arr[i] == arr[j])
      {
        count++;
      }
    }

    if (count > 1)
    {
      dupCount++;
    }
  }

  return dupCount;
}

int mostRepeating(int arr[], int n)
{
  int count = 0;
  int maxCount = 0;
  int maxEle = arr[0];

  for (int i = 0; i < n; i++)
  {
    int count = 1;
    for (int j = i + 1; j < n; j++)
    {
      if (arr[i] == arr[j])
      {
        count++;
      }
    }
    if (count > maxCount)
    {
      maxCount = count;
      maxEle = arr[i];
    }
  }

  return maxEle;
}

int main()
{
  int arr[100], n;

  printf("Enter the number of elements in the array: ");
  scanf("%d", &n);

  printf("Enter the elements of the array: ");
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }

  int dupCount = countDuplicates(arr, n);
  printf("Total number of duplicate values = %d\n", dupCount);

  int mostRep = mostRepeating(arr, n);
  printf("Most repeating element = %d\n", mostRep);

  return 0;
}
