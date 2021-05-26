use std::{thread, time};

fn main() {

    let lines = 4;

    let mut nums : [u8; 0x25] = [0; 0x25];

    nums[0x24] = 0xb3;
    nums[0x0e] = 0xb4;
    nums[0x06] = 0xeb;
    nums[0x0d] = 0xcf;
    nums[0x03] = 0xc1;
    nums[0x0a] = 0xd5;
    nums[0x1e] = 0x9a;
    nums[0x1a] = 0x39;
    nums[0x0f] = 0x49;
    nums[0x0c] = 0x48;
    nums[0x14] = 0x40;
    nums[0x04] = 0xe0;
    nums[0x05] = 0xc2;
    nums[0x17] = 0xae;
    nums[0x1d] = 0x37;
    nums[0x23] = 0xa6;
    nums[0x08] = 0xc0;
    nums[0x07] = 0xda;
    nums[0x21] = 0x97;
    nums[0x19] = 0x3d;
    nums[0x11] = 0x9d;
    nums[0x10] = 0xc4;
    nums[0x1c] = 0xb6;
    nums[0x18] = 0x8f;
    nums[0x02] = 0xbf;
    nums[0x13] = 0xbe;
    nums[0x15] = 0xa5;
    nums[0x00] = 0xc5;
    nums[0x20] = 0x22;
    nums[0x0b] = 0xa9;
    nums[0x1f] = 0x89;
    nums[0x01] = 0xc4;
    nums[0x12] = 0xa5;
    nums[0x09] = 0x57;
    nums[0x16] = 0x34;
    nums[0x1b] = 0x97;
    nums[0x22] = 0x7e;

    let mut chars = [' '; 0x25];

    for (i, n) in nums.iter().enumerate() {
        chars[i] = ((n >> 1) + (i as u8)) as char;
    }
    
    let flag : String = chars.iter().collect();

    let lyrics = ["Puff the magic dragon lived by the sea",
    "And frolicked in the autumn mist in a land called Honah Lee",
    "Little Jackie Paper loved that rascal Puff",
    "And brought him strings and sealing wax and other fancy stuff\n",
    "Oh, Puff the magic dragon lived by the sea",
    "And frolicked in the autumn mist in a land called Honah Lee",
    "Puff the magic dragon lived by the sea",
    "And frolicked in the autumn mist in a land called Honah Lee\n",
    "Together they would travel on a boat with billowed sail",
    "Jackie kept a lookout perched on Puff's gigantic tail",
    "Noble kings and princes would bow whene'er they came",
    "Pirate ships would lower their flags when Puff roared out his name\n",
    "Oh, Puff the magic dragon lived by the sea",
    "And frolicked in the autumn mist in a land called Honah Lee",
    "Puff the magic dragon lived by the sea",
    "And frolicked in the autumn mist in a land called Honah Lee\n",
    "A dragon lives forever, but not so little boys",
    "Painted wings and giant's rings make way for other toys",
    "One gray night it happened, Jackie Paper came no more",
    "And Puff, that mighty dragon, he ceased his fearless roar\n",
    "His head was bent in sorrow, green scales fell like rain",
    "Puff no longer went to play along the cherry lane",
    "Without his lifelong friend, Puff could not be brave",
    "So Puff, that mighty dragon, sadly slipped into his cave",
    "Oh, Puff the magic dragon lived by the sea",
    "And frolicked in the autumn mist in a land called Honah Lee",
    "Puff the magic dragon lived by the sea",
    "And frolicked in the autumn mist in a land called Honah Lee\n", 
    &flag];

    for i in 0..lines {
        println!("{}", lyrics[i]);
        thread::sleep(time::Duration::from_millis(2000));
    }
}
