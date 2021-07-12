/*author @Deepson Shrestha;   CS250;  Submitted to Professor Robert Matthews */  

/* this is a simple spell checker program: It reads a single line of text from user
   and then looks up each word in the dictionary cracklib-small. If the word is not
   in the dictionary, the word with the smallest Levenstein distance from the incorrectly
   spelled word is chosen from dictionary and is printed */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "levenstein.h"
#include "dictionary.h"

int main ()
{
  /*running function read_dictionary*/
  read_dictionary();

  /*creating char array to store user input*/
  char s[5000];
  fgets (s, 5000, stdin);

  /*tokenizing contents of s*/
  char* token;
  token = strtok (s,",! \n");

  /*If token does not have NULL*/
  while (token != NULL) {
    int not_found = 1;
    for ( int i=0; i<N; i++){      /*loop for when the token is found in dictionary array*/
      if (strcmp (token, dictionary[i]) == 0){
	not_found=0;
	printf("%s ",token);
	break;
      }
    }
    if (not_found==1){            /*Loop for when the token is not found in dictionary array*/
      int min_distance = 30;
      int position = 0;
      for ( int j=0; j<N; j++){
	int d= distance(token, dictionary[j]);   /*levenstein distance between token and the words in dictionary*/
	if (d<min_distance){
	  min_distance=d;
	  position = j;
	}
      }

      printf("*%s* ", dictionary[position]);     /*printing the correct word.*/
    }

    token = strtok(NULL, " ,!\n");
  }
  return 0;

}
  
    
      
	
