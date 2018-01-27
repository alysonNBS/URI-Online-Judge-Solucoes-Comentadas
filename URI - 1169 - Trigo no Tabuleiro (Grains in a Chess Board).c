/*
* By @alysonNBS
* Problema 1169 do site www.urionlinejudge.com.br
* Link do problema (em inglês): https://www.urionlinejudge.com.br/judge/en/problems/view/1169
*/

/* AVISO IMPORTANTE ***** AVISO IMPORTANTE ***** AVISO IMPORTANTE ***** AVISO IMPORTANTE ***** AVISO IMPORTANTE ***** AVISO IMPORTANTE ***** AVISO IMPORTANTE 
* 
* Este código está sendo compartilhado para estudos. Assim sendo, é terminantemente proibido o uso e reprodução deste para fins que não estejam relacionados ao mesmo ou sem permição do autor.
*
* REPRODUÇÃO DE TRECHO DOS TERMOS & CONDIÇÕES DA URI RELACIONADOS AO COMPARTILHAMENTO DE CÓDIGOS
*
* COMPARTILHAMENTO DE CÓDIGOS-FONTE
* Usuários podem compartilhar suas soluções (códigos-fonte) em repositórios públicos (como GitHub, BitBucket ou semelhantes) e sites pessoais de acordo com sua vontade. Todavia, fica proibido o uso destes por parte de terceiros como forma de obter qualquer tipo de vantagem dentro do URI Online Judge. Os usuários que porventura façam uso desta prática podem ter suas contas desativadas sem aviso prévio.
*/

/* Comentários da solução:
*
* Resolução do problema matemático:
*
* No primeiro quadrado do tabuleiro, vai haver apenas um grão de trigo, no segundo dois, no terceiro quatro e assim segue.
* Logo o tabuleiro tem 1 + 2 + 4 + ... graos de trigo. Perceba que isso corresponde a soma de potências de dois.
*
* 2^0 + 2^1 + 2^2 + 2^3 + ...
*
* Já calculada a quantidade de graos de trigo, é nescessário converter isso em Kgs, segue equação
* 
* 1 Kg = 1000 g = 1000 * 12 graos = 12000 graos
*
* Aplicação ao código:
*
* Assim como enunciado no problema, é necessário uma variável de 64 bits sem ponto flutuante para guardar o valor alto.
* Além disso, essa variavel deve ter memória reservada somente para inteiros não negativos (unsigned = sem sinal).
*
* Afim de otimizar o tempo, para cada conjunto de testes,
* Será calculado o valor de trigo para todas as casas do tabuleiro até o maior valor existente na entrada.
*
* Depois, basta imprimir os valor pedido em cada caso.
*/

#include <stdio.h>

#define UNIDADE_KG_GRAO 12000 // 1 Kg = 1000 g = 1000 * 12 graos = 12000 graos

// Definição do tipo de variável: inteiro de 64 bits não negativo
typedef unsigned long long int ulli;

void calculadora(int x);

ulli potencia_de_2[64], graos_trigo[64], trigo_kgs[64];
int i; // variável para for

int main(void)
{
    int n, x[100], maior_x = 0;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &x[i]);

        // atualiza o valor de maior_x para a entrada atual se for necessário
        (x[i] > maior_x) ? maior_x = x[i] : 0 ;
    }


    calculadora(maior_x);


    for(i = 0; i < n; i++)
        printf("%lli kg\n", trigo_kgs[ (x[i] - 1) ]);

    return 0;
}


// Realiza todos os cálculos
void calculadora_de_trigo(int x)
{
    graos_trigo[0] = potencia_de_2[0] = 1;
    trigo_kgs[0] = graos_trigo[0] / UNIDADE_KG_GRAO;

    for(i = 1; i < x; i++)
    {
        potencia_de_2[i] = 2*potencia_de_2[i-1];
        graos_trigo[i] = graos_trigo[i-1] + potencia_de_2[i];
        trigo_kgs[i] = graos_trigo[i] / UNIDADE_KG_GRAO;
    }
}