#include "../structures.h"


void renamefile(char* name, file** file_){
	if((*file_)){
		strcpy((*file_)->name,name);
	}
}