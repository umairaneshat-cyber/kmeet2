#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char s[100];
    gets(s);
    char* ptr=malloc(sizeof(char));
    *ptr=s[0];
    int l=1;  
    int count=1;
    for(int i=1;i<strlen(s);i++){
    if(s[i]!=s[i-1]){
    ptr=(char*)realloc(ptr,l+2);
    *(ptr+l)=count+'0';
    l++;
    *(ptr+l)=s[i];
    l++;
    count=1;
    }
    else
    count++;
    }
    l++;
    *(ptr+l)=count+'0'; 
    for(int i=0;i<=l;i++)
    printf("%c",ptr[i]);
    return 0;
}