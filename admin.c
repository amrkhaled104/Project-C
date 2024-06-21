#include "Heder.h"

extern  struct STUDENTS * Head;
struct STUDENTS * HELP=NULL;
struct STUDENTS * PAST=NULL;
struct STUDENTS * TEMP=NULL;
char admin_password[10];

void admin()
{

   /*printf("loading");
    for(int i=0;i<3;i++)
        {
            printf(".");
            sleep(1);
        }*/
    clearScreen();
    char choice_2;
    while(1)
    {
        printf("***************************\n");
        printf("for menu enter  [M] : \n");
        printf("for exit  enter [E] : \n");
	    printf("for BACK enter  [B] : \n");
        printf("***************************\n");
        fflush(stdin);
        scanf("%c",&choice_2);
        if(choice_2=='M')
        {
            menu_admin();
        }
        else if (choice_2=='E')
        {
            EXIT();
            break;
        }
		else if (choice_2=='B')
        {
            first_page();
            break;
        }
        else
        {
            printf("Invalid option!!!!!!\n");
        }
    }

}

void menu_admin(){
    /*printf("loading");
    for(int i=0;i<3;i++)
        {
            printf(".");
            sleep(1);
        }*/
    clearScreen();
    unsigned int menu_choice;
    printf("                 menu                  \n");
    printf("*******************************************\n");
    printf("for Add student record enter     [1] : \n");
    printf("for Remove student record  enter [2] : \n");
    printf("for View student record enter    [3] : \n");
    printf("for View all records  enter      [4] : \n");
    printf("for Edit admin password enter    [5] : \n");
    printf("for Edit student grade enter     [6] : \n");
    printf("*******************************************\n");
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
				printf("Invalid option!!!!!! \n");sleep(1);
				menu_admin();
		}

}

