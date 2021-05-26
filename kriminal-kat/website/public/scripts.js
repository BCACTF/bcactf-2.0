// Potentially make it harder (force usage of hashcat rather than online solver)

// Timer (requires usage of webex tools if fast enough? test time needed to brute force md5)
// salt md5 / sha1

const socket = io();

socket.on("username", (username) => {
  document.getElementById("username").setAttribute("value", username);
});

socket.on("signInResponse", (type, content) => {
  if (type == "success") {
    document.getElementById("success").innerText = content;
    document.getElementById("error").innerText = "";
  } else {
    document.getElementById("error").innerText = content;
    document.getElementById("success").innerText = "";
  }
});

function submitForm() {
  // Imply that md5 is being used here
  socket.emit(
    "signInAttempt",
    document.getElementById("password").value.trim()
  );
}
