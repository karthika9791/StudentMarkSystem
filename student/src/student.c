/* student.c - student functions are provided in this file*/

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
This module is called by the menu file to perform various student operations
INCLUDE FILES: student.h
*/

/* includes */
#include "student.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

/* defines */
#define TOTAL_SUBJECT  (10)
#define RANK_ONE       (1)

/* typedefs */

/* globals */

/* locals */

/* forward declarations */

/*******************************************************************************
* 
* studentAdd - Function enter new student
* 
* DESCRIPTION
* The function will add a new student entry to the list of students
* 
* PARAMETERS: pstInfo
* 
* GLOBALS: menuStdntTask
* 
* RETURNS: lReturnFlag
* 
* ERRNO: N/A
*
*/
bool studentAdd
    (
    student* pstInfo
    )
    {
        bool lReturnFlag = true;
        if (pstInfo != NULL)
        {
            student *ststudentInfoTable = 
                calloc(ststudentInfoTable,(ucStdntCnt+1)*sizeof(student));
            if (ststudentInfoTable != NULL)
            {
                ststudentInfoTable[ucStdntCnt].ucStd_name = pstInfo->ucStd_name;
                ststudentInfoTable[ucStdntCnt].uiStd_roll = pstInfo->uiStd_roll;
                ststudentInfoTable[ucStdntCnt].menustdntMark.ucEng_mark 
                    = pstInfo->menustdntMark.ucEng_mark;
                ststudentInfoTable[ucStdntCnt].menustdntMark.ucMaths_mark 
                    = pstInfo->menustdntMark.ucMaths_mark;
                ststudentInfoTable[ucStdntCnt].menustdntMark.ucPhy_mark 
                    = pstInfo->menustdntMark.ucPhy_mark;
                ststudentInfoTable[ucStdntCnt].menustdntMark.ucChem_mark 
                    = pstInfo->menustdntMark.ucChem_mark;
                ststudentInfoTable[ucStdntCnt].menustdntMark.ucMal_mark 
                    = pstInfo->menustdntMark.ucMal_mark;
                ststudentInfoTable[ucStdntCnt].menustdntMark.ucBio_mark 
                    = pstInfo->menustdntMark.ucBio_mark;
                ststudentInfoTable[ucStdntCnt].menustdntMark.ucHstry_mark 
                    = pstInfo->menustdntMark.ucHstry_mark;
                ststudentInfoTable[ucStdntCnt].menustdntMark.ucGeo_mark 
                    = pstInfo->menustdntMark.ucGeo_mark;
                ststudentInfoTable[ucStdntCnt].menustdntMark.ucHindi_mark 
                    = pstInfo->menustdntMark.ucHindi_mark;
                ststudentInfoTable[ucStdntCnt].menustdntMark.ucCs_mark 
                    = pstInfo->menustdntMark.ucCs_mark;
            }
            free(ststudentInfoTable);
        }
        else
        {
            lReturnFlag = false;
        }
        return lReturnFlag;
    }

/*******************************************************************************
* 
* studentCalcSum - Function to calculate the sum of the mark of a student
* 
* DESCRIPTION
* The function will calculate the total sum of marks of all subject of each 
* student
* 
* PARAMETERS: pstInfo,
*             pfAvg
* 
* GLOBALS: menuStdntTask
* 
* RETURNS: lReturnFlag
* 
* ERRNO: N/A
*
*/
bool studentCalcSum
    (
    student* pstInfo,  
    uint32_t* pulSum
    )
    {
        bool lReturnFlag = true;
        if ((pstInfo != NULL) && (pulSum != NULL))
        {
            *pulSum = (pstInfo->menustdntMark.ucEng_mark +
                pstInfo->menustdntMark.ucMaths_mark +
                pstInfo->menustdntMark.ucPhy_mark +
                pstInfo->menustdntMark.ucChem_mark +
                pstInfo->menustdntMark.ucMal_mark +
                pstInfo->menustdntMark.ucBio_mark +
                pstInfo->menustdntMark.ucHstry_mark +
                pstInfo->menustdntMark.ucGeo_mark +
                pstInfo->menustdntMark.ucHindi_mark +
                pstInfo->menustdntMark.ucCs_mark);
        }
        else
        {
            lReturnFlag = false;
        }
        return lReturnFlag;
    }


