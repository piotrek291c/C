/*!*********************************************************************************
* @file
* @brief     Source file chapter8.c Chapter 8 from book
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
#include "chapter8.h"
#include <limits.h>
#include <float.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>

/*!*****************************************************************************
 * PRIVATE VARIABLES SECTION
*******************************************************************************/

/*!*****************************************************************************
 * START - STATIC FUNCTIONS SECTION
*******************************************************************************/
static char *now()
{
    time_t t;
    time(&t);
    return asctime(localtime(&t));
}

/*******************************************************************************
 * START - FUNCTIONS SECTION
*******************************************************************************/

/**
 * @brief function from chapter 8
 *
 * @return Std_ReturnType
 */
Std_ReturnType chapter8_exc1(int argc, char *argv[])
{

    char comment[80];
    char cmd[240];
    char time[40];

    fgets(comment, 80, stdin);
    comment[strcspn(comment, "\n")] = 0;

    strcpy(time, now());
    time[strlen(time) - 1] = ' ';

    sprintf(cmd, "echo '%s %s' >> reports.log", comment, time);

    system(cmd);

    if (execl("/sbin/ifconfig", "/sbin/ifconfig", NULL) == -1)
    {
        if (execlp("ipconfig", "ipconfig", NULL) == -1)
        {
            fprintf(stderr, "Nie moge uruchomic programu ipconfig: %s\n", strerror(errno));
            return E_NOT_OK;
        }
    }

    return E_OK;
}
/*!*****************************************************************************
 * STOP - FUNCTIONS SECTION
*******************************************************************************/
