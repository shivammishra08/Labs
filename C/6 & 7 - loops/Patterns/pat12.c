#include <stdio.h>
int main(){
int n;
printf("Enter no. of rows:");
scanf("%d",&n);
for (int i=1;i<=n;i++){
for (int j=n;j>=1;j--){
if(i==j)
printf("* ");
else
printf("%d ",j);
}
printf("\n");
}
return 0;
}
