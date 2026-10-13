#include<stdio.h>
#include<stdlib.h> //transpose a to get at then find a*at
int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    int** B=(int**)calloc(n,sizeof(int*)); 
    int** A=(int**)calloc(m,sizeof(int*));
    int** C=(int**)calloc(m,sizeof(int*));
    
    for(int i=0;i<n;i++){
    A[i]=(int*)calloc(n,sizeof(int));
       C[i]=(int*)calloc(m,sizeof(int)); 
    }
    for(int i=0;i<n;i++)
        B[i]=(int*)calloc(m,sizeof(int));

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
          scanf("%d",&A[i][j]);
          B[j][i]=A[i][j];
        }
    }
     for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
           int sum=0;
           for(int k=0;k<n;k++){
            sum+=A[i][k]*B[k][j];
           }
           C[i][j]=sum;
           printf("%d  ",C[i][j]);
        }
        printf("\n");
    }
    return 0;
}