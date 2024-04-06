#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

namespace Engine::Managers
{
    /**
     * Abstract class defining a set of required functionalities for managers that 
     * control certain resources for the engine. Certain functions must be overriden to
     * be used by subclasses in a general setting.
     */
    class ResourceManager 
    {
        public:
            /**
             * The resource controlled by this manager is properly initialised and once
             * completed, the resource can be used with the exepected functionality.
             */
            virtual void initialise(){};

            /**
             * The resource controlled by this manager is properly shutdown and not in
             * use any more, memory usage is deallocated correctly.
             */
            virtual void shutdown(){};
    };
}

#endif
