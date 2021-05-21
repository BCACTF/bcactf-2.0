const express = require("express");
const socketio = require("socket.io");
const { readFileSync } = require("fs");
const md5 = require("md5");

const app = express();
app.use("/", express.static(__dirname + "/public"));
const port = process.env.PORT || 9000;
const server = app.listen(port);
const io = socketio(server, {
  cors: {
    origin: "*",
  },
});

const usernameFile = readFileSync("usernames.txt", "utf-8");
const usernames = usernameFile.split("\n");

const flag = readFileSync("flag.txt", "utf-8");

// If usernames are being sent in real-time, close socket after enough time has passed

io.on("connection", (socket) => {
  let username = usernames[Math.floor(Math.random() * usernames.length)].trim();
  socket.emit("username", username);
  socket.on("signInAttempt", (password) => {
    console.log("recieved password: " + password);
    console.log("username is: " + username);
    if (username == password) {
      console.log("username and password are equal");
      socket.emit(
        "signInResponse",
        "failure",
        "Nice try, but your username and password can't be the same!"
      );
      console.log("successfully emitted case 1");
    } else if (md5(username) == md5(password)) {
      console.log("Correct answer");
      socket.emit(
        "signInResponse",
        "success",
        "You signed in successfully! Agent Gerald found this in the chat logs:\n" +
          flag
      );
      console.log("successfully emitted case 2");
    } else {
      console.log("Wrong answer");
      socket.emit(
        "signInResponse",
        "failure",
        "Incorrect Password! You might not be " + username + ", reanalyzing..."
      );
      console.log("successfully emitted case 3");
      username = usernames[Math.floor(Math.random() * usernames.length)];
      socket.emit("username", username);
    }
  });
});
