/*!*********************************************************************************
* @file
* @brief     Source file chapter5.c Chapter 5 from book
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
#include "chapter5.h"
#include <limits.h>
#include <float.h>

/*!*****************************************************************************
 * PRIVATE VARIABLES
*******************************************************************************/

/*!*****************************************************************************
 * START - STATIC FUNCTIONS
*******************************************************************************/

/**
 * @brief Function fish
 *
 * @param fish - structure
 */
static void catalog(Fish_SType fish)
{
    printf("%s to %s majaca %d zebow. Ten okaza ma %d lata \n",
           fish.name, fish.species, fish.teeth, fish.age);
}

static void label(Fish_SType fish)
{
    printf("Imie: %s \n", fish.name);
    printf("Gatunek: %s\n", fish.species);
    printf("Wiek: %d lata\n", fish.age);
    printf("Liczba zebow: %d\n", fish.teeth);
    printf("Karmic, podajac %s (porcja o wadze %2.2f), a nastepnie cwiczyc: %s, przez %2.2f godziny\n",
           fish.care.food.ingriditenst, fish.care.food.weight,
           fish.care.exercise_hours.description, fish.care.exercise_hours.duration);
}

static void badge(Diver_SType diver)
{
    printf("Imie %s, Zbiornik %2.2f, (%d), Kombinezon %s\n ",
           diver.name, diver.kit.tankCapacity, diver.kit.tankPsi, diver.kit.suitMaterial);
}

static void happyBirthday(Turtle_SType *t)
{
    t->age = t->age + 1;
    printf("Najlepszego, %s, teraz masz %d lat. \n", t->name, t->age);
}
/*******************************************************************************
 * START - FUNCTIONS
*******************************************************************************/

/**
 * @brief function from chapter 5
 *
 * @return Std_ReturnType
 */
Std_ReturnType chapter5_exc1(int argc, char *argv[])
{

    Fish_SType snappy = {
        "Brzytewka",
        "Pirania",
        4,
        69,
        {
            {
                "mieso",
                0.2,
            },
            {
                "plywanie w jacuzzi",
                2.5,
            },
        },
    };
    Fish_SType grappy;
    grappy = snappy;
    catalog(snappy);
    label(snappy);

    Diver_SType randy =
        {
            "Rafal",
            {
                5.5,
                3500,
                "neopren",
            },
        };
    badge(randy);

    Turtle_SType myrtle =
        {
            "Marceli",
            "zolw",
            99,
        };
    happyBirthday(&myrtle);
    printf(" %s, teraz masz %d lat. \n", myrtle.name, myrtle.age);
    return E_OK;
}
/*!*****************************************************************************
 * STOP - FUNCTIONS
*******************************************************************************/
