#include <napi.h>
#include "Board.h"

namespace owl
{

class BoardProxy : 
    public Napi::ObjectWrap<BoardProxy>
{
public:
    BoardProxy(const Napi::CallbackInfo&);
    Napi::Value id(const Napi::CallbackInfo&);

    static Napi::Function GetClass(Napi::Env);

private:
    owl::BoardPtr   _board;
};

//add function wrapper
Napi::Number addWrapped(const Napi::CallbackInfo& info);
Napi::Number subWrapped(const Napi::CallbackInfo& info);
 
//Export API
Napi::Object Init(Napi::Env env, Napi::Object exports);
NODE_API_MODULE(addon, Init)

}