#include "NumClass.h"

int power(int x, int n) {
	int result = 1;
	for (int i = 0; i < n; i++) {
		result *= x;
	}
	return result;
}

int reverse(int num) {
	int reversed = 0;
	while (num != 0) {
		reversed *= 10;
		reversed += num % 10;
		num /= 10;
	}
	return reversed;
}

/* will return if a number is Armstrong number
An Armstrong number is an n-digit number that is equal to the sum of the nth powers of its digits.
For Example: 407 = 43 + 03 + 73 = 64 + 0 + 343 = 407
*/



int isArmstrong(int num) {
	int sum = 0, count  = 0, n = num;
	while (n != 0) {
		count++;
		n /= 10;
	}
	n = num;
	while (n != 0) {
		sum += power(n % 10, count);
		n /= 10;
	}
	return (num == sum) ? 1 : 0;
}
/* will return if a number is a palindrome */
int isPalindrome(int num) {
	return (num == reverse(num)) ? 1 : 0;
}