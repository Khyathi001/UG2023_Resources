#include <stdio.h>
long long int* SortBinary(long long int *array,long long int N);
int main()
{
    long long int N;
    scanf("%lld", &N);
    long long int array[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%lld",&array[i]);
    }
    long long int* arr = SortBinary(array,N);
    for (int i = 0; i < N; i++)
    {
        printf("%lld ",arr[i]);
    }
    // printf("%d\n",arr);
    printf("\n");
}