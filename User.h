#ifndef User_h
#define User_h
struct STUDENTS
{
    //name, total grade, unique id, age, gender, and password.
    char Name[30];
    char Password[10];
    char Gender[10];
    float Grade;
    int Id;
    int Age;
	struct STUDENTS *NEXT;
};
void user();
void login();
void View_your_record();
void Edit_your_password();
void Edit_your_name();
#endif




