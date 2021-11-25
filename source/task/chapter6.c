/*!*********************************************************************************
* @file
* @brief     Source file chapter6.c Chapter 6 from book
*
* @par Copyright
* This code is the property of \n
*
* @par Hints
* For history information see the commit comments in the code repository.
*
**********************************************************************************/

/*******************************************************************************
 * INCLUDES
*******************************************************************************/
#include "chapter6.h"
#include <limits.h>
#include <float.h>
#include <string.h>

/*!*****************************************************************************
 * PRIVATE VARIABLES
*******************************************************************************/
Island_SType amity = {"Wyspa przyjazni", "9:00", "17:00", NULL};
Island_SType craggy = {"Wyspa Skalista", "9:00", "17:00", NULL};
Island_SType islaNublar = {"Wyspa chmur", "9:00", "17:00", NULL};
Island_SType shutter = {"Wyspa zjaw", "9:00", "17:00", NULL};
Island_SType skull = {"Wyspa czasek", "9:00", "17:00", NULL};

/*!*****************************************************************************
 * START - STATIC FUNCTIONS
*******************************************************************************/

static void display(Island_SType *start)
{
    Island_SType *i = start;
    for (; i != NULL; i = i->next)
    {
        printf("Lotnisko %s otwarte w godzinach %s - %s \n", i->name, i->opens, i->closes);
    }
}

static Island_SType *creat(char *name)
{
    Island_SType *p = malloc(sizeof(Island_SType));
    p->name = strdup(name);
    p->opens = "9:00";
    p->closes = "17:00";
    p->next = NULL;
    return p;
}

static void releas(Island_SType *start)
{
    Island_SType *i = start;
    Island_SType *next = NULL;
    for (; i != NULL; i = next)
    {
        next = i->next;
        free(i->name);
        free(i);
    }
}

/*******************************************************************************
 * START - FUNCTIONS
*******************************************************************************/

/**
 * @brief function from chapter 5
 *
 * @return Std_ReturnType
 */
Std_ReturnType chapter6_exc1(int argc, char *argv[])
{

    // amity.next = &craggy;
    // craggy.next = &islaNublar;
    // islaNublar.next = &skull;
    // skull.next = &shutter;
    // display(&amity);

    // char name[80];
    // fgets(name, 80, stdin);
    // Island_SType *island0 = creat(name);

    // fgets(name, 80, stdin);
    // Island_SType *island1 = creat(name);

    // island0->next = island1;
    // display(island0);

    // free(island0->name);
    // free(island1->name);
    // free(island0);
    // free(island1);

    Island_SType *start = NULL;
    Island_SType *i = NULL;
    Island_SType *next = NULL;
    char name[80];

    for (; fgets(name, 80, stdin) != NULL; i = next)
    {
        next = creat(name);
        if (start == NULL)
        {
            start = next;
        }
        if (i != NULL)
        {
            i->next = next;
        }
    }
    display(start);
    releas(start);
    return E_OK;
}
/*!*****************************************************************************
 * STOP - FUNCTIONS
*******************************************************************************/
