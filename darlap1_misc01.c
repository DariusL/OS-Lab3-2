/*Darius Lapunas IF-1/8 darlap1*/
/*darlap1_misc01.c*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/statvfs.h>

#define TMP_DIR "./temp"

void dl_spausdinti_einama(){
        char *cwd;
        cwd = getcwd(NULL, pathconf(".", _PC_PATH_MAX));
        printf("einamas katalogas: %s\n", cwd);
        free(cwd);
}

int dl_sukurti_laikina(){
	
	if(mkdir(TMP_DIR, S_IRWXU|S_IRWXO) == 0){
		printf("Sukurtas aplankas \"temp\"\n");
		return 1;
	}else{
		printf("Nepavyko sukurti aplanko\n");
		return 0;
	}
}

void dl_istrinti_laikina(){
	if(rmdir(TMP_DIR) == 0){
		printf("Laikinas aplankas istrintas\n");
	}else{
		printf("Aplanko istrinti nepavyko\n");
	}
}

int main(int argc, char *argv[]){
        printf( "(C) 2013 Lapunas Darius, %s\n", __FILE__ );
	
	dl_spausdinti_einama();
	if(dl_sukurti_laikina()){
		chdir(TMP_DIR);
		dl_spausdinti_einama();
		chdir("..");
		dl_spausdinti_einama();
		dl_istrinti_laikina();
		return 0;
	}
	return 1;
}