void Add_student_record()
{
    /*printf("loading");
    for(int i=0;i<3;i++)
        {
            printf(".");
            sleep(1);
        }*/
    clearScreen();
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
//name---------------------
	printf("Enter Name:\n");gets(SNew->Name);
	fflush(stdin);
//grade--------------------
    while (1)
    {
        while (1)
         {
            printf("Enter Grade (0 -> 100):\n");
            if (scanf("%f", &SNew->Grade) == 1)
            {
                break;
            }
            else
            {
                printf("Invalid input, please enter a floating-point number.\n");
                while (getchar() != '\n');
            }
        }

        if (SNew->Grade >= 0 && SNew->Grade <= 100)
        {
            break;
        } else
        {
            printf("Invalid option, please enter a grade between 0 and 100.\n");
        }
    }
	fflush(stdin);
//ID--------------------
	struct STUDENTS * CheckID=NULL;
		CheckID=Head;
    while(1)
    {
		 while (1)
        {
            printf("Enter ID:\n");
            if (scanf("%i", &SNew->Id) == 1)
            {
                break;
            }
            else
            {
                printf("Invalid input, please enter an integer.\n");
                while (getchar() != '\n');
            }
        }

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

//GENDER----------------------
    while(1)
    {
        printf("Enter Gender (male/female):\n");
        scanf(" %s",&SNew->Gender);
        if(strcmp("female",SNew->Gender)!=0 && strcmp("male",SNew->Gender)!=0)
        {
            printf("invalid option\n");
        }
        else
        {
            break;
        }
    }
//age------------------------
	while(1) {
        printf("Enter Age:\n");
        if (scanf("%d", &SNew->Age) == 1) {
            break;
        } else {
            printf("Invalid input, please enter an integer.\n");
            while(getchar() != '\n');
        }
    }
//password--------------------
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
	printf("\nDONE \n");
	printf("***************************\n");
}

void View_all_records()
{
    /*printf("loading");
    for(int i=0;i<3;i++)
        {
            printf(".");
            sleep(1);
        }*/
    clearScreen();
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

		printf("<-STUDENT[%d]->\nName:%s\nGrade:%0.2f\nID:%d\nGender:%s\nAge:%d\nPassword:%s\n\n\n",++counter_Client,HELP->Name,HELP->Grade,HELP->Id,HELP->Gender,HELP->Age,HELP->Password);
		HELP=HELP->NEXT;
	}
}
void View_student_record ()
{
    /*printf("loading");
    for(int i=0;i<3;i++)
        {
            printf(".");
            sleep(1);
        }*/
    clearScreen();
    int found =0 ;
    int user_id=0;
    printf("Enter Id :");scanf("%d",&user_id);
	HELP=Head;
	while(HELP!=NULL)
	{

        if(HELP->Id==user_id)
        {
            found =1 ;
            printf("\n         student info           \n");
            printf("************************************\n");
            printf("Name: %s    \n", HELP->Name);
            fflush(stdin);
            printf("Grade: %0.2f \n", HELP->Grade);
            printf("ID: %d\n", HELP->Id);
            printf("Gender: %s\n", HELP->Gender);
            fflush(stdin);
            printf("Age: %d\n", HELP->Age);
            printf("Password: %s\n\n", HELP->Password);
            printf("*********************************");


            printf("\n");
            break;
	   }
	  HELP= HELP->NEXT ;
	}

	if (!found) printf("Student with ID %d Not Found Ya Admoooooooooooooooooon.\n", user_id);
}
void Edit_admin_password() {
    FILE *file;
    char line[100];
    int c, i = 0;
    char password[10];
    char *token;
    char username[50];
    clearScreen();
    printf("Enter username: ");
    scanf("%s",username);
    printf("\n");
    printf("Enter new password:");
    for (i = 0; i < 10; i++)
    {
        c = getch();
        if(c == 13 )
            break;
        printf("*");
        password[i]=c;
    }
    password[i]='\0';

    file = fopen("Admin_info.csv", "r+");
    if (file == NULL)
    {
        printf("Unable to open file.\n");
        return;
    }
   size_t username_length = strlen(username);

    // Read each line from the file
    while (fgets(line, sizeof(line), file) != NULL)
    {
        // Find the username in the line
        token = strtok(line, ",");
        if (token != NULL && strncmp(token, username, username_length) == 0) {

            fseek(file, 0, SEEK_SET); // Move the file pointer back to the start of the line
            fprintf(file, "%s,%s\n", username, password); // Write the new line
            printf("\nPassword updated successfully.\n");
            fclose(file);
            return;
        }
    }
    // If the password is not found, print an error message
    printf("\nPassword not found.\n");
    fclose(file);
}
void Edit_student_grade() {
    unsigned int check_id, new_grade;
    char choice;
   /* printf("loading");
    for(int i=0;i<3;i++)
        {
            printf(".");
            sleep(1);
        }*/
    clearScreen();
    printf("***********************************\n");
    printf("Enter ID of student to edit:\n");
    scanf("%u", &check_id);

    if (Head == NULL) {
        printf("\nThere isn't any data.\n");
        return;
    }

    HELP = Head;
    while (HELP != NULL) {
        if (HELP->Id == check_id)
        {
            printf("Correct ID\n");
            printf("Enter new grade: ");
            scanf("%i", &new_grade);

            if (new_grade >= 0 && new_grade <= 100)
            {
                HELP->Grade = new_grade;
                printf("Grade updated successfully.\n");
                break;
            }
            else
            {
                printf("Grade out of range.\n");
                printf("***********************************\n");
                printf("To try again press [T]:\n");
                printf("To exit press      [E]:\n");
                scanf(" %c", &choice);
                printf("***********************************\n");
                switch (choice) {
                    case 'T':
                        Edit_student_grade();
                        break;
                    case 'E':
                        EXIT();
                        return;
                    default:
                        printf("Invalid option!\n");
                        break;
                }
            }
        }
        HELP = HELP->NEXT;
    }

    if (HELP == NULL) {
        printf("No student registered with this ID.\n");
    }

    printf("***********************************\n");
}

void Remove_student_record(){
    unsigned int check_id;
    char choice;
    /*printf("loading");
    for(int i=0;i<3;i++)
        {
            printf(".");
            sleep(1);
        }*/
    clearScreen();
    printf("***********************************\n");
    printf("Enter ID of student to delete:\n");
    scanf("%i", &check_id);

    if (Head == NULL)
    {
        printf("\nThere isn't any data.\n");
        return;
    }
    else
    {
        HELP = Head;
        while (HELP != NULL)
        {
            if (HELP->Id == check_id)
            {
                printf("Correct ID\n");
                if (PAST == NULL)
                { // If the node to delete is the head
                    Head = HELP->NEXT;
                }
                else
                {
                    PAST->NEXT = HELP->NEXT;
                }
                TEMP = HELP;
                HELP = HELP->NEXT;
                free(TEMP); // Free memory
                printf("Deleted successfully.\n");
                printf("***********************************\n");

                return;
            }
            PAST = HELP;
            HELP = HELP->NEXT;
         }
         printf("No student registered with this ID.\n");
         printf("***********************************\n");
    }
}





//gcc admin.c User.c Mangment.c main.c -o p.exe
