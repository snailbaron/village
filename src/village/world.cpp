#include "world.hpp"

void World::update(Time delta)
{
    _movementSystem.update(_entityManager, delta);

    _aiSystem.update(_entityManager, delta);
}
