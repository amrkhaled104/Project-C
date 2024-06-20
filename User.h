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
/*
----------------------------------------------------------------------------
Name:user
Parameters:No parameters
Return: Nothing to return
Usage: it ask if he want menu or to exit.
----------------------------------------------------------------------------
*/
void user();
/*
----------------------------------------------------------------------------
Name:menu_user
Parameters:No parameters
Return: Nothing to return
Usage: it show menu for user and ask him to choose what page he want to go to.
----------------------------------------------------------------------------
*/
void menu_user();
/*
----------------------------------------------------------------------------
Name:Find_Student
Parameters:No parameters
Return: Nothing to return
Usage: it used to search about student in memory.
----------------------------------------------------------------------------
*/
void Find_Student();
/*
----------------------------------------------------------------------------
Name:View_your_record
Parameters:No parameters
Return: Nothing to return
Usage: it used to View his record.
----------------------------------------------------------------------------
*/
void View_your_record();
/*
----------------------------------------------------------------------------
Name:Edit_your_password
Parameters:No parameters
Return: Nothing to return
Usage: it used to Edit his saved password in memory.
----------------------------------------------------------------------------
*/

void Edit_your_password();
/*
----------------------------------------------------------------------------
Name:Edit_your_name
Parameters:No parameters
Return: Nothing to return
Usage: it used to Edit his saved name in memory.
----------------------------------------------------------------------------
*/
void Edit_your_name();
#endif
