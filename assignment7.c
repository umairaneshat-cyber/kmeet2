#include<stdio.h>
void reverse(int* left,int* right){
    while(left<right){
        int temp=*left;
        *left=*right;
        *right=temp;
        left++;
        right--;
    }
}
int main(){
    int n;
    printf("Enter n");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    reverse(&a[0],&a[n-1]);
    for(int i=0;i<n;i++)
    printf("%d ",a[i]);
    int k;
    scanf("%d",&k);
    if(n%2==0)
    for(int i=0;i<(n-k);i++)
    reverse(&a[i],&a[k+i]);
    else{
    for(int i=0;i<(n-k);i++)
    reverse(&a[i],&a[k+i]);  
    reverse(&a[n-k],&a[n-1]); 
    }
    for(int i=0;i<n;i++)
    printf("%d ",a[i]);
    return 0;
}