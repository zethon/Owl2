//address of native addon 
const {add} = require('./owlapi/build/Release/addon.node'); 
//Calling functions of native addon 
var retevent = 
    {
        'value': add(3,4),
        'func' : "add"
    };

//console.log(result);
//communicating with main process of electron app.
postMessage(retevent, "");

const {sub} = require('./owlapi/build/Release/addon.node');
var subevent = 
    {
        'value': sub(4,1),
        'func' : 'sub'
    };

postMessage(subevent, "");
