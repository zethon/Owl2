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
    if (event.func != "add")
    {
        //print result on console and h1 tag
        console.log("worker : ", event.data);
        document.querySelector('h1').innerHTML = "native addon add function(3, 4): " + event.data;
        //terminate webworker
        worker.terminate();
    }
    else
    {
        alert(event.data);
    }
   
   //set it to undefined
   worker = undefined;
}

worker.onerror = function (event) 
{
  console.log(event.message, event);
};