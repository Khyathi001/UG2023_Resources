#include <stdio.h>
#include <stdlib.h>
long long int* ModifyArray(long long int N,long long int* array);
int main(){
    long long int N;
    scanf("%lld",&N);
    long long int* array = (long long int*)malloc(sizeof(long long int)*N);
    array = ModifyArray(N,array);
    for (int i = 0; i < N; i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");
}