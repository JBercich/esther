// #include <Game/GameLoop.hpp>

// #include <Engine/Utilities/FPSCounter.hpp>
// #include <iostream>

// void GameLoop::controller(){};

// void GameLoop::update(){};

// void GameLoop::draw(){};

// void GameLoop::run() {

//   SDL_Event e;
//   FPSCounter fpsCounter;

//   for (int i = 0; i < 600; i++) {
//     //   while (running) {

//     fpsCounter.startLoop();
//     if (fpsCounter.frameRate == fpsCounter.frameCounter) {
//       cout << "FPS: " << to_string(fpsCounter.fps()) << "\n";
//     }

//     while (SDL_PollEvent(&e)) {
//       if (e.type == SDL_QUIT || e.type == SDL_KEYDOWN) {
//         running = false;
//       }
//     }

//     fpsCounter.endLoop();
//   }
// };
