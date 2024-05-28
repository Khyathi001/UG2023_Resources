#include <stdio.h>
#include <stdlib.h>
long long int swap(long long int* arr,long long int  N);
int main()
{
    long long int N;
    scanf("%lld",&N);
    long long int array[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%lld",&array[i]);
    }
    swap(array,N);
    for (int i = 0; i < N; i++)
    {
        printf("%lld ",array[i]);
    }
    printf("\n");
}