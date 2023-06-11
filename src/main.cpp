#include <Esther/Esther.hpp>
#include <Engine/Engine.hpp>

#include <cstdlib>
#include <csignal>
#include <iostream>

void exiting() {
    std::cout << "Exiting";
}
void exiting_s(int i) {
    std::cout << "Exiting"<<std::endl; exit(0);
}


int main()
{
        //^C
    signal(SIGINT, exiting_s);
    //abort()
    signal(SIGABRT, exiting_s);
    //sent by "kill" command
    signal(SIGTERM, exiting_s);
    //^Z
    signal(SIGTSTP, exiting_s);
    std::atexit(exiting);
    std::set_terminate(exiting);
    Esther::Esther game;
    Engine::Engine engine;
    engine.run(game);
}
