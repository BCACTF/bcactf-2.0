from flask import Flask, render_template, request, redirect, make_response
from json import loads, dumps

app = Flask(__name__)

with open("flag.txt", "r") as file:
    flag = file.read()

def check_token(token: str):
    # TODO: Set contents to contents of token, or just throw an error if something's wrong
    contents = '{"name":"vampire","admin":false}'
    return loads(contents)

@app.route("/")
def home():
    user = None
    token = request.cookies.get("enterprise-grade-token")
    if token is not None:
        user = check_token(token)
        return render_template("home.html", username=user["name"], is_admin=user["admin"])
    else:
        return render_template("home.html")

@app.route("/login")
def login():
    contents = dumps({"name": "vampire", "admin": False})
    # TODO: Create token with contents of contents
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
    user = check_token(token)
    if user["admin"]:
        return render_template("flagmachine.html", message=flag)
    else:
        return render_template("flagmachine.html", message="At Generic Enterprise™, We Care about Security and Privacy. That's why only Authorized™ Personnel™ are permitted to modify our Enterprise™ Industrial™-Grade Settings™."), 403
