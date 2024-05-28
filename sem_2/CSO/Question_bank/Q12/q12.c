#include <stdio.h>
#include <stdlib.h>
long long int SpecialNumber(long long int N,long long int* array,long long int count);
int main(){
    long long int N;
    scanf("%lld",&N);
    long long int M = N;
    long long int count = 0;
    while (M!=0)
    {
        M = M/10;
        count++;
    }
    long long int* arr = (long long int*)malloc(sizeof(long long int)*count); 
    long long int ans = SpecialNumber(N,arr,count);
    // printf("%lld\n",ans);
    // for (int i = 0; i < count; i++)
    // {
    //     printf("%lld ",arr[i]);
    // }
    if(ans==N) printf("TRUE");
    else printf("FALSE");
    printf("\n");
}