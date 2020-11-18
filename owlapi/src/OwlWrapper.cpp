#include "example.h"
#include "OwlWrapper.h"

namespace owl
{

BoardProxy::BoardProxy(const Napi::CallbackInfo& info) 
    : ObjectWrap{info}
{
    Napi::Env env = info.Env();

    if (info.Length() < 1) 
    {
        Napi::TypeError::New(env, "Wrong number of arguments")
            .ThrowAsJavaScriptException();

        return;
    }

    if (!info[0].IsString()) 
    {
        Napi::TypeError::New(env, "there's no board Id!")
            .ThrowAsJavaScriptException();

        return;
    }

    const std::string id = info[0].As<Napi::String>().Utf8Value();
    _board = std::make_shared<owl::Board>(id);
}

Napi::Value BoardProxy::id(const Napi::CallbackInfo& info) 
{
    Napi::Env env = info.Env();
    return Napi::String::New(env, _board->id());
}

Napi::Function BoardProxy::GetClass(Napi::Env env) 
{
    return DefineClass(env, 
        "BoardProxy", 
        {
            BoardProxy::InstanceMethod("id", &BoardProxy::id),
        });
}

// Napi::Object Init(Napi::Env env, Napi::Object exports) 
// {
//     Napi::String name = Napi::String::New(env, "BoardProxy");
//     exports.Set(name, BoardProxy::GetClass(env));
//     return exports;
// }

Napi::Number addWrapped(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();
    
    //check if arguments are integer only.
    if(info.Length()<2 || !info[0].IsNumber() || !info[1].IsNumber())
    {
        Napi::TypeError::New(env, "arg1::Number, arg2::Number expected").ThrowAsJavaScriptException();
    }

    //convert javascripts datatype to c++
    Napi::Number first = info[0].As<Napi::Number>();
    Napi::Number second = info[1].As<Napi::Number>();
    
    //run c++ function return value and return it in javascript
    Napi::Number returnValue = Napi::Number::New(env, owl::add(first.Int32Value(), second.Int32Value()));
    
    return returnValue;
}

Napi::Number subWrapped(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();
    //check if arguments are integer only.
    if(info.Length()<2 || !info[0].IsNumber() || !info[1].IsNumber()){
        Napi::TypeError::New(env, "arg1::Number, arg2::Number expected").ThrowAsJavaScriptException();
    }
    //convert javascripts datatype to c++
    Napi::Number first = info[0].As<Napi::Number>();
    Napi::Number second = info[1].As<Napi::Number>();
    //run c++ function return value and return it in javascript
    Napi::Number returnValue = Napi::Number::New(env, owl::sub(first.Int32Value(), second.Int32Value()));
    
    return returnValue;
}

Napi::Object Init(Napi::Env env, Napi::Object exports) 
{
    Napi::String name = Napi::String::New(env, "BoardProxy");
    exports.Set(name, BoardProxy::GetClass(env));
    // return exports;

    //export Napi function
    exports.Set("add", Napi::Function::New(env, owl::addWrapped));
    exports.Set("sub", Napi::Function::New(env, owl::subWrapped));
    return exports;
}

}