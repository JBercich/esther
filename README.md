# Game Project

## Overview

Codebase for a game written in C++ and using SDL2 as a wrapper for asset rendering and audio management. All other features such as physics and game engines, and overall game logic are all selfmade from scratch.

This repo is public at the moment, but big plans will push this to be made private.

### Structure

File structure [reference](https://www.linkedin.com/pulse/what-general-c-project-structure-like-herbert-elwood-gilliland-iii/) for the application melds a bunch of different parts. The overall game structure is defined below.

```
└── game            # Contain anything related to the game          
    ├── assets      # Store assets and animations
    ├── audio       # Store any audio files
    ├── bin         # Executables
    ├── build       # Compilation binaries
    ├── doc         # Documentation files
    ├── inc         # External libraries
    ├── lib         # Library headers
    └── src         # All source code for the game
```

### `make`

Currently using `cmake` for generating the needed make files. Using [this guide](https://cmake.org/cmake/help/latest/guide/tutorial/A%20Basic%20Starting%20Point.html) for starting off with this tool.

```
cd game
cmake -H. -DCMAKE_BUILD_TYPE=<Debug,Release>
```


# Library Management

Refer to `game/CMakeLists.txt` for the search patterns used for locating library files (`PACKAGE_SEARCH_PATHS`).

## Darwin

This is the OS I use for development. There were a few known issues that I encountered for adding certain library files.

- `SDL2*` libraries seemed to not contain any linker directory when installed via homebrew. I suggest installing `.dmg` framework releases from official [GitHub `libsdl` repos](https://github.com/libsdl-org/SDL/releases). There appeared to issues with popular installed libraries such as `ffmpeg` which didn't would impact sourcing libraries files and so I needed to uninstall these and only add the `.framework` releases to `/Library/Frameworks` which I add as a search pattern.
- `SPDLOG` could be installed directly with homebrew with no known issues.

## Linux

Not tested.

## Windows

Not tested.
