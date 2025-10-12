#include<stdio.h>
int rev(int n, int r)
{
    if(n==0)
        return r;
    else
        return rev(n/10, r*10+(n%10));
}

int main()
{
    int num;
    printf("Enter a number:");
    scanf("%d", &num);
    if(num==rev(num,0))
        printf("Number is a palindrome");
    else
        printf("Number is not a palindrome");
    return 0;
}
