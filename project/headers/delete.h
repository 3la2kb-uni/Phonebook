#include <stdio.h>

int delete_table(char name[])
{
   if (remove(concat("database/",name)) == 0)
	return 1;
   else
	return 0;
}
