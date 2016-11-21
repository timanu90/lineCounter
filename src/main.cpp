#include "include/includes.h"

extern TList fileList;

int main(int argc, char** argv)
{
    /* @TODO Load config info from file */


    /* Search dir and sub dirs and get a list off all files there */
    loadAllFileFromDir((char*)"/home/tiago/rtos/kernel");

    /* Do things */
    getInforFromFiles();

    /* Gen report */
    genReport();


    return 0;
}
