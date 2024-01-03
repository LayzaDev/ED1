typedef struct ponto Ponto;

Ponto *createPonto(float x, float y);
void destroyPonto(Ponto *p);
float acessarX(Ponto *p);
float acessarY(Ponto *p);
float distancia(Ponto *p1, Ponto *p2);
