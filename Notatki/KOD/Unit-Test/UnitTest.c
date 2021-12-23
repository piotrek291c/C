/*!*********************************************************************************
* @file
* @brief     Source file UnitTest.c
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
#include "UnitTest.h"

/*!*****************************************************************************
 * PRIVATE VARIABLES SECTION
*******************************************************************************/

/*!*****************************************************************************
 * START - STATIC FUNCTIONS SECTION
*******************************************************************************/

/*******************************************************************************
 * START - FUNCTIONS SECTION
*******************************************************************************/

/**
 * @brief Adding Unit-Tests to Diagnostics
 *
 */

// 1. Create a new unit-tests folder in SwcDiagnosticServ
// 2.

/**
 * @brief Adding a new header file to SwcDiagnosticService use function from other file
 */

// 1. First, you need to add a new file to the makefile: TEST_MOCKED_HEADERS += sensor/math/math.h
// 2. In test_SwcDiagnostic_Jobs.c add #include "mock_math.h"
// 3. When adding a mock, check if there is a function such as mock_math_Init() in the file;
// If there is such a function, add it in TEST_SETUP(SwcDiagnosticService)
// We also need to add the function TEST_TEAR_DOWN(SwcDiagnosticService) mock_math_Verify(); mock_math_Destroy();

/**
 * @brief Using Rte_Read_VAR_temp in tests, which refers directly to the variable
 */

// 1. After adding a new declaration in the DiagnosticServices.h file, add the name of this function in the cmock_config.yml file: '(?: CheckStatus \ s * \ (+. *? \) +)',
// 2. In the test_runner.c file add: RUN_TEST_CASE(DiagnosticJobs, test_DiagSensor);
// 3. Check the definition of Rte_Read_VAR_temp in the Rte.h file, If we find the declaration in the code
// VAR(TempType, RTE_VAR_NOINIT) Rte_Temp;
// In the test file, add at the beginning VAR(TempType, RTE_VAR_NOINIT) Rte_Temp;
// 4.

/**
 * @brief When Rte refers to another function and there is a compile-time error, use StubWithCallback
 */

// 1. Sprawdzić definicję RTE, jeśli wskazuje na fukncję, to należy w teście lub TEST_SETUP() dodać StubWithCallback
// 2. Sprawdzamy jaki jest błąd podczas kompilacji i dodajemy Rte lub nazwę funkcji np.
    // mathResult_StubWithCallback(Math_Callback);
    // gdzie definicja funkcji sint8 mathResult(uint8 var, sint32 *pointer)
    //  tworzymy w pliku:
    // sint8 Math_Callback(uint8 var, sint32 *pointer, int cmock_num_calls)
    // {
    //     (void)var;
    //     *pointer = 100;
    //     return 0;
    // }

/**
 * @brief Wykorzystanie w testach zmiennych globalnych z pliku DiagnosticServices.c
 */

// 1. W pliku DiagnosticServices.c definiujemy zmienna STATIC uint8 DidVar;
// 2. By w testach korzystać z tej samej zmiennej należy dodać na początku testów : extern STATIC uint8 DidVar;

/**
 * @brief Używanie funkcji Rte w testach
 */

// 1. Gdy Rte odnosi się do funkcji np. FUNC(Std_ReturnType, Swc) Diag_GetStatus(P2VAR() ErrorStatus)
// W teście nie używamy Rte tylko odnosimy się bezpośrednio do funkcji np. Diag_GetStatus_ExpectAnyArgsAndReturn();

/**
 * @brief Używanie _ExpectAnyArgsAndReturn
 */



/*!*****************************************************************************
 * STOP - FUNCTIONS SECTION
*******************************************************************************/
