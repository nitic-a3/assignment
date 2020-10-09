#include "csvloader.h"
#include <stdio.h>
#include <string.h>

int loaduser(const char *path, User *dest) {

	// Load the file
	FILE *fp;
	fp = fopen(path, "r");
	
	// Check the load was successful
	if(fp == NULL) {
		// If laod was failure, put error message and return
		dest = NULL;
		return -1;
	}
	
	// Load, parse csv, and store to user array
	char row_buffer[MAX_CSV_SIZE];
	int number = 0;
	while(fgets(row_buffer, MAX_CSV_SIZE, fp) != NULL){
		int student_number;
		char student_name[MAX_STR_SIZE];
		char student_school[MAX_STR_SIZE];
		char student_ruby[MAX_STR_SIZE];
		sscanf(
				row_buffer,
				"%d,%[^,],%[^,],%s",
				&student_number, student_name, student_ruby, student_school
		);
		dest[number].number = student_number;
		strcpy(dest[number].name, student_name);
		strcpy(dest[number].ruby, student_ruby);
		strcpy(dest[number].school, student_school);
		number++;
	}

	// close file stream
	fclose(fp);

	// return users
	return number;
}

