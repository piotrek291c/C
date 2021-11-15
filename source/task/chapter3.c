/*!*********************************************************************************
* @file
* @brief     Chapter 2 from book
*
* @par Copyright
* This code is the property of \n
*
* @par Hints
* For history information see the commit comments in the code repository.
*
**********************************************************************************/

/*!*****************************************************************************
 * Includes
*******************************************************************************/
#include "chapter2.h"
#include <string.h>

/*!*****************************************************************************
 * Private variables
*******************************************************************************/

/*!*****************************************************************************
 * START - Static functions
*******************************************************************************/

/**
 * @brief 
 * 
 */
static void bermuda(void)
{
    float32 lat;
    float32 longi;
    char tab[80];
    while (scanf("%f,%f,%79[^\n]", &lat, &longi, tab) == 3)
    {
        if ((lat >= 26) && (lat <= 34) &&
            (longi <= -64) && (longi >= -76))
        {
            printf("%f,%f,%s\n", lat, longi, tab);
        }
    }
}

/**
 * @brief
 * 
 * @return Std_ReturnType
 */
static Std_ReturnType gps(void)
{
    float32 lat;
    float32 longi;
    char tab[80];

    boolean start = FALSE;
    while (scanf("%f,%f,%79[^\n]", &lat, &longi, tab) == 3)
    {
        if (start == FALSE)
        {
            printf("data=[\n");
            start = TRUE;
        }
        if ((lat > 90.0) || (lat < -90.0))
        {
            fprintf(stderr, "Bledna szerokosc geograficzna %f", lat);
            return E_NOT_OK;
        }
        if ((longi > 180.0) || (longi < -180.0))
        {
            fprintf(stderr, "Bledna dlugosc geograficzna %f", longi);
            return E_NOT_OK;
        }
        printf("{latitude: %f, longtitude: %f, info: '%s'},\n", lat, longi, tab);
    }
    printf("]\n");
    return E_OK;
}
/*******************************************************************************
 * START - functions
*******************************************************************************/

/**
 * @brief function from chapter 3
 * 
 * ./source/build/main.exe < ./source/build/gps.csv > ./source/build/output.json 2> ./source/build/error.txt
 *  wywolanie w bash 
 *  <  przekierowanie standardowego strumienia wejsciowego jako pliku .sv
 *  > przekeierowanie satandardowego strumienia wyjsciowgo do pliku .json 
 *  2> przekierowanie bledow ze standardowgo strumienia do pliku error.txt
 * @return Std_ReturnType
 */

Std_ReturnType chapter3_exc1(void)
{

    bermuda();
    return E_OK;
}
/*!*****************************************************************************
 * STOP - functions
*******************************************************************************/
