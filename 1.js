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


// const promise1 = new Promise((resolve,reject)=>{
//     setTimeout(resolve,500,'one');
// });

// const promise2 = new Promise((resolve,reject)=>{
//     setTimeout(resolve,100,'two');
// });

// Promise.race([promise1,promise2]).then((value)=>{
//     console.log(value);
// });

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