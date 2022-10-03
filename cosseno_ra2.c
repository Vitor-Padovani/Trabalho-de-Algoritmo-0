#include <stdio.h>
#include <math.h>

#define PRECISION 0.001
#define PI 3.1415926535

int factorial(int x) { // Calcula o fatorial
	int i = x-1;

	while (i > 1) {
		x *= i;
		i--;
	}
	return x;
}

double power(float base, int exponent) { // Calcula a potência
	double powered = 1;

	for (int i = 0; i < exponent; i++) {
		powered *= base;
	}
	return powered;
}

double difference(double x, double y) { // Retorna a diferença absoluta
	if (x > y) {
		return x - y;

	} else {
		return y - x;
	}
}

double remainderOfFloatDivision(double x, double y) { // Calcula resto da divisão para float
	while (x > y) {
		x -= y;
	}
	return x;
}

void line(int x) { // Faz uma linha
	for (int i = 0; i < x; i++) (i % 2 == 0) ? printf("-") : printf("="); printf("\n");
}

int main() {
	float x, num;
	double cosine = 1;

	int sign = -1;
	int evens = 2;
	int terms = 0;

	printf("Digite um valor para calcular o cosseno: \n");
	printf("(em radianos) ");
	scanf(" %f", &num);

	x = remainderOfFloatDivision(num, PI);

	while (difference(cosine, cos(x)) > PRECISION) {
		cosine += sign * (power(x, evens) / factorial(evens));

		sign *= -1;
		evens += 2;
		terms += 1;
	}

	line(27);
	printf("Apos %d termos da expressao... \n", terms);
	printf("O cosseno de %f radianos \n", num);
	printf("Eh aproximadamente %f \n", cosine);
	line(27);
	
	return 0;
}
