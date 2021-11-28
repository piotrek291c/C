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
#include <stdarg.h>

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

char *listName[] = {
    "Piotr",
    "Pawel",
    "Adam",
    "Robert",
    "Wojtek",
    "Olaf"};
/*!*****************************************************************************
 * START - STATIC FUNCTIONS SECTION
*******************************************************************************/

static boolean
sportNoBieber(char *s)
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

static int compareNames(const void *a, const void *b)
{
    char **nr1 = (char **)a;
    char **nr2 = (char **)b;

    return strcmp(*nr1, *nr2);
}

static int compareRectangleDesc(const void *a, const void *b)
{
    Rectangle_SType *nr1 = (Rectangle_SType *)a;
    Rectangle_SType *nr2 = (Rectangle_SType *)b;

    return (nr2->height * nr2->height) - (nr1->height * nr1->width);
}

static int compareNamesDesc(const void *a, const void *b)
{
    char **nr1 = (char **)a;
    char **nr2 = (char **)b;

    return strcmp(*nr2, *nr1);
}

static void dump(Response_SType response)
{
    printf("Drogi %s \n", response.name);
    printf("Niestety zostales odrzucony \n");
}

static void secondChance(Response_SType response)
{
    printf("Drogi %s \n", response.name);
    printf("Druga szansa \n");
}

static void marriage(Response_SType response)
{
    printf("Drogi %s \n", response.name);
    printf("Gratulujemy propozycji malzenstwa \n");
}

static float32 price(Drink_EType price)
{
    switch (price)
    {
    case MUDSLIDE:
        return 6.79;
        break;
    case FUZZY_NAVEL:
        return 5.31;
        break;
    case MONKEY_GLAND:
        return 4.82;
        break;
    case ZOMBIE:
        return 5.89;
        break;
    default:
        return 0.0;
        break;
    }
}

static void print_sint16(sint16 args, ...)
{
    va_list ap;
    va_start(ap, args);

    sint16 i;

    for (i = 0; i < args; i++)
    {
        printf("argument: %d \n", va_arg(ap, int));
    }

    va_end(ap);
}

static float32 total(int args, ...)
{
    float32 total = 0;

    va_list ap;
    va_start(ap, args);

    for (uint8 i = 0; i < args; i++)
    {
        total += price(va_arg(ap, Drink_EType));
    }

    va_end(ap);
    return total;
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

    printf("\n");

    qsort(listName, sizeof(listName) / sizeof(listName[0]), sizeof(char *), compareNames);

    for (uint8 i = 0; i < sizeof(listName) / sizeof(listName[0]); i++)
    {
        printf("%s  \n", listName[i]);
    }
    printf("\n");

    qsort(rectangle, sizeof(rectangle) / sizeof(rectangle[0]), sizeof(Rectangle_SType), compareRectangleDesc);

    for (uint8 i = 0; i < sizeof(rectangle) / sizeof(rectangle[0]); i++)
    {
        printf("%d,%d  ", rectangle[i].height, rectangle[i].width);
    }

    printf("\n");

    qsort(listName, sizeof(listName) / sizeof(listName[0]), sizeof(char *), compareNamesDesc);

    for (uint8 i = 0; i < sizeof(listName) / sizeof(listName[0]); i++)
    {
        printf("%s  \n", listName[i]);
    }

    // ---------------------------------------------------------------------------------------------
    Response_SType r[] =
        {
            {"Michale", DUMP},
            {"Lukaszu", SECOND_CHANCE},
            {"Macieju", SECOND_CHANCE},
            {"Wilhelmie", MARRIAGE},
        };

    uint8 i;
    for (i = 0; i < 4; i++)
    {
        switch (r[i].type)
        {
        case DUMP:
            dump(r[i]);
            break;
        case SECOND_CHANCE:
            secondChance(r[i]);
            break;
        default:
            marriage(r[i]);
            break;
        }
    }

    printf("\n\n");

    Replies_FPtrType replies = {dump, secondChance, marriage};
    for (i = 0; i < 4; i++)
    {
        replies[r[i].type](r[i]);
    }

    print_sint16(3, 67, 98, 128);

    printf("Cena wynosi: %.2f zl \n", total(3, MONKEY_GLAND, MUDSLIDE, FUZZY_NAVEL));

    return E_OK;
}
/*!*****************************************************************************
 * STOP - FUNCTIONS SECTION
*******************************************************************************/
