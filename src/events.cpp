#include <emscripten/html5.h>
#include <iostream>

EM_BOOL campMenu_callBack(int et, const EmscriptenMouseEvent *me, void *userData);

void initEvents(){

    emscripten_set_click_callback("#hidden",NULL,EM_TRUE,campMenu_callBack);

    return;
}

EM_BOOL campMenu_callBack(int et, const EmscriptenMouseEvent *me, void *userData){
    std::string nClass = "disabled";

    emscripten::val doc = emscripten::val::global("document");

    emscripten::val el = doc.call<emscripten::val>("getElementById",std::string("camp"));

    emscripten::val ev = emscripten::val::global("event")["target"];

    if(ev["id"].as<std::string>() == "hidden"){
        if(el["classList"].call<bool>("contains",nClass)){
            el["classList"].call<void>("remove",nClass);
        }else{
            el["classList"].call<void>("add",nClass);
        }
    }

    return EM_TRUE;
}