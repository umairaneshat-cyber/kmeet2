#include<stdio.h> 
#include<stdlib.h>
int check(int **M,int x,int y,int z){
    int sum1=0,sum2=0,target=0;
    for(int j=z;j<z+x;j++)
    target+=M[y][j];
    
    for(int i=y;i<y+x;i++){
        sum1=0,sum2=0;
        for(int j=z;j<z+x;j++){
        sum1+=M[i][j];
        sum2+=M[j][i];
        }
        if(sum1!=target||sum2!=target)
        return 0;
    }
    return 1;
}

int det(int** A,int n){
    int deter=0,sign=1;
if(n==1)
return A[0][0];
if(n==2)
return A[0][0]*A[1][1]-A[1][0]*A[0][1];

    int **minor=(int**)malloc((n-1)*sizeof(int*));
    for(int j=0;j<n-1;j++)
    minor[j]=(int*)malloc((n-1)*sizeof(int));
    for(int j=0;j<n;j++){
       
    for(int i=1;i<n;i++){
         int c=0;
        for(int k=0;k<n;k++){
            if(k==j)
            continue;
            else
            minor[i-1][c++]=A[i][k];
        }
    }  
    deter+=sign*A[0][j]*(det(minor,n-1));
    sign=sign*-1; 
    }
    for (int i = 0; i < n- 1; i++)
    free(minor[i]);
    free(minor);

return deter;
}
int main(){
    int **M=(int**)malloc(4*sizeof(int*));
    for(int i=0;i<4;i++)
    M[i]=(int*)malloc(4*sizeof(int));
    
   
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++)
        scanf("%d",&M[i][j]);
    }

     int i,j,k,flag=0;
    for(i=4;i>=1&&flag!=1;i--){
        for(j=0;j<=4-i&&flag!=1;j++){
            for(k=0;k<=4-i&&flag!=1;k++){
                if(check(M,i,j,k)==1)
                flag=1;
            }
        }
    }
    printf("The maximum submatrix is of order %d starting at row no %d and column no %d",i,j,k);
    printf("Deterinant =%d",det(M,4));
    return 0;
    
}