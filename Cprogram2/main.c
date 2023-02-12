#include <stdio.h>

int hasSmallerCombination(int* combination, int index) {
	for (int i = index+1; i < 5; i++) {
		if (combination[i] > 0) {
			return 1;
		}
	}
	return 0;
}

void printCombinations(const int* points, int score) {
	int total = 0;
	int combination[5] = {0,0,0,0,0};
	do {
		for (int i = 0; i < 5; i++) {
			if (!hasSmallerCombination(combination, i)) {
				if (combination[i] > 0) {
					total -= points[i];
					combination[i] -= 1;
				} else {
					while (1) {
						total += points[i];
						combination[i] += 1;
						if (total >= score) {
							if (total == score) {
								printf("%d TD + 2pt, ", combination[0]);
								printf("%d TD + FG, ", combination[1]);
								printf("%d TD, ", combination[2]);
								printf("%d FG, ", combination[3]);
								printf("%d Safety\n", combination[4]);
							}
							total -= points[i];
							combination[i] -= 1;
							break;
						}
					}
				}
			}
		}
	} while (total > 0);
}

int main() {
	const int points[5] = {8, 7, 6, 3, 2};
	while (1) {
		int num;
		printf("Enter 0 or 1 to STOP\n");
		printf("Enter the NFL score: ");
		scanf("%d", &num);
		if (num > 1) {
			printCombinations(points, num);
		} else {
			if (num == 0 || num == 1) {
				break;
			}
			else {
				printf("Invalid Input!\n");
			}
		}
	}
	return 0;
}
