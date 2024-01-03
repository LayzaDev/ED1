10. Na notação pós-fixa (ou notação polonesa reversa), os números sempre ficam à esquerda 
e a operação a ser realizada à direita. Mostre o passo a passo de uma pilha
após as operações de empilha e desempilha necessárias para resolver as expressões
pós-fixas mostradas a seguir.

Notação Infixa                                      Notação Pós-fixa

(51 + 13 ∗ 12)                                      51 13 12 ∗ +
(5 ∗ (3 + 2)/4 − 6)                                 5 3 2 + ∗4/6−
(5 + 3 + 2 ∗ 4 − 6 ∗ 7 ∗ 1)                         5 3 + 2 4 ∗ +6 7∗ 1 ∗ −
(5 ∗ (3 + (2 ∗ (4 + (6 ∗ (7 + 1))))))               5 3 2 4 6 7 1 + ∗ + ∗ + ∗


### PASSO A PASSO

1. Leia a expressão da esquerda para a direita(padrão)

2. Se o valor lido for um numero, empilhe-o

3. Se o valor lido for um operador(por exemplo: +): então:

    - Desempilhe um valor e guarde-o na variavel Y

    - Desempilhe um valor e guarde-o na veriavel X

    - Empilhe o resultado de X + Y
    
    - Continue lendo a expressão e volte ao passo 2

### notação 01

51 13 12 ∗ +
------------------
push(p, 51);

p[51];

i++;
------------------
push(p, 13);

p[51, 13];

i++;
------------------
push(p, 12);

p[51, 13, 12];

i++;
------------------
expressão == '*'

n1 = pop(p, 12);
n2 = pop(p, 13);

resultado = n1 * n2
resultado = 156

push(p, resultado);

p[51, 156];

i++;
------------------
expressão == '+'

n1 = pop(p, x);
n2 = pop(p, x);

resultado = n1 + n2
resultado = 207

push(p, resultado);

p[207];
------------------
resultadoFinal = pop(p, x);

