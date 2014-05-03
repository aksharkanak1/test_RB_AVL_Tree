

DumpSearchResult::DumpSearchResult(char *fileName)
{
    strcpy(file,fileName,strlen(fileName));
}

int  DumpSearchResult::readEntry(search_result &result )
{
     int numRead = 0;
     if(END_OF_FILE_REACHED == endOffile)
     {
        
     }
     if(NULL == fd)
     {
         fd = fopen(file,"r");
         if(NULL == fd)
         {
            cout<<endl << "failed to open the file"<<file <<endl;
            return -1;
         }    
     }
     
   
      size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream)  
     
     
}



