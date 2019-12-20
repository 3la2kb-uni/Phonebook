#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>

 

void main()

{
#ifdef __APPLE__
    printf("You have Windows Operating System");
#endif

#ifdef __WIN32__
    printf("You have Windows Operating System");
#endif
}
