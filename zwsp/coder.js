const ZWSP_BIT_TABLE = ["\u200b", "\u200c"];
const REVERSE_BIT_TABLE = {
  "\u200b": 0,
  "\u200c": 1
};


const encode = (str) => {
  const buf = new TextEncoder().encode(str);

  let out = "";
  for (let i = 0; i < buf.length; ++i) {
    out += (ZWSP_BIT_TABLE[(buf[i] >> 7) & 1] +
      ZWSP_BIT_TABLE[(buf[i] >> 6) & 1] +
      ZWSP_BIT_TABLE[(buf[i] >> 5) & 1] +
      ZWSP_BIT_TABLE[(buf[i] >> 4) & 1] +
      ZWSP_BIT_TABLE[(buf[i] >> 3) & 1] +
      ZWSP_BIT_TABLE[(buf[i] >> 2) & 1] +
      ZWSP_BIT_TABLE[(buf[i] >> 1) & 1] +
      ZWSP_BIT_TABLE[buf[i] & 1]);
  }

  return out;
}

const decode = (str) => {
  const bits = str.match(/[\u200b\u200c]/g);
  const out = new Uint8Array(bits.length >> 3);

  for (let i = 0; i < bits.length; ++i) {
    out[i >> 3] |= REVERSE_BIT_TABLE[bits[i]] << ((i & 0x7) ^ 0x7);
  }

  return new TextDecoder().decode(out);
}

// Running zwsp.txt shows the solution
// Encode was used to encode zwsp.txt
