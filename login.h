#ifndef Login_h
#define Login_h

/*
----------------------------------------------------------------------------
Name:Login
Parameters:No parameters
Return: it return(int)[1] if for admin,[2] for user and,
[-1] for wrong input or no data saved in memory
Usage: it ask if you are an admin or student and guide him to register page
----------------------------------------------------------------------------
*/

int Login();
/*
----------------------------------------------------------------------------
Name:login_admin
Parameters:No parameters
Return: it return [0] if compiler couldn't open file
Usage: it ask admin about his information to login and, make sure it is True
----------------------------------------------------------------------------
*/
int login_admin();
/*
----------------------------------------------------------------------------
Name:login_user
Parameters:one parameter (poiter to User Id)
Return: it return (int) Flag : [1] if he login Successfully and [-1]
(if he enter password or Id wrong 3 time) or(no data in memory)
Usage: it ask user about his information to login and, make sure it is True
----------------------------------------------------------------------------
*/
int login_user(int *);
#endif
