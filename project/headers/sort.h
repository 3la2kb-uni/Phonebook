#include <stdio.h>
#include <stdlib.h>

struct data {
int id;
long int lastname;
};

void order(char name[],int col){
int i=0;
int lines = next_id(name);
struct data arr[lines];
for(i;i<lines;i++){
	arr[i].id = i;
	arr[i].lastname = (long int)atol(ascii(column(row(name,i),col)));
	}

struct data copy;
i=1;
int sorted = 0;

while(!sorted){
sorted = 1;
for(i;i<lines;i++){
if(arr[i].lastname>arr[i-1].lastname){
copy.lastname = arr[i].lastname;
arr[i].lastname = arr[i-1].lastname;
arr[i-1].lastname = copy.lastname;

copy.id = arr[i].id;
arr[i].id = arr[i-1].id;
arr[i-1].id = copy.id;

sorted = 0;

}



}
}
i=0;
for(i;i<lines;i++){
printf("%s\n",row(name,arr[i].id));
}
}


