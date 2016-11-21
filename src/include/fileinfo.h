/**
 *
 *
 * @file fileinfo.h
 * @ingroup
 * @brief Class to store file info
 * @author tvasconcelos
 * @date 21-11-2016
 *
 * List node to store file info
 */

#ifndef FILEINFO_H
#define FILEINFO_H

class TFileInfo
{
public:
    TFileInfo();

    char*   path;
    char*   extension;
    int     lines;
};

#endif // FILEINFO_H
