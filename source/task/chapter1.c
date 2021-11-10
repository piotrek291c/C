/*!*********************************************************************************
* @file
* @brief     Chapter 1 from book
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
#include "chapter1.h"

/*!*****************************************************************************
 * Private variables
*******************************************************************************/

/*!*****************************************************************************
 * START - functions
*******************************************************************************/

/**
 * @brief  Function to count card.
 * @param  void - void
 * @return Std_ReturnType - standart type to inform status function
 */
Std_ReturnType chapter1_exc1(void)
{
    char card_name[3];
    sint32 val = 0;
    sint32 count = 0;
    puts("Wpisz symbol karty:");
    scanf("%2s", card_name);

    switch (card_name[0])
    {
    case 'K':
    case 'Q':
    case 'J':
        val = 10;
        break;
    case 'A':
        val = 11;
        break;
    default:
        val = atoi(card_name);
    }

    if ((val >= 3) && (val <= 6))
    {
        count++;
        printf("Dodano jeden do wartosci licznika: %ld\n", count);
    }
    else if (val == 10)
    {
        count--;
        printf("Odjeto jeden od wartosci licznika: %ld\n", count);
    }

    printf("Wartosc karty to: %ld\n", val);
    return E_OK;
}

/*!*****************************************************************************
 * STOP - functions
*******************************************************************************/
