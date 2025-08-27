#include "GameRuntime.h"

namespace GameRuntime
{
    bool shouldFinish{false};
}

void GameRuntime::run(
    const std::function<void()> onStart,
    const std::function<void()> onUpdate,
    const std::function<void()> onFinish)
{
    if (onStart)
        onStart();

    do
    {
        if (onUpdate)
            onUpdate();
        else // We need to end process, there is nothing to do
            finish();
    } while (!shouldFinish);

    if (onFinish)
        onFinish();
}

void GameRuntime::finish()
{
    shouldFinish = true;
}
