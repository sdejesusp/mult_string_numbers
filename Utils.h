/**
 * Utils.h
 * Header for the utilities source file.
 */
#ifndef __UTILS_H
#define __UTILS_H

struct ParseNumber {
	unsigned long integerPart;
	int   fractionPart;
};

extern char * multiplyStrNumberByInteger(int quantity, char *strNumber);

#endif