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
 * License along with OOC-GCC. If not, see
 * <http://www.gnu.org/licenses/>.
 */


#pragma once
#include "OOCfg.h"

//value
#ifndef __OOC_VALUE__RETURN_ERROR_LIMIT
	#define __OOC_VALUE__RETURN_ERROR_LIMIT (0-10000)
#endif

#ifndef __OOC_VALUE__TRUE
	#define __OOC_VALUE__TRUE (1)
#endif

#ifndef __OOC_VALUE__FALSE
	#define __OOC_VALUE__FALSE (0)
#endif

#ifndef __OOC_VALUE__OK
	#define __OOC_VALUE__OK (0)
#endif

#ifndef __OOC_VALUE__FAIL
	#define __OOC_VALUE__FAIL (0-1)
#endif

//utils
#define __OOC_FUNCTION__OFFSET_OF offsetof

#define __OOC_FUNCTION__CONTAINER_OF(ptr, type, member) ({			\
	const typeof( ((type *)0)->member ) *__mptr = (ptr); \
	(type *)( (char *)__mptr - offsetof(type,member) );})

#define __OOC_FUNCTION__SWAP(a, b) \
        do { typeof(a) __tmp = (a); (a) = (b); (b) = __tmp; } while (0)

#ifndef __OOC_FUNCTION__MEMORY_COPY
	#define __OOC_FUNCTION__MEMORY_COPY memcpy
#endif
#ifndef __OOC_FUNCTION__MEMORY_CLEAN
	#define __OOC_FUNCTION__MEMORY_CLEAN(pt,num) memset(pt,'\0',num)
#endif

#define __OOC_FUNCTION__VALUE_TO_STRING(x) __OOC_FUNCTION__VALUE_TO_CHARS(x)
#define __OOC_FUNCTION__VALUE_TO_CHARS(x) #x

#define __OOC_FUNCTION__PACK_PARAMETER(Type,...) ((void *)&(Type){__VA_ARGS__})

#define __OOC_FUNCTION__INI(pointer,Type,parameter) ini##Type((Type*)(pointer),(parameter))
#define __OOC_FUNCTION__FIN(pointer,Type,parameter) fin##Type((Type*)(pointer),(parameter))
#define __OOC_FUNCTION__NEW(Type,parameter)  ((void *)new##Type((parameter)))
#define __OOC_FUNCTION__DEL(pointer,Type,parameter) del##Type((struct _##Type**)&(pointer),(parameter))

//debug
#ifdef __OOC_USING__CLASS_FUNCTION_PRINTER
	#define __OOC_FUNCTION__PRINT_CLASS  printf("%s    \t%p\t%p\n",__FUNCTION__,__OOC_VARIABLE__THIS,__OOC_VARIABLE__PARAMETER)
#else
	#define __OOC_FUNCTION__PRINT_CLASS  ((void)0)
#endif

#if defined(__OOC_USING__DEBUG)
	#include "OODbg.h"
#else
	#define __OOC_FUNCTION__RESET_MEMORY_FUNCTIONS(real_alloc,real_realloc,real_free) ((void)0)
	#define __OOC_FUNCTION__ALLOC(num) calloc(1,num)
	#define __OOC_FUNCTION__FREE  free
	#define __OOC_FUNCTION__REALLOC realloc
	#define __OOC_FUNCTION__ASSERT(test) ((void)0)
	#define __OOC_FUNCTION__CHECK(test) ((void)0)
	#define __OOC_FUNCTION__LOG(what) ((void)0);
	#define __OOC_FUNCTION__THROW(e)  ((void)0);
	#define __OOC_FUNCTION__TRY ((void)0);
	#define __OOC_FUNCTION__CATCH(e) ((void)0);
	#define __OOC_FUNCTION__ELSE_CATCH ((void)0);
	#define __OOC_FUNCTION__CATCH_ELSE ((void)0);
	#define __OOC_FUNCTION__FINALLY ((void)0);
	#define __OOC_FUNCTION__END_TRY ((void)0);
	#define __OOC_FUNCTION__SET_EXCEPTIONS ((void)0);
	#define __OOC_FUNCTION__GET_EXCEPTIONS ((void**)0);
	#define __OOC_FUNCTION__SET_EXCEPTION ((void)0);
	#define __OOC_FUNCTION__GET_EXCEPTION ((void*)0);
	typedef struct {char * reason;} Exception;
