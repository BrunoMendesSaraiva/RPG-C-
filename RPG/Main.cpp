//Bruno Mendes Bauso Diniz Saraiva - 2185932
//Felipe Julien Rocha Pinho - 2241480

#include "Heroi.h"
#include "Mapa.h"
#include "Arma.h"
#include "Pocao.h"
#include "Inimigo.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <typeinfo>

using namespace std;

// Função para salvar a pontuação do jogador
void salvarPontuacao(const string& nome, int nivelMaximo) {
    ofstream arquivo("high_scores.txt", ios::app);
    if (arquivo.is_open()) {
        arquivo << nome << " - Nivel Maximo: " << nivelMaximo << endl;
        arquivo.close();
    } else {
        cout << "Erro ao abrir o arquivo high_scores.txt!" << endl;
    }
}

// Função para limpar a tela
void clear() {
    system("cls");
}

int main() {
    // Solicitar o nome do jogador
    string nomeHeroi;
    cout << "Digite o nome do seu heroi: ";
    cin >> nomeHeroi;

    // Inicializa o herói com o nome fornecido pelo jogador com 100 de vida
    Heroi heroi(nomeHeroi, 100);

    // Definir número de níveis
    int numNiveis;
    cout << "Escolha o numero de niveis ou digite 0 para um numero aleatorio: ";
    cin >> numNiveis;

    if (numNiveis == 0) {
        srand(time(0));
        numNiveis = rand() % 5 + 2;  // Número aleatório de níveis entre 2 e 6
        cout << "Numero de niveis definido aleatoriamente: " << numNiveis << endl;
    }

    // Adicionando os nomes dos níveis
    string nomeDosNiveis[] = {
        "Caverna do Dragao",
        "Cemiterio",
        "Pantano",
        "Masmorra",
        "Castelo",
        "Floresta Sombria"
    };

    bool jogoAtivo = true;
    for (int nivelAtual = 1; nivelAtual <= numNiveis && jogoAtivo; ++nivelAtual) {
        cout << "\n--- Nivel " << nivelAtual << ": " << nomeDosNiveis[nivelAtual - 1] << " ---\n";

        // Definir tamanho do caminho para o nível atual
        int tamanhoCaminho;
        cout << "Escolha o tamanho do caminho ou digite 0 para tamanho aleatorio: ";
        cin >> tamanhoCaminho;

        if (tamanhoCaminho == 0) {
            srand(time(0));
            tamanhoCaminho = rand() % 10 + 5;  // Tamanho aleatório do caminho entre 5 e 15
            cout << "Tamanho do caminho definido aleatoriamente: " << tamanhoCaminho << endl;
        }

        // Inicializa o mapa para o nível atual
        Mapa mapa(tamanhoCaminho, nivelAtual);
        mapa.gerarMapa();

        int posicaoJogador = 0;

        while (jogoAtivo && posicaoJogador < tamanhoCaminho) {
            clear();  // Limpa a tela a cada iteração

            // Mostra os pontos de vida do herói
            cout << "Pontos de vida: " << heroi.getPontosVida() << endl;

            // Mostra o mapa
            mapa.mostrarMapa(posicaoJogador);

            // Pede ao jogador para escolher uma ação
            cout << "Escolha uma acao (f para avancar, u para usar item, d para descartar item): ";
            char acao;
            cin >> acao;

            switch (acao) {
                case 'f':
                    posicaoJogador++;
                    break;
                case 'u': {
                    // Verifica o que está na célula atual
                    Mapa::Celula* celulaAtual = mapa.obterCelulaAtual(posicaoJogador);
                    Inimigo* inimigo = nullptr;
                    if (celulaAtual && celulaAtual->inimigo != nullptr) {
                        inimigo = celulaAtual->inimigo;
                    }

                    // Mostra as opções para o jogador escolher
                    cout << "Usar item do cinto (0-" << (heroi.getQuantidadeItensCinto() - 1) << ") ou da mochila (m)? ";
                    char escolha;
                    cin >> escolha;

                    // Verifica se a escolha é para o cinto
                    if (escolha >= '0' && escolha <= '4') {
                        int indice = escolha - '0';
                        if (indice >= 0 && indice < heroi.getQuantidadeItensCinto()) {
                            if (inimigo) {
                                heroi.usarItemCinto(indice, *inimigo);  // Usa o item, seja uma arma ou poção
                            } else {
                                heroi.usarItemCinto(indice);  // Usa o item, geralmente uma poção
                            }
                        } else {
                            std::cout << "Indice invalido!" << std::endl;
                        }
                    } 
                    // Verifica se a escolha é para a mochila
                    else if (escolha == 'm') {
                        heroi.usarItemMochila();
                    } 
                    // Caso contrário, indica escolha inválida
                    else {
                        cout << "Escolha invalida!" << endl;
                    }
                    break;
                }
                case 'd': {
                    // Menu de descarte
                    cout << "Escolha onde deseja descartar um item (c: cinto, m: mochila): ";
                    char escolhaDescartar;
                    cin >> escolhaDescartar;

                    if (escolhaDescartar == 'c') {
                        cout << "Escolha o item do cinto para descartar (0-" << (heroi.getQuantidadeItensCinto() - 1) << "): ";
                        int indiceDescartar;
                        cin >> indiceDescartar;
                        if (indiceDescartar >= 0 && indiceDescartar < heroi.getQuantidadeItensCinto()) {
                            heroi.descartarItemCinto(indiceDescartar);  // Descartar item do cinto
                        } else {
                            cout << "Indice invalido!" << endl;
                        }
                    } else if (escolhaDescartar == 'm') {
                        heroi.descartarItemMochila();  // Descartar item do topo da mochila
                    } else {
                        cout << "Escolha invalida!" << endl;
                    }
                    break;
                }
                default:
                    cout << "Acao invalida!" << endl;
                    break;
            }

            // Verifica o que está na célula atual
            Mapa::Celula* celulaAtual = mapa.obterCelulaAtual(posicaoJogador);

            if (celulaAtual) {
                // Se há um inimigo na célula atual
                if (celulaAtual->inimigo != nullptr) {
                    Inimigo* inimigo = celulaAtual->inimigo;
                    cout << "Voce encontrou um " << inimigo->getNome() << "!" << endl;

                    // Luta contra o inimigo
                    while (heroi.getPontosVida() > 0 && inimigo->getPontosVida() > 0) {
                        char escolha;
                        cout << "Escolha de onde voce quer usar uma arma (c: cinto, m: mochila): ";
                        cin >> escolha;

                        if (escolha == 'c') {
                            int indiceArma;
                            cout << "Escolha uma arma do cinto para atacar (0-" << (heroi.getQuantidadeItensCinto() - 1) << "): ";
                            cin >> indiceArma;

                            if (indiceArma >= 0 && indiceArma < heroi.getQuantidadeItensCinto()) {
                                heroi.usarItemCinto(indiceArma, *inimigo);  // Usando inimigo aqui
                            } else {
                                cout << "Indice invalido!" << endl;
                            }
                        } else if (escolha == 'm') {
                            heroi.usarItemMochila();
                        } else {
                            cout << "Escolha invalida!" << endl;
                            continue;  // Volta para a escolha da arma
                        }

                        // Inimigo ataca se ainda estiver vivo
                        if (inimigo->getPontosVida() > 0) {
                            heroi.receberDano(inimigo->getPoderAtaque());
                            cout << inimigo->getNome() << " ataca e causa " << inimigo->getPoderAtaque() << " de dano." << endl;
                        }

                        // Verifica se o heroi foi derrotado
                        if (heroi.getPontosVida() <= 0) {
                            cout << "Voce foi derrotado!" << endl;
                            jogoAtivo = false;  // Encerra o jogo
                            break;  // Sai do loop de combate
                        }
                    }

                    // Verifica se o inimigo foi derrotado
                    if (inimigo->getPontosVida() <= 0) {
                        cout << "Voce derrotou o " << inimigo->getNome() << "!" << endl;
                        delete inimigo;  // Libera a memória do inimigo derrotado
                        celulaAtual->inimigo = nullptr;
                    }
                }

                // Se há um item na célula atual
                if (celulaAtual->item != nullptr) {
                    Item* item = celulaAtual->item;
                    cout << "Voce encontrou um(a) " << item->getNome() << "!" << endl;

                    // Mostrar os status do item pego
                    cout << "Status do item:" << endl;
                    cout << "Peso: " << item->getPeso() << endl;

                    if (Arma* arma = dynamic_cast<Arma*>(item)) {
                        cout << "Tipo: Arma" << endl;
                        cout << "Dano: " << arma->getPoderAtaque() << endl;
                    } else if (Pocao* pocao = dynamic_cast<Pocao*>(item)) {
                        cout << "Tipo: Pocao" << endl;
                        cout << "Cura: " << pocao->getPoderCura() << endl;
                    }

                    // Pergunta onde adicionar o item
                    cout << "Deseja adicionar ao cinto (c), a mochila (m) ou ignorar (n)? ";
                    char escolha;
                    cin >> escolha;
                    if (escolha == 'c') {
                        heroi.adicionarAoCinto(item);
                    } else if (escolha == 'm') {
                        heroi.adicionarNaMochila(item);
                    } else if (escolha == 'n') {
                        cout << "Voce decidiu nao pegar o item." << endl;
                    } else {
                        cout << "Escolha invalida!" << endl;
                    }
                    celulaAtual->item = nullptr;  // Remove o item do mapa
                }
            }

            // Condição de vitória ao completar o nível (se não for o último)
            if (nivelAtual < numNiveis && posicaoJogador >= tamanhoCaminho) {
                cout << "Voce completou o nivel " << nivelAtual << "!" << endl;
            }

            // Se o jogo foi completado no último nível
            if (nivelAtual == numNiveis && posicaoJogador >= tamanhoCaminho) {
                cout << "Voce completou o ultimo nivel e venceu o jogo!" << endl;
                salvarPontuacao(heroi.getNome(), nivelAtual);  // Salva a pontuação
                jogoAtivo = false;
            }
        }
    }

    return 0;
}
