#include <Engine/Core/GameController.hpp>

#include <chrono>
#include <thread>
#include <iostream>

void GameController::step()
{   
    frameStart = std::chrono::steady_clock::now();
    frameElapsed = frameStart - framePrevious;
    framePrevious = frameStart;
    std::cout << frameElapsed.count() << std::endl;
    // std::this_thread::sleep_until(frameDelay);
};

void GameController::update()
{

};

bool GameController::canUpdate()
{
    return false;
};