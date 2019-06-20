#include "napi.h"
#include "JsVlcMediaPlayer.hpp"

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  JsVlcMediaPlayer::Init(env, exports);
  return exports;
}

// Register and initialize native add-on
NODE_API_MODULE(Cerberus, Init)