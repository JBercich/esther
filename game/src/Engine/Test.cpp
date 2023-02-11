// #include <Engine/GameLoop.hpp>
// #include <SDL2/SDL.h>
// #include <map>
// #include <functional>
// using namespace std;

// map<int, bool> keys_on;
// map<int, function<void()>> do_action;

// //Give action to key function
// void give_action(int key, std::function<void()> func) {
//   do_action[key] = func;
// }

// // assign actions for key
// void press_a() {
//   cout << "a";
// }

// SDL_Event event;

// void run(){
//   // do_action[SDLK_a] = press_a;
//   give_action(SDLK_a, press_a);

//   while (SDL_PollEvent(&event)){
//     if (event.type == SDL_KEYDOWN) {
//       if (keys_on[event.key.keysym.sym] == NULL){
//         keys_on[event.key.keysym.sym] = true;
//       }
//       else {
//         keys_on[event.key.keysym.sym] != keys_on[event.key.keysym.sym];
//       }
//     }
//     // run stuff
//     if (keys_on[event.key.keysym.sym] = true) {
//       do_action[event.key.keysym.sym];
//     }
//   }
// }