#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "headers/general.h"
#define MAX 256

int modify(char table[],int line,int modify_me,char modified[]){
FILE *fptr1, *fptr2;
char new_file[20]="modifier";
int i ,cur_line = 0;
char ch, arr[5];
next_id(table);
fptr1 = fopen(concat("database/",table),"r");
if(fptr1 == NULL){printf("problem opening file!"); return 0;}
fptr2 = fopen(concat("database/",new_file),"w");
if(fptr2 == NULL){printf("unable to open modifying file!"); return 0;}
ch = fgetc(fptr1);
while(!feof(fptr1) && ch != EOF)
{
        if(!feof(fptr1))
        {
                cur_line++;
                if(cur_line!=line)
                {
                        fprintf(fptr2,"%c",ch);
                }
                else
                {       arr[5] = row(table, line);
                        while(i!=modify_me+1)
                        {
                                strcpy(fptr2, arr[i]);
                                if(i==modify_me)
                                {
                                        fprintf(fptr2,"%s",modified);
                                }
                                i++;
                        }
                }
        }

ch = fgetc(fptr1);
}
fclose(fptr1);
fclose(fptr2);
remove(table);
rename(new_file, table);
printf("modification success!");
return 0;
}

int main(){
int num,field;
char tabname[MAX], done[MAX];
printf("enter file name:");
scanf("%s",&tabname);
printf("enter the row you want to modify on:");
scanf("%d",&num);
printf("enter the field you want to modify:");
scanf("%d",&field);
printf("enter your modification:");
scanf("%s",&done);
modify(tabname,num,field,done);
return 0;
}
