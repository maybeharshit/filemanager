#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int dir_id = 0;

typedef struct directory dir;

struct directory{
	char* name;
	struct directory* parent_dir;
	struct directory* next_dir;
	struct directory* sub_dir;
	struct file* sub_file;
	int id;
};

dir* createfile(char* name){
	
	dir* newfile = (dir*)malloc(sizeof(dir));

	if(newfile){

		newfile->name = (char*)malloc(sizeof(strlen(name)));
		strcpy(newfile->name,name);
		newfile->parent_dir = NULL;
		newfile->next_dir = NULL;
		newfile->sub_dir = NULL;
		newfile->sub_file = NULL;
		newfile->id = dir_id++;
	}
	return newfile;
}
