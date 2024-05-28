#include <stdio.h>
#include <stdlib.h>
long long int* sortLikeWave(long long int* array,long long int N);
int main(){
    long long int N;
    scanf("%lld",&N);
    long long int array[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%lld",&array[i]);
    }
    long long int* ans = (long long int*)malloc(sizeof(long long int)*N);
    ans = sortLikeWave(array,N);
    for (int i = 0; i < N; i++)
    {
        printf("%lld ",ans[i]);
    }
    printf("\n");
    // printf("%lld\n",ans);
}