/*******************************************************************************
* @file
* @brief     Header file Own_Types.h
*
* @par Copyright
* This code is the property of \n
*
* @par Hints
* For history information see the commit comments in the code repository.
*
*******************************************************************************/

#ifndef __OWN_TYPES_H__
#define __OWN_TYPES_H__

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Standart_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define EXAMPLE 0u /* Example DEFINE */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

typedef void (*ExampleNotificationCallbackType)(void); /* Example MACROS */

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**
 * @brief example of typedef create new type exampleReturnType.
 */
typedef sint8 exampleReturnType;

/**
 * @brief example of typedef enum create new type Motor_OnOff_EType.
 */
typedef enum
{
    MOTOR_DISABLE = 0,
    MOTOR_ENABLE = 1,
} Motor_OnOff_EType;

/**
 * @brief Enum of type data stored in union
 */
typedef enum
{
    UNIT_COUNT = 0,
    UNIT_KGS = 1,
    UNIT_LITTERS = 2,
} Unit_Measure_EType;

/**
 * @brief Union example storing data of motor
 */
typedef union
{
    sint32 distanceCM;
    sint16 distanceM;
    sint8 distanceKM;
} Motor_distance_UType;

/**
 * @brief Unione stored quantity
 */
typedef union
{
    uint8 count;
    float32 weight;
    float32 volume;
} Quantity_UType;

/**
 * @brief Structure example storing data of motor
 */
typedef struct
{
    Motor_OnOff_EType onOff;
    sint8 speed;
    exampleReturnType status;
} Motor_OnOff_SType;

typedef struct
{
    boolean firstVisit:1;
    boolean comeAgain:1;
    uint8 fingerLost:4;
    boolean sharkAttack:1;
    uint8 daysWeek:3;
}Survey_SType;

/**
 * @brief Structure of fruit order
 */
typedef struct
{
    const char *name;
    const char *country;
    Quantity_UType amount;
    Unit_Measure_EType units;
} Fruit_Order_SType;

typedef struct
{
    const char *name;
    const char *species;
    sint8 age;
} Turtle_SType;

typedef struct
{
    float32 tankCapacity;
    uint16 tankPsi;
    const char *suitMaterial;
} Equipment_SType;

typedef struct
{
    const char *name;
    Equipment_SType kit;
} Diver_SType;

typedef struct
{
    const char *description;
    float32 duration;
} Exercise_SType;

typedef struct
{
    const char *ingriditenst;
    float32 weight;
} Meal_SType;

typedef struct
{
    Meal_SType food;
    Exercise_SType exercise_hours;
} Preferences_SType;

/**
 * @brief structure fish
 */
typedef struct
{
    const char *name;
    const char *species;
    uint8 age;
    uint8 teeth;
    Preferences_SType care;
} Fish_SType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#endif // __OWN_TYPES_H__

/**********************************************************************************************************************
 *  END OF FILE: Own_Types.h
 *********************************************************************************************************************/
