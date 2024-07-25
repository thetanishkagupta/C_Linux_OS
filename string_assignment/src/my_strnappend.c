#include"../include/hdr.h"

void my_strnappend(char *dest , char *src, int num)
{
    int length = my_strlen(dest);

  //  int length1 = my_strlen(src);

//    printf("length is dst %d  src %d", length,length1);
    dest = dest + length;
    while( *src != '\0' && num != 0)
    {
        *(dest++) = *(src++);
        num--;
    }
    *dest = '\0';
}
