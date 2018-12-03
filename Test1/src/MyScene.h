//
// Created by Lukas on 29/11/2018.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_MYSCENE_H
#define GBA_SPRITE_ENGINE_PROJECT_MYSCENE_H
#include <libgba-sprite-engine/scene.h>

class MyScene: public Scene {
private:
    std::unique_ptr<Sprite> smile;
    std::unique_ptr<Background> bg_test;

    int scrollX, scrollY;

public:
    MyScene(std::shared_ptr<GBAEngine> engine) : Scene(engine), scrollX(0), scrollY(0) {}

    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    void load() override;
    void tick(u16 keys) override;

};


#endif //GBA_SPRITE_ENGINE_PROJECT_MYSCENE_H
