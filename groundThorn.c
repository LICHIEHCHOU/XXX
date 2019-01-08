#include <stdlib.h>

#include "functionlist.h"


void groundthorn(g* gPtr)
{
   int i;
   for(i=0;i<50;i++){
   if(gPtr->barD_y==gPtr->y && gPtr->barD_x==gPtr->x+i)
   {
      printf("you are dead");

   }

   }

}

