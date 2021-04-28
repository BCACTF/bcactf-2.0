import puppeteer from 'puppeteer';

const browser = puppeteer.launch();

/**
 * @param {number} ms
 * @returns {Promise<void>}
 */
function timeout(ms) {
    return new Promise((resolve, _) => {
        setTimeout(() => {
            resolve();
        }, ms);
    });
}

/**
 * @param {string} url
 * @param {string} passcode
 * @returns {Promise<void>}
 */
export default async function visit(url, passcode) {
    const page = await (await browser).newPage();

    await page.goto(url, {waitUntil: "load", timeout: 500});
    await page.click("#get-flag");
    await page.waitForSelector(".e");
    for (let i = 0; i < passcode.length; i++) {
        const char = passcode.charAt(i);
        const id = "button" + Math.floor(Math.random() * 123456);
        await page.evaluate(`
            document.querySelectorAll(".e > button").forEach(button => {
                if (button.innerText === "${char}") {
                    button.id = "${id}";
                }
            })
        `);
        await page.click(`#${id}`);
        await timeout(50);
    }
    await page.click(".s");
    await timeout(100);

    await page.close();
}
