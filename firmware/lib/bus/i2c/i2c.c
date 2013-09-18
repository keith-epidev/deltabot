//lcd.c
#include "display.h"
#include <string.h>


void shift_buffer(Display *display);
void new_line(Display *display);

Display display_new(LCD *lcd){
	char buffer[lcd->col+1][lcd->row+2]; //why does this need an extra char?
	memset(buffer,32,lcd->col*lcd->row);
	Display display = {lcd,buffer,0};
	return display;
}


void display_print(Display *display,char *string){

	if(display->pointer+strlen(string) >= display->lcd->row*display->lcd->col){
		//shift buffer up
		shift_buffer(display);	
		display->pointer = display->pointer-display->lcd->col;
	}	

	for(int i = 0; i < strlen(string); i++){
		char c = string[i];

		switch(c){
			case '\n':
				shift_buffer(display);
				new_line(display);
				break;
			default:
				display->buffer[display->pointer] = c;
				display->pointer++;

		}
	}
	display_commit(display);
}


void shift_buffer(Display *display){
	for(int i = 1; i < display->lcd->row; i++){
		memcpy(&display->buffer[(i-1)*display->lcd->col],&display->buffer[i*display->lcd->col],display->lcd->col);	
	}
	memset(&display->buffer[(display->lcd->row-1)*(display->lcd->col)],32,display->lcd->col);

}

void new_line(Display *display){
	display->pointer = (display->lcd->row-1)*(display->lcd->col);
}


void display_commit(Display *display){
	//write_string(display->lcd,display->buffer);	
//	write_string(display->lcd,"123");	
	
	for(int i = 0; i < display->lcd->col*display->lcd->row; i++){
		write_character(display->lcd, display->buffer[i]);
	}


}
