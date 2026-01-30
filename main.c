/*
 * Created by Celso Andre on 26/01/26
 * Super Trunfo - Cadastro de Cartas
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* =========================
   STRUCT
=========================*/
typedef struct {
    char estado;
    char codigo[5];   // A01 + '\0'
    char *cidade;     // string dinamica
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
} Carta;

/* =========================
   FUNÇÃO: LIMPAR BUFFER
=========================*/
void clearBuffer(void) {
    while (getchar() != '\n');
}

/* =========================
   FUNÇÕES AUXILIARES
=========================*/
int readInt(const char *label) {
    int value;

    printf("%s", label);
    if (scanf("%d", &value) != 1) {
        printf("Entrada invalida! Usando 0.\n");
        clearBuffer();
        return 0;
    }

    return value;
}

float readFloat(const char *label) {
    float value;

    printf("%s", label);
    if (scanf("%f", &value) != 1) {
        printf("Entrada invalida! Usando 0.\n");
        clearBuffer();
        return 0.0f;
    }

    return value;
}

/* =========================
   FUNÇÃO: LER STRING DINAMICA (WINDOWS)
=========================*/
char* readString(const char *label) {

    char buffer[1024];
    char *text;

    printf("%s", label);
    clearBuffer();

    fgets(buffer, sizeof(buffer), stdin);

    buffer[strcspn(buffer, "\n")] = '\0';

    text = (char*) malloc(strlen(buffer) + 1);
    strcpy(text, buffer);

    return text;
}

/* =========================
   FUNÇÃO: CADASTRAR CARTA
=========================*/
void cadastrarCarta(Carta *c, int numero) {

    printf("\n=== Cadastro da Carta %d ===\n", numero);

    printf("Estado (A-H): ");
    scanf(" %c", &c->estado);

    printf("Codigo da carta (ex: A01): ");
    scanf("%s", c->codigo);

    c->cidade = readString("Nome da cidade: ");

    c->populacao = readInt("Populacao: ");
    c->area = readFloat("Area (km2): ");
    c->pib = readFloat("PIB (em bilhoes): ");
    c->pontosTuristicos = readInt("Numero de pontos turisticos: ");
}

/* =========================
   FUNÇÃO: IMPRIMIR CARTA
=========================*/
void imprimirCarta(Carta c, int numero) {

    printf("\n===== CARTA %d =====\n", numero);
    printf("Estado: %c\n", c.estado);
    printf("Codigo: %s\n", c.codigo);
    printf("Nome da Cidade: %s\n", c.cidade);
    printf("Populacao: %d\n", c.populacao);
    printf("Area: %.2f km2\n", c.area);
    printf("PIB: %.2f bilhoes de reais\n", c.pib);
    printf("Pontos Turisticos: %d\n", c.pontosTuristicos);
}

/* =========================
   MAIN
=========================*/
int main(void) {

    Carta carta1;
    Carta carta2;

    cadastrarCarta(&carta1, 1);
    cadastrarCarta(&carta2, 2);

    imprimirCarta(carta1, 1);
    imprimirCarta(carta2, 2);

    /* =========================
       LIBERAR MEMÓRIA
    ==========================*/
    free(carta1.cidade);
    free(carta2.cidade);

    return 0;
}
