ge_target(
    PROGRAM

    DEPENDS
        ge
        evening

    RESOURCES
        SPRITE /assets/sprites/tree.png
        SPRITE /assets/sprites/villager.png

    SOURCES
        ai.cpp
        main.cpp
        movement.cpp
        world.cpp
)
