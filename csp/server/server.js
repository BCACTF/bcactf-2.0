import express from 'express';
import { fileURLToPath } from 'node:url';
import { join, dirname } from 'node:path';

const __dirname = dirname(fileURLToPath(import.meta.url));
const app = express();

app.use(express.static(join(__dirname, "../public")));

app.listen(1337);
console.log("Listening on http://localhost:1337");
