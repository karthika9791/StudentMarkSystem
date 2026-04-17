/* menu.c - menu file to input option, calls function in student file*/

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
This module inputs the user option by displaying various options and calls the 
respective function in student.c
INCLUDE FILES: menu.h
*/

/* includes */
#include "menu.h"
#include "student.h"
#include <stdbool.h>

/* defines */
#define TASK_COUNT          (12)
#define INPUT_BUFFER        (100)
#define CHAR_MIN            (0)
#define CHAR_MAX            (255)

/* typedefs */
typedef enum
    {
        STD_OVERVIEW = 1,
        STD_ADD,
        STD_LIST,
        STD_DELETE,
        STD_SRCH_NAME,
        STD_SRT_NAME,
        STD_SRT_ROLL,
        STD_SRT_RANK,
        STD_DLT_NAME,
        STD_DLT_ROLL,
        STD_DLT_ALL,
        STD_EXIT
    }OPTION_TYPE;

/* globals */
typedef struct 
    {
        OPTION_TYPE eInputOption;
        bool (*pMenuFucnHandler) (void);
    }menuStdntTask;
float fAvg;

/* locals */
uint8_t ucinpBuff[INPUT_BUFFER];
menuStdntTask pstmenuStdntTask[TASK_COUNT] = 
    {
        {STD_OVERVIEW, (bool *)menuStudentOverview},
        {STD_ADD, (bool *)menuAddStudent},
        {STD_LIST, (bool *)menuListStudent},
        {STD_DELETE, (bool *)menuDeleteStudent},
        {STD_SRCH_NAME, (bool *)menuListSearchByName},
        {STD_SRT_NAME, (bool *)menuListSortByName},
        {STD_SRT_ROLL, (bool *)menuListSortByRoll},
        {STD_SRT_RANK, (bool *)menuListSortByRank},
        {STD_DLT_NAME, (bool *)menuDeleteByName},
        {STD_DLT_ROLL, (bool *)menuDeleteByRoll},
        {STD_DLT_ALL, (bool *)menuDeleteAll},
    };


/* forward declarations */
bool menuMain(void);
bool menuStudentOverview(void);
bool menuAddStudent(void);
bool menuListStudent(void);
bool menuDeleteStudent(void);
bool menuListSearchByName(void);
bool menuListSortByName(void);
bool menuListSortByRoll(void);
bool menuListSortByRank(void);	
bool menuDeleteByName(void);
bool menuDeleteByRoll(void);
bool menuDeleteAll(void);

/*******************************************************************************
* 
* menuMain.c - Display various user input options
* 
* DESCRIPTION
* The function will display user input and calls the corresponding menu function
* in the file
* 
* PARAMETERS
* N/A
* 
* GLOBALS: menuStdntTask
* 
* RETURNS: lReturnFlag
* 
* ERRNO: N/A
*
*/

