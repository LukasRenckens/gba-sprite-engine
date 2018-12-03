//
// Created by Lukas on 29/11/2018.
//

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include "MyScene.h"
#include "smile.h"
#include "bg_test.h"
#include "track1.h"


std::vector<Background *> MyScene::backgrounds() {
    return {
        bg_test.get()

    };
}

std::vector<Sprite *> MyScene::sprites() {
    return {
        smile.get()
    };
}

void MyScene::load() {
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(smilePal, sizeof(smilePal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(track_pal, sizeof(track_pal)));

    SpriteBuilder<Sprite> builder;

    smile = builder
            .withData(smileTiles, sizeof(smileTiles))
            .withSize(SIZE_8_8)
            .withLocation(110, 80)
            .buildPtr();

    bg_test = std::unique_ptr<Background>(new Background(1, track_data, sizeof(track_data), track1, sizeof(track1)));
    bg_test.get()->useMapScreenBlock(16);
}

void MyScene::tick(u16 keys) {

    scrollY -= 1;

    smile.get()->moveTo(smile.get()->getX(),smile.get()->getY() - 1);

    bg_test.get()->scroll(scrollX, scrollY);

}
