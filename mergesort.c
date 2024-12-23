#include <stdio.h>

void mergeSort(int unsortedArray[], int size);

int main(void)
{
    int SIZE;
    scanf("%d", &SIZE);
    int arr[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, SIZE);

    for (int i = 0; i < SIZE; i++)
    {
        printf("%i. element is : %i\n", i + 1, arr[i]);
    }
}

void mergeSort(int unsortedArray[], int size)
{
    if (size > 1)
    {
        int newLeftArray[size / 2], newRightArray[size - size / 2];
        for (int i = 0; i < size / 2; i++)
        {
            newLeftArray[i] = unsortedArray[i];
        }

        for (int i = size / 2; i < size; i++)
        {
            newRightArray[i - size / 2] = unsortedArray[i];
        }
        mergeSort(newLeftArray, size / 2);
        mergeSort(newRightArray, size - size / 2);

        int tempArray[size];
        int indLeft = 0, indRight = 0;
        int i, leftPass = 0, rightPass = 0;
        for (i = 0; i < size; i++)
        {
            if (indLeft >= size / 2)
            {
                leftPass = 1;
                break;
            }
            else if (indRight >= size - size / 2)
            {
                rightPass = 1;
                break;
            }
            if (newLeftArray[indLeft] < newRightArray[indRight])
            {
                tempArray[i] = newLeftArray[indLeft];
                indLeft++;
            }
            else
            {
                tempArray[i] = newRightArray[indRight];
                indRight++;
            }
        }
        if (leftPass)
        {
            for (int j = i; j < size && indRight < size - size / 2; j++)
            {
                tempArray[j] = newRightArray[indRight];
                indRight++;
            }
        }
        else if (rightPass)
        {
            for (int j = i; j < size && indLeft < size / 2; j++)
            {
                tempArray[j] = newLeftArray[indLeft];
                indLeft++;
            }
        }
        for (i = 0; i < size; i++)
        {
            unsortedArray[i] = tempArray[i];
        }
    }
    else
    {
        return;
    }
}
