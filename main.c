#include <stdio.h>

// Função para imprimir o array
void imprimirArray(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Função de busca linear
int buscaLinear(int arr[], int tamanho, int valor) {
    for (int i = 0; i < tamanho; i++) {
        if (arr[i] == valor) {
            return i; // Retorna o índice onde encontrou
        }
    }
    return -1; // Não encontrado
}

// Função de ordenação bubble sort
void bubbleSort(int arr[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Troca os elementos
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Função de busca binária (array precisa estar ordenado)
int buscaBinaria(int arr[], int tamanho, int valor) {
    int inicio = 0;
    int fim = tamanho - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (arr[meio] == valor) {
            return meio;
        } else if (arr[meio] < valor) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    return -1;
}

int main() {
    int numeros[] = {88, 42, 17, 95, 23, 56, 71, 3, 39, 64};
    int tamanho = 10;

    printf("Array original:\n");
    imprimirArray(numeros, tamanho);

    // Buscar 23 usando busca linear
    int indiceLinear = buscaLinear(numeros, tamanho, 23);
    if (indiceLinear != -1) {
        printf("\n23 encontrado na posicao (busca linear): %d\n", indiceLinear);
    } else {
        printf("\n23 nao encontrado (busca linear).\n");
    }

    printf("\nOrdenando array...\n");
    bubbleSort(numeros, tamanho);

    printf("Array ordenado:\n");
    imprimirArray(numeros, tamanho);

    // Buscar 23 usando busca binária
    int indiceBinaria = buscaBinaria(numeros, tamanho, 23);
    if (indiceBinaria != -1) {
        printf("\n23 encontrado na posicao (busca binaria): %d\n", indiceBinaria);
    } else {
        printf("\n23 nao encontrado (busca binaria).\n");
    }

    return 0;
}
