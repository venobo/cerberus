//
// Created by marcus-sa on 6/11/2019.
//

#ifndef CERBERUS_PLAYER_HPP
#define CERBERUS_PLAYER_HPP

class CerberusPlayer : public Napi::ObjectWrap<CerberusPlayer> {
  public:
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    CerberusPlayer(const Napi::CallbackInfo &info);

  private:
    static Napi::FunctionReference constructor;
};

#endif //CERBERUS_PLAYER_HPP
