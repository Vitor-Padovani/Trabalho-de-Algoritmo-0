#include <stdio.h>
#include <math.h>

int isTriangle(float* t) { // Verifica se as medidas formam um triângulo

	if (! (t[0] < (t[1] + t[2]))) {
		return 0;

	} else if (! (t[1] < (t[2] + t[0]))) {
		return 0;

	} else if (! (t[2] < (t[0] + t[1]))) {
		return 0;
		
	} else {
		return 1;
	}
}

float areaOfTriangle(float* t) { // Calcula a área do triângulo
	float s = (t[0] + t[1] + t[2]) / 2;

	return sqrtf(s * (s - t[0]) * (s - t[1]) * (s - t[2]));
}

char* triangleType(float* t) { // Calcula o tipo do triângulo
	float aux;

	if (t[1] > t[2]) { // Coloca a maior medida na primeira posição
		if (t[1] > t[0]) {
			aux = t[1];
			t[1] = t[0];
			t[0] = aux;
		}
	} else {
		if (t[2] > t[0]) {
			aux = t[2];
			t[2] = t[0];
			t[0] = aux;
		}
	}

	if ((t[0]*t[0]) > (t[1]*t[1] + t[2]*t[2])) {
		return "Obtusangulo";

	} else if ((t[0]*t[0]) < (t[1]*t[1] + t[2]*t[2])) {
		return "Acutangulo";

	} else {
		return "Retangulo";
	}
	return "Calvo";
}

void line(int x) { // Faz uma linha
	for (int i = 0; i < x; i++) (i % 2 == 0) ? printf("-") : printf("="); printf("\n");
}

int main() {
    float triangle[] = {-1, -1, -1};

    printf("\nDigite as medidas dos lados do triangulo: \n");
    while ((triangle[0] < 0) || (triangle[1] < 0) || (triangle[2] < 0)) { // Só aceita valores positivos
    	line(20);
    	printf("(valores positivos) \n");

    	printf("Lado A: ");
    	scanf(" %f", &triangle[0]);
    	printf("Lado B: ");
    	scanf(" %f", &triangle[1]);
    	printf("Lado C: ");
    	scanf(" %f", &triangle[2]);
    }

	line(27);
    if (isTriangle(triangle)) {
    	printf("O triangulo de lados: \n");
    	printf("{%.2f, %.2f, %.2f} \n", triangle[0], triangle[1], triangle[2]);
    	
    	printf("Tem %f de area \n", areaOfTriangle(triangle));
    	printf("E eh do tipo: %s \n", triangleType(triangle));

    } else {
    	printf("Nao eh triangulo :( \n");
    }
    line(27);
}
