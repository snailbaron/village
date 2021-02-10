#include "config.hpp"
#include "dimensions.hpp"
#include "events.hpp"
#include "world.hpp"

#include <ge.hpp>

int main()
{
    auto world = World{};

    ge::Client client;
    client.windowTitle = config().windowTitle;
    client.create();

    auto timer = ge::FrameTimer{config().fps};
    while (client.isAlive()) {
        client.processInput();

        if (int framesPassed = timer(); framesPassed > 0) {
            commands.deliver();
            for (int i = 0; i < framesPassed; i++) {
                world.update(timer.delta());
            }
            events.deliver();

            client.update(framesPassed * timer.delta());
            client.display();
        }

        timer.relax();
    }
}
