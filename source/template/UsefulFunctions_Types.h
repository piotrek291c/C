/*******************************************************************************
* @file
* @brief     Header file UsefulFunctions_Types.h
*
* @par Copyright
* This code is the property of \n
*
* @par Hints
* For history information see the commit comments in the code repository.
*
*******************************************************************************/

#ifndef __USEFULFUNCTIONS_TYPES_H__
#define __USEFULFUNCTIONS_TYPES_H__

/**********************************************************************************************************************
 * INCLUDES SECTION
 *********************************************************************************************************************/
#include "templateStandart_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS SECTION
 *********************************************************************************************************************/

#define EXAMPLE 0u /* Example DEFINE */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS SECTION
 *********************************************************************************************************************/

typedef void (*ExampleNotificationCallbackType)(void); /* Example MACROS */

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES SECTION
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
 * @brief Union example storing data of motor
 */
typedef union
{
    sint32 distanceCM;
    sint16 distanceM;
    sint8 distanceKM;
} Motor_distance_UType;

/**
 * @brief Structure example storing data of motor
 */
typedef struct
{
    Motor_OnOff_EType onOff;
    sint8 speed;
    exampleReturnType status;
} Motor_OnOff_SType;

/**
 * @brief Bit field
 */
typedef struct
{
    boolean firstVisit : 1;
    boolean comeAgain : 1;
    uint8 fingerLost : 4;
    boolean sharkAttack : 1;
    uint8 daysWeek : 3;
} Survey_SType;

typedef struct Island_SType
{
    char *name;
    char *opens;
    char *closes;
    struct Island_SType *next;
} Island_SType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES SECTION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES SECTION
 *********************************************************************************************************************/

#endif // __USEFULFUNCTIONS_TYPES_H__

/**********************************************************************************************************************
 *  END OF FILE: UsefulFunctions_Types.h
 *********************************************************************************************************************/
