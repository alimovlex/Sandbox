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
 * This library is distributed in the hope that it will be useful,but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see
 * <http://www.gnu.org/licenses/>.
 */

#pragma once

/////////////////////////////////////////////
//__OOC_BLOCK
#ifdef __cplusplus
	#define __OOC_BLOCK__EXTERN_C_BEGIN extern "C" {
	#define __OOC_BLOCK__EXTERN_C_END   }
#else
	#define __OOC_BLOCK__EXTERN_C_BEGIN
	#define __OOC_BLOCK__EXTERN_C_END
#endif

#ifndef __OOC_FUNCTION__ALLOC
#define __OOC_FUNCTION__ALLOC calloc(1,num)
#endif

#ifndef __OOC_FUNCTION__FREE
#define __OOC_FUNCTION__FREE free
#endif


#ifndef __OOC_FUNCTION__PRINT_CLASS
#define __OOC_FUNCTION__PRINT_CLASS
#endif
#ifndef __OOC_FUNCTION__NEW_THREAD_LOCK
#define __OOC_FUNCTION__NEW_THREAD_LOCK
#endif
#ifndef __OOC_FUNCTION__NEW_THREAD_UNLOCK
#define __OOC_FUNCTION__NEW_THREAD_UNLOCK
#endif
#ifndef __OOC_FUNCTION__DELETE_THREAD_LOCK
#define __OOC_FUNCTION__DELETE_THREAD_LOCK
#endif
#ifndef __OOC_FUNCTION__DELETE_THREAD_UNLOCK
#define __OOC_FUNCTION__DELETE_THREAD_UNLOCK
#endif
//////////////////////////////////////


//class core design
#define __OOC_CLASS__DECLARE_DEFINITIONS(Type) \
	typedef struct _##Type Type; \
	typedef struct _##Type * (*Type##Pt##Fn)(void *,...);

#define __OOC_CLASS__DECLARE_STACK_FUNCTIONS(Type) \
	__OOC_BLOCK__EXTERN_C_BEGIN \
		int ini##Type(struct _##Type * ,void *); \
		int fin##Type(struct _##Type * ,void *); \
	__OOC_BLOCK__EXTERN_C_END

#define __OOC_CLASS__DECLARE_HEAP_FUNCTIONS(Type) \
	__OOC_BLOCK__EXTERN_C_BEGIN \
		struct _##Type * new##Type(void *); \
		int del##Type(struct _##Type **,void *); \
	__OOC_BLOCK__EXTERN_C_END

#define __OOC_CLASS__DECLARE_FUNCTIONS(Type) \
	__OOC_CLASS__DECLARE_STACK_FUNCTIONS(Type)\
	__OOC_CLASS__DECLARE_HEAP_FUNCTIONS(Type)


#define __OOC_CLASS__RAW_DESIGN(Type) \
	__OOC_CLASS__DECLARE_DEFINITIONS(Type) \
	__OOC_CLASS__DECLARE_FUNCTIONS(Type) \
	struct _##Type

//////////////////////////////////////

//ctor&dtor design
#define __OOC_CONSTRUCTOR__CLASS_DESIGN(Type) \
	struct _##Type * new##Type(void *__OOC_VARIABLE__PARAMETER) { \
		struct _##Type *__OOC_VARIABLE__THIS=NULL; \
		int ret_ini=0; \
		__OOC_FUNCTION__NEW_THREAD_LOCK ; \
		__OOC_FUNCTION__PRINT_CLASS ; \
		__OOC_VARIABLE__THIS=(struct _##Type*)__OOC_FUNCTION__ALLOC(sizeof(struct _##Type)); \
		if( NULL==__OOC_VARIABLE__THIS ) { \
			__OOC_FUNCTION__NEW_THREAD_UNLOCK ; \
			return NULL; \
		} \
		ret_ini=ini##Type(__OOC_VARIABLE__THIS,__OOC_VARIABLE__PARAMETER); \
		if(0>ret_ini) { \
			__OOC_FUNCTION__FREE(__OOC_VARIABLE__THIS); \
			__OOC_FUNCTION__NEW_THREAD_UNLOCK ; \
			return NULL; \
		} \
		__OOC_FUNCTION__NEW_THREAD_UNLOCK ; \
		return __OOC_VARIABLE__THIS; \
	} \
	int ini##Type(struct _##Type * __OOC_VARIABLE__THIS,void *__OOC_VARIABLE__PARAMETER)
//
#define __OOC_DESTRUCTOR__CLASS_DESIGN(Type) \
	int del##Type(struct _##Type **__OOC_VARIABLE__THIS_ADDRESS,void *__OOC_VARIABLE__PARAMETER) { \
		struct _##Type * __OOC_VARIABLE__THIS=*(__OOC_VARIABLE__THIS_ADDRESS); \
		int ret_fin=0; \
		__OOC_FUNCTION__DELETE_THREAD_LOCK ; \
		__OOC_FUNCTION__PRINT_CLASS ; \
		if(NULL==__OOC_VARIABLE__THIS_ADDRESS||NULL==__OOC_VARIABLE__THIS) { \
			__OOC_FUNCTION__DELETE_THREAD_UNLOCK ; \
			return (-1); \
		} \
		ret_fin=fin##Type(*(__OOC_VARIABLE__THIS_ADDRESS),__OOC_VARIABLE__PARAMETER); \
		if(0>ret_fin) {\
			__OOC_FUNCTION__DELETE_THREAD_UNLOCK ; \
			return (-1); \
		} \
		__OOC_FUNCTION__FREE(*(__OOC_VARIABLE__THIS_ADDRESS)); \
		(*(__OOC_VARIABLE__THIS_ADDRESS))=NULL; \
		__OOC_FUNCTION__DELETE_THREAD_UNLOCK ; \
		return (0); \
	} \
	int fin##Type(struct _##Type *__OOC_VARIABLE__THIS,void *__OOC_VARIABLE__PARAMETER)

/////////////////////////////////////////////////////////////
