#include <stdlib.h>
#include <string.h>
#include <dirent.h>

char* concat(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1) + strlen(s2) + 1); // +1 for the null-terminator
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}




int table_exists(char name[]){

DIR *d;
struct dirent *dir;
d = opendir("./database");

if (d){
        while ((dir = readdir(d)) != NULL){

        if(!(strcmp(dir->d_name,name))){

                return 1;
                }

     }

        closedir(d);
	return 0;
}
}



long int find_size(char file_name[]){
    // opening the file in read mode
    FILE* fp = fopen(concat("database/",file_name), "r");

    // checking if the file exist or not
    if (fp == NULL) {
        return -1;
    }

    fseek(fp, 0L, SEEK_END);

    // calculating the size of the file
    long int res = ftell(fp);

    // closing the file
    fclose(fp);

    return res;
}



int next_id(char name[]){
if(table_exists(name)){

}
return 0;
}

