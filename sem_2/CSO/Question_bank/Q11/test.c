#include <stdio.h>
#include <stdlib.h>
long long *maxValues(long long int n, long long int *arr, long long int *diffs, long long int *result){
    long long int sum = 0;
    for (int p = 0; p < n; p++) {
        long long int cur, mx;
        if (arr[p] == 0) {
            cur = p;
        } else {
            cur = n - p - 1;
        }
        if (p > (n - p - 1)) {
            mx = p;
        } else {
            mx = n - p - 1;
        }
        sum += cur;
        long long int diff = mx - cur;
        diffs[p] = diff;
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (diffs[j] < diffs[j + 1]) {
                long long int temp = diffs[j];
                diffs[j] = diffs[j + 1];
                diffs[j + 1] = temp;
            }
        }
    }

    for (int p = 0; p < n; p++) 
    {
        sum += diffs[p];
        result[p] = sum;
    }
    return result;
}

signed main()
{
    long long int n;
    scanf("%lld", &n);
    long long int *arr = (long long int *)malloc(n * sizeof(long long int));
    for (int i = 0; i < n; ++i)
    {
        scanf("%lld", &arr[i]);
    }
    long long int *diffs = (long long int *)malloc(n * sizeof(long long int));
    long long int *result = (long long int *)malloc(n * sizeof(long long int));
    result = maxValues(n, arr, diffs, result);
    for (int i = 0; i < n; ++i)
    {
        printf("%lld ", result[i]);
    }
    printf("\n");
    free(arr);
    free(result);
    free(diffs);
    return 0;
}