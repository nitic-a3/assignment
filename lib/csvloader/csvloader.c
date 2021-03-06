#include "csvloader.h"
#include "../macros.h"
#include <stdio.h>
#include <string.h>

int loaduser(const char *path, char name[][MAX_STR_SIZE], char roma[][MAX_STR_SIZE], char jhc[][MAX_STR_SIZE]) {

  // Load the file
  FILE *fp;
  fp = fopen(path, "r");

  // Check the load was successful
  if(fp == NULL) {
    // If laod was failure, put error message and return
    return -1;
  }

  // Load, parse csv, and store to user array
  int number = 0;
	char row_buffer[MAX_STR_SIZE * 4 + 3];
  while(fgets(row_buffer, MAX_CSV_SIZE, fp) != NULL){
    int student_number;
    char student_name[MAX_STR_SIZE];
    char student_school[MAX_STR_SIZE];
    char student_roma[MAX_STR_SIZE];
    sscanf(
        row_buffer,
        "%d,%[^,],%[^,],%s",
        &student_number, student_name, student_roma, student_school
    );
		strcpy(name[student_number - 1], student_name);
		strcpy(roma[student_number - 1], student_roma);
		strcpy(jhc[student_number - 1], student_school);
		number++;
  }

  // close file stream
  fclose(fp);

  // return users
  return number;
}

int saveuser(
		const char* path,
		char name[][MAX_STR_SIZE], char roma[][MAX_STR_SIZE], char jhc[][MAX_STR_SIZE], int size) {
  // Load the file
  FILE *fp;
  fp = fopen(path, "w");

  // Check the load was successful
  // If laod was failure, put error message and return
  if(fp == NULL) return -1;

  // Print informations to csv
  for(int i = 0;i<size;i++) {
    fprintf(
      fp, "%d,%s,%s,%s\n",
			i + 1, name[i], roma[i], jhc[i]
    );
  }

  // close file stream
  fclose(fp);

  return 0;
}

