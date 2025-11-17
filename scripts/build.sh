#!/bin/bash

PROJECT_DIR=`realpath $(dirname $(dirname ${BASH_SOURCE[0]}))`
printf "Building project: %s \n" $PROJECT_DIR
cmake \
    -S"$PROJECT_DIR/src" \
    -B"$PROJECT_DIR/build" \
    --fresh 
make -C $PROJECT_DIR/build

