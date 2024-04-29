#include "Heder.h"
//pointer to pointer linked list
struct STUDENTS *Head=NULL;
void user()
{   printf("loading");
    for(int i=0;i<3;i++)
        {
            printf(".");
            sleep(1);
        }

    a:for(int i=0;i<1;i++){
		clearScreen();
		char choise_2;
		printf("***************************\n");
		printf("for login enter L : \n");
		printf("for back  enter B : \n");
		printf("***************************\n");
		fflush(stdin);
		scanf("%c",&choise_2);
		switch(choise_2)
			{
			case 'L':
				login();
				break;
			case 'B':
				first_page();
				break;
			default:
				printf("Invalid option!!!!!! \n");
				goto a; 
			}
	}
}
void login()
{   unsigned int menu_choice;
    printf("loading");
    for(int i=0;i<3;i++)
        {
            printf(".");
            sleep(1);
        }
    clearScreen();
    printf("               menu                \n");
    printf("***********************************\n");
    printf("for View your record enter 1     : \n");
    printf("for Edit your password  enter 2  : \n");
    printf("for Edit your name enter 3       : \n");
    printf("**********************************8\n");
    scanf("%i",&menu_choice);
    switch(menu_choice)
        {
        case 1:
            View_your_record();
            break;
        case 2:
            Edit_your_password();
            break;
        case 3:
            Edit_your_name();
            break;
        default:
            printf("Invalid option!!!!!! \n");
        }
}
void View_your_record()
{

}
void Edit_your_password()
{

}
void Edit_your_name()
{

}
