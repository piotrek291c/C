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

/*!
 * @brief  Function to count card.
 * @param  void - void
 * @return Std_ReturnType - standart type to inform status function
 */
Std_ReturnType chapter1_exc1(void)
{
    char card_name[3];
    int val = 0;
    puts("Wpisz symbol karty:");
    scanf("%2s", card_name);

    if(card_name[0] == 'K')
    {
        val = 10;
    }
    else if (card_name[0] == 'Q')
    {
        val = 10;
    }
    else if (card_name[0] == 'J')
    {
        val = 10;
    }else if (card_name[0] == 'A')
    {
        val = 11;
    }
    else
    {
        val = atoi(card_name);
    }

    printf("Wartosc karty to: %i\n", val);
    return E_OK;
}

/*!*****************************************************************************
 * STOP - functions 
*******************************************************************************/
