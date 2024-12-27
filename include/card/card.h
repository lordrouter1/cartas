#ifndef __CARD__
#define __CARD__

#include <emscripten.h>
#include <emscripten/html5.h>
#include <emscripten/val.h>
#include <random>
#include <string>
#include <map>
#include <vector>


class Card
{
    public:
        Card(int _rarity, std::string _name, std::string _cClass, std::string _subclass, std::string _sex);
        Card(int _rarity, std::string _name, std::string _sex);

        int init(int _rarity, std::string _name, std::string _cClass, std::string _subclass, std::string _sex);
        int rollD6(int _x); // Rola dado _x vezes

        std::string getCard();

    private:
        std::string name;
        std::string cClass;
        std::string subclass;
        std::string sex;

        // Atributos Básicos
        int health;          // Pontos de vida do personagem
        int mana;            // Pontos de energia mágica
        int stamina;         // Energia para ataques ou movimentos físicos
        int level;           // Nível do personagem
        int experience;      // Pontos de experiência acumulados
        int rarity;           // Define a raridade da carta (1 - 8)

        // Atributos Primários
        int strength;        // Força física (afeta dano de ataques físicos)
        int agility;         // Agilidade (afeta velocidade de ataque e evasão)
        int intelligence;    // Inteligência (afeta dano mágico e regeneração de mana)
        int charisma;        // Carisma (influência em interações sociais e negociação)
        int constitution;    // Constituição (afeta a resistência e pontos de vida)
        int dexterity;       // Destreza (afeta precisão e habilidades manuais)
        int luck;            // Sorte (afeta chances de crítico e eventos aleatórios)

        std::map <std::string,std::vector<std::string>> hierarquia = {
            {"Dragon",{"Elder Dragon","Fire Drake","Frost Wyrm","Shadow Wyvern","Storm Dragon"}},
            {"Druid",{"Beast Shapeshifter","Elemental Weaver","Forest Sage","Mooncaller","Natures Guardian"}},
            {"Elf",{"Arcane Archer","Bladedancer","High Elf Mage","Shadowblade","Wild Elf Tracker"}}//,
            //{"Orc",{"Beastmaster","Berserker","Bloodreaver","Ironclad Orc","War Shaman"}},
            //{"Warrior",{"Battlelord","Gladiator","Shieldbearer","Swordmaster","Warlord"}}
        };
        
};

#include "../../src/card/card.cpp"

#endif