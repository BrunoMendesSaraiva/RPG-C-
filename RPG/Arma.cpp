//Bruno Mendes Bauso Diniz Saraiva - 2185932
//Felipe Julien Rocha Pinho - 2241480

#include "Arma.h"
#include "Heroi.h"
#include "Inimigo.h"
#include <iostream>

using namespace std;

Arma::Arma(string nome, int peso, int poderAtaque)
    : Item(nome, peso), poderAtaque(poderAtaque) {}

int Arma::getPoderAtaque() const {
    return poderAtaque;
}

void Arma::usar(Heroi& heroi) {
    // Não faz nada, pois armas devem ser usadas com um inimigo
}

void Arma::usar(Heroi& heroi, Inimigo& inimigo) {
    cout << "Voce usou a " << getNome() << " com poder de ataque " << poderAtaque << endl;
    inimigo.receberDano(poderAtaque);  // Aplica o dano ao inimigo
    cout << inimigo.getNome() << " tem " << inimigo.getPontosVida() << " pontos de vida restantes." << endl;
}
