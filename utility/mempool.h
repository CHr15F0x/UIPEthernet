/*
 mempool.h - sleek implementation of a memory pool
 Copyright (c) 2013 Norbert Truchsess <norbert.truchsess@t-online.de>
 All rights reserved.

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef MEMPOOL_H
#define MEMPOOL_H

#include <inttypes.h>

#define POOLSTART 0
#define NOBLOCK 0

#include "mempool_conf.h"

struct memblock
{
  memaddress begin;
  memaddress size;
  memhandle nextblock;

  memblock() :
    begin(0),
    size(0),
    nextblock(0)
  {}
};

class MemoryPool
{
#ifdef MEMPOOLTEST_H
  friend class MemoryPoolTest;
#endif

protected:
  struct memblock blocks[MEMPOOL_NUM_MEMBLOCKS+1];

public:
  void init();
  memhandle allocBlock(memaddress);
  void freeBlock(memhandle);
  void resizeBlock(memhandle handle, memaddress position);
  void resizeBlock(memhandle handle, memaddress position, memaddress size);
  memaddress blockSize(memhandle);
};
#endif
