#ifndef STANDART_TYPES_H
#define STANDART_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

# define MSB_FIRST        0u    /* big endian ordering bit */
# define LSB_FIRST        1u    /* little endian ordering bit */

# define HIGH_BYTE_FIRST  0u    /* big endian ordering bit */
# define LOW_BYTE_FIRST   1u    /* little endian ordering bit */

/* Boolena value */
#ifndef TRUE
#define TRUE            1u
#endif

#ifndef FALSE
#define FALSE           0u
#endif


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

 typedef unsigned char         boolean;       /*        TRUE .. FALSE           */

 typedef signed char           sint8;         /*        -128 .. +127            */

 typedef unsigned char         uint8;         /*           0 .. 255             */

 typedef signed short          sint16;        /*      -32768 .. +32767          */

 typedef unsigned short        uint16;        /*           0 .. 65535           */

 typedef signed long           sint32;        /* -2147483648 .. +2147483647     */

 typedef unsigned long         uint32;        /*           0 .. 4294967295      */

 

 typedef signed int            sint8_least;   /* At least 7 bit + 1 bit sign    */

 typedef unsigned int          uint8_least;   /* At least 8 bit                 */

 typedef signed int            sint16_least;  /* At least 15 bit + 1 bit sign   */

 typedef unsigned int          uint16_least;  /* At least 16 bit                */

 typedef signed int            sint32_least;  /* At least 31 bit + 1 bit sign   */

 typedef unsigned int          uint32_least;  /* At least 32 bit                */

 
#if defined(__ghs__) && !defined(__LLONG_BIT)

 /* 
   The option --no_long_long for GHS compiler disables the support for the long long data type and generates compile
   errors if this type is used. Following typedefs are omitted if --no_long_long is
   given (__LLONG_BIT is not defined in this case).
 */ 

#else

#define PLATFORM_SUPPORT_SINT64_UINT64

 typedef signed long long      sint64;        /* -9223372036854775808 .. 9223372036854775807      */

 typedef unsigned long long    uint64;        /*                    0 .. 18446744073709551615     */

#endif

 

#if defined(__ghs__) && defined(__NoFloat__) 

 /* 

   The option -fnone for GHS compiler disallows all floating-point operations and generates compile errors if such
   operations are used by the software. This also applies to any corresponding type definition. 
   Following typedefs are omitted if -fnone is given (__NoFloat__ is defined in this case).

 */ 

# else

 typedef float                 float32;

 typedef double                float64;

# endif

 

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#endif  /* STANDART_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Standart_Types.h
 *********************************************************************************************************************/