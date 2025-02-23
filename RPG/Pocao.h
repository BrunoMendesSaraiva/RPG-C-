//Bruno Mendes Bauso Diniz Saraiva - 2185932
//Felipe Julien Rocha Pinho - 2241480

#ifndef POCAO_H
#define POCAO_H

#include "Item.h"
#include "Heroi.h"
#include <iostream>

class Pocao : public Item {
private:
    int poderCura;

public:
    Pocao(const std::string& nome, int peso, int poderCura);  
    int getPoderCura() const;
    void usar(Heroi& heroi) override;  // Usar sem inimigo
    void usar(Heroi& heroi, Inimigo& inimigo) override {};  // Poções não afetam inimigos
};

// Tipos de poções
class ElixirOfRenewal : public Pocao {
public:
    ElixirOfRenewal() : Pocao("Elixir of Renewal", 2, 20) {}
};

class TearsOfThePhoenix : public Pocao {
public:
    TearsOfThePhoenix() : Pocao("Tears of the Phoenix", 2, 15) {}
};

class WarriorsRespite : public Pocao {
public:
    WarriorsRespite() : Pocao("Warriors Respite", 3, 10) {}
};

#endif // POCAO_H
