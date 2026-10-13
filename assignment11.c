#include<stdio.h>
#include<stdlib.h>

int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    int** ptr1=(int**)malloc(m*sizeof(int*));
    for(int i=0;i<m;i++){
    ptr1[i]=(int*)malloc(n*sizeof(int));
    }
    int c=0;
    int** ptr2=NULL;
    for(int i=0;i<m;i++){
        int flag=1;
        for(int j=0;j<n;j++){
        scanf("%d",&ptr1[i][j]);
        if(ptr1[i][j]!=0)
        flag=0;
        }
        if(flag==0){
        ptr2=(int**)realloc(ptr2,(++c)*sizeof(int*));
        ptr2[c-1]=ptr1[i];
        }
    }
    for(int i=0;i<c;i++){
        for(int j=0;j<n;j++){
            printf("%d",ptr2[i][j]);
        }
        printf("\n");
    }
    free(ptr1);
    free(ptr2);
    return 0;
}