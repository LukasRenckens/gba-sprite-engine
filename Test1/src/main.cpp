//
// Created by Lukas on 29/11/2018.
//
#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/background/text.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/palette/palette_manager.h>
#include <libgba-sprite-engine/allocator.h>

#include "MyScene.h"

int main(){

    std::shared_ptr<GBAEngine> engine(new GBAEngine());

    MyScene* startScene = new MyScene(engine);
    engine->setScene(startScene);

    while (true){
        engine->update();
        engine->delay(1000);
    }
}