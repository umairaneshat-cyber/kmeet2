#include<stdio.h>

#include<math.h>

#include<string.h>

int binary_no(int n,int bin,int c){
    bin=bin+n%2*pow(10,c);
    if(n==0)
    return bin;
    return(binary_no(n/2,bin,c+1));
}

int lessthan9(int x,int ans,int base,int c){
ans=ans+x%base*pow(10,c);
if(x==0)
return ans;
return(lessthan9(x/base,ans,base,c+1));
}

void above(int x, char a[], int base, int index) {
    if (x == 0) {
        a[index] = '\0'; // Properly terminate the string at the end
        return;
    }
    
    int remainder = x % base;
    if (remainder > 9)
        a[index] = (char)(remainder + 55); // 'A' is 65, so 10 + 55 = 65
    else
        a[index] = (char)(remainder + '0');
        
    above(x / base, a, base, index + 1);
}

int main(){
    printf("Enter a number");
    int n,b;
    scanf("%d",&n);
    printf("The binary equivalent= %d",binary_no(n,0,0));
    printf("Enter any base");
    scanf("%d",&b);
    if(b<=9)
    printf("The equivalent= %d",lessthan9(n,0,b,0));
    else{
        char a[]="";
        above(n,a,b,0);
        printf("%s",a);
    }
    return 0;
}