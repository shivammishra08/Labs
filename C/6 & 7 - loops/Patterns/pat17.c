#include <stdio.h>
int main(){
int n;
printf("Enter no. of rows:");
scanf("%d",&n);
for (int i=1,k=1;i<=n;i++){
for (int j=1;j<=n-i;j++)
printf("\t");
for (int j=1;j<=i;j++,k++)
printf("%d\t",k);
printf("\n");
}
return 0;
}
