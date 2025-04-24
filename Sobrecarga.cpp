/* Exercício 2: Sobrecarga*/

#include <iostream>
using namespace std;

class NumComplexo {
private:
    int a, b;

public:
    //Construtor
    NumComplexo(int x, int y);

    void set_a(int x);
    void set_b(int y);
    int get_a() const;
    int get_b() const;
    void print() const;

    friend NumComplexo operator+(int p, NumComplexo f); //pré
    friend NumComplexo operator+(NumComplexo f, int p); //pós
    friend NumComplexo operator-(int p, NumComplexo f); //pré
    friend NumComplexo operator-(NumComplexo f, int p); //pós
    friend NumComplexo operator*(int p, NumComplexo f); //pré
    friend NumComplexo operator*(NumComplexo f, int p); //pós
    friend ostream &operator<<(ostream &saida, const NumComplexo &num);
    friend istream &operator>>(istream &entrada, NumComplexo &num);

    //os operadores binários são constantes
NumComplexo operator+(const NumComplexo &f) const {
    return NumComplexo(this->a + f.a, this->b + f.b);
}

NumComplexo operator-(const NumComplexo &f) const {
    return NumComplexo(this->a - f.a, this->b - f.b);
}

NumComplexo operator*(const NumComplexo &f) const {
    return NumComplexo(a * f.a - b * f.b, a * f.b + b * f.a);
}

NumComplexo &operator++() {// pre-fixado
    a = a + 1;
    return *this;
}

NumComplexo operator++(int) { // pos-fixado
    NumComplexo copiaInicial = *this;
    a = 1 + a;
    return copiaInicial;
}

NumComplexo &operator--() { // pre-fixado
    a = a - 1;
    return *this;
}

NumComplexo operator--(int) { // pos-fixado
    NumComplexo copiaInicial = *this;
    a = 1 - a;
    return copiaInicial;
    }
};

NumComplexo::NumComplexo(int x, int y) {
    set_a(x);
    set_b(y);
}

NumComplexo operator+(int p, NumComplexo f) {
    return NumComplexo(f.a + p, f.b);
}

NumComplexo operator+(NumComplexo f, int p) {
    return NumComplexo(f.a + p, f.b);
}

NumComplexo operator-(int p, NumComplexo f) {
    return NumComplexo(p - f.a, f.b);
}

NumComplexo operator-(NumComplexo f, int p) {
    return NumComplexo(f.a - p, f.b);
}

NumComplexo operator*(NumComplexo f, int p) {
    return NumComplexo(f.a * p, f.b);
}

NumComplexo operator*(int p, NumComplexo f) {
    return NumComplexo(p * f.a, f.b);
}

ostream &operator<<(ostream &saida, const NumComplexo &num) {
    saida << num.get_a() << " + " << num.get_b() << "i" << endl;
    return saida;
}

istream &operator>>(istream &entrada, NumComplexo &num) {
    entrada >> num.a >> num.b;
    return entrada;
}

void NumComplexo::set_a(int x) {
    a = x;
}

void NumComplexo::set_b(int y) {
    b = y;
}

int NumComplexo::get_a() const {
    return a;
}

int NumComplexo::get_b() const {
    return b;
}

void NumComplexo::print() const {
    cout << get_a() << "+" << get_b() << "i" << endl;
}

int main() {
    // Testando as Sobrecargas nos Operadores
    NumComplexo a1(3, -5);
    NumComplexo a2(2, 1);

    cout << "Testes de Sobrecarga do operador (+): " << endl;
    NumComplexo a3 = 3 + a1; // chamando operator+(int, NumComplexo)
    cout << a3;
    NumComplexo a4 = a1 + 3; // chamando operator+(NumComplexo, int)
    cout << a4;
    NumComplexo a5 = a1 + a2; // chamando operator+(NumComplexo, NumComplexo)
    cout << a5 << endl;

    cout << "Testes de Sobrecarga do operador(-): " << endl;
    NumComplexo b1 = 2 - a1; // chamando operator-(int, NumComplexo)
    cout << b1;
    NumComplexo b2 = a1 - 2; // chamando operator-(NumComplexo, int)
    cout << b2;
    NumComplexo b3 = a1 - a2; // chamando operator-(NumComplexo, NumComplexo)
    cout << b3 << endl;

    cout << "Testes de Sobrecarga do operador (*): " << endl;
    NumComplexo c1 = 3 * a1; // chamando operator*(int, NumComplexo)
    NumComplexo c2 = a1 * 3; // chamando operator*(NumComplexo, int)
    NumComplexo c3(3, 3);
    NumComplexo c4(2, -5);
    NumComplexo c5 = c3 * c4; // chamando operator*(NumComplexo, NumComplexo)
    cout << c1;
    cout << c2;
    cout << c3;
    cout << c5 << endl;

    cout << "Testes de Sobrecarga do operador (++) pre e pos fixado: " << endl;
    NumComplexo d1 = ++a1;
    cout << d1;
    NumComplexo d2 = a1++;
    cout << d2 << endl;

    cout << "Testes de Sobrecarga do operador (--) pre e pos fixado: " << endl;
    NumComplexo e1 = --a1;
    cout << e1;
    NumComplexo e2 = a1--;
    cout << e2 << endl;

    cout << "Testes de Sobrecarga do operador (<<): " << endl;
    NumComplexo f1(2, 2);
    cout << f1 << endl;


    cout << "Testes de Sobrecarga do operador (>>): " << endl;
    NumComplexo g1(2, 2);
    cout << "Vetor de g1: " << endl;
    cout << g1;
    cout << "\nDigite o valor de a e b: " << endl;
    cin >> g1;
    cout << endl;
    cout << "Novos valores de g1: " << endl;
    cout << g1;

    return 0;
}
