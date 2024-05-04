#include "Heder.h"

int main()
{
	/*دي هتكون فانكشن لو البرنامج بيتفتح لاول مره خالص شخص اشتراه وكدا هيطلب منه اسم الادمن والباسورد بتاعه ويبقي ثابت معانا بق ولو حب يغيره نغيرهوله عادي بس الفانكشن
دي هتشتغل مره واحده بس
*/
	if(welcome_admin()==1) goto a;
	clearScreen();
    load_data();
    first_page();
	save_data();
    a:return 0;
}
