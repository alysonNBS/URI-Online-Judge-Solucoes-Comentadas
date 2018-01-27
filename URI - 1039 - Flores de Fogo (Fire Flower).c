/*
* By @alysonNBS
* Problema 1039 do site www.urionlinejudge.com.br
* Link do problema (em inglês): https://www.urionlinejudge.com.br/judge/en/problems/view/1039
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
* Idéia para resolver o problema:
*
* Para cada entrada, armazena os dados em estruturas de circuferencias e realiza o seguinte teste:
*
* (Distância_entre_centros) <= (Raio_Homem - Raio_Flor)
*
* Quando verdadeiro, deve imprimir "RICO". Caso seja falso, deve imprimir "MORTO".
*
* OBS. 1: afim de evitar uso de raiz quadrada para calcular a distância entre os centros da circuferencia, o caso de teste foi quebrado em dois casos de teste no código:
* caso 1: Raio_Homem >= Raio_Flor e caso 2: Distância_quadrada_entre_centros <= (Raio_Homem - Raio_Flor)*(Raio_Homem - Raio_Flor)
*
* OBS. 2: poderia ter sido incluido a biblioteca <math.h> para utilizar a ideia proposta na solução.
*/

#include <stdio.h>

typedef struct 
{
	int *x, *y;
} ponto;

typedef struct 
{
	ponto centro;
	int *raio;
} circuferencia;

int distancia_quadrada( ponto *p1, ponto *p2 );

int main(void)
{
	int r1, x1, y1, r2, x2, y2;
	circuferencia homem, flor;

	// o bloco será repetido enquanto o input não estiver vazio, ou seja, enquanto a função scanf não retorna EOF (End Of File)
	while( scanf("%d %d %d %d %d %d", &r1, &x1, &y1, &r2, &x2, &y2) != EOF )
	{
		homem.raio = &r1;
		homem.centro.x = &x1;
		homem.centro.y = &y1;
		flor.raio = &r2;
		flor.centro.x = &x2;
		flor.centro.y = &y2;


		if ( (*homem.raio >= *flor.raio) &&
			 (distancia_quadrada( &homem.centro, &flor.centro ) <= (*homem.raio - *flor.raio) * (*homem.raio - *flor.raio) ) )
			printf("RICO\n");
		else
			printf("MORTO\n");
	}

	return 0;
}

int distancia_quadrada( ponto *p1, ponto *p2 )
{
	// Equação da distância entre pontos d^2 = (x0 - x1)^2 + (y0 - y1)^2
	return (*p1->x - *p2->x) * (*p1->x - *p2->x) + (*p1->y - *p2->y) * (*p1->y - *p2->y);
}