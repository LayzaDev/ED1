/*
Tipo Abstrato de Dados (TAD) Círculo é definido com base no TAD Ponto, representando um círculo no plano cartesiano bidimensional. Possui as seguintes operações:

(a) criar_circulo(ponto_centro, raio): cria um círculo com centro no ponto recebido como parâmetro e raio r, e retorna um ponteiro para o círculo criado.

(b) area(circulo): calcula e retorna a área do círculo recebido como parâmetro.

(c) dentro(ponto, circulo): verifica se o ponto recebido como parâmetro está dentro do círculo recebido como parâmetro, e retorna 1 se sim, e 0 caso contrário.

(d) destruir_circulo(circulo): libera a memória alocada para o círculo recebido como parâmetro.

O TAD Círculo é implementado em C e utiliza o TAD Ponto para armazenar o centro do círculo.

*/

#define PI 3.14

typedef struct circle Circle;

Circle *createCircle(Ponto* centro, float raio);
float area(Circle *circulo);
int dentroDoCirculo(Ponto *ponto, Circle *circulo);
void destruirCirculo(Circle *circulo);

