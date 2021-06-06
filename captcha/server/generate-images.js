const { createCanvas } = require("canvas");
const { writeFileSync } = require("fs");

const font = "32px 'Times New Roman'";

const canvas1 = createCanvas(16, 32);
const ctx1 = canvas1.getContext("2d");
ctx1.font = font;
ctx1.fillStyle = "black";
ctx1.fillText("1", 0, 24);
writeFileSync("1.png", canvas1.toBuffer());

const canvasl = createCanvas(16, 32);
const ctxl = canvasl.getContext("2d");
ctxl.font = font;
ctxl.fillStyle = "black";
ctxl.fillText("l", 0, 24);
writeFileSync("l.png", canvasl.toBuffer());