/*
   This file will be containing the declaration for class which will be used
   for dumping the search results to a file 
*/

#define DUMP_SEARCH_RESULT_FILE_NAME_SIZE   256
#define END_OF_FILE_REACHED                 1

typedef struct search_result_packed{
    uint64_t key ;
    int64_t time;
}__attribute__(__packed__)search_result;


class DumpSearchResult
{
     private :       
     FILE  *fd ;
     char file[DUMP_SEARCH_RESULT_FILE_NAME_SIZE];
     uint8_t endOffile;
     public :
     DumpSearchResult(char*fileName) ;
     
     
}
