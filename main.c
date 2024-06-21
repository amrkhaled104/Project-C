#include "Heder.h"

int main()
{
	printf("\t\t\t\t\t Welcome to Student Record System :) \n\n");
	printf("\t\t\t\t\t   by amr khaled & ola ahmed \n");
	sleep(2);
	clearScreen();
	if(welcome_admin()==1) return 0;
    load_data();
    first_page();
	save_data();
    return 0;
}
