//
// Created by marcus-sa on 6/11/2019.
// notes: switch to cmake-js when
// * node_api.h not found
// * ERR! OMG There is no Visual C++ compiler installed. Install Visual C++ Build Toolset or Visual Studio
//
#include "napi.h"
#include "JsVlcMediaPlayer.hpp"
#include "vlc.hpp"

Napi::FunctionReference JsVlcMediaPlayer::constructor;

Napi::Object JsVlcMediaPlayer::Init(Napi::Env env, Napi::Object exports) {
	// This method is used to hook the accessor and method callbacks
	Napi::Function func = DefineClass(env, "VlcMediaPlayer", {  // CerberusPlayer // JsVlcMediaPlayer
	  InstanceAccessor("mute", &JsVlcMediaPlayer::GetMute, &JsVlcMediaPlayer::SetMute),
    InstanceMethod("play", &JsVlcMediaPlayer::Play),
    InstanceMethod("pause", &JsVlcMediaPlayer::Pause)
	});

	// Create a persistent reference to the class constructor. This will allow
	// a function called on a class prototype and a function
	// called on instance of a class to be distinguished from each other.
	constructor = Napi::Persistent(func);
	// Call the SuppressDestruct() method on the static data prevent the calling
	// to this destructor to reset the reference when the environment is no longer
	// available.
	constructor.SuppressDestruct();
	exports.Set("VlcMediaPlayer", func);

	return exports;
}

JsVlcMediaPlayer::JsVlcMediaPlayer(const Napi::CallbackInfo &info) : Napi::ObjectWrap<JsVlcMediaPlayer>(info) {
	Napi::Env env = info.Env();

	if (!info[0].IsString()) {
	  Napi::TypeError::New(env, "You must provide a video URI!").ThrowAsJavaScriptException();
	}/*else if (info.Length() > 1) {
	 Napi::TypeError::New(env, "You must provide a single argument!").ThrowAsJavaScriptException();
	}*/

  _videoURI = info[0].As<Napi::String>().ToString();

	// @TODO: JsVlcInstance & JsVlcMedia
  _vlc = VLC::Instance(0, nullptr);
  _media = VLC::Media(_vlc, _videoURI, VLC::Media::FromPath);
  _mp = VLC::MediaPlayer(_media);

  _emit = info.This().As<Napi::Object>().Get("emit").As<Napi::Function>();
}

void JsVlcMediaPlayer::SetMute(const Napi::CallbackInfo &info, const Napi::Value &value) {
  // @TODO: figure out whether or not its actually necessary
  bool mute = value.As<Napi::Boolean>().ToBoolean();

  // @TODO: disable all audio tracks instead, since this method might not always work
  _mp.setMute(mute);
}

Napi::Value JsVlcMediaPlayer::GetMute(const Napi::CallbackInfo &info) {
  return Napi::Boolean::New(info.Env(), _mp.mute());
}

Napi::Value JsVlcMediaPlayer::Play(const Napi::CallbackInfo &info) {
  return Napi::Boolean::New(info.Env(), _mp.play());
}

void JsVlcMediaPlayer::Stop(const Napi::CallbackInfo &info) {
  _mp.stop();
}

void JsVlcMediaPlayer::Pause(const Napi::CallbackInfo &info) {
  _mp.pause();
}

