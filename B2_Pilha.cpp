#include <iostream>
using namespace std;

// ============================================================
// B.2 - PILHA (TAD dado no enunciado)
//   a) Inserir elementos
//   b) Excluir elementos
//   c) Listar o conteudo da pilha
//   d) Verificar se um dado elemento esta presente na pilha
// ============================================================

typedef struct Reg {
    int infor;
    Reg *prox;
} No;

typedef struct TipoPilha {
    No *Topo;
    int tamanho;
} Pilha;

class ManipulaPilha {
public:
    void Inicializar(Pilha &p) {
        p.Topo = NULL;
        p.tamanho = 0;
    }

    bool PilhaVazia(Pilha &p) {
        return p.Topo == NULL;
    }

    // a) Inserir elementos (push)
    void Inserir(Pilha &p, int valor) {
        No *novo = new No;
        novo->infor = valor;
        novo->prox = p.Topo;
        p.Topo = novo;
        p.tamanho++;
        cout << "Elemento " << valor << " inserido na pilha." << endl;
    }

    // b) Excluir elementos (pop)
    void Excluir(Pilha &p) {
        if (PilhaVazia(p)) {
            cout << "Pilha vazia! Nao ha elementos para excluir." << endl;
            return;
        }
        No *aux = p.Topo;
        cout << "Elemento removido: " << aux->infor << endl;
        p.Topo = p.Topo->prox;
        delete aux;
        p.tamanho--;
    }

    // c) Lista o conteudo da pilha
    void Listar(Pilha &p) {
        if (PilhaVazia(p)) {
            cout << "Pilha vazia!" << endl;
            return;
        }
        No *aux = p.Topo;
        cout << "Conteudo da pilha (Topo -> Base): ";
        while (aux != NULL) {
            cout << aux->infor << " ";
            aux = aux->prox;
        }
        cout << endl << "Tamanho: " << p.tamanho << endl;
    }

    // d) Verificar se um dado elemento esta presente na pilha
    bool Verificar(Pilha &p, int valor) {
        No *aux = p.Topo;
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
        cout << "        PILHA - ESCOLHA UMA OPCAO" << endl;
        cout << "==========================================" << endl;
        cout << "  [1] INSERIR ELEMENTO (PUSH)" << endl;
        cout << "  [2] EXCLUIR ELEMENTO (POP)" << endl;
        cout << "  [3] LISTAR CONTEUDO DA PILHA" << endl;
        cout << "  [4] VERIFICAR SE ELEMENTO ESTA PRESENTE" << endl;
        cout << "  [5] SAIR" << endl;
        cout << "==========================================" << endl;
        cout << "OPCAO: ";
        cin >> opc;
        return opc;
    }
};

int main() {
    Pilha pilha;
    ManipulaPilha mp;
    mp.Inicializar(pilha);
    int opc, valor;
    do {
        opc = mp.Menu();
        switch (opc) {
            case 1:
                cout << "Digite o valor a inserir: ";
                cin >> valor;
                mp.Inserir(pilha, valor);
                break;
            case 2:
                mp.Excluir(pilha);
                break;
            case 3:
                mp.Listar(pilha);
                break;
            case 4:
                cout << "Digite o valor a verificar: ";
                cin >> valor;
                cout << (mp.Verificar(pilha, valor) ? "Elemento presente na pilha!" : "Elemento NAO esta na pilha.") << endl;
                break;
        }
    } while (opc != 5);
    return 0;
}
