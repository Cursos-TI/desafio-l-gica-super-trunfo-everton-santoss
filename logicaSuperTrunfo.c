#include <stdio.h>

typedef struct {
    char estado[50];
    char codigo[10];
    char nome[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
    float super_poder;
} Carta;

void calcular_atributos(Carta *carta) {
    carta->densidade_populacional = carta->populacao / carta->area;
    carta->pib_per_capita = carta->pib / carta->populacao;
    carta->super_poder = carta->populacao + carta->area + carta->pib +
                         carta->pontos_turisticos + carta->pib_per_capita + (1 / carta->densidade_populacional);
}

void ler_carta(Carta *carta) {
    printf("Digite o estado: ");
    scanf(" %[^\n]", carta->estado);
    printf("Digite o codigo: ");
    scanf(" %s", carta->codigo);
    printf("Digite o nome: ");
    scanf(" %[^\n]", carta->nome);
    printf("Digite a populacao: ");
    scanf(" %lu", &carta->populacao);
    printf("Digite a area: ");
    scanf(" %f", &carta->area);
    printf("Digite o PIB: ");
    scanf(" %f", &carta->pib);
    printf("Digite o numero de pontos turisticos: ");
    scanf(" %d", &carta->pontos_turisticos);
    
    calcular_atributos(carta);
}

void comparar(Carta c1, Carta c2) {
    int opcao;
    printf("\nEscolha o atributo para comparar:\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - Densidade Populacional (menor vence)\n");
    printf("Escolha: ");
    scanf(" %d", &opcao);

    printf("\nComparacao de Cartas:\n");
    printf("%s vs %s\n", c1.nome, c2.nome);

    switch(opcao) {
        case 1:
            printf("Populacao: %lu vs %lu\n", c1.populacao, c2.populacao);
            printf("Vencedor: %s\n", c1.populacao > c2.populacao ? c1.nome : (c1.populacao < c2.populacao ? c2.nome : "Empate!"));
            break;
        case 2:
            printf("Area: %.2f vs %.2f\n", c1.area, c2.area);
            printf("Vencedor: %s\n", c1.area > c2.area ? c1.nome : (c1.area < c2.area ? c2.nome : "Empate!"));
            break;
        case 3:
            printf("PIB: %.2f vs %.2f\n", c1.pib, c2.pib);
            printf("Vencedor: %s\n", c1.pib > c2.pib ? c1.nome : (c1.pib < c2.pib ? c2.nome : "Empate!"));
            break;
        case 4:
            printf("Pontos Turisticos: %d vs %d\n", c1.pontos_turisticos, c2.pontos_turisticos);
            printf("Vencedor: %s\n", c1.pontos_turisticos > c2.pontos_turisticos ? c1.nome : (c1.pontos_turisticos < c2.pontos_turisticos ? c2.nome : "Empate!"));
            break;
        case 5:
            printf("Densidade Populacional: %.2f vs %.2f\n", c1.densidade_populacional, c2.densidade_populacional);
            printf("Vencedor: %s\n", c1.densidade_populacional < c2.densidade_populacional ? c1.nome : (c1.densidade_populacional > c2.densidade_populacional ? c2.nome : "Empate!"));
            break;
        default:
            printf("Opcao invalida!\n");
    }
}

int main() {
    Carta carta1, carta2;
    
    printf("Cadastro da Carta 1:\n");
    ler_carta(&carta1);
    
    printf("\nCadastro da Carta 2:\n");
    ler_carta(&carta2);
    
    comparar(carta1, carta2);
    
    return 0;
}
