#include <stdio.h>
#include <stdlib.h>
#include "headers/general.h"

struct dates {
            int year;
            int month;
            int day;
};

int insert(char table[],char firstname[],char lastname[],char phone_number[],char address[],char city[],struct dates date) {
    FILE *fptr;
    fptr = fopen(concat("database/",table),"a");
    fprintf(fptr,"%d,%s,%s,%s,%s,%s,%d/%d/%d\n",next_id(table),firstname,lastname,phone_number,address,city,date.year,date.month,date.day);
    fclose(fptr);
    return 0;
}
/*
int main(){ struct dates date; date.year=2001; date.month=3; date.day=16; 
insert("gabor","gaber","zayed","0123","smo7a","eskndrya",date); return 0;
}
*/
