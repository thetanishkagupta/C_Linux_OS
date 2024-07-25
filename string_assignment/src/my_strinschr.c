#include"../include/hdr.h"

void my_strinschr(char *src, char ch, int pos) 
{
    int len = my_strlen(src);
    int l = len-1;
    for(int j = l; j >= pos; j--){
        src[j + 1] = src[j];
    }
    src[pos] = ch;
    src[len+1] = '\0';   
}
