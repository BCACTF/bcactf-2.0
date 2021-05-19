const socket = io('http://localhost:9000', {
    query: {
        username
    }
})

socket.on("username", (username) => {
    document.getElementById("username").setAttribute("value", username)
})

socket.on("signInResponse", (type, content) => {
    if (type === "success") {
        document.getElementById("success").innerHTML = content;
        document.getElementById("error").innerHTML = "";
    } else {
        document.getElementById("error").innerHTML = content;
        document.getElementById("success").innerHTML = "";
    }
})

function submitForm() {
    
}