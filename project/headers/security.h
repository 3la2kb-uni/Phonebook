#include <regex.h>
#include <stdio.h>
#include <stdlib.h>


int print_result(int return_value){
  if (return_value == 0){
    return 1;
  }
  else if (return_value == REG_NOMATCH){
    return 0;
  }
  else{
    return -1;
  }
}


int regex_match(char reg[],char text[]) {
  regex_t regex;
  int return_value;
  return_value = regcomp(&regex,reg,0);
  return_value = regexec(&regex, text, 0, NULL, 0);
  return print_result(return_value);
}

int verify_number(char number[]){
return regex_match("^01[[:digit:]]\\{9\\}$",number);
}

int verify_email(char email[]){
return regex_match("^[-.[:alnum:]]\\{1,\\}@[-.[:alnum:]]\\{1,\\}$",email);
}


int verify_date(char date[]){
return regex_match("^[[:digit:]]\\{4\\}-[01][[:digit:]]-[0123][[:digit:]]$",date);
}
