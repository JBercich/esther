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
    ├── include     # External libraries
    ├── lib         # Library headers
    └── src         # All source code for the game
```

### `make`

Currently using `cmake` for generating the needed make files. Using [this guide](https://cmake.org/cmake/help/latest/guide/tutorial/A%20Basic%20Starting%20Point.html) for starting off with this tool.
