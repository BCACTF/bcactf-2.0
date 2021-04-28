const defaultTheme = {bg: "#ffffff", fg: "#000000", bbg: "#0000ff", bfg: "#ffffff"};
let passcode = "";

/**
 * @param {{bg: unknown, fg: unknown, bbg: unknown, bfg: unknown}} theme 
 */
function applyTheme(theme) {
    if (typeof theme.bg !== "string") throw new Error("bg must be a string");
    if (typeof theme.fg !== "string") throw new Error("fg must be a string");
    if (typeof theme.bbg !== "string") throw new Error("bbg must be a string");
    if (typeof theme.bfg !== "string") throw new Error("bfg must be a string");

    document.getElementById("style").innerText = `
    body, .modal-content {
        background-color: ${theme.bg};
    }

    body {
        color: ${theme.fg};
    }

    button {
        background-color: ${theme.bbg};
        color: ${theme.bfg};
    }
    `;

    const permalink = `#${encodeURIComponent(JSON.stringify(theme))}`;
    document.getElementById("permalink").setAttribute("href", permalink);
}

function getThemeFromForm() {
    const data = new FormData(/** @type {HTMLFormElement} */ (document.getElementById("theme-creator")));
    return {
        bg: data.get("bg"),
        fg: data.get("fg"),
        bbg: data.get("bbg"),
        bfg: data.get("bfg")
    };
}

/**
 * @param {string} [text] 
 */
function updatePasscodeDisplay(text) {
    const display = /** @type {HTMLElement | null} */ (document.querySelector(".passcode-display"));
    if (display) {
        display.innerText = text || (passcode.length > 0 ? passcode : "Enter passcode to access flag.");
    }
}

function getFlag() {
    updatePasscodeDisplay("Submitting, please wait...");
    fetch("/flag", {
        headers: {
            "X-Passcode": passcode
        }
    }).then(response => response.text()).then(text => {
        updatePasscodeDisplay(text);
        passcode = "";
    });
}

function setupPasscodeModal() {
    const template = /** @type {HTMLTemplateElement} */ (document.getElementById("passcode-modal"));
    const content = /** @type {HTMLElement} */ (template.content.firstElementChild.cloneNode(true));
    document.body.appendChild(content);

    content.querySelectorAll(".e > button").forEach(button => button.addEventListener("click", _ => {
        passcode += button.innerHTML;
        updatePasscodeDisplay();
    }));

    content.querySelector(".submit-passcode").addEventListener("click", _ => {
        getFlag();
    });

    content.querySelector(".reset-passcode").addEventListener("click", _ => {
        passcode = "";
        updatePasscodeDisplay();
    });

    content.querySelector(".close-modal").addEventListener("click", _ => {
        content.remove();
    });
}

window.addEventListener("DOMContentLoaded", _ => {
    let theme = defaultTheme;

    try {
        if (window.location.hash && window.location.hash.length > 1) {
            theme = JSON.parse(decodeURIComponent(window.location.hash.slice(1)));
        }
        applyTheme(theme);
    } catch (e) {
        alert(`Error loading theme: ${e}`);
        theme = defaultTheme;
    }

    updatePasscodeDisplay();

    /** @type {HTMLInputElement} */ (document.getElementById("bg")).value = theme.bg;
    /** @type {HTMLInputElement} */ (document.getElementById("fg")).value = theme.fg;
    /** @type {HTMLInputElement} */ (document.getElementById("bbg")).value = theme.bbg;
    /** @type {HTMLInputElement} */ (document.getElementById("bfg")).value = theme.bfg;

    document.getElementById("theme-creator").addEventListener("change", _ => {
        applyTheme(getThemeFromForm());
    });

    document.getElementById("get-flag").addEventListener("click", _ => {
        setupPasscodeModal();
    });
});