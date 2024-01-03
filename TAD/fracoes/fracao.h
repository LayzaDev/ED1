typedef struct {

    int num, den;

}fracao_t;

fracao_t *create(int num, int den);

void print(fracao_t *f);

void destroy(fracao_t *f);

fracao_t *sum(fracao_t *F1, fracao_t *F2);