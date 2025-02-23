//Bruno Mendes Bauso Diniz Saraiva - 2185932
//Felipe Julien Rocha Pinho - 2241480

#include "Inimigo.h"

Inimigo::Inimigo(string nome, int pontosVida, int poderAtaque)
    : nome(nome), pontosVida(pontosVida), poderAtaque(poderAtaque) {}

string Inimigo::getNome() const {
    return nome;
}

int Inimigo::getPontosVida() const {
    return pontosVida;
}

int Inimigo::getPoderAtaque() const {
    return poderAtaque;
}

void Inimigo::receberDano(int dano) {
    pontosVida -= dano;
    if (pontosVida < 0) pontosVida = 0;
}
