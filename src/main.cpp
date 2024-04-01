#include <Esther/Esther.hpp>
#include <Engine/Engine.hpp>

int main()
{
    Engine::Engine engine;
    Esther::Esther game;
    engine.initialise();
    engine.run(game);
    engine.shutdown();
}
