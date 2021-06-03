const http = require('http');
const express = require('express');
const path = require('path');
const logger = require('morgan');
const PORT = 54321;
const sqlite = require('sqlite3').verbose();
let db;

function createDB(req, res) {
    // creates the in-memory db
    db = new sqlite.Database(':memory:', function (err) {
        if (err) {
            return console.log(err.message);
        }
        createTable(req, res);
    });
}

function createTable(req, res) {
    // creates the user table
    db.run("CREATE TABLE user(username VARCHAR(45) NOT NULL PRIMARY KEY, password VARCHAR(45) NOT NULL, flag VARCHAR(45) NOT NULL);", function (err) {
        if (err) {
            return console.log(err.message);
        }
        console.log('Table created')
        insertValues(req, res);
    });
}

function insertValues(req, res) {
    // inserts a mock row into the table with the flag
    db.run(`INSERT INTO user(username, password, flag) VALUES(?, ?, ?)`, ['j(J32hf8hlALKIPkjenjKD', '8j9SPej3]\dfjjIhabenm,', 'bcactf{s0_y0u_f04nd_th3_fl13r?}'], function (err) {
        if (err) {
            return console.log(err.message);
        }
        console.log('Inserted Properly');

        let sql = `SELECT flag from user where username = '${req.body.Username}' AND password = '${req.body.Password}'`;
        console.log(sql);
        let flag = db.get(sql, function(err, flag) {
            // console.log(flag.flag);
            if(flag !== undefined) {
                res.render('1', {flag: flag.flag});
                //res.send("Your flag is " + flag.flag);
                closeDB();
            } else {
                console.log("whoops")
                res.render('2', {invalid: true});
                closeDB();
            }
        });
    });
}

function closeDB() {
    db.close(function (err) {
        if (err) {
            return console.log(err.message);
        }
        console.log('Database deleted');
    });
}

//Create 'app' - handler for http requests
const app = express();
app.set('views', path.join(__dirname, '/templates'));
app.set('view engine', 'hbs');

app.use(express.urlencoded({extended: false}));


//Middleware to handle http requests
app.use(logger('dev'));

//Middleware to handle static requests
app.use(express.static(path.join(__dirname, "/public")));

//Routes!
app.get('/', (req, res) => {
    res.render('2', {invalid: false});
    // res.sendFile(path.join(__dirname, '/public/index.html'));
});

app.post('/', (req, res) => {
    createDB(req, res);
});

const server = http.createServer(app);
server.listen(PORT);
console.log(`HTTP server listening at http://localhost:${PORT}`);