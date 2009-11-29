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
//
//  Various macro definitions for various Perl builds:
//  --------------------------------------------------
//
//      PERL5010
//      v5.010 Core (default from ActiveState.com)
//			Defines the following:	
//          WIN32,_WINDOWS,EMBED,MSWIN32,HAVE_DES_FCRYPT,MULTIPLICITY,
//          PERL_IMPLICIT_CONTEXT,PERL_IMPLICIT_SYS,PERL_MSVCRT_READFIX,
//          PERL_NO_GET_CONTEXT,PERL_POLLUTE,USE_ITHREADS
//
//
//
//      PERL5008
//      v5.008 Core (default from ActiveState.com)
//			Defines the following:	
//          WIN32,_WINDOWS,EMBED,MSWIN32,HAVE_DES_FCRYPT,MULTIPLICITY,
//          PERL_IMPLICIT_CONTEXT,PERL_IMPLICIT_SYS,PERL_MSVCRT_READFIX,
//          PERL_NO_GET_CONTEXT,PERL_POLLUTE,USE_ITHREADS
//
//
//		PERL5006
//      v5.006 Core (default from ActiveState.com)
//			Defines the following:	
//          WIN32,_WINDOWS,EMBED,MSWIN32,HAVE_DES_FCRYPT,MULTIPLICITY,
//          PERL_IMPLICIT_CONTEXT,PERL_IMPLICIT_SYS,PERL_MSVCRT_READFIX,
//          PERL_NO_GET_CONTEXT,PERL_POLLUTE,USE_ITHREADS
//          
//
//		PERL5005_AS
//      v5.005 ActiveState
//			Defines the following:
//          EMBED,MSWIN32,PERL_OBJECT
//
//		PERL5005
//      v5.005 Core
//			Defines the following:
//          EMBED,MSWIN32
//
//		PERL5003
//      v5.003 ActiveState
//			Defines the following:
//          EMBED,MSWIN32,PERL_OBJECT

////////////////////////////
// The macro _MSC_VER defines the version of the Microsoft compiler being used
// If this macro is not defined (eg. compiling resources, which uses the 
// resource compiler and not the c compiler) then let's define it for
// fun (and so Perl's headers work correctly).
// Default value is 1200 (defining MS C version 6.0)
#ifndef _MSC_VER
    #define _MSC_VER 1200
#endif

#if defined PERL5010
    //  ActiveState version of Perl 5.010
    //  Linked libraries:
    //                  - Perl510.lib
    //        
    #pragma message( "Compiling for ActiveState version of Perl 5.010" )
    #define EMBED
    #define MSWIN32
    #define HAVE_DES_FCRYPT
    #define MULTIPLICITY
    #define PERL_IMPLICIT_CONTEXT
    #define PERL_IMPLICIT_SYS
    #define PERL_MSVCRT_READFIX
    #define PERL_NO_GET_CONTEXT
    #define PERL_POLLUTE
    #define USE_ITHREADS
    #define USE_LARGE_FILES 
    #define NO_STRICT 
    #define USE_PERLIO 

#elif defined PERL5008
    //  ActiveState version of Perl 5.008
    //  Linked libraries:
    //                  - Perl58.lib
    //        
    #pragma message( "Compiling for ActiveState version of Perl 5.008" )
    #define EMBED
    #define MSWIN32
    #define HAVE_DES_FCRYPT
    #define MULTIPLICITY
    #define PERL_IMPLICIT_CONTEXT
    #define PERL_IMPLICIT_SYS
    #define PERL_MSVCRT_READFIX
    #define PERL_NO_GET_CONTEXT
    #define PERL_POLLUTE
    #define USE_ITHREADS
    #define USE_LARGE_FILES 
    #define NO_STRICT 
    #define USE_PERLIO 

#elif defined PERL5006
    //  ActiveState version of Perl 5.006
    //  Linked libraries:
    //                  - PerlEZ.lib
    //                  - Perl56.lib
    //        
    #pragma message( "Compiling for ActiveState version of Perl 5.006" )
    #define EMBED
    #define MSWIN32
    #define HAVE_DES_FCRYPT
    #define MULTIPLICITY
    #define PERL_IMPLICIT_CONTEXT
    #define PERL_IMPLICIT_SYS
    #define PERL_MSVCRT_READFIX
    #define PERL_NO_GET_CONTEXT
    #define PERL_POLLUTE
    #define USE_ITHREADS
 
#elif defined PERL5005_AS
    // ActiveState version of Perl 5.005
    // Linked libraries:
    //                  - none
    //
    #pragma message( "Compiling for ActiveState version of Perl 5.005" )
//    #define EMBED
    #define MSWIN32
    #define PERL_OBJECT

#elif defined PERL5005
    //  Core version of Perl 5.005
    // Linked libraries:
    //                  - perl.lib
    //
    #pragma message( "Compiling for Core version of Perl 5.005" )
    #define EMBED
    #define MSWIN32

#elif defined PERL5003 
    //  ActiveState version of Perl 5.003
    // Linked libraries:
    //                  - none
    //    
    #pragma message( "Compiling for ActiveState version of Perl 5.003" )
    #define EMBED
    #define MSWIN32
    #define PERL_OBJECT
#else
	//  No Perl build version specified. This is a problem.
    // Linked libraries:
    //                  - none
    //    
    #pragma message( "*** No Perl build version detected. Check preWin32Perl.h for supported macros." )
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
