/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file <Add File Name> 
 * @brief <Statistical analytics on a dataset>
 *
 * <Program to find mean,median,maximum and minimum elements of an array and also to sort the array elements from largest to smallest>
 *
 * @author <Abbas Ali>
 * @date <19/07/2020>
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void print_array (unsigned char *p, int l) {
	int i;	
	for (i=0;i<l;i++) {
		printf("%d\t",*p);
		p++;	
	}
	printf("\n");	
}

void print_array_int (int *p, int l) {
	int i;	
	for (i=0;i<l;i++) {
		printf("%d\t",*p);
		p++;	
	}
	printf("\n");	
}

void typecasting(unsigned char test[SIZE], int array[SIZE]) {
    for (int i = 0; i < SIZE; ++i)
        array[i] = test[i];
}

void sort_array(int *p,int l) {
	int i,j,temp;
	for(i=0;i<l;i++) {
		for(j=i+1;j<l;j++) {
			if (*(p+i)<*(p+j)) {
				temp = *(p+i);
				*(p+i) = *(p+j);
				*(p+j) = temp;
			}
		}
	}
}

float find_mean (int *p,int l) {
	int i,sum=0;
	float mean;
	for(i=0;i<l;i++) {
		sum += *p;
		p++;
	}
	mean = sum/l;
	return mean;
}

float find_median (int *p,int l) {
	int i=l/2;
	float median;
	if (i%2 == 0) {
		median = (*(p+i) + *(p+i+1))/2;
	}	
	else {
		median = *(p+i+1);
	}
	return median;
}

int find_maximum(int *p,int l) {
	int i,max=*p;
	for (i=0;i<l;++i) {
		if(*(p+i)>max) {
			max = *(p+i);
		}
	}
	return max;
}

int find_minimum(int *p,int l) {
	int i,min;
	for (i=0;i<l;++i) {
		if(*(p+i)<*p) {
			min = *(p+i);
		}
	}
	return min;
}

void print_statistics(float mean,float median, int max, int min) {
	printf("Mean : %.2f\n",mean);
	printf("Median : %.2f\n",median);
	printf("Maximum : %d\n",max);
	printf("Minimum : %d\n",min);
}

void main() {
  
  unsigned char test[SIZE] = {34,201,190,154,8,194,2,6,114,88,45,76,123,87,25,23,200,122,150,90,92,87,177,244,201,6,12,60,8,2,5,67,7,87,250,230,99,3,100,90};



  /* Other Variable Declarations Go Here */
int array[SIZE] = {};
float mean,median;
int maximum,minimum;
  /* Statistics and Printing Functions Go Here */
print_array(test, SIZE);
typecasting(test,array);
sort_array(array,SIZE);
print_array_int(array,SIZE);
mean = find_mean(array,SIZE);
median = find_median(array,SIZE);
maximum = find_maximum(array,SIZE);
minimum = find_minimum(array,SIZE);
print_statistics(mean,median,maximum,minimum);
}

/* Add other Implementation File Code Here */


