#include <stdio.h>                                  
#include <unistd.h>
 
int main() {
 
    char *args[] = {"ls", "-l", NULL};
    char *env[] = {"PATH=/bin", "USER=tanishka", NULL};
 
    //execvp("ls", args);
    //  execlp("ls", "ls", "-l", NULL);
    //execl("/bin/ls", "ls", "-l", NULL);
     //execv("/bin/ls", args);
    //execve("/bin/ls", args, env);
    execle("/bin/ls", "ls", "-l", NULL, env);
    // If execvp returns, an error occurred
    perror("execvp");
    return 1;   
}    
