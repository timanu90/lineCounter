/**
 *
 *
 * @file main.cpp
 * @ingroup
 * @brief Program entry point
 * @author tvasconcelos
 * @date 21-11-2016
 *
 *
 */

#include "include/includes.h"

extern TList fileList;

int main(int argc, char** argv)
{
    /* Check for args */
    if ( argc < 2 ) {
        printf("./prog <pathToDir>\n");
        return 1;
    }


    /* @TODO Load config info from file */


    /* Search dir and sub dirs and get a list off all files there */
    loadAllFileFromDir(argv[1]);

    /* Do things */
    getInforFromFiles();

    /* Gen report */
    genReport();


    return 0;
}
