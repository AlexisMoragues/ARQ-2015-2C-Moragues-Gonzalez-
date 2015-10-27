#include "./fn.c"

static const char* video = (char *) 0xB8000;
static char* currentVideo = (char *) 0xB8000;


void print(char* msg, int colour){
	int leng = strLength(msg);
	int i=0;
	int j=0;

	while(i < leng){
	currentVideo[j] = msg[i];
	currentVideo[j+1] = (char) colour;
	i++;
	j+=2;
	}
 
}

