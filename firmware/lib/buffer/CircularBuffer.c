#include "CircularBuffer.h"
#include <stdio.h>
#include <stdlib.h>  

CircularBuffer *circular_buffer_new(unsigned int size){
	char *buffer;
	buffer = (char*) malloc( sizeof(char) * (size));
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
		printf("  b ");
	else
	if(buffer->start == i )
		printf("  s ");
	else
	if( buffer->end == i)
		printf("  e ");
	else
		printf("    ");
}
printf("\n\n");


	printf("-------------\n| Buffer    |\n| Start: %i  |\n| End: %i    |\n| Size: %i |\n-------------\n",buffer->start,buffer->end,buffer->size);


}


int main(void){
printf("Creating buffer...\n");
CircularBuffer buffer;
buffer = circular_buffer_new(16);
circular_buffer_debug(&buffer);
printf("Putting char in buffer\n");
for(int i = 0; i < 4; i++){
circular_buffer_put(&buffer,'a');
circular_buffer_debug(&buffer);
circular_buffer_put(&buffer,'b');
circular_buffer_debug(&buffer);
circular_buffer_put(&buffer,'c');
circular_buffer_debug(&buffer);
}
printf("Getting char out of buffer:'%c'\n",circular_buffer_get(&buffer));
circular_buffer_debug(&buffer);


for(int i = 0; i < 14; i++){
printf("Getting char out of buffer:'%c'\n",circular_buffer_get(&buffer));
printf("is buffer empty:'%s'\n",circular_buffer_isempty(&buffer)?"True":"False");}

return 1;
}

*/
