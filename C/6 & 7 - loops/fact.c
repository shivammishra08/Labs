#include <stdio.h>
int main(){
    int num, pro=1;
    printf("Enter a number : ");
    scanf("%d",&num);
    for (int i=2; i<=num; i++)
        pro *= i;
    printf("Factorial of %d is %d\n",num,pro);
}