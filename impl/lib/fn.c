static const char* video = (char *) 0xB8000;
static char* currentVideo = (char *) 0xB8000;
static const int width = 80;
static const int height = 25 ;


void print(char* msg, int colour){
	int leng = strLength(msg);
	int i=0;
	while(i < leng){
	currentVideo[0] = msg[i];
	currentVideo[1] = (char) colour;
	i++;
	currentVideo+=2;
	}
 
} 

void nextLine(){
	int residue = ((int)currentVideo - (int)video)%width;
	currentVideo += 2*width;
	currentVideo -= residue;
}

void mrClean(){
	int wholeScreen = width * height * 2;
	currentVideo = (char*) 0xB8000;
	while(wholeScreen){
		print(" ", 0x00);
		wholeScreen--;
	}
}

void printNumber(int number, int colour){
	int length = intLength(number);
	int numberAux = number;
	int powerDivisor = 0;
	char unitToPrintPosta [length+1] ;
	int counter = 0;
	while(length){
		powerDivisor = power(10, length-1);
		unitToPrintPosta[counter] =(char) (numberAux/(powerDivisor) + 48);
		counter++;
		numberAux = numberAux % powerDivisor;
		length--;
	}
	unitToPrintPosta[counter] = 0;
	print(unitToPrintPosta, colour);
}

int intLength(int number){
	int length = 0;
	if(number == 0){
		return 1;
	}
	while(number){
		length++;
		number = number/10;
	}
	return length;
}

int power(int number, int powerNumber){
	if(powerNumber == 0){
		return 1;
	}
	return power(number, powerNumber-1) * number;
}

void mrResetti(){
	currentVideo =  (char *) 0xB8000;
}

int strLength (char* msg) {
	int length = 0;
	while(*msg) {
	msg++;
	length++;
	}
	return length;
}

void playSound(int frequence) {
	int divisor;
	char tmp;
	print("holi", 0x13);
	divisor = 1193180 / frequence;
	OUTx(0x43, 0xBE);
	OUTx(0x42, (char) divisor);
	OUTx(0x42, (char) (divisor >> 8));
	tmp = INx(0x61);
	printNumber(tmp, 0x02);
	if(tmp != (tmp | 0x3)){
		OUTx(0x61, (tmp | 0x3));
		printNumber(tmp | 0x3, 0x09);
	}
}

void noSound() {
	char tmp = (INx(0x61) & 0xFC);
	printNumber(tmp, 0x04);
	OUTx(0x61, tmp);
}


void beepBoop(){
	playSound(1000);
	
	
}
int superGetSeconds(){
	int seconds = getSeconds();
	seconds = (0xF & seconds) + (10 * (seconds >> 4))+ (100 * (seconds >> 8))+ (1000 * (seconds >> 12));
	seconds = seconds % 60;
	return seconds;	
}

int superGetSeconds2(){
	int seconds = getSeconds2();
	seconds = (0xF & seconds) + (10 * (seconds >> 4))+ (100 * (seconds >> 8))+ (1000 * (seconds >> 12));
	seconds = seconds % 60;
	return seconds;	
}

int superGetMinutes(){
	int minutes = getMinutes2();
	minutes = (0xF & minutes) + (10 * (minutes >> 4)) + (100 * (minutes >> 8)) + (1000 * (minutes >> 12));
	minutes = minutes % 60;
	return minutes;
}

int superGetHours(){
	int hours = getHours2();
	hours = (0xF & hours) + (10 * (hours >> 4)) + (100 * (hours >> 8)) + (1000 * (hours >> 12));
	hours = hours % 24;
	return hours;

}

int getSeconds2(){
	OUTx(0x70, 0);
	return INx(0x71);
}

int getMinutes2(){
	OUTx(0x70, 2);
	return INx(0x71);	
}

int getHours2(){
	OUTx(0x70, 4);
	return INx(0x71);
}

int INx(int port);

void OUTx (int port, int value);

int getSeconds();

int getMinutes();

int getHours();

int cuatro();
