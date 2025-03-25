#include <stdio.h>
#include <string.h>

#define NUMEROS_ATRIBUTOS 4

typedef struct {
    char nome[50];
    int populacao;
    float area;
    int pib;
    float densidade_demografica;
} Pais;

void exibirAtributos() {
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Densidade Demográfica\n");
}

int escolherAtributo(int atributoUsado) {
    int escolha;
    do {
        printf("Escolha um atributo: ");
        scanf("%d", &escolha);
        if (escolha < 1 || escolha > NUMEROS_ATRIBUTOS || escolha == atributoUsado) {
            printf("Opção inválida ou já escolhida! Tente novamente.\n");
        }
    } while (escolha < 1 || escolha > NUMEROS_ATRIBUTOS || escolha == atributoUsado);
    return escolha;
}

float obterValorAtributo(Pais p, int atributo) {
    switch (atributo) {
        case 1: return p.populacao;
        case 2: return p.area;
        case 3: return p.pib;
        case 4: return p.densidade_demografica;
        default: return 0;
    }
}

void compararCartas(Pais p1, Pais p2, int atributo1, int atributo2) {
    float valor1_p1 = obterValorAtributo(p1, atributo1);
    float valor1_p2 = obterValorAtributo(p2, atributo1);
    float valor2_p1 = obterValorAtributo(p1, atributo2);
    float valor2_p2 = obterValorAtributo(p2, atributo2);

    int vitoria1 = (atributo1 == 4) ? (valor1_p1 < valor1_p2) : (valor1_p1 > valor1_p2);
    int vitoria2 = (atributo2 == 4) ? (valor2_p1 < valor2_p2) : (valor2_p1 > valor2_p2);

    float soma_p1 = valor1_p1 + valor2_p1;
    float soma_p2 = valor1_p2 + valor2_p2;

    printf("\nResultados da Comparação:\n");
    printf("%s: %.2f + %.2f = %.2f\n", p1.nome, valor1_p1, valor2_p1, soma_p1);
    printf("%s: %.2f + %.2f = %.2f\n", p2.nome, valor1_p2, valor2_p2, soma_p2);

    if (soma_p1 > soma_p2) {
        printf("Vencedor: %s!\n", p1.nome);
    } else if (soma_p1 < soma_p2) {
        printf("Vencedor: %s!\n", p2.nome);
    } else {
        printf("Empate!\n");
    }
}

int main() {
    // Cartas pré-definidas
    Pais carta1 = {"Caucaia", 214000000, 8515767, 1600000, 25.1};
    Pais carta2 = {"Fortaleza", 331000000, 9834000, 22675000, 33.7};

    printf("Bem-vindo ao Super Trunfo!\n");

    printf("Escolha dois atributos para a comparação:\n");
    exibirAtributos();
    int atributo1 = escolherAtributo(0);
    exibirAtributos();
    int atributo2 = escolherAtributo(atributo1);

    compararCartas(carta1, carta2, atributo1, atributo2);
    
    return 0;
}