/*******************************************************************************
* 
* studentCalcAverage - Function to calculate the averge of the mark of student
* 
* DESCRIPTION
* The function will calculate the average of mark of each student
* 
* PARAMETERS: pstInfo,
*             pfAvg
* 
* GLOBALS: N/A
* 
* RETURNS: lReturnFlag
* 
* ERRNO: N/A
*
*/
bool studentCalcAverage
    (
    student* pstInfo,  
    float* pfAvg
    )
    {
        bool lReturnFlag = true;
        if ((pfAvg != NULL) && (pstInfo != NULL))
        {
            *pfAvg = (float)(pstInfo->menustdntMark.ucEng_mark +
                pstInfo->menustdntMark.ucMaths_mark +
                pstInfo->menustdntMark.ucPhy_mark +
                pstInfo->menustdntMark.ucChem_mark +
                pstInfo->menustdntMark.ucMal_mark +
                pstInfo->menustdntMark.ucBio_mark +
                pstInfo->menustdntMark.ucHstry_mark +
                pstInfo->menustdntMark.ucGeo_mark +
                pstInfo->menustdntMark.ucHindi_mark +
                pstInfo->menustdntMark.ucCs_mark) / (float)TOTAL_SUBJECT;
        }
        else
        {
            lReturnFlag = false;
        }
        return lReturnFlag;
    }

/*******************************************************************************
* 
* studentCalcGrades - Function calculate the grade of the student
* 
* DESCRIPTION
* The function will calculate the grade a student based on the total mark
* 
* PARAMETERS: pstInfo,
*             pucSum
* 
* GLOBALS: N/A
* 
* RETURNS: lReturnFlag
* 
* ERRNO: N/A
*
*/
bool studentCalcGrades
    (
    student* pstInfo,  
    uint8_t* pucSum
    )
    {
        bool lReturnFlag = true;
        if ((pucSum != NULL) && (pstInfo != NULL))
        {
            switch (*pucSum /TOTAL_SUBJECT)
            {
            case 10:
            case 9:
                printf("A\n");
                break;
            case 8:
                printf("B\n");
                break;
            case 7:
                printf("C\n");
                break;
            case 6:
                printf("D\n");
                break;
            case 5:
                printf("E\n");
                break;
            default:
                printf("F\n");
                break;
            }
        }
        else
        {
            lReturnFlag = false;
        }
        return lReturnFlag;
    }
/*******************************************************************************
* 
* studentUpdateRank - Function to update the rank of student in the list
* 
* DESCRIPTION
* The function will update the a student's rank based on the mark
* 
* PARAMETERS: N/A
* 
* GLOBALS: menuStdntTask
* 
* RETURNS: lReturnFlag
* 
* ERRNO: N/A
*
*/
bool studentUpdateRank
    (
    void
    )
    {
        bool lReturnFlag   = true;
        uint8_t ucInIndex  = ZERO_INITIALIZATION;
        uint8_t ucOutIndex = ZERO_INITIALIZATION;
        uint32_t uiRank    = RANK_ONE;
        student stTempstudentInfo;
        if (ucStdntCnt <= ZERO_INITIALIZATION)
        {
            lReturnFlag = false;
        }
        
        for ( ; ucOutIndex < ucStdntCnt ; ucOutIndex++)
        {
            for ( ; ucInIndex < ucStdntCnt; ucInIndex++)
            {
                if (ststudentInfoTable[ucOutIndex].ucMark_sum < 
                    ststudentInfoTable[ucInIndex].ucMark_sum)
                {
                    stTempstudentInfo = ststudentInfoTable[ucOutIndex];
                    ststudentInfoTable[ucOutIndex] = 
                        ststudentInfoTable[ucInIndex];
                    ststudentInfoTable[ucInIndex] = stTempstudentInfo;
                }
                
            }   
        }
        ststudentInfoTable[ZERO_INITIALIZATION].ucrank = uiRank;
        for (ucOutIndex = ZERO_INITIALIZATION; ucOutIndex < ucStdntCnt; 
            ucOutIndex++)
        {
            if (ststudentInfoTable[ucOutIndex].ucMark_sum ==
                ststudentInfoTable[ucOutIndex].ucMark_sum)
            {
                ststudentInfoTable[ucOutIndex].ucrank = uiRank;
            }
            else
            {
                uiRank = ucOutIndex + RANK_ONE;
                ststudentInfoTable[ucOutIndex].ucrank = uiRank;
            }
            
        }
        

        return lReturnFlag;
    }

/*******************************************************************************
* 
* studentGetCount - Function to get the count of students in the list 
* 
* DESCRIPTION
* The function will update the pointer for student number with the number of st-
* udents
* 
* PARAMETERS: pulCount
*            
* GLOBALS: N/A
* 
* RETURNS: lReturnFlag
* 
* ERRNO: N/A
*
*/
bool studentGetCount
    (  
    uint32_t* pulCount
    )
    {
        bool lReturnFlag = true;
        if (pulCount != NULL)
        {
            *pulCount = ucStdntCnt;
        }
        else
        {
            lReturnFlag = false;
        }
        return lReturnFlag;
    }

