#include "Heder.h"
unsigned int ret_choise;
char choise_2;
void first_page()
{
    unsigned int choise;
    printf("loading");
    for(int i=0;i<3;i++)
        {
            printf(".");
            sleep(1);
        }


        clearScreen();
        printf("***************************\n");
        printf("for admin enter 1 : \n");
        printf("for user  enter 2 : \n");
        printf("***************************\n");
        scanf("%i",&choise);
		clearScreen();
        printf("loading");
        for(int i=0;i<3;i++)
            {
                printf(".");
                sleep(1);
            }
        printf("\n");
        clearScreen();
        switch(choise)
        {
        case 1:
            admin();
            break;
        case 2:
            user();
            break;
        default:
            printf("Invalid option!!!!!! \n");
        }
        printf("loading");
        for(int i=0;i<3;i++)
            {
                printf(".");
                sleep(1);
            }
		a:for(int i=0;i<1;i++){	
			clearScreen();
			printf("***************************\n");
			printf("for exit enter E  : \n");
			printf("for again  enter L : \n");
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
				clearScreen();
				break;
			default:
				printf("Invalid option!!!!!! \n");
				printf("loading");
		        for(int i=0;i<3;i++)
				{
					printf(".");
					sleep(1);
				}
				goto a;
			}
		}
}

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

}
void EXIT()
{
    printf("loading");
    for(int i=0;i<3;i++)
            {
                printf(".");
                sleep(1);
            }
        clearScreen();
    printf("thank you <3 \n");
}
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
