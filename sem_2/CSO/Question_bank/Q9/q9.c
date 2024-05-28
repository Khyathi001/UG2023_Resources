#include <stdio.h>
long long int First(long long int *array, long long int N, long long int* temp);
int main()
{
    long long int N;
    scanf("%lld", &N);
    long long int arr[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &arr[i]);
    }
    long long int temp[N+1];
    for (int i = 0; i < N+1; i++)
    {
        temp[i] = 0;
    }
    long long int ans = First(arr, N, temp);
    // printf("%lld\n",ans);
    // for (int i = 0; i < N+1; i++)
    // {
    //     printf("%lld ",temp[i]);
    // }
    // printf("\n");
    printf("%lld\n",ans);
}