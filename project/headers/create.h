#include <stdlib.h>
#include <stdio.h>
#include "general.h"
#include <dirent.h>


int create_table(char name[]){

FILE * fPtr;

if(table_exists(name)){
	printf("Table name already exists.\n\n");
	return 0;
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

