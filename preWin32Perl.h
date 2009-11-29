#ifndef _PREWIN32_PERL_H
#define _PREWIN32_PERL_H

#   define _PREWIN32PERL_H_VERSION     20080321

//////////////////////////////////////////////////////////////////////////
//
//  preWin32Perl.h
//  --------------
//  This is a header to use *before* using the Win32Perl.h header.
//  This header file defines macros that in turn will enable
//  appropriate Perl macros that the default Win32 Perl
//  builds from ActiveState.com use.
//
//  TO USE THIS:
//      Refer to the Win32Perl.h header for details on use.
//

////////////////////////////
// The macro _MSC_VER defines the version of the Microsoft compiler being used
// If this macro is not defined (eg. compiling resources, which uses the 
// resource compiler and not the c compiler) then let's define it for
// fun (and so Perl's headers work correctly).
// Default value is 1200 (defining MS C version 6.0)
#ifndef _MSC_VER
    #define _MSC_VER 1200
#endif

	//////////////////////////////////////////////////////////////////////////
	//
	//  Load Perl Headers
	//  -----------------
	//	If we are building with the core distribution headers we can not define
	//	the function names using C++ because of name mangling
	#if defined(__cplusplus) 
		extern "C" {
	#endif

		#include "EXTERN.h"
		#include "perl.h"
		#include "XSub.h"

	#if defined(__cplusplus) 
		}
	#endif

#endif // _PREWIN32_PERL_H
