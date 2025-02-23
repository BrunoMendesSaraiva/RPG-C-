//Bruno Mendes Bauso Diniz Saraiva - 2185932
//Felipe Julien Rocha Pinho - 2241480

#ifndef ARMA_H
#define ARMA_H

#include "Item.h"

using namespace std;

class Arma : public Item {
private:
    int poderAtaque;

public:
    Arma(string nome, int peso, int poderAtaque);
    int getPoderAtaque() const;
    void usar(Heroi& heroi) override;  // Sobrecarga para armas sem inimigos (não faz nada)
    void usar(Heroi& heroi, Inimigo& inimigo) override;  // Sobrecarga para armas com inimigos
};

// Tipos de armas
class EspadaMadeira : public Arma {
public:
    EspadaMadeira() : Arma("wooden sword ", 1, 5) {}
};

class BladeOfTheEternalFlame : public Arma {
public:
    BladeOfTheEternalFlame() : Arma("Blade of the Eternal Flame ", 3, 25) {}
};

class ShadowReaver : public Arma {
public:
    ShadowReaver() : Arma("Shadow Reaver ", 2, 20) {}
};

class DragonsBane : public Arma {
public:
    DragonsBane() : Arma("Dragons Bane ", 4, 30) {}
};

#endif
