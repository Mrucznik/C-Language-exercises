#include <stdio.h>
#include <stdlib.h>

//Obraz przedstawia jakiœ napis, ale nie wiem co to jest
/*
Zawartosc pliku plik18a.txt
  ######                    #       ##  
                    ##     ####     ##  
  #####   #####    ####     ##    ##  ##
    ##      ##      ##    ######   #### 
    ##      ##        ##  ##      # ##  
   ####    ####    #####   ##       ##  
                                        
                                        

*/

unsigned char bmp[] = {
	0xfc, 0x00, 0x00, 0x10, 0x30,
	0xb4, 0x00, 0x00, 0x30, 0x78,
	0x30, 0x78, 0x7c, 0x7c, 0x78,
	0x30, 0xcc, 0xc0, 0x30, 0x30,
	0x30, 0xfc, 0x78, 0x30, 0x30,
	0x30, 0xc0, 0x0c, 0x34, 0x00,
	0x78, 0x78, 0xf8, 0x18, 0x30,
	0x00, 0x00, 0x00, 0x00, 0x00
};

int main(void)
{
	FILE *f = fopen("plik18a.txt", "w");
	if(f == NULL)
	{
		printf("Nie udalo sie otworzyc pliku plik18a.txt w trybie zapisu.");
		exit(1);
	}

	for(int i=0; i<8; i++)
	{
		for(int j=0; j<5; j++)
		{
			for(int bit = 0b1; bit < (0b1<<8); bit=bit<<1)
			{
				char znak = (bmp[i * 6 + j] & bit) ? '#' : ' ';
				putchar(znak);
				fputc(znak, f);
			}
		}
		putchar('\n');
		fputc('\n', f);
	}
	fclose(f);
	return 0;
}