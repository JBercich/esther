
#ifndef LOGGER_H
#define LOGGER_H

#include <map>
#include <string>

namespace Engine
{

    enum Logger { Engine, Runtime };
    static std::map<Logger, std::string> LoggerMap {{Engine, "Engine"}, {Runtime, "Runtime"}};
    void initLogger();
    void quitLogger();
}

#endif
