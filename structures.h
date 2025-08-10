#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>

int dir_id = 0;
int file_id = 0;

typedef struct dir dir;

typedef struct file file;

struct dir{
	char* name;
	struct dir* parent_dir; 
	struct dir* next_dir; //link to the next dir in the same parent dir
	struct dir* sub_dir;
	struct dir* sub_file;
	int id;
};

struct file{
	char* name;
	struct dir* parent_dir;
	struct file* next_file;
	char* content;
	char* ext;
	int id;
};


