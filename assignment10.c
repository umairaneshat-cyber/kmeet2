#include <stdio.h>
#include <string.h>

void shorten(char *s)
{
 if(s[0]=='\0')
 return;
 int i;
 for(i=0;i<strlen(s);i++){
    if(s[i]==s[i+1]){
        int j=i;
        while(s[j]!='\0'){
            s[j]=s[j+2];
            j++;
        }
        shorten(s);
    }
 }
 return;
}

int main()
{
    char str[100];

    scanf(" %[^\n]",str);
    shorten(str);
    printf("%s", str);

    return 0;
}