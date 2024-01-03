#include <stdio.h>
#include <stdlib.h>

struct complexo {
	float real;
	float imag;
};

typedef struct complexo Complexo;

/*
 * Entrada: dois valores do tipo float
 * Saida: um numero complexo composto pelos dois valores
 * Pre-condicao: nao existe
 * Pos-condicao: nao existe
 * Processo: atribui o primeiro valor a parte real e o segundo a parte imaginaria
 */
Complexo criar(float real, float imag){

    Complexo c;

    c.real = real;
    c.imag = imag;

    return c;
}

/*
 * Entrada: dois numeros complexos validos
 * Saida: um numero complexo
 * Pre-condicao: nao existe
 * Pos-condicao: nao existe
 * Processo: soma as partes reais e soma a partes imaginarias
 */
Complexo soma(Complexo c1, Complexo c2){

    Complexo soma;

    soma = criar(c1.real + c2.real, c1.imag + c2.imag);

    return soma;

    // return (criar(c1.real + c2.real, c1.imag + c2.imag));
}

/* versao 1
Complexo soma(Complexo c1, Complexo c2)
{
	Complexo s;

	s.real = c1.real + c2.real;
	s.imag = c1.imag + c2.imag;

	return s;
}
*/

/*
    Entrada: um numero complexo por valor e dois valores float por referencia
    Saida: nao existe
    Pre-condicao: nao existe (poderia dizer que as variaveis float tem que ser declaradas... mas nao precisa dizer)
    Pos-condicao: dois valores float recebe, respectivamente, a parte real e imaginaria do numero complexo
    Processo: atribui as partes do numero as variaveis
 */
void separa(Complexo c, float *real, float *imag)
{
	*real = c.real;
	*imag = c.imag;
}

float get_real(Complexo c)
{
	return c.real;
}

float get_imag(Complexo c)
{
	return c.imag;
}

Complexo multiplica(Complexo c1, Complexo c2)
{}

float modulo(Complexo c)
{}

// FONTE:
// https://brasilescola.uol.com.br/matematica/numeros-complexos.htm

int main()
{
	Complexo c1, c2, c3;
	float aux1, aux2;

	// ler os dois numeros
	// armazenar os dois numeros
	
	printf("Digite a parte real e imaginaria do primeiro numero: \n");
	// leitura de dois numeros float
	scanf("%f %f", &aux1, &aux2);
	// criacao do primeiro numero complexo
	c1 = criar(aux1, aux2);


	printf("Digite a parte real e imaginaria do segundo numero: ");
	// leitura de dois numeros float
	scanf("%f %f", &aux1, &aux2);
	// criacao do segundo numero complexo
	c2 = criar(aux1, aux2);
	
	// soma dos numeros
	c3 = soma(c1, c2);

	// APENAS PARA TESTE:
	//printf("%.2f %.2f\n", c3.real, c3.imag);
	//separa(c3, &aux1, &aux2);
	printf("%.2f %.2fi\n", get_real(c3), get_imag(c3));

	return 0;
}