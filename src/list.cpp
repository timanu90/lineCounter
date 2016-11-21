#include "include/includes.h"

TList fileList;

/* *************************************************  NODE SPACE  ************************************************* */
TNode::TNode()
{
    next = prev = NULL;
}

/* *************************************************  LIST SPACE  ************************************************* */
TList::TList()
{
    first = last = NULL;
    elements = 0;
}

void TList::insertFile(char* path)
{
    TNode* newNode = new TNode();

    /* Get file extension */
    char *ptr = path;

    /* Go through string to fine char '.' */
    while ( *ptr != '\0' && *ptr != '.' ) {

        ptr++;
    }

    /* Allocate space for strings */
    newNode->data.extension = (char*)malloc(strlen(ptr) * sizeof(char) + 1 );
    newNode->data.path = (char*)malloc(strlen(path) * sizeof(char) + 1 );

    /* Copy extension to file info */
    strcpy(newNode->data.extension, ptr+1);
    strcpy(newNode->data.path, path);

    /* Insert in list */
    if ( first == NULL )
    {
        first = last = newNode;
    }
    else
    {
        newNode->next = first;
        first->prev = newNode;
        first = newNode;
    }

    /* Update number of items on list */
    elements++;
}


//dbg code
void TList::print()
{
    TNode* ptr = first;
    std::cout<<"****************************************************************************"<<std::endl;
    std::cout<<"Number of file on list = "<<elements<<std::endl;

    while ( ptr != NULL ) {

        std::cout<<ptr->data.path<<std::endl;
        ptr = ptr->next;
    }

}

