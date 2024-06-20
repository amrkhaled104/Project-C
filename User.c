#include "Heder.h"
//pointer to pointer linked list
struct STUDENTS *Head=NULL;
struct STUDENTS *Help=NULL;
int User_Id;

void user()
{   /*printf("loading");
    for(int i=0;i<3;i++)
        {
            printf(".");
            sleep(1);
        }*/
    clearScreen();

   while(1)
    {
        printf("***************************\n");
        printf("for menu enter  [M] : \n");
        printf("for exit  enter [E] : \n");
        printf("***************************\n");
        fflush(stdin);
        char choice_2;
        scanf("%c",&choice_2);
        if(choice_2=='M')
        {
            menu_user();
        }
        else if (choice_2=='E')
        {
            EXIT();
            break;
        }
        else
        {

            printf("Invalid option!!!!!! \n");
        }
    }
}

void menu_user()
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
    printf("for View your record enter    [1]  : \n");
    printf("for Edit your password  enter [2]  : \n");
    printf("for Edit your name enter      [3]  : \n");
    printf("**********************************\n");
    scanf("%i",&menu_choice);
	Find_Student();
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
				 menu_user();
        }
}
void Find_Student()
{
	printf("loading");
    for(int i=0;i<3;i++)
        {
            printf(".");
            sleep(1);
        }
    clearScreen();
	Help=Head;
	while(Help!=NULL)
	{
	  if(Help->Id==User_Id)
	  {
		  break;
	  }
	  	Help= Help->NEXT ;
	}
}

void View_your_record()
{
	        printf("\n         %s info           \n",Help->Name);
            printf("************************************\n");
            printf("Name: %s    \n", Help->Name);
            fflush(stdin);
            printf("Grade: %0.2f \n", Help->Grade);
            printf("ID: %d\n", Help->Id);
            printf("Gender: %s\n", Help->Gender);
            fflush(stdin);
            printf("Age: %d\n", Help->Age);
            printf("Password: %s\n\n", Help->Password);
            printf("************************************");

}

void Edit_your_password()
{
    char New_pass[100];
    int  c;
    int i;
    printf("Enter New Password:\n\n");

    for (i = 0; i < 100; i++) {
        c = getch();
        if(c == 13)
            break;
        printf("*");
        New_pass[i]=c;
    }
	New_pass[i]='\0';
    printf("\n");

	strcpy(Help->Password,New_pass);
	printf("Changed successfully\n");
}

void Edit_your_name()
{
    char New_Name[100];
    printf("Enter New Name:\n\n");
	fflush(stdin);
    gets(New_Name);
	fflush(stdin);
	strcpy(Help->Name,New_Name);
	printf("Changed successfully\n");
}
