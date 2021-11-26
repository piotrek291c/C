/*******************************************************************************
* @file
* @brief      Header file chapter7.h Chapter 7 from book
*
* @par Copyright
* This code is the property of \n
*
* @par Hints
* For history information see the commit comments in the code repository.
*
*******************************************************************************/

#ifndef __CHAPTER7_H__
#define __CHAPTER7_H__

/*******************************************************************************
 * INCLUDES SECTION
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "Standart_Types.h"
#include "Own_Types.h"

/*******************************************************************************
 * GLOBAL CONSTANT MACROS SECTION
*******************************************************************************/

/* example Error code */
#define EXAMPLE_ERR_OK 0
#define EXAMPLE_ERR_BUSY -1

/*******************************************************************************
 * FUNCTION DECLARATION SECTION
*******************************************************************************/
Std_ReturnType chapter7_exc1(int argc, char *argv[]);

#endif // __CHAPTER7_H__

/**********************************************************************************************************************
 *  END OF FILE: chapter7.h
 *********************************************************************************************************************/
