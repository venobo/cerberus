//
// Created by marcus-sa on 6/11/2019.
//

#ifndef CERBERUS_PLAYER_HPP
#define CERBERUS_PLAYER_HPP

#include <napi.h>
#include <vlc.hpp>

class JsVlcMediaPlayer : public Napi::ObjectWrap<JsVlcMediaPlayer> {
  public:
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    JsVlcMediaPlayer(const Napi::CallbackInfo &info);

  private:
    static Napi::FunctionReference constructor;

    std::string _videoURI;
    VLC::Instance _vlc;
    VLC::Media _media;
    VLC::MediaPlayer _mp;
    Napi::Function _emit;

    Napi::Value GetMute(const Napi::CallbackInfo &info);
    void SetMute(const Napi::CallbackInfo &info, const Napi::Value& value);

    Napi::Value Play(const Napi::CallbackInfo &info);
    void Pause(const Napi::CallbackInfo &info);
    void Stop(const Napi::CallbackInfo &info);
};

#endif //CERBERUS_PLAYER_HPP
