#include "headers/create.h"
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

int choice_2;
char name[20];
printf("Table name : ");
scanf("%s",name);
if(!table_exists(name)){
	printf("Table doesn't exist.\n\n");
	main();
	}
else{
printf("1 > Add record\n2 > Select record\n3 > Modify record\n4 > Remove record\n____________________\n\n> ");
scanf("%d",&choice_2);
	}
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
return 0;
}



