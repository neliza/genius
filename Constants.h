#define BUZZER 15

#define WAITING_START   	0 
#define PLAYING_SEQ     	1
#define USER_TYPING     	3
#define VALIDATING_SEQ  	4
#define WAITING_EASTER_EGG 	5

#define BTN_RED    				11
#define BTN_WHITE  				10
#define BTN_BLUE   				9
#define BTN_PINK   				8
#define BTN_START    			3

#define L_RED    	7
#define L_WHITE 	6
#define L_BLUE  	5
#define L_PINK  	4

#define DEBUGGING 0

const int BOTOES_SEQ[]={BTN_START,BTN_RED,BTN_WHITE,BTN_BLUE,BTN_PINK};

const int EASTER_EGG_SEQ[] = { BTN_PINK, BTN_PINK, BTN_WHITE, BTN_WHITE, BTN_RED, BTN_BLUE, BTN_RED, BTN_BLUE };