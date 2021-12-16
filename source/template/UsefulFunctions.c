/*!*********************************************************************************
* @file
* @brief     Source file UsefulFunctions.c
*
* @par Copyright
* This code is the property of \n
*
* @par Hints
* For history information see the commit comments in the code repository.
*
**********************************************************************************/

/*******************************************************************************
 * INCLUDES SECTION
*******************************************************************************/
#include "UsefulFunctions.h"

/*!*****************************************************************************
 * PRIVATE VARIABLES SECTION
*******************************************************************************/

/*!*****************************************************************************
 * START - STATIC FUNCTIONS SECTION
*******************************************************************************/

/*******************************************************************************
 * START - FUNCTIONS SECTION
*******************************************************************************/

/**
 * @brief function template
 *
 * @return Std_ReturnType
 */
Std_ReturnType template(void)
{

    return E_OK;
}

/**
 * @brief Reads data from stdin and stores them according to the parameter format into the locations pointed
 * by the additional arguments.
 */
int scanf("%d,%f,%79s[^\n]", &lat, &longi, tab);

/**
 * @brief Compares the C string str1 to the C string str2.
 *
 * @param str1 C string to be compared.
 * @param str2 C string to be compared.
 * @return int  The function returns the zero value when S1 is the same as S2, less than zero when
 * S1 <S2 and greater than zero when S1> S2.
 */
int strcmp(const char *str1, const char *str2);

/**
 * @brief Returns a pointer to the first occurrence of str2 in str1, or a null pointer if str2 is not part of str1.
 * @param str1 C string to be scanned.
 * @param str2 C string containing the sequence of characters to match.
 * @return char* A pointer to the first occurrence in str1 of the entire sequence of characters specified in str2, or a null pointer if the sequence is not present in str1.
 */
char *strstr(const char *str1, const char *str2);

/**
 * @brief Returns a pointer to the first occurrence of character in the C string str.
 *
 * @param str C string.
 * @param character Character to be located. It is passed as its int promotion, but it is internally converted back to char for the comparison.
 * @return char* A pointer to the first occurrence of character in str.
 * If the character is not found, the function returns a null pointer.
 */
char *strchr(char *str, int character);

/**
 * @brief The function adds to the Destination chain SOURCE. Sign \ 0 from the end of the Destination chain is
 * overwritten by the first SOURCE chain sign. The source chain is added to the target chain, including the '\ 0' mark.
 *
 * @param destination - Chain of the characters to which the source chain is added
 * @param source - Posted character chain
 * @return char* - Returns the address passed through the Destination argument.
 */
char *strcat(char *destination, const char *source);

/**
 * @brief The function copies characters (SRC) to the characters (DEST). The function does not check whether the copied chain will fit in the target table.
 *
 * @param dest Indicator to the target characters
 * @param src Indicator for the source signboard
 * @return char* Returns the indicator passed through the Dest argument.
 */
char *strcpy(char *dest, const char *src);

/**
 * @brief The function calculates the length of the character chain in the style. The end of the character chain in style C is determined by the terminal sign '\ 0'. Chain in style C has so many characters how much they are between the beginning of the string, and the '\ 0' mark.
 *
 * @param str Culture string in style C
 * @return size_t The length of the character chain transferred as an argument.
 */
size_t strlen(const char *str);

/**
 * @brief Parse options from a command line
 *
 * @param argc The argument count that was passed to main().
 * @param argv The argument array that was passed to main().
 * @param optstring A string of recognized option letters; if a letter is followed by a colon, the option takes an argument. Valid option characters for optstring consist of a single alphanumeric character (i.e. a letter or digit).
 * @return int  The getopt() function returns the next option character from argv that matches a letter in optstring, if there's one that matches. If the option takes an argument, getopt() sets the global variable optarg to point to the option argument as follows:
If the option is the last letter in the string pointed to by an element of argv, then optarg contains the next element of argv, and optind is incremented by 2.
Otherwise, optarg points to the string following the option letter in that element of argv, and optind is incremented by 1.
The getopt() function returns -1 is returned and doesn't change optind if:
argv[optind] is NULL
*argv[optind] isn't the character '-'
argv[optind] points to the string "-".
 */
int getopt(int argc, char *const argv[], const char *optstring);

/**
 * @brief Returns a character chain containing the value of the environment variable named given as the Varname argument.
The chain returned by the functions should not be modified by the application.
The same memory area can be used at the next call to call the GENTV () function overwriting the previous result.
Depending on the platform, this function can pay attention to the size of the letters.

 * @param varname A chain containing the name of the desired variable.
 * @return char* The function returns a chain ended with zero containing the value of the desired variable. In case of failure, the function returns NULL.
 */
char *getenv(const char *varname);

/**
 * @brief The Malloc function is allocated to a size block size. The content of this block is not initialized.
 *
 * @param size The size of the block allocated
 * @return void* Indicator for a swept block of memory or NULL in the event of an error.
 */
void *malloc(size_t size);

