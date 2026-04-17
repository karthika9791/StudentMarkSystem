#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/* defines */
#define ZERO_INITIALIZATION (0)

typedef struct
    {
        uint16_t ucEng_mark;
        uint16_t ucMaths_mark;
        uint16_t ucPhy_mark;
        uint16_t ucChem_mark;
        uint16_t ucMal_mark;
        uint16_t ucBio_mark;
        uint16_t ucHstry_mark;
        uint16_t ucGeo_mark;
        uint16_t ucHindi_mark;
        uint16_t ucCs_mark;
    }menuStdntMark;

typedef struct 
    {
        uint8_t ucEngGrade;
        uint8_t ucMathGrade;
        uint8_t ucPhyGrade;
        uint8_t ucChemGrade;
        uint8_t ucMalGrade;
        uint8_t ucBioGrade;
        uint8_t ucHstryGrade;
        uint8_t ucGeoGrade;
        uint8_t ucHindiGrade;
        uint8_t ucCsGrade;
    }menuStdntGrade;

typedef struct
    {
        uint8_t ucStd_name;
        uint32_t uiStd_roll;
        menuStdntMark menustdntMark;
        /*-----studnt add------*/
        uint16_t ucMark_sum;
        uint16_t ucMark_avg;
        menuStdntGrade menustdntGrade;
        uint16_t ucrank;
    }student;

uint8_t ucStdntCnt = ZERO_INITIALIZATION;
student *ststudentInfoTable = NULL;