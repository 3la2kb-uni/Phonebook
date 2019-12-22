#include <stdio.h>
#include <stdlib.h>



int verify_number(char number[]){
int len = strlen(number);

if(len>13){return 0;}


else if(number[0] == '+' && len != 13 ){return 0;}


else if(number[0] == '+' && len == 13){
int i=1;
for(i;i<len;i++){
int ord = (int)number[i];
if(ord < 48 || ord > 57 ){return 0;}
}
}


else if(number[0] != '+' && len != 11){return 0;}

else if(len == 11){
int i=0;
for(i;i<len;i++){
int ord = (int)number[i];
if(ord < 48 || ord > 57 ){return 0;}
}
}



return 1;
}

int verify_email(char email[]){
int len = strlen(email);
if(len>40){return 0;}
int i=0;
for(i;i<len;i++){
int ord = (int)email[i];
if(ord < 43 || ord == 44 || ord == 47 || (ord > 57 && ord < 64) || (ord > 57 && ord < 64) || (ord > 90 && ord < 94) || (ord > 57 && ord < 64) || ord == 96 || ord > 122 ){return 0;}
}
return 1;
}


int verify_date(char date[]){
int len = strlen(date);
if(len!=10){return 0;}
else if(date[4] != '-' && date[7] != '-'){return 0;}
int i=0;
for(i;i<4;i++){
int ord = (int)date[i];
if(ord < 48 || ord > 57 ){return 0;}
}
if( ( (int)date[5] < 48 || (int)date[5] > 50 ) || ( (int)date[6] < 48 || (int)date[6] > 57 ) || ( (int)date[8] < 48 || (int)date[8] > 52 ) || ( (int)date[9] < 48 || (int)date[9] > 57 ) ){return 0;}

return 1;


}



