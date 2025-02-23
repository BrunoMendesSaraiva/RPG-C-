//Bruno Mendes Bauso Diniz Saraiva - 2185932
//Felipe Julien Rocha Pinho - 2241480

#include "Item.h"

using namespace std;

Item::Item(string nome, int peso)
    : nome(nome), peso(peso) {}

string Item::getNome() const {
    return nome;
}

int Item::getPeso() const {
    return peso;
}
