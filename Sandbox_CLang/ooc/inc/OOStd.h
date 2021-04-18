/**
 * Copyright (C)  2011-2011  Jesse Meng (pingf0@gmail.com).
 *
 * This file is part of OOC-GCC.
 *
 * OOC-GCC is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * OOC-GCC is distributed in the hope that it will be useful,but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see
 * <http://www.gnu.org/licenses/>.
 */

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "OOCfg.h"
#include "OOBase.h"

//class&static design
#define CLASS __OOC_CLASS__ROOTED_DESIGN
#define CLASS_EX __OOC_CLASS__EXTENDED_DESIGN

#define STATIC __OOC_STATIC__ROOTED_DESIGN
#define STATIC_EX __OOC_STATIC__EXTENDED_DESIGN


//assemble

#define ASM_00 __OOC_ASSEMBLE__00
#define ASM_01 __OOC_ASSEMBLE__01
#define ASM_10 __OOC_ASSEMBLE__10
#define ASM_11 __OOC_ASSEMBLE__11

#define ASM0_00(Type) __OOC_ASSEMBLE__00(Type,NULL,NULL,NULL,NULL)
#define ASM0_01(Type,SuType) __OOC_ASSEMBLE__01(Type,SuType,NULL,NULL,NULL,NULL)
#define ASM0_10(Type,SuType) __OOC_ASSEMBLE__10(Type,SuType,NULL,NULL,NULL,NULL)
#define ASM0_11(Type,SuType) __OOC_ASSEMBLE__11(Type,SuType,NULL,NULL,NULL,NULL)

#define ASM ASM_00
#define ASM_EX ASM_11
#define ASM0 ASM0_00
#define ASM0_EX ASM0_11
//static part link

#define ST __OOC_CLASS__REAL_STATIC

//basic functions
#define INI __OOC_FUNCTION__INI
#define FIN __OOC_FUNCTION__FIN
#define NEW __OOC_FUNCTION__NEW
#define DEL __OOC_FUNCTION__DEL
#define DELETE __OOC_FUNCTION__DELETE

#define INI0(pointer,Type) INI(pointer,Type,NULL)
#define FIN0(pointer,Type) FIN(pointer,Type,NULL)
#define NEW0(Type) NEW(Type,NULL)
#define DEL0(pointer,Type) DEL(pointer,Type,NULL)
#define DELETE0(pointer) DELETE(pointer,NULL)
//
//
#define NEW_PV __OOC_FUNCTION__CLASS_PRIVATE_NEW
#define DEL_PV __OOC_FUNCTION__CLASS_PRIVATE_DEL

#define PV(p) ((void *)__OOC_CLASS__PRIVATE(p))
#define PVT(p,Type) ((Type *)__OOC_CLASS__PRIVATE(p))
//memory function
#define RESET_MF __OOC_FUNCTION__RESET_MEMORY_FUNCTIONS
#define ALLOC __OOC_FUNCTION__ALLOC
#define FREE __OOC_FUNCTION__FREE
#define REALLOC __OOC_FUNCTION__REALLOC

//block
#define EC_BEGIN __OOC_BLOCK__EXTERN_C_BEGIN
#define EC_END __OOC_BLOCK__EXTERN_C_END

//param
#define PP __OOC_FUNCTION__PACK_PARAMETER

//value
#define RE_LIMIT __OOC_VALUE__RETURN_ERROR_LIMIT
#define TRUE __OOC_VALUE__TRUE
#define FALSE __OOC_VALUE__FALSE
#define OK __OOC_VALUE__OK
#define FAIL __OOC_VALUE__FAIL
//utils
#define SWAP __OOC_FUNCTION__SWAP

//assert&exception
#define ASSERT __OOC_FUNCTION__ASSERT
#define CHECK __OOC_FUNCTION__CHECK
#define THROW __OOC_FUNCTION__THROW
#define TRY __OOC_FUNCTION__TRY
#define CATCH __OOC_FUNCTION__CATCH
#define ELSE_CATCH __OOC_FUNCTION__ELSE_CATCH
#define CATCH_ELSE __OOC_FUNCTION__CATCH_ELSE
#define FINALLY __OOC_FUNCTION__FINALLY
#define END_TRY __OOC_FUNCTION__END_TRY
#define THROW0(e) \
	__OOC_FUNCTION__TRY \
		__OOC_FUNCTION__THROW(e) \
	__OOC_FUNCTION__END_TRY

#define SET_EXCEPTIONS __OOC_FUNCTION__SET_EXCEPTIONS
#define GET_EXCEPTIONS __OOC_FUNCTION__GET_EXCEPTIONS
#define SET_EXCEPTION __OOC_FUNCTION__SET_EXCEPTION
#define GET_EXCEPTION __OOC_FUNCTION__GET_EXCEPTION
