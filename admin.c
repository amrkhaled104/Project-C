#include "Heder.h"
//عملتله اكسترين علشان ف هنا فانكشن معتمده علهيه وعلشان اعرف استخدمه 
extern  struct STUDENTS * Head;
struct STUDENTS * HELP=NULL;
char admin_password[10];
void admin()
{   printf("loading");
    for(int i=0;i<3;i++)
        {
            printf(".");
            sleep(1);
        }

    clearScreen();
    char choice_2;
    printf("***************************\n");
    printf("for login enter L : \n");
    printf("for back  enter B : \n");
    printf("***************************\n");
    fflush(stdin);
    scanf("%c",&choice_2);
    switch(choice_2)
        {
        case 'L':
            login_admin();
            break;
        case 'B':
            first_page();
            break;
        default:
            printf("Invalid option!!!!!! \n");
        }
}
int login_admin()
{  
	FILE *file;
	char username[50];
	char password[50];
	char file_username[50];
	char file_password[50];
    printf("loading");
    for(int i=0;i<3;i++)
        {
            printf(".");
            sleep(1);
        }
    clearScreen();
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
						clearScreen();
						printf("\nLogin Successful! \n");
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
				    return 0;
				}
				// أغلق ملف النص
				fclose(file);
    printf("loading");
    for(int i=0;i<3;i++)
        {
            printf(".");
            sleep(1);
        }
		 unsigned int menu_choice;
    clearScreen();
    printf("               menu                  \n");
    printf("*************************************\n");
    printf("for Add student record enter 1     : \n");
    printf("for Remove student record  enter 2 : \n");
    printf("for View student record enter 3    : \n");
    printf("for View all records  enter 4      : \n");
    printf("for Edit admin password enter 5    : \n");
    printf("for Edit student grade enter 6     : \n");
    printf("*************************************\n");
    fflush(stdin);
    scanf("%i",&menu_choice);
    switch(menu_choice)
        {
        case 1:
            Add_student_record();
            break;
        case 2:
            Remove_student_record();
            break;
        case 3:
            View_student_record();
            break;
        case 4:
            View_all_records();
            break;
        case 5:
            Edit_admin_password();
            break;
        case 6:
            Edit_student_grade();
            break;
        default:
            printf("Invalid option!!!!!! \n");
        }
}
void Add_student_record()
{
    struct STUDENTS *SNew;
	if(Head==NULL)
	{
		SNew=(struct STUDENTS*)malloc(sizeof(struct STUDENTS));
		Head=SNew;
	}
	else
	{
		HELP=Head;
		while(HELP->NEXT!=NULL)
			HELP = HELP->NEXT;
		SNew=( struct STUDENTS*)malloc(sizeof( struct STUDENTS));
		HELP->NEXT=SNew;
	}
	SNew->NEXT=NULL;
	fflush(stdin);
	printf("Now You Enter Data Please Foucs\n\n");
	printf("Enter Name:\n");gets(SNew->Name);
	fflush(stdin);
	printf("Enter Grade:\n");scanf("%d",&SNew->Grade);
	while(1)
    {
		struct STUDENTS * CheckID=NULL;
		CheckID=Head;
		printf("Enter ID:\n");scanf("%d",&SNew->Id);
        while(CheckID->NEXT!=NULL)
        {
            if(CheckID->Id==SNew->Id)
            {
                printf("This ID Is Exist ,Try Again \n");
				break;
            }
            else
            {
				 CheckID = CheckID->NEXT;
            }
        }
		if(CheckID->NEXT==NULL) break;
    }
	
	printf("Enter Gender:\n");scanf("%s",&SNew->Gender);
	printf("Enter Age:\n");scanf("%s",&SNew->Age);
	printf("Enter Password:\n");
	int c;int i;
    for (i = 0; i < 50; i++)
    {
        c = getch();
        if(c == 13)
          break;
        printf("*");
        SNew->Password[i]=c;
    }
	SNew->Password[i] = '\0';
	printf("\n");
}
void View_all_records()
{
	HELP=Head;
	int counter_Client=0;
	if(HELP==NULL)
	{
		printf("Mafesh Lsa Tolaaaab Ya Admin\n");
	}
	int i=0;
	while(HELP!=NULL)
	{
		if(i++==0)
		printf("                                                     STUDENTS LIST                                                         \n");

		printf("<-STUDENT[%d]->\nName:%s\nGrade:%d\nID:%d\nGender:%s\nAge:%d\nPassword:%s\n\n\n",++counter_Client,HELP->Name,HELP->Grade,HELP->Id,HELP->Gender,HELP->Age,HELP->Password);
		HELP=HELP->NEXT;
	}
}


void View_student_record ()
{

    int found =0 ;
    int user_id=0;
    printf("Enter Id :");scanf("%d",&user_id);
	HELP=Head;
	while(HELP!=NULL)
	{
        printf("                         Student Information                     \n");

	  if(HELP->Id==user_id)
	  {
		  found =1 ;
		printf("\nName:%s\nGrade:%d\nID:%d\nGender:%s\nAge:%d\nPassword:%s\n\n\n",HELP->Name,HELP->Grade,HELP->Id,HELP->Gender,HELP->Age,HELP->Password);
		  break;
	  }
	  HELP= HELP->NEXT ;
	}

	if (!found) printf("Student with ID %d Not Found Ya Admoooooooooooooooooon.\n", user_id);
}
void Edit_admin_password()
{

}
void Edit_student_grade()
{

}
void Remove_student_record()
{
	
}
//gcc admin.c User.c Mangment.c main.c -o p.exe