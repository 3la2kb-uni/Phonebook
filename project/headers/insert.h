#include <stdio.h>
#include <stdlib.h>


int insert(char table[],char firstname[],char lastname[],char phone_number[],char address[],char email[],char date[]) {
    int id = next_id(table);
    FILE *fptr;
    fptr = fopen(concat("database/",table),"a");
    fprintf(fptr,"%d,%s,%s,%s,%s,%s,%s\n",id,firstname,lastname,phone_number,address,email,date);
    fclose(fptr);
    return 0;
}
/*
int main(){ struct dates date; date.year=2001; date.month=3; date.day=16; 
insert("gabor","gaber","zayed","0123","smo7a","eskndrya",date); return 0;
}
*/
