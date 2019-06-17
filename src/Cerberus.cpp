#include "napi.h"
#include "CerberusPlayer.hpp"

Napi::Object Init (Napi::Env env, Napi::Object exports) {
  CerberusPlayer::Init(env, exports);
  return exports;
}

// Register and initialize native add-on
NODE_API_MODULE(Cerberus, Init)