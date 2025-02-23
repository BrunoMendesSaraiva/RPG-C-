//Bruno Mendes Bauso Diniz Saraiva - 2185932
//Felipe Julien Rocha Pinho - 2241480

#ifndef INIMIGO_H
#define INIMIGO_H

#include <string>

using namespace std;

class Inimigo {
private:
    string nome;
    int pontosVida;
    int poderAtaque;

public:
    Inimigo(string nome, int pontosVida, int poderAtaque);
    virtual ~Inimigo() = default;  // Destrutor virtual

    string getNome() const;
    int getPontosVida() const;
    int getPoderAtaque() const;
    void receberDano(int dano);
};

// Tipos de inimigos
class Goblin : public Inimigo {
public:
    Goblin() : Inimigo("Goblin", 20, 5) {}
};

class Orc : public Inimigo {
public:
    Orc() : Inimigo("Orc", 30, 10) {}
};

class Esqueleto : public Inimigo {
public:
    Esqueleto() : Inimigo("Esqueleto", 30, 7) {}
};

class Slime : public Inimigo {
public:
    Slime() : Inimigo("Slime", 20, 5) {}
};

class Morcego : public Inimigo {
public:
    Morcego() : Inimigo("Morcego", 25, 6) {}
};

// Bosses para cada nível
//Dragao - Boss do nível 1
class Dragao : public Inimigo {
public:
    Dragao() : Inimigo("Dragao", 50, 15) {}
};
//Rei Esqueleto - Boss do nível 2
class ReiEsqueleto : public Inimigo {
public:
    ReiEsqueleto() : Inimigo("Rei Esqueleto", 60, 20) {}
};
//Slime Gigante - Boss do nível 3
class SlimeGigante : public Inimigo {
public:
    SlimeGigante() : Inimigo("Slime Gigante", 70, 18) {}
};
//Lorde Morcego - Boss do nível 4
class LordeMorcego : public Inimigo {
public:
    LordeMorcego() : Inimigo("Lorde Morcego", 80, 22) {}
};

// Lich King - Boss do nível 5
class LichKing : public Inimigo {
public:
    LichKing() : Inimigo("Lich King", 120, 25) {}
};

// Dark Knight - Boss do nível 6
class DarkKnight : public Inimigo {
public:
    DarkKnight() : Inimigo("Dark Knight", 150, 30) {}
};

#endif
