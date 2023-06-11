#include <Engine/Core/GameLoop.hpp>
#include <Engine/Core/GameController.hpp>

namespace Engine 
{
    /**
     * Execute the game loop.
     * 
     * Execution game controller
     *      An added GameController utility is used for ensuring the execution of the
     *      game loop is efficient and with suitable FPS and tick rate results. A
     *      deWitter implementation is used.
     */
    void GameLoop::start()
    {
        GameController controller;
        while(running)
        {
            controller.step();
            while(controller.canUpdate())
            {
                input();
                update();
                controller.update();
            }
            render(controller.getInterpolation());
        }
    };

    /**
     * TODO
     */
    void GameLoop::input() 
    {

    };

    /**
     * TODO
     */
    void GameLoop::update() 
    {

    };

    /**
     * TODO
     */
    void GameLoop::render(double interpolation) 
    {

    };
}
