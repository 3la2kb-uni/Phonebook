#include "headers/create.h"
#include "headers/insert.h"
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
printf("1 > Add record\n2 > Select record\n3 > Modify record\n4 > Remove record\n____________________\n\n> ");
scanf("%d",&choice_2);
if(choice_2 == 1){

        char firstname[15];
        char lastname[15];
        char birth[10];
        char address[40];
        char email[40];
        char number[15];
printf("First name : ");
scanf("%s",firstname);
printf("Last name : ");
scanf("%s",lastname);
printf("Date of birth (YYYY-MM-DD): ");
scanf("%s",birth);
printf("Address : ");
scanf("%s",address);
printf("Email : ");
scanf("%s",email);
printf("Phone number : ");
scanf("%s",number);
insert(name,firstname,lastname,number,address,email,birth);
printf("\n");
main();
}}}



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
return 0;
}





