/*
* MIT License
*
* Copyright (c) 2022 Amber-Sophia Schröck

* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/
#ifndef SYS_DIRENT_H
#define SYS_DIRENT_H

#ifdef __cplusplus
extern "C"
{
#endif

// copie fom my OS for RPI2

#include <types.h>


#define FS_FILE        0x01
#define FS_DIRECTORY   0x02
#define FS_CHARDEVICE  0x03
#define FS_BLOCKDEVICE 0x04
#define FS_PIPE        0x05
#define FS_SYMLINK     0x06
#define FS_MOUNTPOINT  0x08 // Is the file an active mountpoint?

struct fs_node;

typedef struct dirent_t
{
    char name[128]; // Filename.
    uint32_t ino;     // Inode number. Required by POSIX.
}dirent_t;

// These typedefs define the type of callbacks - called when read/write/open/close
// are called.
typedef uint32_t (*read_type_t)(struct fs_node*,uint8_t*,uint32_t,uint32_t);
typedef uint32_t (*write_type_t)(struct fs_node*,uint8_t*,uint32_t,uint32_t);
typedef void (*open_type_t)(struct fs_node*);
typedef void (*close_type_t)(struct fs_node*);
typedef dirent_t* (*readdir_type_t)(struct fs_node*,uint32_t);
typedef struct fs_node * (*finddir_type_t)(struct fs_node*,char *name);

typedef struct fs_node
{
    char name[128];     // The filename.
    uint32_t mask;        // The permissions mask.
    uint32_t uid;         // The owning user.
    uint32_t gid;         // The owning group.
    uint32_t flags;       // Includes the node type. See #defines above.
    uint32_t inode;       // This is device-specific - provides a way for a filesystem to identify files.
    uint32_t length;      // Size of the file, in bytes.
    uint32_t impl;        // An implementation-defined number.
    read_type_t read;
    write_type_t write;
    open_type_t open;
    close_type_t close;
    readdir_type_t readdir;
    finddir_type_t finddir;
    struct fs_node *ptr; // Used by mountpoints and symlinks.
} fs_node_t;



extern fs_node_t *fs_root; // The root of the filesystem.

uint32_t    read_fs(fs_node_t *node, uint8_t *buffer, uint32_t offset, uint32_t size);
uint32_t    write_fs(fs_node_t *node, uint8_t *buffer, uint32_t offset, uint32_t size);
void        open_fs(fs_node_t *node, uint8_t read, uint8_t write);
void        close_fs(fs_node_t *node);
dirent_t*   readdir_fs(fs_node_t *node, uint32_t index);
fs_node_t*  finddir_fs(fs_node_t *node, char *name);

#ifdef __cplusplus
}
#endif

#endif