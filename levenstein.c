#include <string.h>
#include "dictionary.h"
#include "levenstein.h"



unsigned int distance (const char*a, const char *b)
{
  unsigned int a_len = strlen(a);
  unsigned int b_len = strlen(b);

  /* The base case occurs when one string is empty. */

  if (a_len == 0) {
    return b_len;
  }

  if (b_len ==0){
    return a_len;
  }

  /*The recursive case */

  char a_head[MAXLENGTH], b_head[MAXLENGTH];
  strcpy (a_head,a);
  strcpy (b_head,b);

  /*Truncate string length by 1*/
  a_head[a_len-1] = '\0';
  b_head[b_len -1] = '\0';

    int head_dist;
  /*Calculate the distance between the heads. */
  if (a[a_len -1] == b[b_len -1]) {
     head_dist = distance (a_head, b_head);
  } else {
    head_dist = 1+ distance (a_head, b_head);
  }

  /*distnace between each string and the head of the other. */
  int ahead2b_dist = 1+ distance (a_head,b);
  int bhead2a_dist =1 + distance(a, b_head);


  /*Levenstein distance*/
  return MIN (head_dist, MIN (ahead2b_dist, bhead2a_dist));
}

  
