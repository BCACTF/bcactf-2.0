const socket = io("http://localhost:9000");

socket.on("username", (username) => {
  document.getElementById("username").setAttribute("value", username);
});

// Doesn't recieve this for some reason???
socket.on("signInResponse", (content) => {
    setTimeout(console.log("Recieved SignIn response: " + content), 1000);
  
  
//   if (type == "success") {
//     document.getElementById("success").innerHTML = content;
//     document.getElementById("error").innerHTML = "";
//   } else {
//     document.getElementById("error").innerHTML = content;
//     document.getElementById("success").innerHTML = "";
//   }
});

function submitForm() {
  console.log(document.getElementById("password").value.trim());
  socket.emit("signInAttempt", document.getElementById("password").value.trim());
}
