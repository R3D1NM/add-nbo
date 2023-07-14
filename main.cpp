// main.cpp
#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

uint32_t convert(char* filename){
	uint32_t nbo, hbo;
	
	FILE* f = fopen(filename,"rb");
	
	if(f==NULL){
		printf("FILE OPEN ERROR\n");
		return 0;
	}
	
	if(fread(&nbo,sizeof(uint32_t),1,f)!=1){
		printf("FILE READ ERROR\n");
	}

	hbo = ntohl(nbo);
	fclose(f);
	
	return hbo;
}

int main(int argc, char** argv) {
	uint32_t a,b,sum;
	if(argc<3){
		printf("Require 2 arguments");
		return 0;
	}

	char* f1 = argv[1];
	char* f2 = argv[2];

	a = convert(f1);
	b = convert(f2);
	sum = a+b;
	
	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n",a,a,b,b,sum,sum);
	return 0;
}

