// This file is required by the index.html file and will
// be executed in the renderer process for that window.
// No Node.js APIs are available in this process because
// `nodeIntegration` is turned off. Use `preload.js` to
// selectively enable features needed in the rendering
// process.

var worker = new Worker('./worker.js');
worker.onmessage = function(event) 
{ 
    console.log(event);
    if (event.data.func == "add")
    {
        //print result on console and h1 tag
        console.log("worker : ", event.data.value);
        document.querySelector('h1').innerHTML = "native addon add function(3, 4): " + event.data.value;
        //terminate webworker
        // worker.terminate();
    }
    else if (event.data.func == "sub")
    {
        console.log("EVENT RESPONSE: " + event.data);
        var subel = document.getElementById('subvalue'); 
        subel.innerText = "sub is [" + event.data.value + "]";
    }
   
   //set it to undefined
//    worker = undefined;
}

worker.onerror = function (event) 
{
    console.log(event.message, event);
};