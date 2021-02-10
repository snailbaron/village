#include "ai.hpp"

#include "movement.hpp"

namespace {

constexpr auto minTargetDistance = 3_m;
constexpr auto maxTargetDistance = 10_m;
constexpr auto targetReachedDistance = 1_m;
constexpr auto minWaitTime = 1_sec;
constexpr auto maxWaitTime = 3_sec;

} // namespace

void AiSystem::update(ge::EntityManager& entityManager, Time delta)
{
    for (auto e : entityManager.entities<DummyAiComponent>()) {
        auto& ai = entityManager.component<DummyAiComponent>(e);
        auto& movement = entityManager.component<MovementComponent>(e);

        if (ai.timeToWait > 0) {
            if (ai.timeToWait > delta) {
                ai.timeToWait -= delta;
            } else {
                ai.timeToWait = 0;
                ai.targetPoint = randomPointInRing(
                    movement.position, minTargetDistance, maxTargetDistance);
                movement.control = (ai.targetPoint - movement.position).unit();
            }
        } else if (distance(movement.position, ai.targetPoint) <=
                targetReachedDistance) {
            ai.timeToWait = randomTime(minWaitTime, maxWaitTime);
        } else {
            // NPC position may change due to external factors, so fix the
            // direction here.
            movement.control = (ai.targetPoint - movement.position).unit();
        }
    }
}
