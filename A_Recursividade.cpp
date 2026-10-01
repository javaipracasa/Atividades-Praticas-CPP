#include <iostream>
#include <cstdio>
using namespace std;



int f1(int n) {
    if (n == 0)
        return (1);
    else
        return (n * f1(n - 1));
}

int f2(int n) {
    if (n == 0)
        return (1);
    if (n == 1)
        return (1);
    else
        return (f2(n - 1) + 2 * f2(n - 2));
}

void f3(int n) {
    if (n == 0)
        printf("Zero ");
    else {
        printf("%d ", n);
        printf("%d ", n);
        f3(n - 1);
    }
}

// ============================================================
// A.2 - Soma recursiva dos pares de 0 ate n
// ============================================================

int SomaPares(int n) {
    if (n <= 0)
        return 0;
    if (n % 2 != 0)
        return SomaPares(n - 1);
    return n + SomaPares(n - 2);
}


int Produto(int a, int b) {
    if (b == 1)
        return a;
    return Produto(a, b - 1) + a;
}



typedef struct Reg {
    int info;
    Reg *prox;
} No;

class ListaRecursiva {
public:
    No *Inserir(No *L, int valor) {
        No *novo = new No;
        novo->info = valor;
        novo->prox = L;
        return novo;
    }

    
    void Imprimir(No *L) {
        if (L == NULL) {
            cout << endl;
            return;
        }
        cout << L->info << " ";
        Imprimir(L->prox);
    }

    
    bool Buscar(No *L, int valor) {
        if (L == NULL)
            return false;
        if (L->info == valor)
            return true;
        return Buscar(L->prox, valor);
    }

    
    No *Excluir(No *L, int valor, bool &excluiu) {
        if (L == NULL) {
            excluiu = false;
            return NULL;
        }
        if (L->info == valor) {
            No *resto = L->prox;
            delete L;
            excluiu = true;
            return resto;
        }
        L->prox = Excluir(L->prox, valor, excluiu);
        return L;
    }
};

int main() {
    cout << "===== A.1 - TESTE DAS FUNCOES RECURSIVAS SIMPLES =====\n\n";

    cout << "-- f1 (fatorial) --\n";
    cout << "f1(0) = " << f1(0) << endl;
    cout << "f1(1) = " << f1(1) << endl;
    cout << "f1(5) = " << f1(5) << endl << endl;

    cout << "-- f2 --\n";
    cout << "f2(0) = " << f2(0) << endl;
    cout << "f2(1) = " << f2(1) << endl;
    cout << "f2(5) = " << f2(5) << endl << endl;

    cout << "-- f3 --\n";
    cout << "f3(0): "; f3(0); cout << endl;
    cout << "f3(1): "; f3(1); cout << endl;
    cout << "f3(5): "; f3(5); cout << endl << endl;

    cout << "===== A.2 - SOMA DOS PARES DE 0 ATE N =====\n\n";
    cout << "SomaPares(9)  = " << SomaPares(9)  << "  (esperado 20)" << endl;
    cout << "SomaPares(10) = " << SomaPares(10) << "  (esperado 30)" << endl;
    cout << "SomaPares(0)  = " << SomaPares(0)  << "  (esperado 0)"  << endl << endl;

    cout << "===== A.3 - PRODUTO RECURSIVO (a * b) =====\n\n";
    cout << "Produto(4, 1) = " << Produto(4, 1) << "  (esperado 4)"  << endl;
    cout << "Produto(4, 5) = " << Produto(4, 5) << "  (esperado 20)" << endl;
    cout << "Produto(7, 3) = " << Produto(7, 3) << "  (esperado 21)" << endl << endl;

    cout << "===== A.4 - OPERACOES RECURSIVAS EM LISTA ENCADEADA =====\n\n";
    ListaRecursiva lr;
    No *L = NULL;
    int valores[] = {5, 10, 15, 20, 25};
    for (int i = 4; i >= 0; i--)
        L = lr.Inserir(L, valores[i]);

    cout << "Lista: ";
    lr.Imprimir(L);

    cout << "Buscar 15: " << (lr.Buscar(L, 15) ? "Encontrado" : "Nao encontrado") << endl;
    cout << "Buscar 99: " << (lr.Buscar(L, 99) ? "Encontrado" : "Nao encontrado") << endl;

    bool excluiu;
    L = lr.Excluir(L, 15, excluiu);
    cout << "Apos excluir 15 (" << (excluiu ? "OK" : "falhou") << "): ";
    lr.Imprimir(L);

    return 0;
}
