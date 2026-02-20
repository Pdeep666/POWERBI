#include <stdio.h>

int main() {
    int arr[5] = {12, 45, 7, 23, 56};
    int *ptr = arr;
    int i, min, max;

    printf("Array Elements:\n");
    for (i = 0; i < 5; i++) {
        printf("%d ", *(ptr + i));
    }

    min = max = *ptr;

    for (i = 1; i < 5; i++) {
        if (*(ptr + i) < min)
            min = *(ptr + i);

        if (*(ptr + i) > max)
            max = *(ptr + i);
    }

    printf("\nMinimum = %d", min);
    printf("\nMaximum = %d", max);

    return 0;
}
