/* default.ld. Default linker script for Or1ksim test programs

   Copyright (C) 1999-2006 OpenCores
   Copyright (C) 2010 Embecosm Limited

   Contributors various OpenCores participants
   Contributor Jeremy Bennett <jeremy.bennett@embecosm.com>

   This file is part of OpenRISC 1000 Architectural Simulator.

   This program is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by the Free
   Software Foundation; either version 3 of the License, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
   FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
   more details.

   You should have received a copy of the GNU General Public License along
   with this program.  If not, see <http:  www.gnu.org/licenses/>.  */

/* ----------------------------------------------------------------------------
   This code is commented throughout for use with Doxygen.
   --------------------------------------------------------------------------*/

ENTRY (_start)
MEMORY
        {
       
        rom    : ORIGIN = 0x80000000, LENGTH = 8K
        }

SECTIONS
{
	  /*
	  For some reason the linker script can't see the _reset_vector symbol 
	  (even if we declare it global), so we explicitly set it. */
        __stack_size = DEFINED(__stack_size) ? __stack_size :2K;
	.init : 
	{
	  KEEP (*(SORT_NONE(.init)))
	} >rom


	.text :
        {
        *(.text)
        } > rom

	.data :
  {
  *(.data)
  } > rom

  .bss :
  {
    *(.bss*)
   
  } > rom 

   .lalign  :
	{
	  PROVIDE(_end = .);
	} >rom  

  .stack  ORIGIN(rom)+LENGTH(rom) - __stack_size :
  {
  PROVIDE(_heap_end = . );
  . = __stack_size;
	PROVIDE(_sp = .);
  } > rom
}
