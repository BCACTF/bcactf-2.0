// Potentially make it harder (force usage of hashcat rather than online solver)

// Timer (requires usage of webex tools if fast enough? test time needed to brute force md5)
// salt md5 / sha1

const socket = io();

socket.on("username", (username) => {
  document.getElementById("username").setAttribute("value", username);
});

// Doesn't recieve this for some reason???
socket.on("signInResponse", (type, content) => {
  setTimeout(console.log("Recieved SignIn response: " + content), 1000);

  if (type == "success") {
    document.getElementById("success").innerHTML = content;
    document.getElementById("error").innerHTML = "";
  } else {
    document.getElementById("error").innerHTML = content;
    document.getElementById("success").innerHTML = "";
  }
});

function submitForm() {
  // Imply that md5 is being used here
  // Ei
  console.log(document.getElementById("password").value.trim());
  socket.emit(
    "signInAttempt",
    document.getElementById("password").value.trim()
  );
}
