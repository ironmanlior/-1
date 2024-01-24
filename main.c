#include "NumClass.h"
#include <stdio.h>

int main() {
	int num1, num2;
	printf("enter first number\n");
	scanf("%d", &num1);
	printf("enter second number\n");
	scanf("%d", &num2);
	for (int i = num1; i <= num2; i++) {
		if (isPrime(i) == 1) printf("%d ", i);
	}
	printf("\n");
	for (int i = num1; i <= num2; i++) {
		if (isArmstrong(i) == 1) printf("%d ", i);
	}
	printf("\n");
	for (int i = num1; i <= num2; i++) {
		if (isStrong(i) == 1) printf("%d ", i);
	}
	printf("\n");
	for (int i = num1; i <= num2; i++) {
		if (isPalindrome(i) == 1) printf("%d ", i);
	}
	printf("\n");
	return 0;
}