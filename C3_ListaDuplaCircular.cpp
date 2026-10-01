#include <iostream>
using namespace std;

// ============================================================
// C.3 - Lista Circular Duplamente Encadeada
//   - Inserir elementos
//   - Retirar elementos
// ============================================================

typedef struct Reg {
    int info;
    Reg *ant;
    Reg *prox;
} No;

class ListaCircularDupla {
private:
    No *inicio;
    int tamanho;

public:
    ListaCircularDupla() {
        inicio = NULL;
        tamanho = 0;
    }

    bool ListaVazia() {
        return inicio == NULL;
    }

    // Inserir elemento (insere no final, mantendo a circularidade)
    void Inserir(int valor) {
        No *novo = new No;
        novo->info = valor;

        if (ListaVazia()) {
            novo->prox = novo;
            novo->ant = novo;
            inicio = novo;
        } else {
            No *ultimo = inicio->ant;
            novo->prox = inicio;
            novo->ant = ultimo;
            ultimo->prox = novo;
            inicio->ant = novo;
        }
        tamanho++;
        cout << "Elemento " << valor << " inserido na lista circular." << endl;
    }

    // Retirar elemento pelo valor
    bool Retirar(int valor) {
        if (ListaVazia()) {
            cout << "Lista vazia! Nao ha elementos para retirar." << endl;
            return false;
        }

        No *atual = inicio;
        do {
            if (atual->info == valor) {
                if (tamanho == 1) {
                    inicio = NULL;
                } else {
                    atual->ant->prox = atual->prox;
                    atual->prox->ant = atual->ant;
                    if (atual == inicio)
                        inicio = atual->prox;
                }
                delete atual;
                tamanho--;
                cout << "Elemento " << valor << " removido." << endl;
                return true;
            }
            atual = atual->prox;
        } while (atual != inicio);

        cout << "Elemento " << valor << " nao encontrado." << endl;
        return false;
    }

    void Imprimir() {
        if (ListaVazia()) {
            cout << "Lista vazia!" << endl;
            return;
        }
        No *atual = inicio;
        cout << "Conteudo da lista circular: ";
        do {
            cout << atual->info << " ";
            atual = atual->prox;
        } while (atual != inicio);
        cout << endl << "Tamanho: " << tamanho << endl;
    }

    int Menu() {
        int opc;
        cout << "\n==========================================" << endl;
        cout << " LISTA CIRCULAR DUPLAMENTE ENCADEADA - MENU" << endl;
        cout << "==========================================" << endl;
        cout << "  [1] INSERIR ELEMENTO" << endl;
        cout << "  [2] RETIRAR ELEMENTO" << endl;
        cout << "  [3] IMPRIMIR LISTA" << endl;
        cout << "  [4] SAIR" << endl;
        cout << "==========================================" << endl;
        cout << "OPCAO: ";
        cin >> opc;
        return opc;
    }
};

int main() {
    ListaCircularDupla lista;
    int opc, valor;
    do {
        opc = lista.Menu();
        switch (opc) {
            case 1:
                cout << "Valor a inserir: ";
                cin >> valor;
                lista.Inserir(valor);
                break;
            case 2:
                cout << "Valor a retirar: ";
                cin >> valor;
                lista.Retirar(valor);
                break;
            case 3:
                lista.Imprimir();
                break;
        }
    } while (opc != 4);
    return 0;
}
