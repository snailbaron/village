#pragma once

#include <ge/thing.hpp>

struct MovementComponent {
    Position position;
    Velocity velocity;
    Acceleration control;
};

class MovementSystem {
public:
    void update(ge::EntityManager& entityManager, Time delta);
};
