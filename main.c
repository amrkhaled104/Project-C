#include "Heder.h"

int main()
{
	printf("OPEN?\n");sleep(2);
	clearScreen();
	if(welcome_admin()==1) return 0;
    load_data();
    first_page();
	save_data();
    return 0;
}
