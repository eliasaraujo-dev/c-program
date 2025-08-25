```c++
#include <iostream>
using namespace std;

/**
 * Classe Utilitario: Fornece funcionalidades para manipulação de vetores
 * Esta classe encapsula operações úteis que podem ser realizadas em um array de números
 */
class Utilitario {
private: 
    int* vetor;     // Ponteiro para o array de números
    int tamanho;    // Tamanho do array

public: 
    /**
     * Construtor da classe
     * @param vet: Ponteiro para o array de números
     * @param tam: Tamanho do array
     */
    Utilitario(int* vet, int tam) {
        vetor = vet;
        tamanho = tam;
    }

    /**
     * Método para encontrar o maior número no array
     * @return O maior número encontrado no array
     */
    int encontrarMaiorNumero() {
        // Inicializa assumindo que o primeiro elemento é o maior
        int maior = vetor[0];
        
        // Percorre o array comparando cada elemento com o maior atual
        for (int i = 1; i < tamanho; i++) {
            if (vetor[i] > maior) {
                maior = vetor[i];
            }
        }
        return maior;
    }

    /**
     * Método para exibir todos os elementos do array
     */
    void mostrarArray() {
        cout << "Elementos do array: ";
        for (int i = 0; i < tamanho; i++) {
            cout << vetor[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    // Inicialização do array de teste
    int numeros[] = {5, 7, 9, 10};
    
    // Calcula o tamanho do array automaticamente
    int tam = end(numeros) - begin(numeros);

    // Cria um objeto da classe Utilitario
    Utilitario objUtil(numeros, tam);

    // Mostra o conteúdo do array
    cout << "\nA Lista de números é:" << endl;
    objUtil.mostrarArray();

    // Encontra e mostra o maior número
    int maximo = objUtil.encontrarMaiorNumero();
    cout << "O maior número é: " << maximo << endl;

    return 0;
}
