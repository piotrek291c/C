/*******************************************************************************
* @file
* @brief      Header file UsefulFunctions.h
*
* @par Copyright
* This code is the property of \n
*
* @par Hints
* For history information see the commit comments in the code repository.
*
*******************************************************************************/

#ifndef __USEFULFUNCTIONS_H__
#define __USEFULFUNCTIONS_H__

/*******************************************************************************
 * INCLUDES SECTION
*******************************************************************************/
#include "Standart_Types.h"
#include "Own_Types.h"

/*******************************************************************************
 * GLOBAL CONSTANT MACROS SECTION
*******************************************************************************/

/**
 * @brief A macro for handle timer.
 *
 * @param t - timer
 */

#define HANDLE_TIMER( t )                          ( if( t > 0u ) { t--; } )
/**
 * @brief A macro for reset timer.
 *
 * @param t - timer
 */

#define RESET_TIMER( t )                           ( t = 0u; )
/**
 * @brief A macro for set timer.
 *
 * @param t - timer
 * @param v - value to set
 */
#define SET_TIMER( t, v )                          ( t = ( v ); )

/**
 * @brief A macro for check timer status.
 *
 * @param t - timer
 * @return timer status
 */
#define IS_TIMER_FINISHED( t )                     ( t == 0u )

/**
 * @brief A macro for return abs value.
 *
 * @return abs value
 */
#define ABS( v )                                   ( (v >= 0) ? ( v ) : ( -v ))

/**
 * @brief Macro for exponentiation.
 * @param x - number
 * @return second power value
 */
#define POW2( x )                                                         ( ( x ) * ( x ) )

/**
 * @brief Convert the order of a multi-byte variable uint32
 * @param v - value
 */
#define BYTE_SWAP_32( v )   { \
                                ((uint32) (( v & 0xFF000000u) >> 24u) | (( v & 0x00FF0000u) >> 8u) | \
                                (( v & 0x0000FF00u) <<  8u) | (( v & 0x000000FFu) << 24u)) \
                            }

/**
 * @brief Convert the order of a multi-byte variable uint16
 * @param v - value
 */
#define BYTE_SWAP_16( v )    ((uint16) (( v & 0xFF00u) >> 8u) | (( v & 0x00FFu) << 8u))

/* Size of any array state buffer */
#define SIZE_OF_ARRAY_ELEMENTS(array) ((sizeof(array)) / (sizeof(array[0])))





/* template Error code */
#define TEMPLATE_ERR_OK 0
#define TEMPLATE_ERR_BUSY -1

/*******************************************************************************
 * FUNCTION DECLARATION SECTION
*******************************************************************************/
Std_ReturnType template(void);

int scanf(const char *format, ...);

int strcmp(const char *str1, const char *str2);

char *strstr(const char *, const char *);

char *strchr(const char *, int);

char *strcat(char *destination, const char *source);

char *strcpy(char *dest, const char *src);

size_t strlen(const char *str);

int getopt(int argc, char *const argv[], const char *optstring);

char *getenv(const char *varname);

void *malloc(size_t size);

void free(void *ptr);

void qsort(
    void *base,
    size_t num,
    size_t width,
    int (*compare)(const void *, const void *));

int system(const char *command);

int isalpha(int ch);

int isdigit(int ch);

void *memchr(void *ptr, int value, std::size_t num);

int memcmp(const void *ptr1, const void *ptr2, std::size_t num);

void *memcpy(void *destination, const void *source, size_t num);

void *memset(void *ptr, int value, std::size_t num);

int atoi(const char *str);

char *itoa(int value, char *str, int base);


#endif // __USEFULFUNCTIONS_H__

/**********************************************************************************************************************
 *  END OF FILE: UsefulFunctions.h
 *********************************************************************************************************************/
