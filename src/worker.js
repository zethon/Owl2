console.log("WORKER!!");
const {sub,add} = require('../owlapi/build/Release/owlapi.node');
var subevent = 
    {
        'value': sub(4,1),
        'func' : 'sub'
    };

postMessage(subevent);

//address of native addon 
// const {add} = require('./owlapi/build/Release/owlapi.node'); 
//Calling functions of native addon 
var retevent = 
    {
        'value': add(3,4),
        'func' : "add"
    };

//console.log(result);
//communicating with main process of electron app.
postMessage(retevent);

const {BoardProxy} = require('../owlapi/build/Release/owlapi.node');
const assert = require("assert");
assert(BoardProxy, "No BoardProxy!");
const board = new BoardProxy("id222");
assert(board.id, "No board id function");
console.log("BOARD: " + board.id())
var boardevent = 
    {
        'value': board.id(),
        'func' : 'board'
    };
postMessage(boardevent);

