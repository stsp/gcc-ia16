/* Subroutines used during code generation for Intel 16-bit x86.
   Copyright (C) 2011-2016 Free Software Foundation, Inc.
   Very preliminary far pointer support by TK Chia

   This file is part of GCC.

   GCC is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

   GCC is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with GCC; see the file COPYING3.  If not see
   <http://www.gnu.org/licenses/>.  */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "c-family/c-common.h"

/* Implements REGISTER_TARGET_PRAGMAS.  */
void
ia16_register_pragmas (void)
{
  c_register_addr_space ("__far", ADDR_SPACE_FAR);
}