/*******************************************************************************
* 
* studentDeleteByName - Function to delete the student record based on name
* 
* DESCRIPTION
* The function will delete the student record from the list based on name given
* by the user
* 
* PARAMETERS: pucName
*            
* GLOBALS: N/A
* 
* RETURNS: lReturnFlag
* 
* ERRNO: N/A
*
*/
bool studentDeleteByName
    (  
    uint8_t* pucName
    )
    {
        uint8_t ucIndex       = ZERO_INITIALIZATION;
        uint32_t uiPucNamelen = ZERO_INITIALIZATION;
        uint8_t ucDelIndex    = ZERO_INITIALIZATION;
        bool lReturnFlag      = true;
        bool lNameFound       = false;
        if (pucName != NULL)
        {
            uiPucNamelen = strlen(pucName);
            for (; ucIndex < ucStdntCnt; ucIndex++)
            {
                if (strncmp(ststudentInfoTable[ucIndex].ucStd_name,pucName, 
                    uiPucNamelen))
                    {
                        lNameFound = true;
                        for (ucDelIndex = ucIndex; ucDelIndex < ucStdntCnt; 
                            ucDelIndex++)
                        {
                            ststudentInfoTable[ucDelIndex] = 
                                ststudentInfoTable[ucDelIndex + 1];
                        }
                        ucStdntCnt--;
                        break;
                    }
            }
            if (!lNameFound)
            {
                printf ("Name not found\n");
                lReturnFlag = false;
            }           
        }
        else
        {
            lReturnFlag = false;
        }
        return lReturnFlag;
    }
/*******************************************************************************
* 
* studentDeleteByRoll - Function to delete the student record based on roll no:
* 
* DESCRIPTION
* The function will delete the student record from the list based on roll number
* given by the user
* 
* PARAMETERS: ulRoll
*            
* GLOBALS: N/A
* 
* RETURNS: lReturnFlag
* 
* ERRNO: N/A
*
*/
bool studentDeleteByRoll
    (  
    uint32_t* ulRoll
    )
    {
        uint8_t ucIndex    = ZERO_INITIALIZATION;
        uint8_t ucDelIndex = ZERO_INITIALIZATION;
        bool lReturnFlag   = true;
        bool lRollnoFound  = false;
        if (ulRoll != NULL)
        {
            for (; ucIndex < ucStdntCnt; ucIndex++)
            {
                if (ststudentInfoTable[ucIndex].uiStd_roll == *ulRoll)
                {
                    lRollnoFound = true;
                    for ( ; ucDelIndex < (ucStdntCnt - 1); ucDelIndex++)
                    {
                        ststudentInfoTable[ucDelIndex] =
                            ststudentInfoTable[ucDelIndex + 1];
                    }
                    ucStdntCnt--;    
                }
                
            }  
            if (!lRollnoFound)
            {
                printf ("Roll number not found\n");
                lReturnFlag = false;
            }
              
        }
        else
        {
            lReturnFlag = false;
        }
        return lReturnFlag;
    }

/*******************************************************************************
* 
* studentDeleteAll - Function to delete all the student record 
* 
* DESCRIPTION
* The function will delete all the student record from the list 
* given by the user
* 
* PARAMETERS: N/A
*            
* GLOBALS: N/A
* 
* RETURNS: lReturnFlag
* 
* ERRNO: N/A
*
*/
bool studentDeleteAll
    (  
    void
    )
    {
        bool lReturnFlag = true;
        if (ststudentInfoTable != NULL)
        {
            memset (ststudentInfoTable, 0, ucStdntCnt*sizeof(student));
            ucStdntCnt = ZERO_INITIALIZATION;
        }
        else
        {
            lReturnFlag = false;
        }
        
        return lReturnFlag;
    }
/*******************************************************************************
* 
* studentGetAvgMarksOfSubjects - Function to get average mark of students
* 
* DESCRIPTION
* The function will find the average mark of all students 
* 
* PARAMETERS: N/A
*            
* GLOBALS: N/A
* 
* RETURNS: lReturnFlag
* 
* ERRNO: N/A
*
*/
bool studentGetAvgMarksOfSubjects
    (  
    uint8_t* pucAvgMarks
    )
    {
        uint8_t ucIndex = ZERO_INITIALIZATION;
        uint32_t ulSum = ZERO_INITIALIZATION;
        bool lReturnFlag = true;
        if (pucAvgMarks != NULL)
        {
            for ( ; ucIndex < ucStdntCnt; ucIndex++)
            {
                ulSum += ststudentInfoTable[ucIndex].ucMark_avg;
            }          
        }
        else
        {
            lReturnFlag = false;
        }
        if (ucStdntCnt != ZERO_INITIALIZATION)
        {
            *pucAvgMarks = ((float)ulSum)/((float)ucStdntCnt);
        }
        else
        {
            lReturnFlag = false;
        }
        return lReturnFlag;
    }

