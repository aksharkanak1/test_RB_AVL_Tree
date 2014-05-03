/*
    File contains the support function required for this experiment 
*/

/*Function for allocation memory chunk */

void * RA_AllocateLargeChunk(uint32_t  size)
{
   void *ptr = NULL ;

   if(0 == size)
      return ptr ;

   ptr = malloc(size);
  
   return ptr ; 
}

/*Function for partitioning the memeory */



