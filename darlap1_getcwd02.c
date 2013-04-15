/* Darius Lapunas IF-1/8 darlap1*/
/*darlap1_getcwd02.c*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

void dl_spausdinti_einama(){
	char *cwd;
	cwd = getcwd(NULL, pathconf(".", _PC_PATH_MAX));
	printf("einamas katalogas: %s\n", cwd);
	free(cwd);
}

int main(int argc, char *argv[]){
	char *cwd;
	int desc;
	printf( "(C) 2013 Lapunas Darius, %s\n", __FILE__ );
	dl_spausdinti_einama();
	cwd = getcwd(NULL, pathconf(".", _PC_PATH_MAX));
	desc = open(cwd, O_RDONLY);
	free(cwd);
	printf("deskriptorius: %d\n", desc);
	chdir("/tmp");
	dl_spausdinti_einama();
	fchdir(desc);
	dl_spausdinti_einama();
	close(desc);
	return 0;
}
