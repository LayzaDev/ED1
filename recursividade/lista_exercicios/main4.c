#include<stdio.h>
#include<math.h>

#define TOL 0.0001  // nivel de tolerancia (precisao)

float raizRec(float start, float end, float n)
{

	// Verifica se o intervalo ainda eh valido
	if (start <= end) {

		// Encontra o valor medio
		float mid = (start + end) / 2;

		// Caso base
		if ((mid * mid - n < TOL) && ((mid + 1) * (mid + 1) > n)) {
			return mid;
		}

		// Verifica para "que lado" a busca deve ir
		else if (mid * mid < n) {
			return raizRec(mid + 1, end, n);
		}
		else {
			return raizRec(start, mid - 1, n);
		}
	}
	return start;
}

float raiz(float n)
{
    return raizRec(0, n, n);
}

// Curiosidade:
// Esse eh o Algoritmo Babilonico, um dos algoritmos mais antigos que se conhece
// Tambem conhecido como Metodo de Heron
float heron(float n)
{
    // Usamos n como uma aproximacao de sua propria raiz
    float x = n;
    float y = 1;

    while (x - y > TOL) {
        x = (x + y) / 2;
        y = n / x;
    }

    return x;
}

int main()
{
	float n;

    printf("Digite um numero: ");
    scanf("%f", &n);

    printf("A raiz (recursiva) de %.2f eh:  %.2f\n", n, raiz(n));
    printf("A raiz (babilonico) de %.2f eh:  %.2f\n", n, heron(n));
    printf("A raiz (sqrt) de %.2f eh:  %.2f\n", n, sqrt(n));

	return 0;
}
