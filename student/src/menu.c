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
#include "student.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/* defines */
#define TASK_COUNT          (12)
#define INPUT_BUFFER        (100)
#define CHAR_MIN            (0)
#define CHAR_MAX            (255)
#define OPTION_ONE          (1)
#define OPTION_TWO          (2)
#define OPTION_THREE        (3)

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
uint8_t fAvg;

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
        uint8_t *pucendptr;
        uint8_t ulTemp = ZERO_INITIALIZATION;
        do
        {
            printf("Student Operation List\n");
            printf("1. Student Overview\n2. Add Student\n3. List Student\n");
            printf(" 4. Delete Student\n5. Search Student by name\n");
            printf("6. Sort by name\n");
            printf("7. Sort by roll number\n8. Sort by Rank\n");   
            printf("9. Delete by name\n");  
            printf("10. Delete by rollno.\n11. Delete All\n 12. Exit\n");
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
            
            if (STD_OVERVIEW <= ucInpNum && ucInpNum <= TASK_COUNT)
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
        bool lReturnflag = true;
        studentGetCount(&ucStdntCnt);
        printf("No: of students = %d\n",ucStdntCnt);
        studentGetAvgMarksOfSubjects(&fAvg);
        printf("Average = %d\n",fAvg);
        return lReturnflag;
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
        student *ststudentInfo = malloc(sizeof(student));
        printf ("Enter student name:\n");
        if (fgets(ststudentInfo->ucStd_name, 
            sizeof(ststudentInfo->ucStd_name), stdin) != NULL)
            {
                if (ststudentInfo->ucStd_name == '\n' ||
                    ststudentInfo->ucStd_name == '\0')
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
                ststudentInfo->uiStd_roll = (uint32_t)ulTemp;
                lReturnFlag = true;
            }
        }
        else
        {
            lReturnFlag = false;
        }
        printf ("Enter marks of each subject in the respective order\n");
        printf("1. English\n2. Maths\n3. Physics\n4. Chemistry\n5.Malayalam\n");
        printf("6. Biology\n7. Histroy\n 8. Geography\n 9. Hindi\n 10. CS\n");
        scanf ("%hd",ststudentInfo->menustdntMark.ucEng_mark);
        scanf ("%hd",ststudentInfo->menustdntMark.ucMaths_mark);
        scanf ("%hd",ststudentInfo->menustdntMark.ucPhy_mark);
        scanf ("%hd",ststudentInfo->menustdntMark.ucChem_mark);
        scanf ("%hd",ststudentInfo->menustdntMark.ucMal_mark);
        scanf ("%hd",ststudentInfo->menustdntMark.ucBio_mark);
        scanf ("%hd",ststudentInfo->menustdntMark.ucHstry_mark);
        scanf ("%hd",ststudentInfo->menustdntMark.ucGeo_mark);
        scanf ("%hd",ststudentInfo->menustdntMark.ucHindi_mark);
        scanf ("%hd",ststudentInfo->menustdntMark.ucCs_mark);  
        printf ("Enter address\n");
        
        studentAdd (&ststudentInfo);
        studentCalcAverage (&ststudentInfo, &fAvg);
        studentCalcSum (&ststudentInfo, &ststudentInfo->ucMark_sum);
        studentCalcGrades (&ststudentInfo, &ststudentInfo->ucMark_sum);
        studentUpdateRank ();
        ucStdntCnt++;
        return lReturnFlag;
    }

/*******************************************************************************
* 
* menuListStudent - Function to print students name based on Student List
* 
* DESCRIPTION
* The function calls the corresponding function to display student list
* 
* PARAMETERS:
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
    
/*******************************************************************************
* 
* menuDeleteStudent - Function to delete student record
* 
* DESCRIPTION
* The function is used to delete student record from based on delete student 
* menu. It provides options to delete menu.
* 
* PARAMETERS:
* N/A
* 
* GLOBALS: N/A
* 
* RETURNS: lReturnFlag
* 
* ERRNO: N/A
*
*/

