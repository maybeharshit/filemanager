#include "../structures.h"



//allocating memory and naming for newdir
dir_* createdir(char* name){
	dir_* newdir = (dir_*)malloc(sizeof(dir_));
	if(newdir){
		newdir->name = (char*)malloc(strlen(name));
		strcpy(newdir->name,name);
		newdir->next_dir = NULL;
		newdir->parent_dir = NULL;
		newdir->sub_file = NULL;
		newdir->sub_fir = NULL;
		newdir->id = file_id++;
		return newdir;
	}
	else{
		printf("Couldn't make new directory\n");
		return NULL;
	}
}

//assigning a file to a parent directory
void assignprntodir(dir_** curdir, dir_** parentdir){
	(*curdir)->parent_dir = *parentdir;
	if((*parentdir)->sub_dir == NULL){
		(*parentdir)->sub_dir = *curdir;
		return;
	}
	dir_* temp = (*parentdir)->sub_dir;
	while(temp->next_dir) temp = temp->next_dir;
	temp->next_file = (*curdir);
	return;
}


