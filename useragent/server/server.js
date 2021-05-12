const express = require("express");
const { readFileSync } = require("fs");
const path = require("path");

const app = express();
const flag = readFileSync("flag.txt", "utf-8");

app.get("/",function (request,response){
    const agent = request.get("User-Agent");
    var userthing;

    if (/gerald/.test(agent.toLowerCase())) {
        userthing = `<!DOCTYPE html>
        <html>
            <head>
            </head>
            <body>
                <h1>Welcome to the Stegosaurus Intelligence-6 Homepage</h1>
                <h2>Are you Agent Gerald?</h2>
                <img src="gerald.PNG" alt="agent gerald" style="width: 50%"></img>
                   <h4> Welcome, Agent Gerald! Your flag is: ${flag} </h4>
            </body>
        </html>`;

    } else {
        userthing = `<!DOCTYPE html>
        <html>
            <head>
            </head>
            <body>
                <h1>Welcome to the Stegosaurus Intelligence-6 Homepage</h1>
                <h2>Are you Agent Gerald?</h2>
                <img src="gerald.PNG" alt="agent gerald" style="width: 50%"></img>
                <h4> You're not Agent Gerald...</h4>
            </body>
        </html>`;
    }

    response.send(userthing);
        

});

app.use(express.static(path.join(__dirname,"public")));

app.listen(2562);
console.log("Listening on http://localhost:2562");




