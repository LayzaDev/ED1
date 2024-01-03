/*
Tipo Abstrato de Dados (TAD) Ponto em R^2 representa um ponto no plano cartesiano bidimensional. 
Possui as seguintes operações:
*/

typedef struct ponto ponto_t;

ponto_t *criar(float x, float y);
void destruir(ponto_t *p);
float acessarX(ponto_t *p);
float acessarY(ponto_t *p);
float distancia(ponto_t *p1, ponto_t *p2);