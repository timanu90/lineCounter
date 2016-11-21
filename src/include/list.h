/**
 *
 *
 * @file list.h
 * @ingroup
 * @brief Simple linked list
 * @author tvasconcelos
 * @date 21-11-2016
 *
 * Simple linked list to store  all files info
 */

#ifndef LIST_H
#define LIST_H

#include "includes.h"

class TNode
{
public:
    TNode*      next;
    TNode*      prev;
    TFileInfo   data;

    TNode();
};

class TList
{
    TNode*  first;
    TNode*  last;
    int     elements;

public:
    TList();

    void insertFile(char* path);

    TNode*  getFirst()  {return first;}
    int     count()     {return elements;}

    //dbg code
    void print();
};

extern TList fileList;

#endif // LIST_H
