//address of native addon 
const {add} = require('./owlapi/build/Release/addon.node'); 
//Calling functions of native addon 
var result = add(3,4);
result.func = "add";
//console.log(result);
//communicating with main process of electron app.
postMessage(result);
