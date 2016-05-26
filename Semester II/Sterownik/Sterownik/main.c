#include <stdio.h>
#include <stdlib.h>

typedef struct dev_t
{
	// informacje podstawowe
	FILE* f; // plik �r�d�owy
	int block_size; // wielko�� bloku
	int block_count; // liczba blok�w
} dev_t;

dev_t* device_open(const char* file_name)
{
	// tutaj nale�y otworzy� plik wej�ciowy
	// przypisa� wielko�� bloku
	// oraz okre�li� liczb� blok�w
	// lub NULL, je�li nie uda�o si� otworzy�
	dev_t *dev = (dev_t*)malloc(sizeof(dev_t));
	dev->f = fopen(file_name, "r+");
	if (dev->f == NULL)
		return NULL;
	dev->block_count = 64;
	dev->block_size = 512;
	return dev;
}

int device_close(dev_t* device)
{
	fclose(device->f);
	free(device);
	return 0; // kod b��du
}

int device_read(dev_t* device, void* buffer, int start_block, int count)
{
	/*
	Wczytaj z urz�dzenia [device] bloki do bufora [buffer].
	Wczyta� nale�y [count] blok�w, zaczynajc od [start_block]
	*/

	if (start_block + count > device->block_count)
		return -1;

	buffer = malloc(device->block_size*count);
	fseek(device->f, start_block, SEEK_SET);
	fread(buffer, device->block_size, count, device->f);
	return count;
}

int device_write(dev_t *device, const void* buffer, int start_block, int count)
{
	/*
	Zapisz do urz�dzenia [device] bloki z bufora [buffer].
	Zapisa� nale�y [count] blok�w, zaczynajc od [start_block].
	*/

	if (start_block + count > device->block_count)
		return -1;

	fseek(device->f, start_block, SEEK_SET);
	fwrite(buffer, device->block_size, count, device->f);
	return count;
}

int main(void)
{

	return 0;
}