#endif

/////////////////////////////////////////////////////////////////
//method declare

	typedef size_t (*tFn)(void *,...);
	typedef size_t (*tPtFn)(void *,...);


	typedef void (*vFn)(void *,...);
	typedef void * (*vPtFn)(void *,...);

	typedef char (*cFn)(void *,...);
	typedef char* (*cPtFn)(void *,...);
	typedef unsigned char (*ucFn)(void *,...);
	typedef unsigned char* (*ucPtFn)(void *,...);

	typedef short (*sFn)(void *,...);
	typedef short* (*sPtFn)(void *,...);
	typedef unsigned short (*usFn)(void *,...);
	typedef unsigned short* (*usPtFn)(void *,...);

	typedef int (*iFn)(void *,...);
	typedef int* (*ipFn)(void *,...);
	typedef unsigned int (*uiFn)(void *,...);
	typedef unsigned int* (*uipFn)(void *,...);

	typedef long (*lFn)(void *,...);
	typedef long* (*lPtFn)(void *,...);
	typedef unsigned long (*ulFn)(void *,...);
	typedef unsigned long* (*ulPtFn)(void *,...);

	typedef long long (*llFn)(void *,...);
	typedef long long * (*llPtFn)(void *,...);
	typedef unsigned long long (*ullFn)(void *,...);
	typedef unsigned long long * (*ullPtFn)(void *,...);

	typedef float (*fFn)(void *,...);
	typedef float* (*fPtFn)(void *,...);
/////////////////////////////////////////////////////////////////
#include "OOCore.h"
////////////////////////////////////////////////////////////////////
//ROOT HEAD
typedef struct __OOC_STRUCT__classRootHead {
	//void * __ooc_ex;
	void * __ooc_realStatic;
}OOC_STRUCT__classRootHead;

typedef struct __OOC_STRUCT__staticRootHead {
	//void * __ooc_ex;
	int (*__ooc_classDelete)(void *,...);
	size_t __ooc_classCount;
}OOC_STRUCT__staticRootHead;

#define __OOC_CLASS__ROOT_HEAD \
		OOC_STRUCT__classRootHead __ooc_classRootHead

#define __OOC_STATIC__ROOT_HEAD \
		OOC_STRUCT__staticRootHead __ooc_staticRootHead

#define __OOC_CLASS__ROOT_HEAD_SIZE (sizeof(OOC_STRUCT__classRootHead))
//////////////////////////////////

#define __OOC_STATIC__ROOT_HEAD_SIZE (sizeof(OOC_STRUCT__staticRootHead))
/////////////////////////////////
//offset
/////////////////////////////////
#define __OOC_CLASS__REAL_STATIC_OFFSET (__OOC_FUNCTION__OFFSET_OF(OOC_STRUCT__classRootHead,__ooc_realStatic))
#define __OOC_CLASS__REAL_STATIC(pointer) (*(void **)((unsigned char*)pointer+__OOC_CLASS__REAL_STATIC_OFFSET))

//
#define __OOC_STATIC__CLASS_DELETE_OFFSET (offsetof(OOC_STRUCT__staticRootHead,__ooc_classDelete))
#define __OOC_STATIC__CLASS_DELETE(pointer) (*(iFn*)((unsigned char *)pointer+__OOC_STATIC__CLASS_DELETE_OFFSET))
#define __OOC_FUNCTION__DELETE(pointer,parameter) __OOC_STATIC__CLASS_DELETE(__OOC_CLASS__REAL_STATIC(pointer))((&pointer),(parameter))

