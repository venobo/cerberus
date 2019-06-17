//
// Created by marcus-sa on 6/11/2019.
// notes: switch to cmake-js when
// * node_api.h not found
// * ERR! OMG There is no Visual C++ compiler installed. Install Visual C++ Build Toolset or Visual Studio
//
#include "napi.h"
#include "CerberusPlayer.hpp"

Napi::FunctionReference CerberusPlayer::constructor;

Napi::Object CerberusPlayer::Init(Napi::Env env, Napi::Object exports) {
	// This method is used to hook the accessor and method callbacks
	Napi::Function func = DefineClass(env, "CerberusPlayer", {
		// InstanceMethod("GetValue", &Example::GetValue),
		// InstanceMethod("SetValue", &Example::SetValue)
	});

	// Create a persistent reference to the class constructor. This will allow
	// a function called on a class prototype and a function
	// called on instance of a class to be distinguished from each other.
	constructor = Napi::Persistent(func);
	// Call the SuppressDestruct() method on the static data prevent the calling
	// to this destructor to reset the reference when the environment is no longer
	// available.
	constructor.SuppressDestruct();
	exports.Set("CerberusPlayer", func);

	return exports;
}

// c++ based constructor
CerberusPlayer::CerberusPlayer(const Napi::CallbackInfo &info) : Napi::ObjectWrap<CerberusPlayer>(info) {
	Napi::Env env = info.Env();
}

