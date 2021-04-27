import express from 'express';
import cookieParser from 'cookie-parser';
import { join, dirname } from 'node:path';
import { fileURLToPath } from 'node:url';
import { randomFillSync } from 'node:crypto';

const __dirname = dirname(fileURLToPath(import.meta.url));
const secret = randomFillSync(Buffer.alloc(30)).toString("base64");
console.log(`Secret: ${secret}`);

const app = express();

app.use(cookieParser());
app.use(express.urlencoded({extended: false}));

app.get("/flag", (req, res) => {
    if (req.cookies.secret === secret) {
        res.sendFile(join(__dirname, "flag.txt"));
    } else {
        res.sendStatus(403);
    }
});

app.post("/submit", (req, res) => {
    
});

app.use(express.static(join(__dirname, "../public")));

app.listen(1337);
console.log("Listening on http://localhost:1337");