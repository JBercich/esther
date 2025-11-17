# Esther

## Overview

Working towards a simple and lightweight customizable game engine in C++ using SDL2
for helping with cross-platform builds. 

## Build

Cmake is used for building the project. Considering the eventual size of the codebase, a
monolith build with static definitions of project files is done in the branching nested
directories **rather** than using a regex globbing for packaging `.cpp` and headers.

```shell
$ cd build
$ cmake ..     
$ make
$ ./Esther
```

> [!NOTE]
> Development on this project is taking place on an `arm64` MacOS platform. At the early
> stages, cross-platforms builds and the output Cmarke artifacts are very much still in
> development.

## Documentation

Doxygen docs can be generated easily from the project root directory.

```shell
# Generate documentation 'html' and 'latex' output in /docs.
$ doxygen .doxygen
```