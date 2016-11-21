#include "include/includes.h"

extern TList fileList;

void countLines(TNode* ptr)
{
    int lines = 0;

    std::string line;
    std::ifstream file (ptr->data.path);
    if ( file.is_open() ) {

        while ( getline (file,line) ) {

            lines++;
        }
        file.close();
    }

    /* Update value on file info */
    ptr->data.lines = lines;
}

void getInforFromFiles()
{
    TNode* ptr = fileList.getFirst();

    while ( ptr != NULL ) {

        countLines( ptr );

        ptr = ptr->next;
    }
}


