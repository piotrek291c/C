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
// https: //gitlab.com/sibros_public/public/-/wikis/c/unit_tests?version_id=b71ad572517e0f39408334b7f4b1e54b25f0f1da


       /*!*****************************************************************************
 * START - STATIC FUNCTIONS SECTION
*******************************************************************************/

       /*******************************************************************************
 * START - FUNCTIONS SECTION
*******************************************************************************/

       /**
 * TODO: Adding Unit-Tests to Diagnostics
 */

       // 1. Create a new unit-tests folder in SwcDiagnosticServ
       // 2.

       /**
 * TODO: Adding a new header file to SwcDiagnosticService use function from other file
 */

       // 1. First, you need to add a new file to the makefile: TEST_MOCKED_HEADERS += sensor/math/math.h
       // 2. In test_SwcDiagnostic_Jobs.c add #include "mock_math.h"
       // 3. When adding a mock, check if there is a function such as mock_math_Init() in the file;
       // If there is such a function, add it in TEST_SETUP(SwcDiagnosticService)
       // We also need to add the function TEST_TEAR_DOWN(SwcDiagnosticService) mock_math_Verify(); mock_math_Destroy();

       /**
 * TODO: Using Rte_Read_VAR_temp in tests, which refers directly to the variable
 */

       // 1. After adding a new declaration in the DiagnosticServices.h file, add the name of this function in the cmock_config.yml file: '(?: CheckStatus \ s * \ (+. *? \) +)',
       // 2. In the test_runner.c file add: RUN_TEST_CASE(DiagnosticJobs, test_DiagSensor);
       // 3. Check the definition of Rte_Read_VAR_temp in the Rte.h file, If we find the declaration in the code
       // VAR(TempType, RTE_VAR_NOINIT) Rte_Temp;
       // In the test file, add at the beginning VAR(TempType, RTE_VAR_NOINIT) Rte_Temp;
       // 4.

/**
 * TODO: When Rte refers to another function and there is a compile-time error, use StubWithCallback
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
 * TODO: Wykorzystanie w testach zmiennych globalnych z pliku DiagnosticServices.c
 */

       // 1. W pliku DiagnosticServices.c definiujemy zmienna STATIC uint8 DidVar;
       // 2. By w testach korzystać z tej samej zmiennej należy dodać na początku testów : extern STATIC uint8 DidVar;

       /**
 * TODO: Używanie funkcji Rte w testach
 */

       // 1. Gdy Rte odnosi się do funkcji np. FUNC(Std_ReturnType, Swc) Diag_GetStatus(P2VAR() ErrorStatus)
       // W teście nie używamy Rte tylko odnosimy się bezpośrednio do funkcji np. Diag_GetStatus_ExpectAnyArgsAndReturn();

/**
 * TODO: Pisanie podstawowych testów na podstawie funkcji CheckNvMBlockStatus
 */

// 1. Na początku testu deklarujemy zmienne przechowujące aktualne stany
// 2. Następnie staramy się po kolei przetestować każdą możliwą ścieżkę w funkcji.
// 3. Np. W pierwszym warunku jest sprawdzane RTE, dlatego należy odszukać jego definicji i odwołać się bezpośrednio.
// 4. Jeśli to możliwe to sprawdzić co zwraca RTE i czy wartość jest poprawna
// 5. Przekazać parametr do RTE poprzez ReturnThruPtr
// 6. Wywołać TEST_ASSERT_EQUAL(E_NOT_OK, CheckNvMBlockStatus(...));
// 7. Zmienić wartość przekazywaną przez funkcję ReturnThruPtr i ponownie sprawdzić wynik.

/**
 * TODO: Błąd podczas ponownego kompilowania testów repit/config/make/test - SwcDiagServices_DiagnosticJobs_test_runner.d : No such file or directory
 */
// 1. Najczęstszą przyczyną tego rodzaju błędu jest zbyt długa ścieżka. Po skróceniu ścieżki problem powinien ustąpić.
                                                                                                                                                                                     /**
 * TODO: Używanie _____ Expect _____- for functions that do not return a value
 */
                                                                                                                                                                                     /**
 * TODO: Używanie _____ ExpectAndReturn _____ for functions that return a value
 */
                                                                                                                                                                                     /**
 * TODO: Używanie _____ ExpectAnyArgs _____ Expect the function with no checks on any of the arguments
 */
                                                                                                                                                                                     /**
 * TODO: Używanie _____ ExpectAnyArgsAndReturn _____ to ignore input arguments but return a value
 */
                                                                                                                                                                                     /**
 * TODO: Używanie _____ Ignore _____ dangerous method of just ignoring the expectation
 */
                                                                                                                                                                                     /**
 * TODO: Używanie _____ IgnoreAndReturn_____ Ignore but always return something for functions that return a value
 */
                                                                                                                                                                                     /**
 * TODO: Używanie _____ StubWithCallback _____ Use a custom callback that can have a small test driver of your own _____- for functions that do not return a value
 */
                                                                                                                                                                                     /**
 * TODO: Używanie _____ ReturnMemThruPtr _____ Modify something inside of a parameter that is a pointer
 */
                                                                                                                                                                                     /**
 * TODO: Używanie _____ ReturnThruPtr _____ Use when your type is known, such as void foo(int *)
 */
                                                                                                                                                                                     /**
 * TODO: Używanie _____ ReturnArrayThruPtr _____ Similar to ReturnThruPtr but you can return an array of integers
 */

                                                                                                                                                                                     /*!*****************************************************************************
 * STOP - FUNCTIONS SECTION
*******************************************************************************/
