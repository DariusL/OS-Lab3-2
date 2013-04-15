/*Darius Lapunas IF-1/8 darlap1*/
/*darlap1_nftw02.c*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ftw.h>

void dl_spausdinti_einama(){
	char *cwd;
	cwd = getcwd(NULL, pathconf(".", _PC_PATH_MAX));
	printf("einamas katalogas: %s\n", cwd);
	free(cwd);
}

int dl_info(const char *fpath, const struct stat *sb, int tflag, struct FTW *ftwbuf){
	if((tflag & FTW_F) == FTW_F){
		printf("%s\n", fpath);
	}
	return 0;
}

int main(int argc, char *argv[]){
	printf( "(C) 2013 Lapunas Darius, %s\n", __FILE__ );
	nftw("/home/darlap1", dl_info, 20, FTW_PHYS);
	return 0;
}
