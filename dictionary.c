/*this is the module for reading from dictionary cracklib-small*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dictionary.h"


/*function which is called in the main module*/
void read_dictionary ()
{
  FILE* fp =fopen ("cracklib-small","r");           /*Using file pointer fp to refer to text stream from cracklib-small*/

  /* Check if fp equals null */
  if (fp==NULL) {
    printf("Could not access the dictionary\n");
    exit(-1);

  }

  
  int i=0;
  /*loop for copying contents referred to by fp into dictionary array*/
  while (i<N){
    fgets(&dictionary[i][0], MAXLENGTH,fp);
    dictionary[i][strlen(dictionary[i]) - 1] = '\0';
    i++;
  }
  
}
