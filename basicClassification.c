#include "NumClass.h"

int isPrime(int num) {
	if (num == 0 || num == 1) return 0;
  	for (int i = 2; i <= num / 2; ++i)
		if (num % i == 0) return 0;
	return 1;
}

/*Strong number is a special number whose sum of the factorial of digits is equal to the original
number. For Example: 145 is strong number
1! + 4! + 5! = 145
*/
int factorial(int num) {
	if (num == 0 || num == 1) return 1;
	return num * factorial(num - 1);
}

int isStrong(int num) {
	int n = num, sum = 0;
	while (n != 0) {
		sum += factorial(n % 10);
		n /= 10;
	}
	return (num == sum) ? 1 : 0;
}