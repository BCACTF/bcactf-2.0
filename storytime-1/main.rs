use std::{thread, time};

fn main() {

    let lines = 4;

    let flag = "bcactf{w0ol_m4k3s_str1ng_ziv4mk3ca91b}";

    let lyrics = 
    ["Baa, baa, black sheep,",
    "Have you any wool?",
    "Yes sir, yes sir,",
    "Three bags full.",
    "One for the master,",
    "One for the dame,",
    "And one for the little boy",
    "Who lives down the lane\n",
    flag,
    "",
    "Did you know? I almost used \"Little Miss Muffet\" for this problem.", 
    "Spiders make string too, kind of."];

    for i in 0..lines {
        println!("{}", lyrics[i]);
        thread::sleep(time::Duration::from_millis(1500));
    }
}
