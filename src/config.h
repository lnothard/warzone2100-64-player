/* config.h.in.  Generated from configure.ac by autoheader.  */

/* Define to 1 if translation of program messages to the user's native
   language is requested. */
#define ENABLE_NLS 1

/* Define to 1 if you have the <alloca.h> header file. */
#define HAVE_ALLOCA_H 1

/* Define if the GNU dcgettext() function is already present or preinstalled.
   */
/* #undef HAVE_DCGETTEXT */

/* Define if FreeType supports the caching routines */
/* #undef HAVE_FT_CACHE */

/* Define if the GNU gettext() function is already present or preinstalled. */
#define HAVE_GETTEXT

/* Define if you have the iconv() function and it works. */
#define HAVE_ICONV 1

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* Define to 1 if you have the `putenv' function. */
#define HAVE_PUTENV 1

/* Define to 1 if you have the `setenv' function. */
#define HAVE_SETENV 1

/* Define to 1 if you have the `posix_spawn' function. */
#define HAVE_POSIX_SPAWN 1

/* Define to 1 if you have the `posix_spawnp' function. */
#define HAVE_POSIX_SPAWNP 1

/* Define to 1 if you have the `environ' declaration. */
#define HAVE_ENVIRON_DECL 1

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* The system provides strlcat */
/* #undef HAVE_SYSTEM_STRLCAT */

/* The system provides strlcpy */
/* #undef HAVE_SYSTEM_STRLCPY */

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the <sys/ucontext.h> header file. */
#define HAVE_SYS_UCONTEXT_H 1

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* The system provides a strlcat we can use */
/* #undef HAVE_VALID_STRLCAT */

/* The system provides a strlcpy we can use */
/* #undef HAVE_VALID_STRLCPY */

/* Name of package */
#define PACKAGE "warzone2100"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT "http://wz2100.net/"

/* Name of distributor compiling this package */
#define PACKAGE_DISTRIBUTOR "UNKNOWN"

/* Define to the full name of this package. */
#define PACKAGE_NAME "Warzone 2100"

/* Define to the full name and version of this package. */
/* #undef PACKAGE_STRING */

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "warzone2100"

/* Define to the home page for this package. */
/* #undef PACKAGE_URL */

/* Define to the version of this package. */
/* #undef PACKAGE_VERSION */

/* Enable extensions on AIX 3, Interix.  */
#ifndef _ALL_SOURCE
#define _ALL_SOURCE 1
#endif
/* Enable GNU extensions on systems that have them.  */
#ifndef _GNU_SOURCE
#define _GNU_SOURCE 1
#endif
/* Enable threading extensions on Solaris.  */
#ifndef _POSIX_PTHREAD_SEMANTICS
#define _POSIX_PTHREAD_SEMANTICS 1
#endif
/* Enable extensions on HP NonStop.  */
#ifndef _TANDEM_SOURCE
#define _TANDEM_SOURCE 1
#endif
/* Enable general extensions on Solaris.  */
#ifndef __EXTENSIONS__
/* #undef __EXTENSIONS__ */
#endif
/* Enable general extensions on macOS. */
#ifndef _DARWIN_C_SOURCE
#define _DARWIN_C_SOURCE 1
#endif


/* Version number of package */
/* #undef VERSION */

/* Define to 1 if on MINIX. */
/* #undef _MINIX */

/* Define to 2 if the system does not provide POSIX.1 features except with
   this defined. */
/* #undef _POSIX_1_SOURCE */

/* Define to 1 if you need to in order for `stat' and other things to work. */
/* #undef _POSIX_SOURCE */

/* Enable POSIX extensions if present */
#define _XOPEN_SOURCE 700

/* Explicitly-configured data dir search path
 - It will be treated as a relative path, and appended to the install PREFIX,
   unless WZ_DATADIR_ISABSOLUTE is defined. */
#define WZ_DATADIR "share/warzone2100"
/* #undef WZ_DATADIR_ISABSOLUTE */

/* The "BINDIR" used for install (within the install prefix) */
#define WZ_BINDIR "bin"

/* The location of the WZ locale information
 - It will be treated as a relative path, and appended to the install PREFIX,
   unless WZ_LOCALEDIR_ISABSOLUTE is defined. */
#define WZ_LOCALEDIR "share/locale"
/* #undef WZ_LOCALEDIR_ISABSOLUTE */

