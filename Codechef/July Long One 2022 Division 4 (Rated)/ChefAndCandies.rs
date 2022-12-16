use std::io;

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    let t: i32 = line.trim().parse().unwrap();
    for _ in 0..t {
        line.clear();
        io::stdin().read_line(&mut line).unwrap();
        let x: Vec<i32> = line.trim().split_whitespace().map(|x| x.parse().unwrap()).collect();
        let n = x[0];
        let k = x[1];
        let mut rlt: i32 = 0;
        if n > k {
			rlt = (n - k + 3) / 4;
		}
        println!("{}", rlt);
    }
}
