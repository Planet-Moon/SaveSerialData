#include <stdio.h>

#define n_data 50

FILE *f_serial;/*File Descriptor*/
FILE *f_log;

void Init_Serial(){
	
}

char Serial_read_byte( void ){
	char read_buffer = 0;
	read_buffer = fgetc(f_serial) & 0xFF;
	return read_buffer;
}

int main(){
	printf("hello world\n");
	f_serial = fopen("/dev/ttyUSB0","r");
	f_log = fopen("./log","w");
	printf("Init_Serial done\n");
	char data[n_data] = {0};
	for(int i = 0; i < n_data; i++){
		data[i] = Serial_read_byte();
		printf("read byte: %x \n", data[i]);
		fputc(data[i],f_log);
	}
	fclose(f_serial);
	fclose(f_log);
	return 0;
}
