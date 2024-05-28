#include <stdio.h>
long long int NoOfOnes(long long int N);
int main(){
    long long int N;
    scanf("%lld",&N);
    long long int ans = NoOfOnes(N);
    if(ans%2!=0) printf("TRUE\n");      // if it contains odd number of ones print true
    else printf("FALSE\n");             // if it contains even number of ones print false
}