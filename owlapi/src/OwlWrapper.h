#include <napi.h>

namespace example
{

//add function wrapper
Napi::Number addWrapped(const Napi::CallbackInfo& info);
Napi::Number subWrapped(const Napi::CallbackInfo& info);
 
//Export API
Napi::Object Init(Napi::Env env, Napi::Object exports);
NODE_API_MODULE(addon, Init)

}