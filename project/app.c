#include "headers/create.h"
#include "headers/insert.h"
#include "headers/delete.h"
#include "headers/security.h"
#include "headers/sort.h"
#include "headers/remove.h"
#include "headers/modify.h"
#include <stdlib.h>
#include <stdio.h>

int main();

void first_choice(){
char name[20];
printf("Table name : ");
scanf("%s",name);
create_table(name);
main();
}



void second_choice(){
char name[20];
printf("Table name : ");
scanf("%s",name);
int choice_2;
if(!table_exists(name)){
        printf("Table doesn't exist.\n\n");
        main();
        }
else{
printf("1 > Add record\n2 > Select record\n3 > Modify record\n4 > Remove record\n5 > Show sorted records\n____________________\n\n> ");
scanf("%d",&choice_2);
if(choice_2 == 1){

        char firstname[15];
        char lastname[15];
        char birth[11];
        char address[40];
        char email[40];
        char number[16];
printf("First name : ");
scanf("%s",firstname);
printf("Last name : ");
scanf("%s",lastname);
printf("Date of birth (YYYY-MM-DD): ");
scanf("%s",birth);
while(!verify_date(birth)){
printf("Invalid date !\n");
printf("Date of birth (YYYY-MM-DD): ");
scanf("%s",birth);
}
printf("Address : ");
scanf("%s",address);
printf("Email : ");
scanf("%s",email);
while(!verify_email(email)){
printf("Wrong email !\n");
printf("Email : ");
scanf("%s",email);
}
printf("Phone number : ");
scanf("%s",number);
while(!verify_number(number)){
printf("Wrong number !\n");
printf("Phone number : ");
scanf("%s",number);
}
insert(name,firstname,lastname,number,address,email,birth);
printf("\n");
main();
}
else if(choice_2 == 2){
int line = 0;
int choice_3;
printf("Search using :\n1 > First name\n2 > Last name\n3 > Address\n4 > Email\n5 > Phone number\n6 > Display all records\n____________________\n\n> ");
scanf("%d",&choice_3);
if(choice_3 == 6){
	for(line;line < next_id(name);line++){
	printf("%d,%s\n",line,row(name,line));
	}

}else{
char value[40];
printf("Enter your search value : ");
scanf("%s",&value);
for(line;line < next_id(name);line++){
if( !strcmp(column(row(name,line),(choice_3)),value))
printf("%d,%s\n",line,row(name,line));
}
}
}
else if(choice_2 == 5){
int choice_3;
printf("Order by :\n1 > First name\n2 > Last name\n3 > Address\n4 > Email\n5 > Phone number\n____________________\n\n> ");
scanf("%d",&choice_3);
if(choice_3 != 6){
	order(name,choice_3);
}

	}
else if(choice_2 == 4){
int choice_3;
printf("Number of row to be deleted :\n\n____________________\n\n> ");
scanf("%d",&choice_3);
delete_record(name,choice_3);
}
else if(choice_2 == 3){
int choice_3;
char val[40];
int field;
printf("Which record do you want to edit (line number) : ");
scanf("%d",&field);
printf("Edit :\n1 > First name\n2 > Last name\n3 > Phone\n4 > Address\n5 > Email\n6 > Date\n____________________\n\n> ");
scanf("%d",&choice_3);
printf("Enter new value : ");
scanf("%s",val);
modify(name,field,val,choice_3);
}
}


}


void third_choice(){
	char del_name[20];
	printf("Table name : ");
	scanf("%s",del_name);
	if(delete_table(del_name)){
		printf("Table deleted successfully.\n");
	}
	else{
		printf("Table couldn't be deleted.\n");
	}
	main();
}


int main(){

int choice_1;

printf("Hello to the 1337 phonebook.\n\n1 > Create table\n2 > Use existing table\n3 > Delete table\n____________________\n\n> ");
scanf("%d",&choice_1);
if(choice_1 == 1){
	first_choice();
	}
else if(choice_1 == 2){
	second_choice();
	}
else if(choice_1 == 3){
        third_choice();
        }

return 0;
}