#define __OOC_STATIC__CLASS_COUNT_OFFSET (offsetof(OOC_STRUCT__staticRootHead,__ooc_classCount))
#define __OOC_STATIC__CLASS_COUNT(pointer) (*(size_t*)((unsigned char *)(pointer)+__OOC_STATIC__CLASS_COUNT_OFFSET))


//////////////////////////////////////////////////////////
//BODY
#define __OOC_CLASS__BODY(pointer) ((void *)((unsigned char *)pointer+__OOC_CLASS__ROOT_HEAD_SIZE))
#define __OOC_STATIC__BODY(pointer) ((void *)((unsigned char *)pointer+__OOC_STATIC__ROOT_HEAD_SIZE))


///////////////////////////////////////////////////////////////////
//CLASS DESIGN
/////////////////////////////////////////////////////////////////////
//TAIL LINK
#define __OOC_CLASS__STATIC_LINK(Type) \
	void ** St##Type##_static

/////////////////////////////////////////////////////////////////////
#ifndef __OOC_CLASS__ANONYMOUS_NAME
	#define __OOC_CLASS__ANONYMOUS_NAME
#endif
/////////////////////////////////////////////////////////////////////

//ROOTED DESIGN
#define __OOC_CLASS__ROOTED_DESIGN(Type) \
	__OOC_CLASS__RAW_DESIGN(Type) { \
		__OOC_CLASS__ROOT_HEAD ; \
		struct

#define __OOC_STATIC__ROOTED_DESIGN(Type) \
			__OOC_CLASS__STATIC_LINK(Type); \
		} __OOC_CLASS__ANONYMOUS_NAME;\
	}; \
	__OOC_CLASS__RAW_DESIGN(St##Type) {\
		__OOC_STATIC__ROOT_HEAD

/////////////////////////////////////////////////////////////
//EXTENDED DESIGN
#define __OOC_STATIC__RAW_DESIGN(Type) __OOC_CLASS__RAW_DESIGN(St##Type)

#ifdef __OOC_USING__ANONYMOUS_EXTENSIONS
	#define __OOC_CLASS__EXTENDED_DESIGN(Type,SuType) \
		__OOC_CLASS__RAW_DESIGN(Type){ \
			struct _##SuType ; \
			struct
	#define __OOC_STATIC__EXTENDED_DESIGN(Type,SuType) \
			__OOC_CLASS__STATIC_LINK(Type); \
			} __OOC_CLASS__ANONYMOUS_NAME;\
		}; \
		__OOC_STATIC__RAW_DESIGN(Type) {\
			struct _St##SuType
#else
    #define __OOC_CLASS__EXTENDED_DESIGN(Type,SuType) \
		__OOC_CLASS__RAW_DESIGN(Type){ \
			struct _##SuType SuType; \
			struct
    #define __OOC_STATIC__EXTENDED_DESIGN(Type,SuType) \
			__OOC_CLASS__STATIC_LINK(Type); \
			} __OOC_CLASS__ANONYMOUS_NAME;\
		}; \
		__OOC_STATIC__RAW_DESIGN(Type) {\
			struct _St##SuType St##SuType
#endif
//////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
//UTILS FOR ROOTED CTOR&DTOR BODY DESIGN
#define __OOC_FUNCTION__ASSIGN_CLASS_DELETE(Type) \
	__OOC_STATIC__CLASS_DELETE(__OOC_VARIABLE__THIS)=(void *)del##Type
#define __OOC_FUNCTION__ASSIGN_REAL_STATIC(Type) \
	__OOC_CLASS__REAL_STATIC(__OOC_VARIABLE__THIS)=(void *)St##Type##_static
/////////////////////////////////////////////////////////////////////////////////
//ROOTED CTOR&DTOR CLASS BODY DESIGN
#define __OOC_CONSTRUCTOR__ROOTED_CLASS_BODY_WITH_STATIC_PART(Type,__OOC_FUNCTION__RELOAD) \
	static struct _St##Type * St##Type##_static=NULL; \
	int (*fn_reload)(void *,...)=NULL; \
	__OOC_FUNCTION__PRINT_CLASS; \
	if(NULL==St##Type##_static) { \
		St##Type##_static=newSt##Type(__OOC_VARIABLE__PARAMETER); \
		if(NULL==St##Type##_static) { \
			return (-1); \
		} \
	} \
	__OOC_VARIABLE__THIS->St##Type##_static=(void **)&(St##Type##_static); \
	++__OOC_STATIC__CLASS_COUNT(St##Type##_static); \
	__OOC_FUNCTION__ASSIGN_REAL_STATIC(Type); \
	fn_reload=(void *)__OOC_FUNCTION__RELOAD; \
	if(NULL!=fn_reload) { \
		return fn_reload(__OOC_VARIABLE__THIS,__OOC_VARIABLE__PARAMETER); \
	} \
	return (0)
#define __OOC_CONSTRUCTOR__EXTENDED_ROOTED_CLASS_BODY_WITH_STATIC_PART(Type,SuType,__OOC_FUNCTION__RELOAD) \
    static struct _St##Type * St##Type##_static=NULL; \
    int (*fn_reload)(void *,...)=NULL; \
    int ret_iniSu=0; \
    __OOC_FUNCTION__PRINT_CLASS ; \
    if(NULL==St##Type##_static) { \
        St##Type##_static=newSt##Type(__OOC_VARIABLE__PARAMETER); \
        if(NULL==St##Type##_static) { \
            return (-1); \
        } \
    } \
    __OOC_VARIABLE__THIS->St##Type##_static=(void **)&(St##Type##_static); \
    ++__OOC_STATIC__CLASS_COUNT(St##Type##_static); \
    ret_iniSu=ini##SuType((SuType *)(__OOC_VARIABLE__THIS),__OOC_VARIABLE__PARAMETER); \
    if(0>ret_iniSu) { \
        return (ret_iniSu); \
    }  \
    __OOC_FUNCTION__ASSIGN_REAL_STATIC(Type); \
    fn_reload=(void *)__OOC_FUNCTION__RELOAD; \
    if(NULL!=fn_reload) { \
		return fn_reload(__OOC_VARIABLE__THIS,__OOC_VARIABLE__PARAMETER); \
    } \
    return (0)
#define __OOC_DESTRUCTOR__ROOTED_CLASS_BODY_WITH_STATIC_PART(Type,__OOC_FUNCTION__UNLOAD) \
    St##Type * St##Type##_static=(*(__OOC_VARIABLE__THIS->St##Type##_static)); \
    int (*fn_unload)(void *,...)=NULL; \
	__OOC_FUNCTION__PRINT_CLASS ; \
	fn_unload=(void *)__OOC_FUNCTION__UNLOAD; \
    if(NULL!=fn_unload) { \
    	int ret_unload=fn_unload(__OOC_VARIABLE__THIS,__OOC_VARIABLE__PARAMETER); \
        if(0>ret_unload){ \
            return (ret_unload); \
        } \
    } \
	if(NULL==St##Type##_static) { \
		return (-1); \
	}\
    if( 0<__OOC_STATIC__CLASS_COUNT(St##Type##_static) ) { \
    	--__OOC_STATIC__CLASS_COUNT(St##Type##_static); \
        if( 0==__OOC_STATIC__CLASS_COUNT(St##Type##_static) ) { \
        	int ret_delSt=0; \
        	*(__OOC_VARIABLE__THIS->St##Type##_static)=NULL; \
            ret_delSt=delSt##Type(&St##Type##_static,__OOC_VARIABLE__PARAMETER); \
            if(0>ret_delSt) { \
                return (ret_delSt); \
            } \
        } \
    }\
    __OOC_FUNCTION__MEMORY_CLEAN(__OOC_CLASS__BODY(__OOC_VARIABLE__THIS),sizeof(Type)-__OOC_CLASS__ROOT_HEAD_SIZE); \
    return (0)
#define __OOC_DESTRUCTOR__EXTENDED_ROOTED_CLASS_BODY_WITH_STATIC_PART(Type,SuType,__OOC_FUNCTION__UNLOAD) \
    St##Type * St##Type##_static=(*(__OOC_VARIABLE__THIS->St##Type##_static)); \
	int ret_finSu=0; \
	int (*fn_unload)(void *,...)=NULL; \
	__OOC_FUNCTION__PRINT_CLASS ; \
	fn_unload=(void *)__OOC_FUNCTION__UNLOAD; \
    if(NULL!=fn_unload) { \
    	int ret_unload=fn_unload(__OOC_VARIABLE__THIS,__OOC_VARIABLE__PARAMETER); \
        if(0>ret_unload){ \
            return (ret_unload); \
        } \
    } \
    ret_finSu=fin##SuType((SuType *)(__OOC_VARIABLE__THIS),__OOC_VARIABLE__PARAMETER); \
    if(0>ret_finSu) { \
        return (ret_finSu); \
    } \
    if(NULL==St##Type##_static) { \
        return (-1); \
    }\
    if( 0<__OOC_STATIC__CLASS_COUNT(St##Type##_static) ) { \
        --__OOC_STATIC__CLASS_COUNT(St##Type##_static) ; \
        if( 0==__OOC_STATIC__CLASS_COUNT(St##Type##_static) ) { \
        	int ret_delSt=0; \
            *(__OOC_VARIABLE__THIS->St##Type##_static)=NULL; \
            ret_delSt=delSt##Type(&St##Type##_static,__OOC_VARIABLE__PARAMETER); \
            if(0>ret_delSt) { \
                return (ret_delSt); \
            } \
        } \
    }\
    __OOC_FUNCTION__MEMORY_CLEAN(__OOC_CLASS__BODY(__OOC_VARIABLE__THIS),sizeof(Type)-__OOC_CLASS__ROOT_HEAD_SIZE); \
    return (0)
///////////////////////////////////////////////////////////////////////////////////////////////////////
////ROOTED CTOR&DTOR STATIC BODY DESIGN
#define __OOC_CONSTRUCTOR__ROOTED_STATIC_BODY(Type,__OOC_FUNCTION__RELOAD_STATIC) \
	int (*fn_reloadSt)(void *,...)=NULL;\
	__OOC_FUNCTION__PRINT_CLASS ; \
	__OOC_FUNCTION__ASSIGN_CLASS_DELETE(Type); \
	fn_reloadSt=(void *)__OOC_FUNCTION__RELOAD_STATIC; \
	if(NULL!=fn_reloadSt) { \
		return fn_reloadSt(__OOC_VARIABLE__THIS,__OOC_VARIABLE__PARAMETER); \
	} \
	return (0)
#define __OOC_CONSTRUCTOR__EXTENDED_ROOTED_STATIC_BODY(Type,SuType,__OOC_FUNCTION__RELOAD_STATIC) \
	int (*fn_reloadSt)(void *,...)=NULL; \
	int ret_iniSu=0; \
	__OOC_FUNCTION__PRINT_CLASS ; \
    ret_iniSu=iniSt##SuType((St##SuType *)(__OOC_VARIABLE__THIS),__OOC_VARIABLE__PARAMETER); \
    if(0>ret_iniSu) { \
        return (ret_iniSu); \
    }  \
    __OOC_FUNCTION__ASSIGN_CLASS_DELETE(Type); \
    fn_reloadSt=(void *)__OOC_FUNCTION__RELOAD_STATIC; \
	if(NULL!=fn_reloadSt) { \
		return fn_reloadSt(__OOC_VARIABLE__THIS,__OOC_VARIABLE__PARAMETER); \
	} \
	return (0)
#define __OOC_DESTRUCTOR__ROOTED_STATIC_BODY(Type,__OOC_FUNCTION__UNLOAD_STATIC) \
	int (*fn_unloadSt)(void *,...)=NULL; \
	__OOC_FUNCTION__PRINT_CLASS ; \
	fn_unloadSt=(void *)__OOC_FUNCTION__UNLOAD_STATIC; \
	if(NULL!=fn_unloadSt) { \
		int ret_unloadSt=fn_unloadSt(__OOC_VARIABLE__THIS,__OOC_VARIABLE__PARAMETER);\
		if(0>ret_unloadSt){ \
			return (ret_unloadSt); \
		} \
	} \
	__OOC_FUNCTION__MEMORY_CLEAN(__OOC_STATIC__BODY(__OOC_VARIABLE__THIS),sizeof(St##Type)-__OOC_STATIC__ROOT_HEAD_SIZE); \
	return (0)
#define __OOC_DESTRUCTOR__EXTENDED_ROOTED_STATIC_BODY(Type,SuType,__OOC_FUNCTION__UNLOAD_STATIC) \
	int (*fn_unloadSt)(void *,...)=NULL; \
	int ret_finSt=0; \
	__OOC_FUNCTION__PRINT_CLASS ; \
	fn_unloadSt=(void *)__OOC_FUNCTION__UNLOAD_STATIC; \
	if(NULL!=fn_unloadSt) { \
		int ret_unloadSt=fn_unloadSt(__OOC_VARIABLE__THIS,__OOC_VARIABLE__PARAMETER);\
		if(0>ret_unloadSt){ \
			return (ret_unloadSt); \
		} \
	} \
	ret_finSt=finSt##SuType((St##SuType *)(__OOC_VARIABLE__THIS),__OOC_VARIABLE__PARAMETER); \
	if(0>ret_finSt){ \
		return (ret_finSt); \
	}  \
	__OOC_FUNCTION__MEMORY_CLEAN(__OOC_STATIC__BODY(__OOC_VARIABLE__THIS),sizeof(St##Type)-__OOC_STATIC__ROOT_HEAD_SIZE); \
	return (0)
/////////////////////////////////////////////////////////////////////////////////////////////////
//UTILS FOR ASSEMBLE WITH STATIC
#define __OOC_CONSTRUCTOR__STATIC_DESIGN(Type) \
		__OOC_CONSTRUCTOR__CLASS_DESIGN(St##Type)

#define __OOC_DESTRUCTOR__STATIC_DESIGN(Type) \
		__OOC_DESTRUCTOR__CLASS_DESIGN(St##Type)
////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//ASSEMBLE WITH STATIC PART
#define __OOC_ASSEMBLE__00(Type,__OOC_FUNCTION__RELOAD,__OOC_FUNCTION__UNLOAD,__OOC_FUNCTION__RELOAD_STATIC,__OOC_FUNCTION__UNLOAD_STATIC) \
	__OOC_CONSTRUCTOR__CLASS_DESIGN(Type){ \
		__OOC_CONSTRUCTOR__ROOTED_CLASS_BODY_WITH_STATIC_PART(Type,__OOC_FUNCTION__RELOAD); \
	} \
	__OOC_DESTRUCTOR__CLASS_DESIGN(Type){ \
		__OOC_DESTRUCTOR__ROOTED_CLASS_BODY_WITH_STATIC_PART(Type,__OOC_FUNCTION__UNLOAD); \
	} \
	__OOC_CONSTRUCTOR__STATIC_DESIGN(Type){ \
		__OOC_CONSTRUCTOR__ROOTED_STATIC_BODY(Type,__OOC_FUNCTION__RELOAD_STATIC); \
	} \
	__OOC_DESTRUCTOR__STATIC_DESIGN(Type){ \
		__OOC_DESTRUCTOR__ROOTED_STATIC_BODY(Type,__OOC_FUNCTION__UNLOAD_STATIC); \
	}

#define __OOC_ASSEMBLE__01(Type,SuType,__OOC_FUNCTION__RELOAD,__OOC_FUNCTION__UNLOAD,__OOC_FUNCTION__RELOAD_STATIC,__OOC_FUNCTION__UNLOAD_STATIC) \
	__OOC_CONSTRUCTOR__CLASS_DESIGN(Type){ \
		__OOC_CONSTRUCTOR__ROOTED_CLASS_BODY_WITH_STATIC_PART(Type,__OOC_FUNCTION__RELOAD); \
	} \
	__OOC_DESTRUCTOR__CLASS_DESIGN(Type){ \
		__OOC_DESTRUCTOR__ROOTED_CLASS_BODY_WITH_STATIC_PART(Type,__OOC_FUNCTION__UNLOAD); \
	} \
	__OOC_CONSTRUCTOR__STATIC_DESIGN(Type){ \
		__OOC_CONSTRUCTOR__EXTENDED_ROOTED_STATIC_BODY(Type,SuType,__OOC_FUNCTION__RELOAD_STATIC); \
	} \
	__OOC_DESTRUCTOR__STATIC_DESIGN(Type){ \
		__OOC_DESTRUCTOR__EXTENDED_ROOTED_STATIC_BODY(Type,SuType,__OOC_FUNCTION__UNLOAD_STATIC); \
	}
#define __OOC_ASSEMBLE__10(Type,SuType,__OOC_FUNCTION__RELOAD,__OOC_FUNCTION__UNLOAD,__OOC_FUNCTION__RELOAD_STATIC,__OOC_FUNCTION__UNLOAD_STATIC) \
	__OOC_CONSTRUCTOR__CLASS_DESIGN(Type){ \
		__OOC_CONSTRUCTOR__EXTENDED_ROOTED_CLASS_BODY_WITH_STATIC_PART(Type,SuType,__OOC_FUNCTION__RELOAD); \
	} \
	__OOC_DESTRUCTOR__CLASS_DESIGN(Type){ \
		__OOC_DESTRUCTOR__EXTENDED_ROOTED_CLASS_BODY_WITH_STATIC_PART(Type,SuType,__OOC_FUNCTION__UNLOAD); \
	} \
	__OOC_CONSTRUCTOR__STATIC_DESIGN(Type){ \
		__OOC_CONSTRUCTOR__ROOTED_STATIC_BODY(Type,__OOC_FUNCTION__RELOAD_STATIC); \
	} \
	__OOC_DESTRUCTOR__STATIC_DESIGN(Type){ \
		__OOC_DESTRUCTOR__ROOTED_STATIC_BODY(Type,__OOC_FUNCTION__UNLOAD_STATIC); \
	}
#define __OOC_ASSEMBLE__11(Type,SuType,__OOC_FUNCTION__RELOAD,__OOC_FUNCTION__UNLOAD,__OOC_FUNCTION__RELOAD_STATIC,__OOC_FUNCTION__UNLOAD_STATIC) \
	__OOC_CONSTRUCTOR__CLASS_DESIGN(Type){ \
		__OOC_CONSTRUCTOR__EXTENDED_ROOTED_CLASS_BODY_WITH_STATIC_PART(Type,SuType,__OOC_FUNCTION__RELOAD); \
	} \
	__OOC_DESTRUCTOR__CLASS_DESIGN(Type){ \
		__OOC_DESTRUCTOR__EXTENDED_ROOTED_CLASS_BODY_WITH_STATIC_PART(Type,SuType,__OOC_FUNCTION__UNLOAD); \
	} \
	__OOC_CONSTRUCTOR__STATIC_DESIGN(Type){ \
		__OOC_CONSTRUCTOR__EXTENDED_ROOTED_STATIC_BODY(Type,SuType,__OOC_FUNCTION__RELOAD_STATIC); \
	} \
	__OOC_DESTRUCTOR__STATIC_DESIGN(Type){ \
		__OOC_DESTRUCTOR__EXTENDED_ROOTED_STATIC_BODY(Type,SuType,__OOC_FUNCTION__UNLOAD_STATIC); \
	}
///////////////////////////////////////////////////////////////////////////////////////
