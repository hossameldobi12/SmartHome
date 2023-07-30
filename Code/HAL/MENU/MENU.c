#include "STD_types.h"
#include "MENU.h"
#include  "main.h"



u8 ui8ComparePass(const u8* pass1,const u8* pass2,const u8 size)
{
	u8 pin_counter=0;
	u8 ret_value = TRUE;
	while (pin_counter<size)
	{
		if (*(pass1+pin_counter)!=*(pass2+pin_counter))
		{
			ret_value= FALSE;
			break;
		pin_counter++;
	}
	return ret_value;
    }
}