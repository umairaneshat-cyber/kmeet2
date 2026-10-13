#include<stdio.h>
#include<stdlib.h>
int determinant(int **M, int k)
{

    if (k == 1)
        return M[0][0];
    if (k == 2)
       return M[0][0] * M[1][1] - M[0][1] * M[1][0];
    
    int det = 0;
    int sign = 1;

    /* Dynamically allocate the (k-1) x (k-1) minor */
    int **minor = malloc((k - 1) * sizeof *minor);
    if (!minor) { perror("malloc"); exit(1); }
    for (int i = 0; i < k - 1; i++) {
        minor[i] = malloc((k - 1) * sizeof **minor);
        if (!minor[i]){ 
            perror("malloc"); exit(1);
        }
    }
    for (int col = 0; col < k; col++){
        for (int i = 1; i < k; i++) {
            int mj = 0;
            for (int j = 0; j < k; j++){
                if (j == col)
                    continue;
                minor[i - 1][mj++] = M[i][j];
            }
        }
        det += sign * M[0][col] * determinant(minor, k - 1);
        sign = -sign;
    }
 
    for (int i = 0; i < k - 1; i++)
    free(minor[i]);
    free(minor);
    return det;
}

int main(){
  
     int n;
    scanf("%d ",&n);
    int** ptr1=(int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++){
    ptr1[i]=(int*)malloc(n*sizeof(int));
    }
    for(int i=0;i<n;i++){
        int flag=1;
        for(int j=0;j<n;j++){
        scanf("%d",&ptr1[i][j]);
        }
    }
    printf("%d",determinant(ptr1,n));
      return 0;
}