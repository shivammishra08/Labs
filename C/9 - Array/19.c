#include<stdio.h>
#include<stdlib.h>
int main(){
    printf("Enter number of rows for matrix :");
    int row; scanf("%d",&row);
    printf("Enter number of columns for matrix :");
    int col; scanf("%d",&col);
    int a[row][col], pb[row];
    
    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++){
            printf("Enter Element %d,%d: ",i+1,j+1);
            scanf("%d",&a[i][j]);
        }
    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++)
            pb[i] += a[i][j];
    
    for(int i=0; i<row; i++){              
        for(int j=0; j<col; j++)
            printf("%d ",a[i][j]);
        printf("  %d \n",pb[i]);
    }
    return 0;
}