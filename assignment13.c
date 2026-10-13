#include<stdio.h>
#include<stdlib.h>

int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    int** ptr1=(int**)malloc(m*sizeof(int*));
    for(int i=0;i<m;i++){
    ptr1[i]=(int*)malloc(n*sizeof(int));
    }
     int** ptr2=NULL;
    for(int i=0;i<m;i++){      
        for(int j=0;j<n;j++)   
        scanf("%d",&ptr1[i][j]);
        }
        int left=0,right=n-1,top=0,bottom=m-1;
        int array[m*n];
        int c=0;
        while(c<(m*n))
        {
            for(int i=left;i<=right;i++)
                array[c++]=ptr1[top][i];
            top++;
            for(int i=top;i<=bottom;i++)
                array[c++]=ptr1[i][right];
            right--;
            for(int i=right;i>=left;i--)
                 array[c++]=ptr1[bottom][i];
            bottom--;
            for(int i=bottom;i>=top;i--)
                 array[c++]=ptr1[i][left];
            left++;
        }
        for(int i=(m*n)-1;i>=0;i--)
        printf("%d ",array[i]);
        for(int i=0;i<n;i++)
        free(ptr1[i]);
        free(ptr1);
    return 0;
}