/*Darius Lapunas IF-1/8 darlap1*/
/*darlap1_statvfs01.c*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/statvfs.h>

int main(int argc, char *argv[]){
	struct stat *buf;
	struct statvfs *buf2;
	buf = malloc(sizeof(struct stat));
	buf2 = malloc(sizeof(struct statvfs));
	printf( "(C) 2013 Lapunas Darius, %s\n", __FILE__ );
	if(argc != 2){
		printf("Reikia 1 argumento - failo/aplanko\n");
		return 1;
	}
	if(stat(argv[1], buf) == 0 && statvfs(argv[1], buf2) == 0){
		printf("dydis - %lu baitu\n", buf->st_size);
		printf("savininkas - %d\n", buf->st_uid);
		printf("failu sistemos bloko dydis - %lu\n", buf2->f_bsize);
	}else{
		printf("nepavyko atidaryti failo\n");
	}
	return 0;
}
