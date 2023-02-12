#include <stdio.h>

void printSalesReport(double* data, char** months) {
	printf("Monthly sales report for 2022:\n");
	printf("%-15sSales\n", "Month");
	for (int i = 0; i < 12; i++) {
		printf("%-15s$%.2lf\n", months[i], data[i]);
	}
	
	
}

void printSalesSummary(double* data) {
	double min = data[0];
	double max = data[0];
	double sum = 0;
	double avg;
	for (int i = 1; i < 12; i++) {
		if (data[i] < min) {
			min = data[i];
		}	
	}
	for (int i = 1; i < 12; i++) {
		if (data[i] > max) {
			max = data[i];
		}	
	}
	for (int i = 0; i < 12; i++) {
		sum += data[i]; 
	}
	avg = sum/12;
	printf("Sales Summary:\n");
	printf("Minimum Sales:     $%.2lf\n", min);
	printf("Maximum Sales:     $%.2lf\n", max);
	printf("Average Sales:     $%.2lf\n", avg);
}

void printMovingAverage(double *data, char **months) {
	double sum;
	double avg;
	printf("6 Month Moving Average:\n");
	for (int i = 0; i < 7; i++) {
		sum = 0;
		for (int j = 0; j < 6; j++) {
			sum += data[i+j];	
		}
		avg = sum/6;
		printf("%-10s-  %-15s$%.2lf\n", months[i], months[i+5], avg);
	}
}

void printHighToLow(double *data, char **months) {
	printf("Sales Report (Highest to Lowest):\n");
	printf("%-15sSales\n", "Month");
	double lastMax;
	int maxIndex = 0;
	double max = 0.0;
	for (int i = 0; i < 12; i++) {
		if (max < data[i]) {
			max = data[i];
			maxIndex = i;
		}
	}
	printf("%-15s$%.2lf\n", months[maxIndex], max);
	for (int j = 1; j < 12; j++) {
		lastMax = max;
		maxIndex = 0;
		max = 0.0;
		for (int i = 0; i < 12; i++) {
			if (max < data[i] && data[i] < lastMax) {
				max = data[i];
				maxIndex = i;
			}
		}
		printf("%-15s$%.2lf\n", months[maxIndex], max);
	}
}

int main() {
	char* months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	FILE* fp = fopen("input.txt", "r");
	double nums[12];
	for (int i = 0; i < 12; i++)
		fscanf(fp, "%lf", &nums[i]);
	fclose(fp);
	
	printSalesReport(nums, months);
	printf("\n\n");
	printSalesSummary(nums);
	printf("\n\n");
	printMovingAverage(nums, months);
	printf("\n\n");
	printHighToLow(nums, months);

	
	

	return 0;
}
