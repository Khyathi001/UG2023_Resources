#include <stdio.h>
#include <stdlib.h>
long long int Palindrome(long long int N);
int main()
{
    long long int N;
    scanf("%lld",&N);
    long long int ans = Palindrome(N);
    // for (int i = 0; i < count; i++)
    // {
    //     printf("%lld ",arr[i]);
    // }
    // printf("\n");
    // printf("%lld\n",ans);
    if(ans==1) printf("TRUE\n");
    else printf("FALSE\n");
}