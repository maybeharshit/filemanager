#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "dir.h"

int file_id = 0;

typedef struct file file;

struct file{
	char* name;
	dir* parent_dir;
	struct file* next_file;
	char* content;
	char* ext;
};

file* createFile(char* name){

	file* newfile = (file*)malloc(sizeof(file));
	
	if(newfile){
		newfile->name = (char*)malloc(sizeof(strlen(name)));
		strcpy(newfile->name,name);
		newfile->parent_dir = NULL;
		newfile->next_file = NULL;
		newfile->content = NULL;
		newfile->ext = NULL;
	}
	
	return newfile;
}

