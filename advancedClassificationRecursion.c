#include "NumClass.h"
#include <stdio.h>

int power(int, int);

int power(int x, int n) {
	if (n == 0) return 1;
	if (n == 1) return x;
	return x * power(x, n - 1);
}

int len(int num) {
	if (num == 0) return 0;
	return len(num / 10) + 1;
}

int armStrong(int num, int length) {
	if (num == 0) return 0;
	return armStrong(num / 10, length) + power(num % 10, length);
}

int reverse(int num, int h) {
	if (h == 0) return 0;
	int reversed = reverse(num / 10, h - 1);
	reversed += (num % 10) * power(10, h - 1);
	return reversed;
}

/* will return if a number is Armstrong number
An Armstrong number is an n-digit number that is equal to the sum of the nth powers of its digits.
For Example: 407 = 4^3 + 0^3 + 7^3 = 64 + 0 + 343 = 407
*/
int isArmstrong(int num) {
	return (num == armStrong(num, len(num))) ? 1 : 0;
}
/* will return if a number is a palindrome */
int isPalindrome(int num) {
	return (num == reverse(num, len(num))) ? 1 : 0;
}