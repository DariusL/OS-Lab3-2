/*Darius Lapunas IF-1/8 darlap1*/
/*darlap1_readdir01.c*/

#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/statvfs.h>
#include <sys/dirent.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <ftw.h>

void dl_spausdinti_irasus(const char *name){
	DIR *dir;
	struct dirent *ent;
	dir = opendir(name);
	dirent = readdir(dir);
	while(dirent){
		printf("Failo %s numeris - %lu\n",
			dirent->d_name, dirent->ino_t);
		dirent = readdir(dir);
	}
	closedir(dir);
}

int main(int argc, char *argv[]){
	char *cwd;
	printf( "(C) 2013 Lapunas Darius, %s\n", __FILE__ );
	cwd = getcwd(NULL, pathconf(".", _PC_PATH_MAX));
	dl_spausdinti_irasus(cwd);
	free(cwd);
	return 0;
}
