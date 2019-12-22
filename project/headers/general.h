#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <assert.h>
#include <math.h>

struct dates {
            int year;
            int month;
            int day;
};



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

char * column(char row[],int col){
char comma = 44;

if(col == 1){return str_split(row,comma)[0];}
else if(col == 2){return str_split(row,comma)[1];}
else if(col == 3){return str_split(row,comma)[2];}
else if(col == 4){return str_split(row,comma)[3];}
else if(col == 5){return str_split(row,comma)[4];}
else if(col == 6){return str_split(row,comma)[5];}
else {return "Wrong column used";}

}

int next_id(char name[]){
if(table_exists(name)){

    FILE *fptr;
    int count = 0;
    char c;
    fptr = fopen(concat("database/",name), "r");

    for (c = getc(fptr); c != EOF; c = getc(fptr))
        if (c == '\n') // Increment count if this character is newline
            count = count + 1;

    // Close the file
    fclose(fptr);
    return count;

}
}

void strreverse(char* begin, char* end) {
	
	char aux;
	
	while(end>begin)
	
		aux=*end, *end--=*begin, *begin++=aux;
	
}
	
void itoa(int value, char* str, int base) {
	
	static char num[] = "0123456789abcdefghijklmnopqrstuvwxyz";
	
	char* wstr=str;
	
	int sign;
	


	
	// Validate base
	
	if (base<2 || base>35){ *wstr='\0'; return; }
	

	
	// Take care of sign
	
	if ((sign=value) < 0) value = -value;
	


	
	// Conversion. Number is reversed.
	
	do *wstr++ = num[value%base]; while(value/=base);
	
	if(sign<0) *wstr++='-';
	
	*wstr='\0';
	

	
	// Reverse string

	
	strreverse(str,wstr-1);
	
}


char * ascii(char string[]){
int i = 0;
int size = 0;
int three = 3;
int two = 2;
int j;
for(i;i<strlen(string);i++){
if((int)string[i] < 100){
	j = 0;
	size += two;
	}
else{
	size += three;
	}
}
i=0;
char *res = (char*)malloc(sizeof (char) * size);
int count = 0;
char buffer[4];
for(i;i<strlen(string);i++){
if((int)string[i] < 100){
        j = 0;
        itoa((int)string[i],buffer,10);
	for(j;j<two;j++){
		res[count] = buffer[j];
		count++;
		}
        }
else{
        j = 0;
        itoa((int)string[i],buffer,10);
        for(j;j<three;j++){ 
                res[count] = buffer[j];
		count++;
                }

        }

}
return res;

}


