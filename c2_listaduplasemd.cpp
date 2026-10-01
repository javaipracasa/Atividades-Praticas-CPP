#include <iostream>
using namespace std;

// ============================================================
// C.2 - Modificacao da funcao InserirInicioLD para impedir a
//        insercao de um elemento que ja exista na lista.
// ============================================================

typedef struct Reg {
    int info;
    Reg *ant;
    Reg *prox;
} NO;

class ListaDupla {
public:
    NO *inicio;
    NO *fim;
    int tamanho;

    ListaDupla() {
        inicio = NULL;
        fim = NULL;
        tamanho = 0;
    }

    bool ListaVaziaLD() {
        return inicio == NULL;
    }

    // Verifica se o elemento ja existe na lista
    bool Existe(int k) {
        NO *p = inicio;
        while (p != NULL) {
            if (p->info == k)
                return true;
            p = p->prox;
        }
        return false;
    }

    //-------------------------------------------------------
    //FUNCAO INSERE: Insere um registro no inicio da Lista,
    //impedindo a insercao de elementos duplicados
    //-------------------------------------------------------
    void InserirInicioLD(int k) {
        if (Existe(k)) {
            cout << "Elemento " << k << " ja existe na lista! Insercao nao realizada." << endl;
            return;
        }

        NO *novo;
        novo = new NO;
        novo->info = k;
        novo->ant = NULL;
        if (ListaVaziaLD()) {
            novo->prox = NULL;
            inicio = fim = novo;
            tamanho++;
        } else {
            novo->prox = inicio;
            inicio->ant = novo;
            inicio = novo;
            tamanho++;
        }
        cout << "Elemento " << k << " inserido no inicio da lista." << endl;
    }

    void Imprimir() {
        if (ListaVaziaLD()) {
            cout << "Lista vazia!" << endl;
            return;
        }
        NO *p = inicio;
        cout << "Conteudo da lista: ";
        while (p != NULL) {
            cout << p->info << " ";
            p = p->prox;
        }
        cout << endl;
    }

    int Menu() {
        int opc;

        cout << " LISTA DUPLA SEM DUPLICADOS - MENU" << endl;
      
        cout << "  [1] INSERIR NO INICIO" << endl;
        cout << "  [2] IMPRIMIR LISTA" << endl;
        cout << "  [3] SAIR" << endl;
        cout << "==========================================" << endl;
        cout << "OPCAO: ";
        cin >> opc;
        return opc;
    }
};

int main() {
    ListaDupla lista;
    int opc, valor;
    do {
        opc = lista.Menu();
        switch (opc) {
            case 1:
                cout << "Valor a inserir: ";
                cin >> valor;
                lista.InserirInicioLD(valor);
                break;
            case 2:
                lista.Imprimir();
                break;
        }
    } while (opc != 3);
    return 0;
}
