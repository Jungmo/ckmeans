#include <stdio.h>

#define IMGDIR "/home/jungmo/Documents/github/material/"
#define NEST "1906_child"
#define NUMCLUSTER 8

int main()
{
	int cluster = NUMCLUSTER;
	int centroid[8] = {0xF, 0x2F, 0x4F, 0x6F, 0x8F, 0xAF, 0xCF, 0xEF};	
	FILE* src_image;
	FILE* dest_image;
	int i, j, k;
	char buf[BUFSIZ];
	char buf2[BUFSIZ];	
	int count = 0;
	src_image = fopen("src.bmp", "rb");
	dest_image = fopen("dest.bmp", "wb");

	
	count = fread(buf, sizeof(char), 1078, src_image);
	fwrite(buf, sizeof(char), count,  dest_image);	
	
	while(1)
	{
		count = fread(buf, sizeof(char), BUFSIZ, src_image);
		
		for(i = 0; i < count; i++)
		{
			if(buf[i] >= 0 && buf[i] < 32)
				buf2[i] = centroid[0];
			else if(buf[i] >= 32 && buf[i] < 64)
				buf2[i] = centroid[1];
			else if(buf[i] >=64 && buf[i] < 96)
				buf2[i] = centroid[2];
			else if(buf[i] >= 96 && buf[i] < 128)
				buf2[i] = centroid[3];
			else if(buf[i] >=128 && buf[i] < 160)
				buf2[i] = centroid[4];
			else if(buf[i] >= 160 && buf[i] < 192)
				buf2[i] = centroid[5];
			else if(buf[i] >= 192 && buf[i] < 224)
				buf2[i] = centroid[6];
			else if(buf[i] >= 224 && buf[i] < 256)
				buf2[i] = centroid[7];		
		}
		
		fwrite(buf2, sizeof(char), count,  dest_image);	
		

		if(count < BUFSIZ)
			break;
	}	
	 
	fclose(src_image);
	fclose(dest_image);	
	return 0;
}
