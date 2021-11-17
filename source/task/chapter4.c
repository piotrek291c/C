/*!*********************************************************************************
* @file
* @brief     Chapter 4 from book
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
#include "chapter4.h"
#include <limits.h>
#include <float.h>
/*!*****************************************************************************
 * Private variables
*******************************************************************************/
float32 total = 0.0;
sint8 count = 0;
sint8 taxPercent = 8;
/*!*****************************************************************************
 * START - Static functions
*******************************************************************************/

/**
 * @brief 
 * 
 * @param f 
 * @return float32 
 */
static float32 addWithTax(float32 f)
{
    float32 taxRate = 1 + taxPercent / 100.0;
    total = total + (f * taxRate);
    count = count + 1;
    return total;
}

/**
 * @brief 
 * 
 */
static void funTax(void)
{
    float32 val;
    printf("Cena dania: ");
    while (scanf("%f", &val) == 1)
    {
        printf("Dotychczasowa suma zamowien: %.2f \n ", addWithTax(val));
        printf(" Cena dania: ");
    }
    printf("\n Sumaryczna wartosc zamowienia %.2f \n", total);
    printf("\n Liczba zamowieonych dan: %d", count);
}
/*******************************************************************************
 * START - functions
*******************************************************************************/

/**
 * @brief function from chapter 4
 *
 * @return Std_ReturnType
 */

Std_ReturnType chapter4_exc1(int argc, char *argv[])
{

    // printf(" Int max wynosi %d \n", INT_MAX);
    // printf(" Int min wynosi %d \n", INT_MIN);
    // printf(" Dane typu int zajmują %0x bajtow \n", sizeof(int));

    // printf(" Float max wynosi %f \n", FLT_MAX);
    // printf(" Float min wynosi %.50f \n", FLT_MIN);
    // printf(" Dane typu float zajmują %0x bajtow \n", sizeof(float));

    funTax();
    return E_OK;
}
/*!*****************************************************************************
 * STOP - functions
*******************************************************************************/
