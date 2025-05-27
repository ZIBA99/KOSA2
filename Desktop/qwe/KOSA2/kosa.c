#include <stdio.h>

int main() {
	int a, b, c;
	printf("Enter three integers: ");
	scanf("%d %d %d", &a, &b, &c);

	if (a == b && b == c) {
		printf("All three numbers are equal.\n");
	}
	else if (a == b || b == c || a == c) {
		printf("Two numbers are equal.\n");
	}
	else {
		printf("All three numbers are different.\n");
	}

	return 0;
}
