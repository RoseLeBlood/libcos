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
#include "sys/dirent.h"

fs_node_t *fs_root = 0; // The root of the filesystem.

uint32_t read_fs(fs_node_t *node,uint8_t *buffer, uint32_t offset, uint32_t size)
{
    // Has the node got a read callback?
    if (node->read != 0)
        return node->read(node,buffer, offset, size);
    else
        return 0;
}

uint32_t write_fs(fs_node_t *node, uint8_t *buffer, uint32_t offset, uint32_t size)
{
    // Has the node got a write callback?
    if (node->write != 0)
        return node->write(node,buffer, offset, size);
    else
        return 0;
}

void open_fs(fs_node_t *node, uint8_t read, uint8_t write)
{
    // Has the node got an open callback?
    if (node->open != 0)
        return node->open(node);
}

void close_fs(fs_node_t *node)
{
    // Has the node got a close callback?
    if (node->close != 0)
        return node->close(node);
}

dirent_t *readdir_fs(fs_node_t *node, uint32_t index)
{
    // Is the node a directory, and does it have a callback?
    if ( (node->flags&0x7) == FS_DIRECTORY &&
         node->readdir != 0 )
        return node->readdir(node, index);
    else
        return 0;
}

fs_node_t *finddir_fs(fs_node_t *node, char *name)
{
    // Is the node a directory, and does it have a callback?
    if ( (node->flags&0x7) == FS_DIRECTORY &&
         node->finddir != 0 )
        return node->finddir(node, name);
    else
        return 0;
}