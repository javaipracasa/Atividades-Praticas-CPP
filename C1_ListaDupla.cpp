#include <iostream>
using namespace std;

// ============================================================
// C.1 - Lista Duplamente Encadeada
//   a) Incluir elementos em qualquer posicao da lista
//   b) Impressao do conteudo da lista       (RECURSIVA)
//   c) Busca de um determinado elemento na lista
//   d) Exclusao de elementos em qualquer posicao da lista
// ============================================================

typedef struct Reg {
    int info;
    Reg *ant;
    Reg *prox;
} No;

class ListaDupla {
private:
    No *inicio; // no cabeca (sentinela), nao guarda dado
    int tamanho;

public:
    ListaDupla() {
        inicio = new No;
        inicio->ant = NULL;
        inicio->prox = NULL;
        tamanho = 0;
    }

    bool ListaVazia() {
        return tamanho == 0;
    }

    // a) Incluir elementos em qualquer posicao da lista (posicao 1-based)
    bool Inserir(int valor, int posicao) {
        if (posicao < 1 || posicao > tamanho + 1) {
            cout << "Posicao invalida!" << endl;
            return false;
        }
        No *atual = inicio;
        for (int i = 0; i < posicao - 1; i++)
            atual = atual->prox;

        No *novo = new No;
        novo->info = valor;
        novo->prox = atual->prox;
        novo->ant = atual;
        if (atual->prox != NULL)
            atual->prox->ant = novo;
        atual->prox = novo;
        tamanho++;
        return true;
    }

    // b) Impressao do conteudo da lista (RECURSIVA)
    void ImprimirRec(No *no) {
        if (no == NULL) {
            cout << endl;
            return;
        }
        cout << no->info << " ";
        ImprimirRec(no->prox);
    }

    void Imprimir() {
        if (ListaVazia()) {
            cout << "Lista vazia!" << endl;
            return;
        }
        cout << "Conteudo da lista: ";
        ImprimirRec(inicio->prox);
    }

    // c) Busca de um determinado elemento na lista
    No *Buscar(int valor) {
        No *atual = inicio->prox;
        while (atual != NULL) {
            if (atual->info == valor)
                return atual;
            atual = atual->prox;
        }
        return NULL;
    }

    // d) Exclusao de elementos em qualquer posicao da lista
    bool ExcluirPosicao(int posicao) {
        if (posicao < 1 || posicao > tamanho) {
            cout << "Posicao invalida!" << endl;
            return false;
        }
        No *atual = inicio->prox;
        for (int i = 1; i < posicao; i++)
            atual = atual->prox;

        atual->ant->prox = atual->prox;
        if (atual->prox != NULL)
            atual->prox->ant = atual->ant;
        delete atual;
        tamanho--;
        return true;
    }

    int TamanhoLista() {
        return tamanho;
    }

    int Menu() {
        int opc;
        cout << "\n==========================================" << endl;
        cout << "   LISTA DUPLAMENTE ENCADEADA - MENU" << endl;
        cout << "==========================================" << endl;
        cout << "  [1] INSERIR ELEMENTO EM UMA POSICAO" << endl;
        cout << "  [2] IMPRIMIR LISTA" << endl;
        cout << "  [3] BUSCAR ELEMENTO" << endl;
        cout << "  [4] EXCLUIR ELEMENTO DE UMA POSICAO" << endl;
        cout << "  [5] SAIR" << endl;
        cout << "==========================================" << endl;
        cout << "OPCAO: ";
        cin >> opc;
        return opc;
    }
};

int main() {
    ListaDupla lista;
    int opc, valor, pos;
    do {
        opc = lista.Menu();
        switch (opc) {
            case 1:
                cout << "Valor a inserir: ";
                cin >> valor;
                cout << "Posicao (1 a " << lista.TamanhoLista() + 1 << "): ";
                cin >> pos;
                if (lista.Inserir(valor, pos))
                    cout << "Inserido com sucesso!" << endl;
                break;
            case 2:
                lista.Imprimir();
                break;
            case 3:
                cout << "Valor a buscar: ";
                cin >> valor;
                if (lista.Buscar(valor) != NULL)
                    cout << "Elemento encontrado!" << endl;
                else
                    cout << "Elemento nao encontrado." << endl;
                break;
            case 4:
                cout << "Posicao a excluir (1 a " << lista.TamanhoLista() << "): ";
                cin >> pos;
                if (lista.ExcluirPosicao(pos))
                    cout << "Excluido com sucesso!" << endl;
                break;
        }
    } while (opc != 5);
    return 0;
}
