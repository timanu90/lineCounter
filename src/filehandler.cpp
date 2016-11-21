/**
 *
 *
 * @file filehandler.cpp
 * @ingroup
 * @brief Get info from file
 * @author tvasconcelos
 * @date 21-11-2016
 *
 * Get path to file, file extension and number of lines (for now)
 */

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


