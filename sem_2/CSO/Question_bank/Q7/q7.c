#include <stdio.h>
#include <limits.h>
long long int MaxB(long long* array,long long int N,long long B,long long int ans);
int main(){
    long long int N,B;
    scanf("%lld%lld",&N,&B);
    long long int array[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%lld",&array[i]);
    }
    long long int Max = INT_MIN;
    long long int ans = MaxB(array,N,B,Max);
    printf("%lld\n",ans);
}