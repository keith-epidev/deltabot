#include "CircularBuffer.h"
#include <stdio.h>
#include <stdlib.h>  

static volatile char buffers[2][64];
int buffer_index = 0;


CircularBuffer *circular_buffer_new(unsigned int size){
	volatile char *buffer;
//	buffer = (char*) malloc( sizeof(char) * (size));

buffer = &buffers[buffer_index++];

	for(int i = 0; i < size; i++)
		buffer[i] = 0;

//	CircularBuffer temp = {buffer,0,0,size};
	CircularBuffer *temp = (CircularBuffer *) malloc( sizeof( CircularBuffer ) );

	temp->buffer = buffer;
	temp->start = 0;
	temp->end = 0;
	temp->size = size;

	return temp;
}


void circular_buffer_put(CircularBuffer *buffer, char c){
	buffer->buffer[buffer->end] = c;
	buffer->end = (buffer->end+1)%buffer->size;
	if(buffer->start == buffer->end)
		buffer->start = (buffer->start+1)%buffer->size;;
}


void circular_buffer_putstr(CircularBuffer *buffer,char *str){
	int i = 0;
	while(str[i] != '\0'){
		circular_buffer_put(buffer,str[i]);
		i++;
	}
}

char circular_buffer_get(CircularBuffer *buffer){
	if(buffer->start == buffer->end)
		return 0;

	char temp = buffer->buffer[buffer->start];
	buffer->start = (buffer->start+1)%buffer->size;

	return temp;
}

char circular_buffer_get_index(CircularBuffer *buffer, int i){
	char temp = buffer->buffer[(buffer->start+i)%buffer->size];
	return temp;
}

void circular_buffer_put_index(CircularBuffer *buffer, int i, char data){
	buffer->buffer[(buffer->start+i)%buffer->size] = data;
}

void circular_buffer_shift(CircularBuffer *buffer, int size){
	buffer->start = (buffer->start+size)%buffer->size;
	buffer->end = (buffer->end+size)%buffer->size;
}

char circular_buffer_pop(CircularBuffer *buffer){
	if(buffer->start == buffer->end)
		return 0;

	char temp = buffer->buffer[buffer->end-1];
	buffer->end = (buffer->end-1)%buffer->size;
	return temp;
}



char circular_buffer_isempty(CircularBuffer *buffer){
	return (buffer->start == buffer->end);
}

/*
void circular_buffer_debug(CircularBuffer *buffer){
	for(int i = 0; i < buffer->size; i++){
		printf("| %c ",buffer->buffer[i]);
	}
	printf("|\n");

	for(int i = 0; i < buffer->size; i++){
		if(buffer->start == i && buffer->end == i)
			printf("--b-");
		else
		if(buffer->start == i )
			printf("--s-");
		else
		if( buffer->end == i)
			printf("--e-");
		else
			printf("----");
	}
	printf("\n\n");


		printf("-------------\n| Buffer    |\n| Start: %i  |\n| End: %i    |\n| Size: %i |\n-------------\n",buffer->start,buffer->end,buffer->size);


}

int main(void){
	printf("Creating buffer...\n");
	CircularBuffer *buffer;
	buffer = circular_buffer_new(16);

	for(int i = 0; i < 20; i++){
	circular_buffer_put_index(buffer,i,i+'a');
	printf("at %i='%c'\n",i,circular_buffer_get_index(buffer,i));
	circular_buffer_debug(buffer);
	}

	circular_buffer_debug(buffer);
	printf("Putting char in buffer\n");
	for(int i = 0; i < 5; i++){
	circular_buffer_put(buffer,'a');
	circular_buffer_debug(buffer);
	circular_buffer_put(buffer,'b');
	circular_buffer_debug(buffer);
	circular_buffer_put(buffer,'c');
	circular_buffer_debug(buffer);
	}
	printf("shifting\n");
	circular_buffer_shift(buffer,8);
	circular_buffer_debug(buffer);

	circular_buffer_put_index(buffer,8,'x');
	printf("at 4=%c\n",circular_buffer_get_index(buffer,8));
	circular_buffer_debug(buffer);

	

	printf("Getting char out of buffer:'%c'\n",circular_buffer_get(buffer));
	circular_buffer_debug(buffer);


	for(int i = 0; i < 14; i++){
	printf("Getting char out of buffer:'%c'\n",circular_buffer_get(buffer));
	printf("is buffer empty:'%s'\n",circular_buffer_isempty(buffer)?"True":"False");}
	return 1;
}


*/
