use std::io;

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    let t: i32 = line.trim().parse().unwrap();
    for _ in 0..t {
        line.clear();
        io::stdin().read_line(&mut line).unwrap();
        let x: Vec<i32> = line.trim().split_whitespace().map(|x| x.parse().unwrap()).collect();
        let a = x[0];
        let b = x[1];
        let c = x[2];
        if a > b && a > c {
            println!("Alice");
        }
        else if b > a && b > c {
            println!("Bob");
        }
        else {
            println!("Charlie");
        }
    }
}