#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    int n;
    printf("Enter n");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements of array");
    for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
    }
    int* ptr=(int*)malloc(sizeof(int));
    *ptr=a[0];
    int l=1;
    for(int i=1;i<n;i++){
        if(a[i]!=a[i-1]){
        ptr=realloc(ptr,l+1);
        ptr[l]=a[i];
        l++;
        }
    }
    for(int i=0;i<l;i++){
    printf("%d ",ptr[i]);
    }
    return 0;
}