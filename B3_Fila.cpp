#include <iostream>
using namespace std;

// ============================================================
// B.3 - FILA (structs do quesito B.2 adaptadas para FILA)
//   a) Inserir elementos
//   b) Excluir elementos
//   c) Listar o conteudo da fila
//   d) Verificar se um dado elemento esta presente na fila
// ============================================================

typedef struct Reg {
    int infor;
    Reg *prox;
} No;

typedef struct TipoFila {
    No *Inicio;
    No *Fim;
    int tamanho;
} Fila;

class ManipulaFila {
public:
    void Inicializar(Fila &f) {
        f.Inicio = NULL;
        f.Fim = NULL;
        f.tamanho = 0;
    }

    bool FilaVazia(Fila &f) {
        return f.Inicio == NULL;
    }

    // a) Inserir elementos (entra no fim da fila)
    void Inserir(Fila &f, int valor) {
        No *novo = new No;
        novo->infor = valor;
        novo->prox = NULL;
        if (FilaVazia(f)) {
            f.Inicio = novo;
            f.Fim = novo;
        } else {
            f.Fim->prox = novo;
            f.Fim = novo;
        }
        f.tamanho++;
        cout << "Elemento " << valor << " inserido na fila." << endl;
    }

    // b) Excluir elementos (sai do inicio da fila)
    void Excluir(Fila &f) {
        if (FilaVazia(f)) {
            cout << "Fila vazia! Nao ha elementos para excluir." << endl;
            return;
        }
        No *aux = f.Inicio;
        cout << "Elemento removido: " << aux->infor << endl;
        f.Inicio = f.Inicio->prox;
        if (f.Inicio == NULL)
            f.Fim = NULL;
        delete aux;
        f.tamanho--;
    }

    // c) Lista o conteudo da fila
    void Listar(Fila &f) {
        if (FilaVazia(f)) {
            cout << "Fila vazia!" << endl;
            return;
        }
        No *aux = f.Inicio;
        cout << "Conteudo da fila (Inicio -> Fim): ";
        while (aux != NULL) {
            cout << aux->infor << " ";
            aux = aux->prox;
        }
        cout << endl << "Tamanho: " << f.tamanho << endl;
    }

    // d) Verificar se um dado elemento esta presente na fila
    bool Verificar(Fila &f, int valor) {
        No *aux = f.Inicio;
        while (aux != NULL) {
            if (aux->infor == valor)
                return true;
            aux = aux->prox;
        }
        return false;
    }

    int Menu() {
        int opc;
        cout << "\n==========================================" << endl;
        cout << "         FILA - ESCOLHA UMA OPCAO" << endl;
        cout << "==========================================" << endl;
        cout << "  [1] INSERIR ELEMENTO" << endl;
        cout << "  [2] EXCLUIR ELEMENTO" << endl;
        cout << "  [3] LISTAR CONTEUDO DA FILA" << endl;
        cout << "  [4] VERIFICAR SE ELEMENTO ESTA PRESENTE" << endl;
        cout << "  [5] SAIR" << endl;
        cout << "==========================================" << endl;
        cout << "OPCAO: ";
        cin >> opc;
        return opc;
    }
};

int main() {
    Fila fila;
    ManipulaFila mf;
    mf.Inicializar(fila);
    int opc, valor;
    do {
        opc = mf.Menu();
        switch (opc) {
            case 1:
                cout << "Digite o valor a inserir: ";
                cin >> valor;
                mf.Inserir(fila, valor);
                break;
            case 2:
                mf.Excluir(fila);
                break;
            case 3:
                mf.Listar(fila);
                break;
            case 4:
                cout << "Digite o valor a verificar: ";
                cin >> valor;
                cout << (mf.Verificar(fila, valor) ? "Elemento presente na fila!" : "Elemento NAO esta na fila.") << endl;
                break;
        }
    } while (opc != 5);
    return 0;
}
