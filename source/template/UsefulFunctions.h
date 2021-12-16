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
