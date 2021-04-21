const cookieParser = require("cookie-parser");
const express = require("express");
const path = require("path");
const { readFileSync } = require("fs");

const DEFAULT_USERNAME = "vampire"; // wholly unrelated to any hypothetical incidents that may have occurred on any hypothetical discord servers

// Read the flag file from the current directory into a string
const flag = readFileSync("flag.txt", "utf8");

// Spin up a web server
const app = express();

// Serve files in the public directory
app.use(express.static(path.join(__dirname, "public")));

// Parse cookies
app.use(cookieParser());

// Home page (haha, get it?)
app.get("/", (request, response) => {
    if (request.cookies.user) {
        // User is signed in
        response.sendFile(path.join(__dirname, "signedin.html"));
    } else {
        // User is signed out
        response.sendFile(path.join(__dirname, "signedout.html"))
    }
});

// Sign in
app.get("/login", (request, response) => {
    // Set the user's username to whatever DEFAULT_USERNAME is (vampire)
    response.cookie("user", DEFAULT_USERNAME);

    // Redirect back to the homepage
    response.redirect(303, "/");
});

// Sign out
app.get("/logout", (request, response) => {
    response.clearCookie("user");

    // Redirect back to the homepage
    response.redirect(303, "/");
});

// Endpoint to turn lights off
app.get("/off", (request, response) => {
    if (request.cookies.user === "admin") {
        // User is admin
        response.type("html");
        response.send(`Flag get! ${flag} Now to turn this light back on...`);
    } else if (request.cookies.user) {
        // User is signed in but not admin
        response.status(403); // Forbidden
        response.type("html");

        // Prevent XSS by replacing all angle brackets
        const user = request.cookies.user.replace(/</g, "&lt;").replace(/>/g, "&gt");
        response.send(`You must be admin to turn off the lights. Currently you are "${user}".`);
    } else {
        // User isn't signed in at all
        response.status(401); // Unauthorized
        response.type("html");
        response.send("You should probably sign in first.");
    }
});

// Listen on port 1337
app.listen(1337);
console.log("Listening on http://localhost:1337")