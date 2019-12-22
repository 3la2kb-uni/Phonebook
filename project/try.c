#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include "headers/general.h"

void check(char name[]){
int lines = next_id(name);
int i=0;
for(i;i<lines;i++)
printf("%s\n", row(concat("database/",name),i) );
}

void main(){
check("sort");
}
