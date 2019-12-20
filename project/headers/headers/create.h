#include <stdlib.h>
#include <stdio.h>
#include "general.h"
#include <dirent.h>


int create_table(char name[]){

DIR *d;
struct dirent *dir;
d = opendir("./database");
FILE * fPtr;

if (d){
        while ((dir = readdir(d)) != NULL)

        {

	if(!(strcmp(dir->d_name,name)))
{

		printf("Table name already exists.\n\n");
		return 0;
		}

     }

        closedir(d);






}
fPtr = fopen(concat("database/",name), "w");

if(fPtr == NULL)
	{
	printf("Table is not created.\n\n");
	return 0;
	}
else{
	fclose(fPtr);
        printf("Table created successfully.\n\n");
	return 1;
}


}

