/*!*********************************************************************************
* @file
* @brief     Source file chapter7.c Chapter 7 from book
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
#include "chapter7.h"
#include <limits.h>
#include <float.h>
#include <string.h>

/*!*****************************************************************************
 * PRIVATE VARIABLES SECTION
*******************************************************************************/
int NUM_ADS = 7;
char *ADS[] = {
    "Wilhelm: SBM GSOH lubi sport, TV, dobre jedzenie",
    "Maciek: SWM NP lubi sztuke, filmy, teatr",
    "Mateusz: SLM ND lubi ksiazki, sztuke, teatr",
    "Michal: DWM DS lubi ciezarowki, sport i Bibera",
    "Piotrek: SAM lubi szachy, trenowanie i sztuke",
    "Jozek: SJM lubi sport, filmy i teatr",
    "Jurek: DBM lubi teatr, ksiazki i dobre jedzenie",
};

sint16 scores[] = {6, 4, 2, 8, 9, 5, 9, 0, 3, 1, 5, 7, 0};

Rectangle_SType rectangle[] = {{2, 2}, {3, 3}, {9, 9}, {5, 5}, {7, 7}, {4, 4}};
/*!*****************************************************************************
 * START - STATIC FUNCTIONS SECTION
*******************************************************************************/

static boolean sportNoBieber(char *s)
{
    return ((strstr(s, "sport")) && (!strstr(s, "Bibera")));
}

static boolean sportOrWorkaut(char *s)
{
    return ((strstr(s, "sport")) || (strstr(s, "trenowanie")));
}

static boolean ns_theater(char *s)
{
    return ((strstr(s, "NP")) && (strstr(s, "teatr")));
}

static boolean arts_theater_or_dining(char *s)
{
    return ((strstr(s, "sztuke")) || (strstr(s, "teatr")) || (strstr(s, "dobre jedzenie")));
}

static Std_ReturnType find(Match_text_FptrType match)
{

    uint8 i;
    puts("Wyniki wyszukiawania:");
    puts("--------------------------------");
    for (i = 0; i < NUM_ADS; i++)
    {
        if (match(ADS[i]))
        {
            printf("%s\n", ADS[i]);
        }
    }

    puts("--------------------------------");
    return E_OK;
}

static int compareScores(const void *a, const void *b)
{
    sint16 nr1 = *(sint16 *)a;
    sint16 nr2 = *(sint16 *)b;

    return nr1 - nr2;
}

static int compareScoresDesc(const void *a, const void *b)
{
    sint16 nr1 = *(sint16 *)a;
    sint16 nr2 = *(sint16 *)b;

    return nr2 - nr1;
}

static int compareRectangle(const void *a, const void *b)
{
    Rectangle_SType *nr1 = (Rectangle_SType *)a;
    Rectangle_SType *nr2 = (Rectangle_SType *)b;

    return (nr1->height * nr1->height) - (nr2->height * nr2->width);
}
/*******************************************************************************
 * START - FUNCTIONS SECTION
*******************************************************************************/

/**
 * @brief function from chapter 7
 *
 * @return Std_ReturnType
 */
Std_ReturnType chapter7_exc1(int argc, char *argv[])
{

    find(sportNoBieber);
    find(sportOrWorkaut);
    find(ns_theater);
    find(arts_theater_or_dining);

    qsort(scores, sizeof(scores) / sizeof(scores[0]), sizeof(sint16), compareScores);

    for (uint8 i = 0; i < sizeof(scores) / sizeof(scores[0]); i++)
    {
        printf("%d, ", scores[i]);
    }
    printf("\n");

    qsort(scores, sizeof(scores) / sizeof(scores[0]), sizeof(sint16), compareScoresDesc);

    for (uint8 i = 0; i < sizeof(scores) / sizeof(scores[0]); i++)
    {
        printf("%d, ", scores[i]);
    }

    printf("\n");

    qsort(rectangle, sizeof(rectangle) / sizeof(rectangle[0]), sizeof(Rectangle_SType), compareRectangle);

    for (uint8 i = 0; i < sizeof(rectangle) / sizeof(rectangle[0]); i++)
    {
        printf("%d,%d  ", rectangle[i].height, rectangle[i].width);
    }

    return E_OK;
}
/*!*****************************************************************************
 * STOP - FUNCTIONS SECTION
*******************************************************************************/
