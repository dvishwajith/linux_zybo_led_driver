#include "dvrowled_wrap.h"
#include <unistd.h>

int main(int argc, char const *argv[])
{
	init_led_module();
	get_led_status();
	set_led_status(0x0);
	sleep(10);
	set_led_status(0x4);
	sleep(10);
	set_led_status(0x2);
	sleep(10);
	set_led_status(0x6);
	sleep(10);
	set_led_status(0xf);
	sleep(10);
	

	/* code */
	return 0;
}