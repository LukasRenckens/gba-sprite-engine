project(Test1)

add_executable(${PROJECT_NAME}.elf
        src/main.cpp
        src/MyScene.cpp
        src/MyScene.h
        src/smile.h
        src/bg_test.h
        src/track1.h)

target_link_libraries(${PROJECT_NAME}.elf gba-sprite-engine)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -v -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.gba
        )
