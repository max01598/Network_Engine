#include <iostream>
#include "engine/engine/engine.hpp"

int main(int argc, char* argv[])
{
    auto& engine = engine::engine::Engine::Instance();
    engine.ParseCommandeLine(argc, argv);
    engine.Run();
    return EXIT_SUCCESS;
}