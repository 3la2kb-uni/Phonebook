#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

struct data_2{
	char firstname[15];
	char lastname[15];
	char phone[13];
	char address[40];
	char email[40];
	char date[11];
};


void modify(char name[],int id,char val[],int field){
int lines = next_id(name);
int i=0;
create_table("tmpcopy");
for(i;i<lines;i++){
if(i == id){
struct data_2 mod;
strcpy(mod.firstname, column(row(name,i),1));
strcpy(mod.lastname , column(row(name,i),2));
strcpy(mod.phone, column(row(name,i),3));
strcpy(mod.address , column(row(name,i),4));
strcpy(mod.email , column(row(name,i),5));
strcpy(mod.date , column(row(name,i),6));
if(field == 1){strcpy(mod.firstname, val);}
else if(field == 2){strcpy(mod.lastname , val);}
else if(field == 3){strcpy(mod.phone , val);}
else if(field == 4){strcpy(mod.address , val);}
else if(field == 5){strcpy(mod.email , val);}
else if(field == 6){strcpy(mod.date , val);}
insert("tmpcopy",mod.firstname,mod.lastname,mod.phone,mod.address,mod.email,mod.date);
}
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

