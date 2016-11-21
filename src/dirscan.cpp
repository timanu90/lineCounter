/**
 *
 *
 * @file dirscan.cpp
 * @ingroup
 * @brief Load all file from dir and subdirs
 * @author tvasconcelos
 * @date 21-11-2016
 *
 *
 */

#include "include/includes.h"

#define ISDIR           0
#define ISFILE          1
#define STREQUAL        0
#define NAME_MAX_SIZE   256

extern TList fileList;

int isFile(const char* name)
{
    DIR* directory = opendir(name);

    if ( directory != NULL ) {

        closedir(directory);
        return ISDIR;
    }

    if ( errno == ENOTDIR ) {

        return ISFILE;
    }

    return -1;
}

void loadAllFileFromDir(char* pathToDir)
{
    char dir[NAME_MAX_SIZE];
    char path[NAME_MAX_SIZE];
    DIR *dpdf;
    struct dirent *epdf;

    strcpy(dir,pathToDir);

    dpdf = opendir(dir);
    if ( dpdf != NULL ) {

        while ( epdf = readdir(dpdf) ) {

            strcpy(path,dir);
            strcat(path,"/");
            strcat(path,epdf->d_name);

            if ( strcmp(epdf->d_name,".") != 0 && strcmp(epdf->d_name,"..") != 0 ) {

                strcpy(path,dir);
                strcat(path,"/");
                strcat(path,epdf->d_name);

                if ( isFile(path) == ISFILE ) {

                   fileList.insertFile(path);
                }
                else {

                   loadAllFileFromDir(path);
                }
            }
        }
    }
}
