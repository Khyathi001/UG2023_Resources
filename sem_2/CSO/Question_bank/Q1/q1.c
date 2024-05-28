#include <stdio.h>
long long int Operations(long long int M,long long int N,long long int S);
int main(){
    long long int M,N,S;
    scanf("%lld%lld%lld",&M,&N,&S);
    long long int ans = Operations(M,N,S);
    printf("%lld\n",ans);
}