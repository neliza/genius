#define BUZZER 22

#define WAITING_START   	  0 
#define PLAYING_SEQ     	  1
#define USER_TYPING     	  3
#define VALIDATING_SEQ  	  4
#define WAITING_EASTER_EGG 	5

#define BTN_WHITE    			9
#define BTN_RED  				  10
#define BTN_BLUE   				11
#define BTN_PINK   				12
#define BTN_START    			24

#define L_PINK  	4
#define L_BLUE  	5
#define L_RED    	6
#define L_WHITE 	7


#define DEBUGGING 1

const int BOTOES_SEQ[]={BTN_START,BTN_WHITE,BTN_RED,BTN_BLUE,BTN_PINK};

const int EASTER_EGG_SEQ[] = { BTN_PINK, BTN_PINK, BTN_RED, BTN_RED, BTN_WHITE, BTN_BLUE, BTN_WHITE, BTN_BLUE };
