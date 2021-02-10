#pragma once

#include "dimensions.hpp"

#include <ge.hpp>

class DummyAiComponent {
public:
    Position targetPoint;
    Time timeToWait = 0.0;
};

class AiSystem {
public:
    void update(ge::EntityManager& entityManager, Time delta);
};
