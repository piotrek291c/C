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
#include <unistd.h>

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

/**
 * @brief Function save data in file
 *
 */
static Std_ReturnType saveDataInFile(int argc, char *argv[])
{
    char tab[80];

    if (argc != 6)
    {
        printf(" Musisz podac 5 argumentow podczas wywolania z wiersza polecen \n");
        printf(" exp:  ./main Jestem jestem.txt tam tam.txt other.txt \n");
        return E_NOT_OK;
    }
    FILE *in = fopen("in.txt", "r");
    if (in == NULL)
    {
        printf("Nie udalo sie otworzyc pliku in.txt \n");
        return E_NOT_OK;
    }
    else
    {
        printf("Plik otwarty pomyslnie!\n");
    }

    FILE *plik1 = fopen(argv[2], "w+");
    FILE *plik2 = fopen(argv[4], "w+");
    FILE *plik3 = fopen(argv[5], "w+");
    if (plik1 == NULL)
    {
        printf("Nie udalo sie otworzyc pliku %s\n", argv[2]);
        // return E_NOT_OK;
    }
    else
    {
        printf("Plik otwarty pomyslnie!\n");
    }
    if (plik2 == NULL)
    {
        printf("Nie udalo sie otworzyc pliku %s\n", argv[4]);
        // return E_NOT_OK;
    }
    else
    {
        printf("Plik otwarty pomyslnie!\n");
    }
    if (plik3 == NULL)
    {
        printf("Nie udalo sie otworzyc pliku plik3.txt\n");
        // return E_NOT_OK;
    }
    else
    {
        printf("Plik otwarty pomyslnie!\n");
    }
    while (fscanf(in, "%79[^\n]\n", tab) == 1)
    {
        if (strstr(tab, argv[1]) != 0)
        {
            fprintf(plik1, "%s\n", tab);
        }
        else if (strstr(tab, argv[3]) != 0)
        {
            fprintf(plik2, "%s\n", tab);
        }
        else
        {
            fprintf(plik3, "%s\n", tab);
        }
    }
    fclose(in);
    fclose(plik1);
    fclose(plik2);
    fclose(plik3);
    return E_OK;
}

/**
 * @brief
 *
 * @param argc
 * @param argv
 * @return Std_ReturnType
 */
static Std_ReturnType orderPizza(int argc, char *argv[])
{
    char *delivery = "";
    sint8 count = 0;
    sint8 thick = 0;
    char ch;

    while ((ch = getopt(argc, argv, "d:t")) != EOF)
    {
        switch (ch)
        {
        case 'd':
            delivery = optarg;
            break;
        case 't':
            thick = TRUE;
            break;
        default:
            fprintf(stderr, "Nieznana opcja %s \n", optarg);
            return E_NOT_OK;
        }
    }
    argc -= optind;
    argv += optind;

    if (thick)
    {
        printf("Grube ciasto \n");
    }

    if (delivery[0])
    {
        printf("dostawa o %s\n", delivery);
    }

    puts("Skladniki:");

    for (count = 0; count < argc; count++)
    {
        puts(argv[count]);
    }

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

Std_ReturnType chapter3_exc1(int argc, char *argv[])
{

    // bermuda();
    // saveDataInFile(argc, argv);
    orderPizza(argc, argv);
    return E_OK;
}
/*!*****************************************************************************
 * STOP - functions
*******************************************************************************/
