#include "../structures.h"


//allocating memory and naming for newfile (this doesn't assign content or extension)
file_* createfile(char* name){
	file_* newfile = (file_*)malloc(sizeof(file_));
	if(newfile){
		newfile->name = (char*)malloc(strlen(name));
		strcpy(newfile->name,name);
		newfile->next_file = NULL;
		newfile->parent_dir = NULL;
		newfile->content = NULL;
		newfile->ext = NULL;
		newfile->id = file_id++;
		return newfile;
	}
	else{
		printf("Couldn't make new file\n");
		return;
	}
}

//assigning a file to a parent directory
void assignprntofile(file_** file, dir_** dir){
	(*file)->parent_dir = *dir;
	if((*dir)->sub_file == NULL){
		(*dir)->sub_file = *file;
		return;
	}
	file_* temp = (*dir)->sub_file;
	while(temp->next_file) temp = temp->next_file;
	temp->next_file = (*file);
	return;
}



