/* Darius Lapunas IF-1/8 darlap1 */
/*darlap1_pathconf.c*/

#include <stdio.h>
#include <unistd.h>

void dl_file_info(const char *name){
	printf("vardo ilgis %lu\n", pathconf(name, _PC_NAME_MAX));
	printf("kelio ilgis %lu\n", pathconf(name, _PC_PATH_MAX));
}


int main(int argc, char *argv[]){

	printf( "(C) 2013 Lapunas Darius, %s\n", __FILE__ );
	dl_file_info(".");
	return 0;
}

