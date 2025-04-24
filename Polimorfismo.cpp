/*
Brenda Raquel Maia
Juliano Vitorino da Silva

Exercício - Polimorfismo
*/

#include <iostream>
#include <vector>
#include <cstdlib> // para system() e rand()
#include <ctime> // para time()
#include <thread> // para chrono::seconds
#include <chrono> // para this_thread::sleep_for

using namespace std;

class Figura {
protected:
    int x, y;  // Posições da figura
public:
    Figura(int x = 0, int y = 0) : x(x), y(y) {}

    // Método abstrato para desenhar a figura
    virtual void Desenha() const = 0;

    // Atualiza a posição da figura
    void SetPosicao(int x, int y) {
        this->x = max(0, x);
        this->y = max(0, y);
    }

    int getX() const{
        return x;
    }
    int getY() const{
        return y;
    }
};

// Classe que representa um Triângulo
class Triangulo : public Figura {
public:
    Triangulo(int x, int y) : Figura(x, y) {}
    void Desenha() const override {
        cout << string(y, '\n') << string(x, ' ') << "A\n";  // Imprime o triângulo na posição (x, y)
    }
};

// Classe que representa um Círculo
class Circulo : public Figura {
public:
    Circulo(int x, int y) : Figura(x, y) {}
    void Desenha() const override {
        cout << string(y, '\n') << string(x, ' ') << "O\n";  // Imprime o círculo na posição (x, y)
    }
};

// Classe que representa um Quadrado
class Quadrado : public Figura {
public:
    Quadrado(int x, int y) : Figura(x, y) {}
    void Desenha() const override {
        cout << string(y, '\n') << string(x, ' ') << "D\n";  // Imprime o quadrado na posição (x, y)
    }
};

// Função para atualizar a tela, desenhando todas as figuras
void DisplayRefresh(const vector<Figura*>& figuras) {
    system("clear");  // Limpa a tela (use "cls" no Windows)
    for (auto figura : figuras) figura->Desenha();
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));  // Inicializa a semente para números aleatórios

    // Cria as figuras e define suas posições iniciais
    vector<Figura*> figuras = { new Triangulo(5, 2), new Circulo(15, 4), new Quadrado(25, 6) };

    // Loop para mover as figuras e atualizar a tela
    for (int i = 0; i < 20; ++i) {
        for (auto figura : figuras) {
            // Move cada figura aleatoriamente para cima ou para baixo (y)
            figura->SetPosicao(figura->getX(), figura->getY() + rand() % 3 - 1);
        }

        DisplayRefresh(figuras);  // Atualiza a tela com as novas posições das figuras
        this_thread::sleep_for(chrono::seconds(1));  // Pausa de 1 segundo
    }

    // Libera a memória alocada para as figuras
    for (auto figura : figuras) delete figura;

    return 0;
}

/*Como adicionar um novo tipo de figura (Trapézio):
Passo a passo

1. Criar a classe Trapezio que herda de Figura:
   - O construtor recebe as coordenadas (x, y) para definir a posição.
   - O método Desenha() imprime o trapézio no terminal, utilizando strings para as linhas.

2. No main(), instanciar um objeto da classe Trapezio e adicioná-lo ao vetor de figuras:
   - Exemplo: `new Trapezio(10, 3)` cria um Trapézio na posição (10, 3).

3. Adicionar a classe Trapezio na lista de figuras:
   - Exemplo: `vector<Figura*> figuras = { new Triangulo(5, 2), new Circulo(15, 4), new Quadrado(25, 6), new Trapezio(10, 3) };`

Assim, o Trapézio será desenhado e movimentado junto com as outras figuras.
*/
