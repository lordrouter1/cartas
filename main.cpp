#include <emscripten/bind.h>
#include <emscripten.h>
#include <emscripten/html5.h>
#include <emscripten/val.h>

#include <iostream>

#include "include/card/card.h"

#include "src/binds.cpp"
#include "src/events.cpp"

int main(){
    emscripten::val elPai[5];

    Card *card[5]; 
    card[0] = new Card(1,"Dragon Master","Male");
    card[1] = new Card(1,"Retdro","Male");
    card[2] = new Card(1,"asilion","Male");
    card[3] = new Card(1,"darf","Male");
    card[4] = new Card(1,"teste de teste testado","Male");

    emscripten::val doc = emscripten::val::global("document");

    elPai[0] = doc.call<emscripten::val>("getElementById",std::string("slot1"));
    elPai[1] = doc.call<emscripten::val>("getElementById",std::string("slot2"));
    elPai[2] = doc.call<emscripten::val>("getElementById",std::string("slot3"));
    elPai[3] = doc.call<emscripten::val>("getElementById",std::string("slot4"));
    elPai[4] = doc.call<emscripten::val>("getElementById",std::string("slot5"));

    elPai[0].set("innerHTML",card[0]->getCard());
    elPai[1].set("innerHTML",card[1]->getCard());
    elPai[2].set("innerHTML",card[2]->getCard());
    elPai[3].set("innerHTML",card[3]->getCard());
    elPai[4].set("innerHTML",card[4]->getCard());

    initEvents();

    std::cout << "v:00012" << std::endl;
    return 0;
}