#include <stdio.h>

int binsearch(int a[], int key, int low, int high)
{
    int mid;
    if (low > high)
        return -1;
    mid = (low + high) / 2;
    if (key == a[mid])
    {
        return mid;
    }
    else if (key < a[mid])
    {
        binsearch(a, key, low, mid - 1);
    }
    else
    {
        binsearch(a, key, mid + 1, high);
    }
}
void bubblesort(int a[], int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n, i, key, position;
    int low, high;
    printf("\nEnter the total number of elements: ");
    scanf("%d", &n);
    int list[n];
    printf("\nEnter the elements of list: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &list[i]);
    }
    bubblesort(list, n);
    low = 0;
    high = n - 1;
    printf("\nEnter element to be searched: ");
    scanf("%d", &key);
    printf("\nSorted array-\n");
    for (int i = 0; i < n; i++)
    {
        printf(" %d", list[i]);
    }
    position = binsearch(list, key, low, high);
    if (position != -1)
    {
        printf("\nNumber present at position %d", (position + 1));
    }
    else
        printf("\n The number is not present in the list");
    return (0);
}
