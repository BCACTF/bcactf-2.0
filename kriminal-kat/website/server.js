const express = require("express");
const { readFileSync } = require("fs");
const md5 = require("md5");

const app = express();
const socketio = require("socket.io");
const { fileURLToPath } = require("url");
app.use(express.static(__dirname + "/public"));
const port = process.env.PORT || 5000;
const server = app.listen(port);
const io = socketio(server);

const usernameFile = readFileSync("usernames.txt", "utf-8");
const usernames = usernameFile.split("\n");

const flag = readFileSync("flag.txt", "utf-8");

io.on("connection", (socket) => {
  const username = usernames[Math.floor(Math.random() * usernames.length)];
  socket.emit("username", username);
  socket.on("signInAttempt", (password) => {
    if (username === password) {
      socket.emit(
        "signInResponse",
        "failure",
        "Nice try, but your username and password can't be the same!"
      );
    } else if (md5(username) === md5(password)) {
      socket.emit(
        "signInResponse",
        "success",
        "You signed in successfully! Agent Gerald found this in the chat logs:\n" +
          flag
      );
    } else {
      socket.emit(
        "signInResponse",
        "failure",
        "Incorrect Password! You might not be " + username + ", reanalyzing..."
      );
      username = usernames[Math.floor(Math.random() * usernames.length)];
      socket.emit("username", username);
    }
  });
});
