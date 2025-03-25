#include <stdio.h>
#include <string.h>

typedef struct {
    char estado[50];
    char codigo[10];
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
} Carta;

void calcular_metricas(Carta *carta) {
    carta->densidade_populacional = carta->populacao / carta->area;
    carta->pib_per_capita = carta->pib / carta->populacao;
}


void comparar_cartas(Carta carta1, Carta carta2) {
    
    char atributo_escolhido[] = "PIB";

    float valor1, valor2;

    if (strcmp(atributo_escolhido, "População") == 0) {
        valor1 = carta1.populacao;
        valor2 = carta2.populacao;
    } else if (strcmp(atributo_escolhido, "Área") == 0) {
        valor1 = carta1.area;
        valor2 = carta2.area;
    } else if (strcmp(atributo_escolhido, "PIB") == 0) {
        valor1 = carta1.pib;
        valor2 = carta2.pib;
    } else if (strcmp(atributo_escolhido, "Densidade Populacional") == 0) {
        valor1 = carta1.densidade_populacional;
        valor2 = carta2.densidade_populacional;
    } else if (strcmp(atributo_escolhido, "PIB per capita") == 0) {
        valor1 = carta1.pib_per_capita;
        valor2 = carta2.pib_per_capita;
    } else {
        printf("Atributo inválido!\n");
        return;
    }

    if (strcmp(atributo_escolhido, "Densidade Populacional") == 0) {
        
        if (valor1 < valor2) {
            printf("Carta 1 (%s) venceu com menor densidade populacional: %.2f hab/km² vs %.2f hab/km²\n",
                   carta1.cidade, valor1, valor2);
        } else if (valor1 > valor2) {
            printf("Carta 2 (%s) venceu com menor densidade populacional: %.2f hab/km² vs %.2f hab/km²\n",
                   carta2.cidade, valor2, valor1);
        } else {
            printf("Empate! Ambas as cartas têm a mesma densidade populacional: %.2f hab/km²\n", valor1);
        }
    } else {
        
        if (valor1 > valor2) {
            printf("Carta 1 (%s) venceu com maior %s: %.2f vs %.2f\n",
                   carta1.cidade, atributo_escolhido, valor1, valor2);
        } else if (valor1 < valor2) {
            printf("Carta 2 (%s) venceu com maior %s: %.2f vs %.2f\n",
                   carta2.cidade, atributo_escolhido, valor2, valor1);
        } else {
            printf("Empate! Ambas as cartas têm o mesmo %s: %.2f\n", atributo_escolhido, valor1);
        }
    }
}

int main() {
    
    Carta carta1 = {"Caucaia", "CE001", "Caucaia", 12325232, 1521.11, 678.9, 300};
    Carta carta2 = {"Fortaleza", "CE002", "Fortaleza", 6747815, 1200.27, 450.5, 250};

    
    calcular_metricas(&carta1);
    calcular_metricas(&carta2);

   
    printf("Carta 1 - Densidade Populacional: %.2f hab/km², PIB per capita: %.2f\n",
           carta1.densidade_populacional, carta1.pib_per_capita);
    printf("Carta 2 - Densidade Populacional: %.2f hab/km², PIB per capita: %.2f\n",
           carta2.densidade_populacional, carta2.pib_per_capita);

    comparar_cartas(carta1, carta2);

    return 0;

}