/**
 * @brief The FREE FUNCTION releases memory covered by the functions previous functions malloc thanks to which this memory is available for future calls of these functions.
 *
 * @param ptr Memory indicator for release. If NULL is equal, nothing happens. If the indicator has not been returned by an earlier call
 */
void free(void *ptr);

/**
 * @brief The function creates a number of characters passed through the function argument. The source string must be terminated with the terminal. The characters created will be terminated with the terminal sign. Memory on a new character string is allocated using the function
 *
 * @param sTekst A string of characters to be copied. Chain must be terminated with the terminal.
 * @return char* Returns a created copy of the character chain transferred through the function argument in case of success. The function returns the NULL value in case of failure.
 */
char *strdup(const char *sTekst);

/**
 * @brief The function performs a quick sorting algorithm (Quicksort) on a blackboard transferred as an BASE argumet. The number of elements in the table specifies the NUM argument, while the number of bytes occupied by one element of the array is given as the Width argument.
 *
 * @param base The indicator on the board to be sorted.
 * @param num Number of elements in the table.
 * @param width Number of bytes occupied by one element of the array.
 * @param compare Function comparing the array elements. The indicators for elements currently compared are to the arguments of the function.
 */
void qsort(
    void *base,
    size_t num,
    size_t width,
    int (*compare)(const void *, const void *));

/**
 * @brief The function calls the system command passed as an argument. The operation of the program is stopped until the command is executed. After completing the command, the operating system will control the program, returning an integer that indicates whether the command is successful.
 *
 * @param command The system command to be performed.
 * @return int When Command is different from NULL, the function returns a value that depends on the value that will be returned by the command interpreter. The function returns the value 0 only when the command interpreter also drew a value of 0. Otherwise, the function returns the value -1 that indicates the occurrence of an error and sets ERRNO to one of the following values.
 */
int system(const char *command);

/**
 * @brief Checks whether the sign passed as an argument is a letter of alphabet.
 *
 * @param ch ASCII sign code
 * @return int The ISALPHA function returns a value different from zero when the argument that has been forwarded to the function is a letter of alphabet. Otherwise, the function returns the zero value.
 */
int isalpha(int ch);

/**
 * @brief Funkcja isdigit zwraca wartość różną od zera gdy argument, który został przekazany do funkcji jest cyfrą. W przeciwnym wypadku funkcja zwraca wartość zero.

 *
 * @param ch ASCII sign code
 * @return int
 */
int isdigit(int ch);

/**
 * @brief It is looking for the first occurrence of Value (Interpreted as Unsigned Char) in the first non-bytes of the block indicated by PTR.
 * 
 * @param ptr Indicator for searched memories
 * @param value A search byte (argument interpreted as Unsigned Char)
 * @param num Number of bytes to search
 * @return void* Indicator for the first toe byte equal to Value if found; Otherwise. Empty indicator.
 */
void *memchr(void *ptr, int value, size_t num);

/**
 * @brief Compares the first num bytes of the block indicated by PTR1 and the first Num bytes of the block indicated by PTR2.
 * 
 * @param ptr1 Indicator for the first compared block
 * @param ptr2 Indicator for the second compared block
 * @param num Number of bytes to comparison
 * @return int Zero, if the contents of memory blocks are the same; Positive value if the first byte not the same in both blocks was larger in PTR1; Negative value otherwise.
 */
int memcmp(const void *ptr1, const void *ptr2, size_t num);

/**
 * @brief Copies num-bytes from a place indicated by Source to memory indicated by Destination. Memory blocks can not take place. 
 * @param destination Memory indicator for copying.
 * @param source Memory indicator from which copying will occur.
 * @param num Number of bytes for copying.
 * @return void* Returns the pointer forwarded to the functions through the Destination argument.
 */
void *memcpy(void *destination, const void *source, size_t num);

/**
 * @brief Sets the first num bytes of the block indicated by PTR on Value (treated as Unsigned Char).
 * 
 * @param ptr Indicator on the memory block to fill
 * @param value The value that will be filled with the block (treated as Unsigned Char)
 * @param num Number of bytes to fill
 * @return void* ptr is returned.
 */
void *memset(void *ptr, int value, size_t num);

/**
 * @brief The function converts the value saved in the character chain to the integer of the integer type INT.
 * 
 * @param str A string to be converted to the numerical form.
 * @return int The function returns the value from the character chain converted to the numeric form (type INT) in the event of success.
The function returns the zero value if it is not possible to convert a character chain transferred as a function argument.
 */
int atoi(const char *str);

/**
 * @brief The function converts an integer to the string. The number will be saved in the character string in the form specified by the Base of the numeric system.
 *
 * @param value The integer to be converted.
 * @param str The place where the conversion result is to be saved.
 * @param base The base of the numeric system in which the result will be saved. The value of this argument must be between 2 and 36.
 * @return char* The function returns the indicator passed to it as an argument p.
 */
char *itoa(int value, char *str, int base);

/*!*****************************************************************************
 * STOP - FUNCTIONS SECTION
*******************************************************************************/