bool menuMain
    (
    void
    )
    {
        bool lReturnFlag = true;
        uint8_t ucInpNum = ZERO_INITIALIZATION;
        uint8_t ucIndex  = ZERO_INITIALIZATION;
        do
        {
            printf("Student Operation List\n");
            printf("1. Student Overview\n2. Add Student\n3. List Student\n
                4. Delete Student\n5. Search Student by name\n6. Sort by name\n,
                7. Sort by roll number\n8. Sort by Rank\n9. Delete by name\n
                10. Delete by rollno.\n11. Delete All\n 12. Exit\n");
            if( fgets (ucinpBuff, sizeof(ucinpBuff), stdin))
            {
                uint8_t *pucendptr;
                uint64_t ulTemp = strtol (ucinpBuff, &pucendptr, 10);
            }

            if (pucendptr == ucinpBuff)
            {
                printf ("Not a valid input\n");
                lReturnFlag = false;
            }
            else if (ulTemp < CHAR_MIN || ulTemp > CHAR_MAX)
            {
                printf ("NUmber out of range\n");
                lReturnFlag = false;
            }
            else
            {
                ucInpNum = (uint8_t)ulTemp;
                lReturnFlag = true;
            }
            
            if (STD_OVERVIEW <= ucInpNum <= TASK_COUNT)
            {
                for ( ; ucIndex < TASK_COUNT; ucIndex++)
                {
                    if (pstmenuStdntTask[ucIndex].eInputOption == ucInpNum)
                    {
                        pstmenuStdntTask[ucIndex].pMenuFucnHandler();
                    }
                }
            }
            else
            {
                lReturnFlag = false;
            }

        }
        while (STD_EXIT != ucInpNum);
        return lReturnFlag;         
    }

/*******************************************************************************
* 
* menuStudentOverview - Displays number of students, average mark of the class
* 
* DESCRIPTION
* The function calls the corresponding function to display the student info
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

bool menuStudentOverview
    (
    void
    )
    {
        printf("No: of students = %d\n",ucStdntCnt);
    }

/*******************************************************************************
* 
* menuAddStudent - Function to add student to the list
* 
* DESCRIPTION
* The function calls the corresponding function in student.c to add the student
* info
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

bool menuAddStudent
    (
    void
    )
    {
        bool lReturnFlag = true;
        student ststudentInfo = malloc(sizeof(student));
        printf ("Enter student name:\n");
        if (fgets(ststudentInfo.ucStd_name, 
            sizeof(ststudentInfo.ucStd_name), stdin) != NULL)
            {
                if (ststudentInfo.ucStd_name == '\n' ||
                    ststudentInfo.ucStd_name == '\0')
                    {
                        printf ("Enter valid name\n");
                        lReturnFlag = false;
                    }    
                else   
                    {
                        lReturnFlag = true;
                    }
        
            }
        else
            {
                printf ("Unable to read input\n");
                lReturnFlag = false;
            }
        printf ("Enter roll no:\n");
        if( fgets (ucinpBuff, sizeof(ucinpBuff), stdin))
        {
                uint8_t *pucendptr;
                uint64_t ulTemp = strtol (ucinpBuff, &pucendptr, 10);
            

            if (pucendptr == ucinpBuff)
            {
                printf ("Not a valid input\n");
                lReturnFlag = false;
            }
            else if (ulTemp < CHAR_MIN || ulTemp > CHAR_MAX)
            {
                printf ("NUmber out of range\n");
                lReturnFlag = false;
            }
            else
            {
                ststudentInfo.uiStd_roll = (uint32_t)ulTemp;
                lReturnFlag = true;
            }
        }
        else
        {
            lReturnFlag = false;
        }
        printf ("Enter marks of each subject in the respective order\n1. English
            \n2. Maths\n3. Physics\n4. Chemistry\n5. Malayalam\n 6. Biology\n
            7. Histroy\n 8. Geography\n 9. Hindi\n 10. CS");
        scanf ("%hd",ststudentInfo.menustdntMark.ucEng_mark);
        scanf ("%hd",ststudentInfo.menustdntMark.ucMaths_mark);
        scanf ("%hd",ststudentInfo.menustdntMark.ucPhy_mark);
        scanf ("%hd",ststudentInfo.menustdntMark.ucChem_mark);
        scanf ("%hd",ststudentInfo.menustdntMark.ucMal_mark);
        scanf ("%hd",ststudentInfo.menustdntMark.ucBio_mark);
        scanf ("%hd",ststudentInfo.menustdntMark.ucHstry_mark);
        scanf ("%hd",ststudentInfo.menustdntMark.ucGeo_mark);
        scanf ("%hd",ststudentInfo.menustdntMark.ucHindi_mark);
        scanf ("%hd",ststudentInfo.menustdntMark.ucCs_mark);  
        printf ("Enter address\n");
        
        studentAdd (ststudentInfo);
        studentCalcAverage (ststudentInfo, &fAvg);
        ucStdntCnt++;
    }

/*******************************************************************************
* 
* menuListStudent - Function to print students name based on Student List
* 
* DESCRIPTION
* The function calls the corresponding function to display student list
* 
* PARAMETERS
* N/A
* 
* GLOBALS: N/A
* 
* RETURNS: lReturnFlag
* 
* ERRNO: N/A
*
*/

bool menuListStudent
    (
    void
    )
    {
        uint8_t ucIndex  = ZERO_INITIALIZATION;
        if (ucStdntCnt == ZERO_INITIALIZATION)
        {
            printf("No student data entered\n");
        }
        else if (ucStdntCnt > ZERO_INITIALIZATION)
        {
            for (ucIndex  = ZERO_INITIALIZATION; ucIndex<ucStdntCnt; ucIndex++) 
            {
                printf("%s",ststudentInfoTable[ucIndex].ucStd_name);
            }
        }
        else
        {
            printf("Invalid operation\n");
        }
    }    