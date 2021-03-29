#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>


int main(void) {
	srand(time(NULL));
	FILE *fptr;
	fptr = fopen("F:\\test.bmp", "wb");
	//Block 1
	char str[] = "BM";
	fwrite(str, 1, 2, fptr);
	int file_size[] = {100}; //Might need to change
	fwrite(file_size, 4, 1, fptr); 
	short zero[] = {0};
	fwrite(zero, 2, 1, fptr);
	fwrite(zero, 2, 1, fptr);
	int offset[] = {54};
	fwrite(offset, 4, 1, fptr); //Might need to change
	//Block 2
	int size_of_header[] = {40};
	fwrite(size_of_header, 4, 1, fptr);
	int img_width[] = {1920};
	fwrite(img_width, 4, 1, fptr);
	int img_height[] = {1080};
	fwrite(img_height, 4, 1, fptr);
	short one[] = {1};
	fwrite(one, 2, 1, fptr);
	short bpp[] = {32};
	fwrite(bpp, 2, 1, fptr);	
	int comp[] = {0};
	fwrite(comp, 4, 1, fptr);
	fwrite(comp, 4, 1, fptr);
	int hor_ppm[] = {0};
	fwrite(hor_ppm, 4, 1, fptr);
	int vert_ppm[] = {0};
	fwrite(vert_ppm, 4, 1, fptr);
	int num_colours[] = {0};
	fwrite(num_colours, 4, 1, fptr);
	int important_colours[] = {0};
	fwrite(important_colours, 4, 1, fptr);

	//Block 3 // Not needed if bpp > 8

	//Block 4
	
	int i = 0;
	for(i = 0; i < img_width[0] * img_height[0]; ++i) {
		int pixels[] = {rand()};
		fwrite(pixels, 4, 1, fptr);
	}



	fclose(fptr);



	return 0;
}
