#ifndef GAME_RUNTIME_H
#define GAME_RUNTIME_H

#include <functional>

namespace GameRuntime
{
    /**
     * Runs the game loop, simply.
     *
     * @param onStart  - Initial function, called once
     * @param onUpdate - Update function, called every frame
     * @param onFinish  - Finish function, called before game finishes
     */
    void run(
        const std::function<void()> onStart,
        const std::function<void()> onUpdate,
        const std::function<void()> onFinish);

    /**
     * Enable to finish the game loop
     */
    void finish();
}

#endif