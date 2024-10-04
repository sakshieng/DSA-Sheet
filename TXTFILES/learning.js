// class Foo {
//     static cool() {
//         console.log('hi');
//     }
// }; 
// const foo = new Foo(); foo.cool();
// function find_max(nums) {
//     let max_num = Number.NEGATIVE_INFINITY; // smaller than all other numbers
//     for (let num of nums) {
//         if (num > max_num) {
//             // (Fill in the missing line here)
//         }
//     }
//     return max_num;
// }

// const { log } = require('console');

// console.log(arguments)

// async function foo(){
//     try{
//         await Promise.reject(new Error("went wrong"));
//     }catch(error){
//             console.error(error.message);
//     }
// }
// foo();

// const fs = require('fs').promises;
// async function readAndPrint(){
//     try{
//         const data = await fs.readFile('file.txt','utf-8');
//         console.log(data);
//     }catch(err){
//         console.log(err);
//     }
// }
// readAndPrint();
// console.log(('Done read'));
// const http = require('http');
// const server = http.createServer((req,res)=>{
//     res.end('Hellpo');
// });
// server.listen(3000);

// let logVal = []
// const context = {
//     console:{
//         log:(value)=>{
//             logVal.push(value)
//         }
//     }
// }

// const http = require('http');
// const host = '127.0.0.1';
// const port = 3000;
// const server = http.createServer((req,res)=>{
//     res.statusCode = 200;
//     res.setHeader("content-type","text/plain");
//     res.end("hello");
// });
// server.listen(port,host,()=>{
//     console.log(`sewrver at http://${host}:${port}`);
// });

// const eventEmitter = require('events');
// class myEmitter extends eventEmitter{}
// const MyEmitter = new myEmitter();
// MyEmitter.on('event',()=>{
//     console.log('an event occured');
// });
// MyEmitter.emit('event');


const promise1 = new Promise((resolve, reject) => {
    setTimeout(resolve, 50, 'one');
});

const promise2 = new Promise((resolve, reject) => {
    setTimeout(resolve, 100, 'two');
});

Promise.race([promise1, promise2]).then((value) => {
    console.log(value);
});

// var fs = require('fs');
// var path = require('path');
// const dire = "test";
// const deleteFile = async()=>{
//     for await(const file of fs.readdir(dire)){
//         await fs.unlink(path.join(dire,file));
//     }
// };
// deleteFile();

// const fs = require('fs').promises;
// const printFile = async()=>{
//     const fileName = ["a.txt","b.txt","c.txt"];
//     fileName.forEach(async(fileName)=>{
//         let contents = await fs.readFile(fileName,"utf-8");
//         console.log(`\n\n${fileName}\n\n`);
//         console.log(contents.toString());
//     });
// };

// (function(){
//     console.log("a");
//     setTimeout(()=>console.log("b"),1000);
//     console.log("c");
//     setTimeout(()=>console.log("d"),500);
// })();

// let x = 10;
// let x = 20;
// console.log(x);

// var bar = function Foo() 
// {
//     return 11;
// }; 
// typeof Foo(); would give refrence error

// Node.js->single-threaded and asynchronous
// var declarations are globally scoped while let and const are blocks scoped.

// var variables can be updated and re-declared within its scope; let variables be updated but not re-declared; const variables can neither be updated nor re-declared. 

// They are all hoisted to the top of their scope. But while var variables are initialised with undefined, let, and const variables are not initialised.

// While var and let can be declared without being initialised, const must be initialized during declaration.



// String coercion takes place while using the ‘ + ‘ operator. When a number is added to a string, the number type is always converted to the string type.

// In JS,NaN is also of type Number
// The data type for the null value is "Object"

// Node.js follows an event-loop architecture that has the following phases: timers, pending callbacks, idle prepare, poll, check, close callbacks, incoming connections/ data/ request

// async function fetchData() {
//   try {
//     const response = await fetch('(link unavailable)');
//     const data = await response.json();
//     console.log(data);
//   } catch (error) {
//     console.error(error);
//   }
// }using this will make ur code look synchronous, even though it's still asynchronous

// function x() {
// for(var i = 1; i<=5; i++){
//     setTimeout(function() {
//     console.log(i);
//     }, i*1000);
//     }
//     console.log("Namaste Javascript");
// }
// x();//answer is 6 6 6 6 Due to closures-> When setTimeout stores function somewhere and attaches timer to it, the function remembers its reference to i, not value of i. All 5 copies of function point to same reference of i. JS stores these 5 functions, prints string and then comes back to the functions. By then the timer has run fully. And due to looping, the i value became 6. And when the callback fun runs the variable i = 6. So same 6 is printed in each log

// function x1() {
// for(let i = 1; i<=5; i++){
//     setTimeout(function() {
//     console.log(i);
//     }, i*1000);
//     }
//     console.log("Namaste Javascript");
// }
// x1();//answer is 1 2 3 4