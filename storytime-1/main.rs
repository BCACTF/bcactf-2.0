
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
    flag];

    for i in 0..lines {
        println!("{}", lyrics[i]);
    }
}
