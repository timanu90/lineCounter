/**
 *
 *
 * @file report.cpp
 * @ingroup
 * @brief Format data to output
 * @author tvasconcelos
 * @date 21-11-2016
 *
 *
 */

#include "include/includes.h"

extern TList fileList;

void genReport()
{
    TNode*  ptr                 = fileList.getFirst();
    TNode*  max                 = ptr;
    TNode*  min                 = ptr;
    int     projectTotalLines   = 0;

    while ( ptr != NULL ) {

        /* Check for max */
        if ( ptr->data.lines > max->data.lines ) {

            max = ptr;
        }

        /* Check for min */
        if ( ptr->data.lines < min->data.lines ) {

            min = ptr;
        }

        /* Update project total line count */
        projectTotalLines += ptr->data.lines;

        /* Point to next file */
        ptr = ptr->next;
    }

    /* report */
    printf("******************************************************************\n");
    printf("*********************      REPORT      ***************************\n");
    printf("******************************************************************\n");

    printf("Number of files       = %d\n", fileList.count());
    printf("Total number of lines = %d\n",projectTotalLines);

    printf("\n\n");
    printf("Biggest  File = %s, with %d lines\n",max->data.path,max->data.lines);
    printf("Smallest File = %s, with %d lines\n",min->data.path,min->data.lines);

    printf("******************************************************************\n");

}
