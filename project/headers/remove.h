#include <stdio.h>
#include <stdlib.h>


void delete_record(char name[],int id){
int lines = next_id(name);
int i=0;
create_table("tmpcopy");
for(i;i<lines;i++){
if(i == id){continue;}
else{
    FILE *fptr;
    fptr = fopen("database/tmpcopy","a");
    fprintf(fptr,"%s\n",row(name,i));
    fclose(fptr);
}
}
delete_table(name);
create_table(name);
i=0;
for(i;i<lines-1;i++){
    FILE *fptr;
    fptr = fopen(concat("database/",name),"a");
    fprintf(fptr,"%s\n",row("tmpcopy",i));
    fclose(fptr);
}
delete_table("tmpcopy");
}



