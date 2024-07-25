#include"../include/hdr.h"

int main() 
{
    char src[MAX];
    char dest[MAX];
    char ch;
    int num;
    int choice;
    int len;
    int len_dest;

    
    printf("Choose an option:\n");
    printf("1. my_strcopy - Copy full string\n");
    printf("2. my_strncopy - Copy specific number of characters\n");
    printf("3. my_strindex - index of the first occurance of character\n");
    printf("4. my_strappend - append src string to dest string\n");
    printf("5. my_strnappend - appends at most n characters from src to the dest\n");
    printf("6. my_strcomp - compare two strings s1 and s2\n");
    printf("7. my_strcompcase - compare two strings s1 and s2 ignoring the cases\n");
    printf("8. my_strspan - count of consecutive character in mainstring, present in substring\n");
    printf("9. my_strpalin - checks whether str is palindrome or not\n");
    printf("10. my_strsqueeze - squeezes the consecutive similar characters in str & returns the modified str\n");
    printf("11. my_strrev -  reverses the string and returns it\n");
    printf("12. my_strinschr -  insert character c in str at given pos\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar();


    switch (choice) {
        case 1:
            printf("Enter the src string: ");
            fgets(src, MAX, stdin);

            len = my_strlen(src);
            src[len - 1] = '\0';

            my_strcopy(dest, src);
            printf("copied string is : %s\n", dest);
            break;
        case 2:
            printf("Enter the src string: ");
            fgets(src, MAX, stdin);

            len = my_strlen(src);
            src[len - 1] = '\0';

            printf("Enter the no. of characters to copy: ");
            scanf("%d", &num);
            my_strncopy(dest, src, num);
            printf("copied string is : %s\n", dest);
            break;
        case 3:
            printf("Enter the string: ");
            fgets(src, MAX, stdin);
    
            len = my_strlen(src);
            src[len - 1] = '\0';

            printf("Enter the character to get index of its 1st occurance: ");
            scanf("%c", &ch);
            int index = my_strindex(src, ch);
            printf("Index of its first occurance is : %d\n", index+1 );
            break;
         case 4:
            printf("Enter the src string: ");
            fgets(src, MAX, stdin);

            len = my_strlen(src);
            src[len - 1] = '\0';

            printf("Enter the dest string: ");
            fgets(dest, MAX, stdin);

            len_dest = my_strlen(dest);
            dest[len -1] = '\0';

            my_strappend(dest, src);
            printf("Appended string is : %s\n", dest);
            break;
         case 5:
            printf("enter the src string : ");
            fgets(src, MAX, stdin);

            len = my_strlen(src);
            src[len-1] = '\0';
    
            printf("enter the dest string: ");
            fgets(dest, MAX, stdin);

            len_dest = my_strlen(dest);
            dest[len_dest-1] = '\0';
    
            printf("enter the number of characters to append : ");
            scanf("%d", &num);
    
            my_strnappend(dest, src, num);
            printf("the appended string is : %s\n", dest);   
            break;
         case 6:
            printf("Enter the first string : ");
            fgets(src, MAX, stdin);

            len = my_strlen(src);
            src[len-1] = '\0';
    
            printf("enter the second string: ");
            fgets(dest, MAX, stdin);

            len_dest = my_strlen(dest);
            dest[len_dest-1] = '\0';
            
            int compare = my_strcomp(src,dest);
            if (compare == 0)
                printf("Strings are equal");
            else if (compare == 1)
                printf("s1 is greater than s2");
            else if(compare == -1)
                printf("s1 is less than s2");
            break;
        case 7:
            printf("Enter the first string : ");
            fgets(src, MAX, stdin);

            len = my_strlen(src);
            src[len-1] = '\0';
    
            printf("enter the second string: ");
            fgets(dest, MAX, stdin);

            len_dest = my_strlen(dest);
            dest[len_dest-1] = '\0';
            
            my_tolower(src);
            my_tolower(dest);
            int compare2 = my_strcomp(src,dest);
            if (compare2 == 0)
                printf("Strings are equal");
            else if (compare2 == 1)
                printf("s1 is greater than s2");
            else if(compare2 == -1)
                printf("s1 is less than s2");
            break;
        case 8:
            printf("Enter the first string : ");
            fgets(src, MAX, stdin);

            //len = my_strlen(src);
            //src[len-1] = '\0';
    
            printf("enter the second string: ");
            fgets(dest, MAX, stdin);

            //len_dest = my_strlen(dest);
            //dest[len_dest-1] = '\0';
            
            int result = my_strspan(src, dest);
            printf("The count of consecutive characters is : %d\n", result);
            break;
        case 9:
            printf("Enter the string : ");
            fgets(src, MAX, stdin);

            len = my_strlen(src);
            src[len-1] = '\0';
            if (my_strpalin(src)) 
            {
                printf("The string is a palindrome.\n");
            } 
            else 
            {
                printf("The string is not a palindrome.\n");
            }
            break;
        case 10:
            printf("Enter the string: ");
            fgets(src, MAX, stdin);

            len = my_strlen(src);
            src[len-1] = '\0';
            
            my_strsqueeze(src);
            printf("The modified string is : %s", src);
            break;
        case 11:
            printf("Enter the string: ");
            fgets(src, MAX, stdin);

            len = my_strlen(src);
            src[len-1] = '\0';

            len = my_strlen(src);
            char *str = src;
            char *start = src;
            char *end = src+len-1;

            my_strrev(str, start, end);

            printf("The reverse string is %s\n ", src);
            break;
        case 12:
            printf("Enter the string: ");
            fgets(src, MAX, stdin);

            len = my_strlen(src);
            src[len-1] = '\0';

            char ch;
            int pos;
               
            printf("Enter the character to insert: ");
            scanf("%c", &ch);

            printf("Enter the position to insert: ");
            scanf("%d", &pos);

            my_strinschr(src, ch, pos);
            printf("The modified string is %s\n ", src);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }
    return 0;
}
