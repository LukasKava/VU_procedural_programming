#include <stdio.h>
#include <math.h>

int main(void) {
	double x = 2.64, y = 5.5, z = 10.12903;

	//Take Users input %lf = double for scanf()
	//printf("Put in variable x as a double: ");
	//scanf("%lf", &x);

	//printf("Put in variable y as a double: ");
	//scanf("%lf", &y);

	//printf("Put in variable z as a double: ");
	//scanf("%lf", &z);

	printf("Answer for x + 4y + z ^ 3: %f\n", x + (4 * y) + pow(z, 3));
	printf("Answer for (x + √y)(z^4 - |z| + 46.3): %f\n", (x + sqrt(y)) * (pow(z, 4) - fabs(z) + 46.3));
	return (0);
}