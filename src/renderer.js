// This file is required by the index.html file and will
// be executed in the renderer process for that window.
// No Node.js APIs are available in this process because
// `nodeIntegration` is turned off. Use `preload.js` to
// selectively enable features needed in the rendering
// process.

var worker = new Worker('./src/worker.js');
worker.onmessage = function(event) 
{ 
    console.log(event);
    if (event.data.func == "add")
    {
        var addel = document.getElementById('addvalue');
        addel.innerHTML = "add is [" + event.data.value + "]";
    }
    else if (event.data.func == "sub")
    {
        var subel = document.getElementById('subvalue'); 
        subel.innerHTML = "sub is [" + event.data.value + "]";
    }
   
   //set it to undefined
//    worker = undefined;
}

worker.onerror = function (event) 
{
    console.log(event.message, event);
};

document.querySelector('#btnEd').addEventListener('click', () => 
{
    var btnval = document.getElementById('buttonvalue');
    btnval.innerHTML = 'Button Clicked!';
})