#include <iostream>
using namespace std;



typedef struct Reg {
    int info;
    Reg *prox;
} No;

class ListaEncadeada {
private:
    No *inicio;
    int tamanho;

public:
    
    ListaEncadeada() {
        inicio = NULL;
        tamanho = 0;
    }

    bool ListaVazia() {
        return inicio == NULL;
    }

    
    void Inserir(int valor) {
        No *novo = new No;
        novo->info = valor;
        novo->prox = inicio;
        inicio = novo;
        tamanho++;
    }


    void Imprimir() {
        if (ListaVazia()) {
            cout << "Lista vazia!" << endl;
            return;
        }
        No *p = inicio;
        cout << "Conteudo da lista: ";
        while (p != NULL) {
            cout << p->info << " ";
            p = p->prox;
        }
        cout << endl;
    }

    
    int TamanhoLista() {
        return tamanho;
    }

    int Menu() {
        int opc;
        cout << "\n==========================================" << endl;
        cout << "   LISTA ENCADEADA - ESCOLHA UMA OPCAO" << endl;
        cout << "==========================================" << endl;
        cout << "  [1] INSERIR ELEMENTO" << endl;
        cout << "  [2] IMPRIMIR LISTA" << endl;
        cout << "  [3] TAMANHO DA LISTA" << endl;
        cout << "  [4] SAIR" << endl;
        cout << "==========================================" << endl;
        cout << "OPCAO: ";
        cin >> opc;
        return opc;
    }
};

int main() {
    ListaEncadeada lista;
    int opc, valor;
    do {
        opc = lista.Menu();
        switch (opc) {
            case 1:
                cout << "Digite o valor a inserir: ";
                cin >> valor;
                lista.Inserir(valor);
                break;
            case 2:
                lista.Imprimir();
                break;
            case 3:
                cout << "Numero de elementos: " << lista.TamanhoLista() << endl;
                break;
        }
    } while (opc != 4);
    return 0;
}
