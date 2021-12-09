/*!*********************************************************************************
* @file
* @brief     Source file chapter9.c Chapter 9 from book
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
#include "chapter9.h"
#include <limits.h>
#include <float.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>
#include <windows.h>
#include <tchar.h>
#include <signal.h>

/*!*****************************************************************************
 * PRIVATE VARIABLES SECTION
*******************************************************************************/

// sint16 score = 0;

/*!*****************************************************************************
 * START - STATIC FUNCTIONS SECTION
*******************************************************************************/

// static void endGame(sint16 sig)
// {
//     printf("\n Wynik koncowy %d \n", score);
//     exit(0);
// }

// static int catchSignal(int sig, HandlerSignal handler)
// {
//     struct sigaction action;
//     action.sa_handler = handler;
//     sigemptyset(&action.sa_mask);
//     action.sa_flags = 0;

//     return sigaction(sig, &action, NULL);
// }

// static void timesUP(int sig)
// {
//     puts("Czas minal!");
//     raise(SIGINT);
// }

// static void error(char *msg)
// {
//     fprintf(stderr, "%s: %s \n", msg, strerror(errno));
//     exit(1);
// }
/*******************************************************************************
 * START - FUNCTIONS SECTION
*******************************************************************************/

/**
 * @brief function from chapter 9
 *
 * @return Std_ReturnType
 */
Std_ReturnType chapter9_exc1(int argc, char *argv[])
{

    // STARTUPINFO si;
    // PROCESS_INFORMATION pi;
    // LPTSTR szCmdline = _tcsdup(TEXT("./main.exe"));

    // ZeroMemory(&si, sizeof(si));
    // si.cb = sizeof(si);
    // ZeroMemory(&pi, sizeof(pi));

    // // Start the child process.
    // if (!CreateProcess(NULL,      // No module name (use command line)
    //                    szCmdline, // Command line
    //                    NULL,      // Process handle not inheritable
    //                    NULL,      // Thread handle not inheritable
    //                    FALSE,     // Set handle inheritance to FALSE
    //                    0,         // No creation flags
    //                    NULL,      // Use parent's environment block
    //                    NULL,      // Use parent's starting directory
    //                    &si,       // Pointer to STARTUPINFO structure
    //                    &pi)       // Pointer to PROCESS_INFORMATION structure
    // )
    // {
    //     printf("CreateProcess failed (%ld).\n", GetLastError());
    //     error("nie moge rozwidlic procesu ");
    // }

    // // Wait until child process exits.
    // WaitForSingleObject(pi.hProcess, INFINITE);

    // // Close process and thread handles.
    // CloseHandle(pi.hProcess);
    // CloseHandle(pi.hThread);

    // catchSignal(SIGALRM, timesUP);
    // catchSignal(SIGINT, endGame);
    // srandom(time(0));

    // while (1)
    // {
    //     int a = random() % 11;
    //     int b = random() % 11;
    //     char txt[4];
    //     alarm(5);
    //     printf("ile wynosi %d razy %d", a, b);
    //     fgets(txt, 4, stdin);
    //     int answer = atoi(txt);
    //     if (answer == (a * b))
    //     {
    //         score++;
    //     }
    //     else
    //     {
    //         printf("Blad twooj wynik wynosi %d", score);
    //     }
    // }

    return E_OK;
}
/*!*****************************************************************************
 * STOP - FUNCTIONS SECTION
*******************************************************************************/
