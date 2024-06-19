#include "Heder.h"

char choise_2;
/*
----------------------------------------------------------------------------
Name:first_page
Parameters:No parameters
Return: Nothing to return
Usage: it used to guide to the next page .
----------------------------------------------------------------------------
*/
void first_page(){
	int ret =Login();
    unsigned int choise;

        switch(ret)
        {
        case 1:
            admin();
            break;
        case 2:
            user();
            break;
        case -1:  // when no info saved in memory or he couldn't login
            EXIT();
            break;
        default:
            printf("Invalid option!!!!!! \n");
            a:for(int i=0;i<1;i++){
			//clearScreen();
			printf("***************************\n");
			printf("for exit enter   [E] : \n");
			printf("for again  enter [L] : \n");
			printf("***************************\n");
			fflush(stdin);
			scanf("%c",&choise_2);
			switch(choise_2)
			{
			case 'E':
				EXIT();
				break;
			case 'L':
                first_page();
				//clearScreen();
				break;
			default:
				printf("Invalid option!!!!!! \n");
				goto a;
			}
		}
    }

}
/*
----------------------------------------------------------------------------
Name:clearScreen
Parameters:No parameters
Return: Nothing to return
Usage: it used to clear screen after each process.
----------------------------------------------------------------------------
*/

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

}
/*
----------------------------------------------------------------------------
Name:EXIT
Parameters:No parameters
Return: Nothing to return
Usage: it used to exit out of program.
----------------------------------------------------------------------------
*/
void EXIT(){
    printf("loading");
    for(int i=0;i<3;i++)
        {
            printf(".");
            sleep(1);
        }
    clearScreen();
    printf("thank you <3 \n");
}
/*
----------------------------------------------------------------------------
Name:welcome_admin
Parameters:No parameters
Return: Nothing to return
Usage: it used to register for the first time.
----------------------------------------------------------------------------
*/
int welcome_admin() {
    char Username[50];
    char Pasword[50];

    FILE *file;
    long size;

    // افتح الملف للقراءة
    file = fopen("Admin_info.csv", "r");

    // التحقق من نجاح فتح الملف
    if (file == NULL) {
        printf("Error opening file.");
        exit(1);
    }

    // انتقل إلى نهاية الملف
    fseek(file, 0, SEEK_END);

    // احصل على موقع المؤشر (حجم الملف)
    size = ftell(file);

    // إعادة ضبط المؤشر إلى بداية الملف
    rewind(file);

    // التحقق من حجم الملف
    if (size == 0) {
        printf("mar7b m3lmm\n\n");
        printf("Enter Username: ");
        scanf("%s", Username);
        printf("Enter Pasword: ");
        scanf("%s", Pasword);

        // إعادة فتح الملف للكتابة
        fclose(file);
        file = fopen("Admin_info.csv", "w");
        if (file == NULL) {
            printf("Error opening file.");
            exit(1);
        }

        // كتابة البيانات إلى الملف
        fprintf(file, "%s,%s\n", Username, Pasword);

        // إغلاق الملف
        fclose(file);
		EXIT();
       return 1;
    } else {
        fclose(file);
        return 0;
    }
}
extern  struct STUDENTS * Head;
struct STUDENTS *HELP2=NULL;

int flagg=0;
/*
---------------------------------------------------------------------------------------------------
Name:save_data
Parameters:No parameters
Return: Nothing to return
Usage: it used to save data after all function done (after changes in memory,to update csv file).
----------------------------------------------------------------------------------------------------
*/
void save_data()
 {
    FILE *file = fopen("Student.csv", "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    fclose(file);

    HELP2 = Head;
    while (HELP2 != NULL) {
        file = fopen("Student.csv", "a");
        if (file == NULL) {
            printf("Error opening file.\n");
            exit(1);
        }

        fprintf(file, "%s,%f,%d,%s,%d,%s\n", HELP2->Name, HELP2->Grade, HELP2->Id, HELP2->Gender,HELP2->Age, HELP2->Password);
        HELP2 = HELP2->NEXT;
        fclose(file);
    }
}

/*
----------------------------------------------------------------------------
Name:clear_list
Parameters:No parameters
Return: Nothing to return
Usage: it used to free memory(linked list space).
----------------------------------------------------------------------------
*/
void clear_list()
 {
    while (Head != NULL)
        {
        struct STUDENTS *ptr = Head;
        Head = Head->NEXT;
        free(ptr);
        }
 }
/*
----------------------------------------------------------------------------
Name:load_data
Parameters:No parameters
Return: Nothing to return
Usage: it used to load data at the beginning of program.
----------------------------------------------------------------------------
*/
void load_data(){
	flagg=0;
    clear_list();
    FILE *file = fopen("Student.csv", "r");
    if (file == NULL)
        {
			printf("Error opening file.\n");
			exit(1);
        }
    char line[200];
    while (fgets(line, sizeof(line), file)) {
        struct STUDENTS *newStudent = (struct STUDENTS *)malloc(sizeof(struct STUDENTS));
        if (newStudent == NULL) {
            printf("Memory allocation failed.\n");
            exit(1);
        }

        sscanf(line, "%99[^,],%f,%d,%99[^,],%d,%s\n", newStudent->Name, &newStudent->Grade, &newStudent->Id, newStudent->Gender,&newStudent->Age, newStudent->Password);

        newStudent->NEXT = NULL;
        if(flagg++==0) Head = newStudent;
		else
		{
			HELP2=Head;
			while(HELP2->NEXT!=NULL) HELP2=HELP2->NEXT;
			HELP2->NEXT=newStudent;
		}
    }
    fclose(file);
}