bool menuDeleteStudent
    (
    void
    )
    {
        uint8_t ucIndex  = ZERO_INITIALIZATION;
        uint8_t ulTemp   = ZERO_INITIALIZATION;
        uint8_t ucInpNum = ZERO_INITIALIZATION;
        bool lReturnFlag = true;
        uint8_t *pucendptr;
        printf ("Enter the option to delete:\n1. Delete by Name\n");
        printf ("2. Delete by Roll no:\n3. Delete all\n");
        if( fgets (ucinpBuff, sizeof(ucinpBuff), stdin))
            {
                //uint8_t *pucendptr;
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
            
            if (STD_OVERVIEW <= ucInpNum && ucInpNum <= TASK_COUNT)
            {
                for ( ; ucIndex < TASK_COUNT; ucIndex++)
                {
                    switch (ucInpNum)
                    {
                    case OPTION_ONE:
                        menuDeleteByName();
                        break;
                    case OPTION_TWO:
                        menuListSortByRoll();
                        break;
                    case OPTION_THREE:
                        menuDeleteAll();
                        break;
                    default:
                        printf("Not a valid input\n");
                        break;
                    }
                }
            }
            else
            {
                lReturnFlag = false;
            }
        
    }    
/*******************************************************************************
* 
* menuDeleteByName - Function to delete student record based on Name
* 
* DESCRIPTION
* The function is used to delete student record from based on the name given by
* the user. 
* 
* PARAMETERS:
* N/A
* 
* GLOBALS: N/A
* 
* RETURNS: lReturnFlag
* 
* ERRNO: N/A
*
*/

bool menuDeleteByName
    (
    void
    )
    {
        bool lReturnFlag = true;
        student ststudentInfo;
        printf("Enter the name to delete:\n");
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
        studentDeleteByName (&ststudentInfo.ucStd_name);
        return lReturnFlag;
        
    } 
/*******************************************************************************
* 
* menuDeleteByRoll - Function to delete student record based on Roll No:
* 
* DESCRIPTION
* The function is used to delete student record from based on the roll no: given 
* by the user. 
* 
* PARAMETERS:
* N/A
* 
* GLOBALS: N/A
* 
* RETURNS: lReturnFlag
* 
* ERRNO: N/A
*
*/

bool menuDeleteByRoll
    (
    void
    )
    {
        bool lReturnFlag = true;
        student ststudentInfo;
        printf("Enter the number to delete:\n");
        scanf("%d",&ststudentInfo.uiStd_roll);
        studentDeleteByRoll (&ststudentInfo.uiStd_roll);
        return lReturnFlag;
        
    }  
/*******************************************************************************
* 
* menuDeleteAll - Function to delete all the student record 
* 
* DESCRIPTION
* The function is used to delete all the student record fromthe structure table
* 
* PARAMETERS:
* N/A
* 
* GLOBALS: N/A
* 
* RETURNS: lReturnFlag
* 
* ERRNO: N/A
*
*/

bool menuDeleteByAll
    (
    void
    )
    {
        bool lReturnFlag = true;
        if (!studentDeleteAll())
        {
            lReturnFlag = false;
        }
        return lReturnFlag;    
    } 
    
/*******************************************************************************
* 
* menuListSearchByName - Function to search by name
* 
* DESCRIPTION
* The function will search the student record based on name given by user.
* 
* PARAMETERS:
* N/A
* 
* GLOBALS: N/A
* 
* RETURNS: lReturnFlag
* 
* ERRNO: N/A
*
*/

bool menuListSearchByName
    (
    void
    )
    {      
       uint8_t ucName[INPUT_BUFFER];
       uint8_t ucIndex = ZERO_INITIALIZATION;
       bool lReturnflag = true;
       printf ("Enter the name:\n");
       scanf ("%[^\n]", ucName); 
       for ( ; ucIndex < ucStdntCnt; ucIndex++)
       {
            if (strcmp(ststudentInfoTable[ucIndex].ucStd_name,ucName) == 0)
            {
                printf("Student found\n");
                printf ("Name: %d\n",ststudentInfoTable[ucIndex].ucStd_name);
                printf ("Roll: %d\n",ststudentInfoTable[ucIndex].uiStd_roll);
                printf ("Total: %d\n",ststudentInfoTable[ucIndex].ucMark_sum);
                printf ("Avg: %d\n",ststudentInfoTable[ucIndex].ucMark_avg);
                printf ("Rank: %d\n",ststudentInfoTable[ucIndex].ucrank);
            }   
       }
       return lReturnflag; 
    }  