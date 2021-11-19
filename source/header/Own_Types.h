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
