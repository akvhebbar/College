// Write a c program to perform binary search
#include <stdio.h>
int main()
{
    int n, i, a[100], low, high, mid, ele, pos = -1;
    printf("Enter the number of elements in the array ");
    scanf("%d", &n);
    printf("Enter the array elements in the ascending order \n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("\nEnter the element to be searched ");
    scanf("%d", &ele);
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (ele == a[mid])
        {
            pos = mid;
            break;
        }
        else if (ele < a[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    if (pos == -1)
        printf("%d is not found", ele);
    else
        printf("%d is found at the position %d", ele, pos + 1);
    return 0;
}
