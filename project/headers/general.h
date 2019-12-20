#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <assert.h>


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


char** str_split(char* a_str, const char a_delim)
{
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;
    /* Count how many elements will be extracted. */
    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    /* Add space for trailing token. */
    count += last_comma < (a_str + strlen(a_str) - 1);

    /* Add space for terminating null string so caller
       knows where the list of returned strings ends. */
    count++;

    result = malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str, delim);

        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    return result;
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



char * row(char name[],int id){
if(table_exists(name)){
    char *content = (char *) malloc(sizeof(char) * find_size(name));
    FILE *fptr;
    char ch;
    int n = 0;
    char crlf = 10;
    char comma = 44;
    fptr = fopen(concat("database/",name), "r");
    ch = fgetc(fptr);

    while (ch != EOF)

    {
	content[n] = ch;
	n++;
        ch = fgetc(fptr);
    }

    fclose(fptr);
    return str_split(content,crlf)[id];
}
}

