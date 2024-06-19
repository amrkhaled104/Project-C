#include "Heder.h"
FILE *file=NULL;
extern  struct STUDENTS * Head;
int ret;
extern int User_Id;


/*
----------------------------------------------------------------------------
Name:Login
Parameters:No parameters
Return: it return(int)[1] if for admin,[2] for user and,
[-1] for wrong input or no data saved in memory
Usage: it ask if you are an admin or student and guide him to register page
----------------------------------------------------------------------------
*/

int Login()
{

    char choise;
    char choise_2;

        printf("***************************\n");
        printf("for admin enter [A] : \n");
        printf("for user  enter [U] : \n");
        printf("***************************\n");
        fflush(stdin);
        scanf("%c",&choise);
		printf("loading");
        for(int i=0;i<3;i++)
            {
                printf(".");
                sleep(1);
            }
        clearScreen();
        switch(choise)
        {
        case 'A':
            ret=login_admin();
            if(ret==-1)//when info saved in memory or login is false
            {
                return -1;
            }
            else
            {
                return 1;
            }
            break;
        case 'U':
            ret=login_user(&User_Id);
            if(ret==-1)//when info saved in memory or login is false
            {
                return -1;
            }
            else
            {
                return 2;
            }
            break;
        default:
            Login();
        }
}

/*
----------------------------------------------------------------------------
Name:login_admin
Parameters:No parameters
Return: it return [0] if compiler couldn't open file
Usage: it ask admin about his information to login and, make sure it is True
----------------------------------------------------------------------------
*/
int login_admin()
{

	char username[50];
	char password[50];
	char file_username[50];
	char file_password[50];
    printf("***************************\n");
	// افتح ملف النص للقراءة
    int c,i=0;
				file = fopen("Admin_info.csv", "r");
				if (file == NULL)
				{
					printf("Unable to open file.\n");
					return 0;
				}

				// اقرأ اسم المستخدم من الملف حتى الفاصلة
				while ((c = fgetc(file)) != EOF && c != ',')
				{
					file_username[i++] = c;
				}
				file_username[i] = '\0'; // إضافة نهاية السلسلة

				// اقرأ كلمة المرور من الملف بعد الفاصلة
				i = 0;
				while ((c = fgetc(file)) != EOF && c != '\n')
				{
					file_password[i++] = c;
				}
				file_password[i] = '\0'; // إضافة نهاية السلسلة
				int attempts=3,Flag=0;
				while(attempts--)
				{
					// اطلب من المستخدم إدخال اسم المستخدم وكلمة المرور
					printf("Enter username:");
					scanf("%s", &username);
					printf("Enter password:");
					for (i = 0; i < 50; i++)
					{
						c = getch();
						if(c == 13)
						   break;
						printf("*");
						password[i]=c;
					}
					password[i]='\0';
					// قارن الاسم وكلمة المرور
					if (strcmp(username, file_username) == 0 && strcmp(password, file_password) == 0)
					{
						Flag=0;
						printf("\n***************************\n");
						printf("Login Successfully ! \n");
						printf("*****************************\n");
						break;
					}
					else
					{
						Flag=1;
						if(attempts!=0){
						   clearScreen();
						   printf("Invalid username or password You Can Try Again.\n");
						}
					}
				}
				if(Flag==1)
				{
					clearScreen();
				    printf("No matter what you do, thief, you will not be able to hack the system\n");
				    return -1;
				}
				// أغلق ملف النص
				fclose(file);

}
/*
----------------------------------------------------------------------------
Name:login_user
Parameters:one parameter (poiter to User Id)
Return: it return (int) Flag : [1] if he login Successfully and [-1]
(if he enter password or Id wrong 3 time) or(no data in memory)
Usage: it ask user about his information to login and, make sure it is True
----------------------------------------------------------------------------
*/
int login_user(int *User_Id)
{
        struct STUDENTS *HELP=NULL;
        char check_password[50];
        int check_id;
        int c,i=0;
        int attempts=3,Flag=0;


        clearScreen();
        while(attempts--)
        {
                printf("*****************************\n");
                printf("Enter id:");
                scanf("%i", &check_id);
                printf("Enter password:");
                for (i = 0; i < 50; i++)
                {
                    c = getch();
                    if(c == 13)
                            break;
                    printf("*");
                    check_password[i]=c;
                }
                check_password[i]='\0';
                printf("\n");
                printf("\n*****************************\n");
                if (Head == NULL)
                {
                    printf("\nThere isn't any data.\n");
                    Flag= -1;
                    break;
                }
                else
                {
                        HELP = Head;
                        while (HELP != NULL)
                        {
                            if (HELP->Id == check_id && strcmp(HELP->Password ,check_password)==0)
                            {
								*User_Id=HELP->Id;
                                Flag=1;
                                printf("\n*****************************\n");
                                printf("Login Successfully ! \n");
                                printf("*****************************\n");
                                break;
                                //menu_user();
                            }
                            HELP = HELP->NEXT;

                            if (HELP == NULL)
                            {
                                printf("wrong ID.\n");
                            }
                        }

                if(Flag==1)
                {
                    break;
                }
                else
                {
                    if(attempts!=0)
                    {
						   //clearScreen();
                        printf("Invalid username or password You Can Try Again.\n");
                    }
                    else
                    {
                        printf("No matter what you do, thief, you will not be able to hack the system\n");
                        Flag= -1;
                    }

                }
                    printf("*****************************\n");
                }

        }
        return Flag;
}
