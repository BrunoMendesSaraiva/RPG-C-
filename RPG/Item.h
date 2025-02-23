//Bruno Mendes Bauso Diniz Saraiva - 2185932
//Felipe Julien Rocha Pinho - 2241480

#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std;

class Heroi;  //  declaração para evitar dependências circulares
class Inimigo;  //  declaração para o uso com armas

class Item {
private:
    std::string nome;
    int peso;

public:
    Item(string nome, int peso);
    string getNome() const;
    int getPeso() const;
    virtual void usar(Heroi& heroi) = 0;  // Função virtual para uso de itens sem inimigos (poções)
    virtual void usar(Heroi& heroi, Inimigo& inimigo) = 0;  // Função virtual para uso de armas
    virtual ~Item() = default;  // Destrutor virtual para garantir a destruição correta das subclasses
};

#endif
