#include "8583.h"

int main(int argc, char const *argv[])
{
	BYTE buf[2000];
	memset( buf , 0x00 , sizeof(buf));
	char errmsg[200];
	FILE *fp = fopen( "message.txt" , "r");
	int i = 0;
	int byte = 0;
	while( fscanf( fp , "%02X" , &byte) != EOF )
	{
		buf[i] = (BYTE)byte;
		i++;
	}
	fclose(fp);
	CUPS_MESSAGE_t *message = CUPS8583_parseMessage( buf , errmsg);
	if ( message == NULL )
	{
		printf( "error : %s\n" , errmsg);
	} else {
		CUPS8583_printMessage( message );
	}
	return 0;
}