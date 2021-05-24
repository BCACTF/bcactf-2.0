use std::{thread, time};

fn main() {

    while true {
            
        let lyrics = 
        ["I know a song that gets on everybody's nerves,",
        "Everybody's nerves, yes, on everybody's nerves,",
        "I know a song that gets on everybody's nerves,",
        "And this is how it goes."];

        for i in lyrics {
            println!("{}", i);
            thread::sleep(time::Duration::from_millis(2000));
        }

    }
    let flag = "bcactf{h1dd3n_c0d3_1s_h1dd3n_238q49eruf5}";
}
