#pragma once

#include "ai.hpp"
#include "movement.hpp"

#include "ge/thing.hpp"

class World {
public:
    void update(Time delta);

private:
    ge::EntityManager _entityManager;
    MovementSystem _movementSystem;
    AiSystem _aiSystem;
};
