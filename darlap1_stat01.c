/*Darius Lapunas IF-1/8 darlap1*/
/*darlap1_stat01.c*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	struct stat *buf;
	buf = malloc(sizeof(struct stat));
	printf( "(C) 2013 Lapunas Darius, %s\n", __FILE__ );
	if(argc != 2){
		printf("Reikia 1 argumento - failo/aplanko\n");
		return 1;
	}
	if(stat(argv[1], buf) == 0){
		printf("dydis - %lu baitu\n", buf->st_size);
		printf("savininkas - %d\n", buf->st_uid);
	}else{
		printf("nepavyko atidaryti failo\n");
	}
	return 0;
}
