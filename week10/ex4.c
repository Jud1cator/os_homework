#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_NAMES 100
#define MAX_NAME_LENGTH 100

struct file {
    ino_t ino;
    int n_names;
    char fname[MAX_NAMES][MAX_NAME_LENGTH]; 
};

struct flist {
    int n_files;
    struct file files[MAX_FILES];
};
/*
void add_file(struct flist *files, struct file *file) {
    if(files->n_files < MAX_FILES) {
        files[files->n_files] = file;
        files->n_files++;
    }   
}
*/
int main() {
    const char *path = "tmp/";
    DIR *dirp;
    struct dirent *dent;
    struct flist fl;
    fl.n_files = 0;
    
    if((dirp = opendir(path)) == NULL) return 1;
    while ((dent = readdir(dirp))) {
        int i;
	for (i = 0; i < fl.n_files; i++) {
	    if (fl.files[i].ino == dent->d_ino)
			break;
		}

		if (i == fl.n_files) {
			struct file f;
            f.ino = dent->d_ino;
            f.n_names = 0;
			fl.files[fl.n_files] = f;
            fl.n_files++;
		}
        
        strcpy(fl.files[i].fname[fl.files[i].n_names], dent->d_name);
        fl.files[i].n_names++;
	}

	closedir(dirp);

	for (int i = 0; i < fl.n_files; i++) {
		if (fl.files[i].n_names >= 2) {
            printf("%ld:", fl.files[i].ino);
		    for (int j = 0; j < fl.files[i].n_names; j++)
			    printf(" %s", fl.files[i].fname[j]);
		    printf("\n");
        }
	}

	return 0;
}
