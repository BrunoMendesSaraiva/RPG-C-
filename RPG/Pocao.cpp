//Bruno Mendes Bauso Diniz Saraiva - 2185932
//Felipe Julien Rocha Pinho - 2241480

#include "Pocao.h"
using namespace std;

Pocao::Pocao(const std::string& nome, int peso, int poderCura)
    : Item(nome, peso), poderCura(poderCura) {
    // Construtor da classe Pocao
}

int Pocao::getPoderCura() const {
    return poderCura;
}

void Pocao::usar(Heroi& heroi) {
    heroi.recuperarVida(poderCura);
    cout << "Voce usou " << getNome() << " e recuperou " << poderCura << " pontos de vida." << endl;
}