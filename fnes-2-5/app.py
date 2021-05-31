from flask import Flask, render_template, request, redirect, make_response

app = Flask(__name__)

with open("flag.txt", "r") as file:
    flag = file.read()

def check_token(token: str) -> str:
    # TODO: Return username for token string, or just throw an error if something's wrong
    return "Not Implemented"

@app.route("/")
def home():
    username = None
    token = request.cookies.get("enterprise-grade-token")
    if token is not None:
        username = check_token(token)
    return render_template("home.html", username=username)

@app.route("/login")
def login():
    # TODO: Generate a token for the username ("guest" or "vampire" or something)
    token = ""
    response = redirect("/", code=303)
    response.set_cookie("enterprise-grade-token", token)
    return response

@app.route("/logout")
def logout():
    response = redirect("/", code=303)
    response.delete_cookie("enterprise-grade-token")
    return response

@app.route("/flagmachine/on")
def turn_flagmachine_on():
    token = request.cookies.get("enterprise-grade-token")
    if token is None:
        return render_template("flagmachine.html", message="At Generic Enterprise™, We Care about Security and Privacy. That's why we require you to Authenticate™ first before modifying any Enterprise™ Industrial™-Grade Settings™.")
    username = check_token(token)
    if username == "admin":
        return render_template("flagmachine.html", message=flag)
    else:
        return render_template("flagmachine.html", message="At Generic Enterprise™, We Care about Security and Privacy. That's why only Authorized™ Personnel™ are permitted to modify our Enterprise™ Industrial™-Grade Settings™."), 403
