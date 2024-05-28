#include <stdio.h>
#include <stdlib.h>
long long int * lineDirection(long long int n,long long int* array,long long int* diffs,long long int* result);
int main(){
    long long int N;
    scanf("%lld",&N);
    long long int array[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%lld",&array[i]);
    }
    long long int* diffs = (long long int*)malloc(sizeof(long long int)*N);
    long long int* result = (long long int*)malloc(sizeof(long long int)*N);
    lineDirection(N,array,diffs,result);
    for (int i = 0; i < N; i++)
    {
        printf("%lld ",result[i]);
    }
    printf("\n");
}
