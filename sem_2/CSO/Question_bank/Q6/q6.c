#include <stdio.h>
long long int GCD(long long int n,long long int m);
int main(){
    long long int a,b;
    scanf("%lld%lld",&a,&b);
    long long int ans = GCD(a,b);
    printf("%d\n",ans);
}