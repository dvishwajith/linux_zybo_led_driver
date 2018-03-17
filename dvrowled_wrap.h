#ifndef DVROWLED_WRAP
#define DVROWLED_WRAP

#ifdef __cplusplus
extern "C" {
#endif

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<errno.h>
#include	<fcntl.h>
#include	<string.h>
#include 	<stdbool.h>


bool is_pqled_open = false ;
int fd_dvled ;
int ret_pqled_status ;

int init_led_module(){
	fd_dvled = open ("/dev/dvrowled", O_RDWR);
	if(fd_dvled < 0){
		printf("dvrowled failed to open\n");
		return -1 ;
	}
	is_pqled_open = true ;
	return 0 ;
}


int get_led_status(){
	if(is_pqled_open){
		unsigned int led_status;
		ret_pqled_status = read(fd_dvled , &led_status , 4);
		if(ret_pqled_status<0){
			printf("Error while raeding LED status..\n");
			return -1 ;
		}
		return led_status ;
	} else {
		printf("get_led_status: Device not open\n");
	}
	return -1 ;

}


int set_led_status(unsigned int state){
	if(is_pqled_open){
		ret_pqled_status = write(fd_dvled , &state , 4);
		if(ret_pqled_status<0){
			printf("Error while raeding LED status..\n");
			return -1 ;
		}
		return 0  ;
	} else {
		printf("set_led_status :Device not open\n");
	}
	return -1 ;
}


int close_led_module(){
	if(is_pqled_open){
		ret_pqled_status = close(fd_dvled);
		if(ret_pqled_status<0){
			return -1 ;
		}
		return 0 ;
	} else{
		printf("close_led_module :Device not open\n");
	}
	return -1 ;
}


#ifdef __cplusplus
}
#endif

#endif /* PQ_LED_KWRAP_H */