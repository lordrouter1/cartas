
Card::Card(int _rarity, std::string _name, std::string _cClass, std::string _subclass, std::string _sex){
    this->init(_rarity,_name,_cClass,_subclass,_sex);

    return;
}

Card::Card(int _rarity, std::string _name, std::string _sex){
    auto it = this->hierarquia.begin();

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> rClass(0,this->hierarquia.size()-1);

    std::advance(it, rClass(gen));

    std::uniform_int_distribution<> rSubClass(0,it->second.size()-1);

    this->init(_rarity,_name,it->first,it->second[rSubClass(gen)],_sex);

    return;
}


int Card::init(int _rarity, std::string _name, std::string _cClass, std::string _subclass, std::string _sex){
    this->name = _name;
    this->cClass = _cClass;
    this->subclass = _subclass;
    this->sex = _sex;
    this->rarity = _rarity;

    this->health = this->rollD6(_rarity) * 100;
    this->mana = this->rollD6(_rarity) * 50;
    this->stamina = this->rollD6(_rarity) * 50;
    this->level = 1;
    this->experience = 0;

    this->strength = this->rollD6(_rarity);
    this->agility = this->rollD6(_rarity);
    this->intelligence = this->rollD6(_rarity);
    this->charisma = this->rollD6(_rarity);
    this->constitution = this->rollD6(_rarity);
    this->dexterity = this->rollD6(_rarity);
    this->luck = this->rollD6(_rarity);

    return 0;
}

int Card::rollD6(int _x){
    int cont = 0;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1,6);

    for(int i=0;i<_x;i++){
        cont += distrib(gen);
    }

    return cont;
};

std::string Card::getCard(){
    std::string resp = "";

    resp += "    <div class='bg-light cards cards-"+std::to_string(this->rarity)+" m-auto card' data-bs-toggle='modal' data-bs-target='#modal'>";
    resp += "        <div class='card-head p-1'>";
    resp += "            <div class='container-fluid'>";
    resp += "                <div class='row border-bottom'>";
    resp += "                    <div class='col text-center'>";
    resp += "                        <span class='ml-auto'><strong>"+this->name+"</strong></span>";
    resp += "                    </div>";
    resp += "                </div>";
    resp += "                <div class='row'>";
    resp += "                    <div class='col text-end'>";
    resp += "                        <span>"+std::to_string(this->level)+"</span> lvl";
    resp += "                    </div>";
    resp += "                </div>";
    resp += "            </div>";
    resp += "        </div>";
    resp += "        <img class='card-img-top' src='/html/img/card/moster/"+this->cClass+"/"+this->subclass+"/"+this->sex[0]+std::to_string(this->rarity)+".jpg'>";
    resp += "        <div class='card-footer h-25'>";
    resp += "            <div class='row'>";
    resp += "                <div class='col text-center'>"+this->cClass+" <br> "+this->subclass+"</div>";
    resp += "            </div>";
    resp += "        </div>";
    resp += "    </div>";

    return resp;
}