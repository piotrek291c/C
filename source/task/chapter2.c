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
 * @brief Function go south
 *
 * @param lat   - latitude
 * @param longi - longitude
 */
static void go_south_est(sint32 *lat, sint32 *longi)
{
    *lat = *lat - 1;
    *longi = *longi + 1;
}

/**
 * @brief printf all size defined in Standart_types.h
 *
 */
static void type_size_defined(void)
{
    printf("Size of sint8: %d\n", sizeof(sint8));
    printf("Size of sint16: %d\n", sizeof(sint16));
    printf("Size of sint32: %d\n", sizeof(sint32));
    printf("Size of sint64: %d\n", sizeof(sint64));
    printf("Size of uint8: %d\n", sizeof(uint8));
    printf("Size of uint16: %d\n", sizeof(uint16));
    printf("Size of uint32: %d\n", sizeof(uint32));
    printf("Size of uint64: %d\n", sizeof(uint64));
    printf("Size of float32: %d\n", sizeof(float32));
    printf("Size of float64: %d\n", sizeof(float64));

    /* Size of cyclic Motion Sensor buffer */
    sint16 bufferSizeArray = 10;
    sint16 bufferArray[bufferSizeArray];
    uint16 bufferSize = sizeof(bufferArray) / sizeof(bufferArray[0]);
    printf("Size of bufferSizeArray: %d\n", sizeof(bufferSizeArray));
    printf("Size of bufferArray: %d\n", sizeof(bufferArray));
    printf("Size of bufferArray[0]: %d\n", sizeof(bufferArray[0]));
    printf("Size of bufferSize: %d\n", bufferSize);

    sint8 tekst[] = "123456789";
    sint8 *pt = tekst;
    printf("Size of tekst: %d\n", sizeof(tekst));
    printf("Size of tekst[0]: %d\n", sizeof(tekst[0]));
    printf("Size of pt: %d\n", sizeof(pt));
    printf("Size of *pt: %d\n", sizeof(*pt));
    // rozmiar tablicy powinien być przekazany w postaci osobnej zmiennej do funkcji
}

/**
 * @brief Function find text song
 *
 * @param tab - tab wit all song
 * @param find - text to find
 */
static void find_text(const char tab[][80], const char find[])
{

    for (sint8 i = 0; i < 5; i++)
    {
        if (strstr(tab[i], find))
        {
            printf("Poszukiwany tekst %s zostal znaleziony w %i, tytul %s \n", find, i, tab[i]);
        }
        else
        {
            // printf("Poszukiwany tekst %s nie zostal znaleziony \n", find);
        }
    }
}

/**
 * @brief Function find song
 *
 */
static void findSong(void)
{
    char listSong[][80] = {"Czlowiek bez liscia",
                           "Utracilas",
                           "Hiena boggie",
                           "Co powie Siara",
                           "Ja mam nieszczescie"};

    while (1)
    {
        char tabSong[80];
        printf("Podaj tytul utworu: ");
        scanf("%s", tabSong);
        find_text(listSong, tabSong);
    }
}

/**
 * @brief Function to reverse text
 * 
 * @param text - text to revert
 * @return char 
 */
static void reverseText(char text[])
{
    sint8 j = 0;
    sint8 i = 0;
    char temp[strlen(text)];
    for (i = strlen(text) - 1; i >= 0; i--, j++)
    {
        temp[j] = text[i];
    }
    for (i = 0; i < strlen(text); i++)
    {
        text[i] = temp[i];
    }
}

/**
 * @brief reverse text
 *
 * @param s - pointer to text
 */
static void revers(char *s)
{
    sint8 len = strlen(s);
    sint8 i = len;
    while (i >= 0)
    {
        printf("%c", s[i]);
        i--;
    }
    printf("\n");
}
/*******************************************************************************
 * START - functions
*******************************************************************************/

/**
 * @brief  Function to swim ship.
 * @param  void - void
 * @return Std_ReturnType - standart type to inform status function
 */
Std_ReturnType chapter2_exc1(void)
{
    sint32 latitude = 32;
    sint32 longitude = -64;
    type_size_defined();

    go_south_est(&latitude, &longitude);
    printf("Stop! Aktualne  polozenie: [%ld, %ld], \n", latitude, longitude);

    // findSong();
    char tab[] = "alamakota";
    reverseText(tab);
    printf("odwrocony tekst: %s ", tab);
    revers(tab);
    findSong();
    return E_OK;
}

/*!*****************************************************************************
 * STOP - functions
*******************************************************************************/
