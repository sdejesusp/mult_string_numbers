/**
 * Utils.c
 * Definition for Utils functions.
 */

#include "Utils.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * parsingNumber
 * This function parse a string number
 * @param strNumber
 * @param lenNumber
 * @return 
 */
struct ParseNumber parsingStrNumber(char *strNumber, int mask) {
	char buf[20];
	int decimalPoints = 2;
	struct ParseNumber Parse;

	memset(buf, '\0', sizeof(buf));
	memcpy(buf, &strNumber[0], mask-(decimalPoints+1));
	Parse.integerPart = atoi(buf);

	memset(buf, '\0', sizeof(buf));
	memcpy(buf, &strNumber[mask-decimalPoints], decimalPoints);
	Parse.fractionPart = atoi(buf);

	return Parse;
}



/**
 * sumStrNumbers
 * This function add two number in string format
 * @param n1
 * @param n2
 * @return
 */
struct ParseNumber sumStrNumbers(struct ParseNumber n1, struct ParseNumber n2) {
	struct ParseNumber result;
	int carry = 0;

	result.fractionPart = n1.fractionPart + n2.fractionPart;

	if(100 <= result.fractionPart){
		result.fractionPart -= 100;
		carry = 1;
	}

	result.integerPart = n1.integerPart + n2.integerPart + carry;

	return result;
}


/**
 * multiplyStrNumberByInteger
 * @param quantity
 * @param strNumber
 * @return
 */
char * multiplyStrNumberByInteger(int quantity, char *strNumber) {
	char result[20];
	char *sum = strdup("00.00");
	struct ParseNumber strNumberParse;
	struct ParseNumber sumParse;

	strNumberParse = parsingStrNumber(strNumber, strlen(strNumber));
	sumParse 	   = parsingStrNumber(sum, strlen(sum));

	int i;
	for(i=0; i<quantity; i++) {
		sumParse = sumStrNumbers(sumParse, strNumberParse);
	}

	sprintf(result, "%lu.%.2d", sumParse.integerPart, sumParse.fractionPart);

	return strdup(result);
}