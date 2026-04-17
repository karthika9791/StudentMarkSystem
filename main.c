/* main.c - main file for student grade system */

/*
* Copyright (c) 2026 Trenser Technology Solutions(P), Ltd.
*
* The right to copy, distribute, modify, or otherwise make use 
* of this software may be licensed only pursuant to the terms 
* of an applicable Trenser Technology Solutions(P), Ltd license agreement.
*/

/*
modification history
--------------------
17apr26, initial work
*/

/*
DESCRIPTION
This module calls the student menu file for student functions
INCLUDE FILES: main.h
*/

/* includes */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
/* defines */

/* typedefs */

/* globals */

/* locals */

/* forward declarations */
bool menuMain(void);

/*******************************************************************************
* 
* main.c - Entry function to the student grade system
* 
* DESCRIPTION
* The function will call the menuMain function to input user option.
* 
* PARAMETERS
* N/A
* 
* GLOBALS: N/A
* 
* RETURNS: N/A
* 
* ERRNO: N/A
*
*/

int main
    (
    void
    )
    {
        menuMain();
    }