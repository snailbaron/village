#include "movement.hpp"

void MovementSystem::update(ge::EntityManager& entityManager, Time delta)
{
    for (auto& movement : entityManager.components<MovementComponent>()) {
        movement.position += velocity * delta;
    }
}
