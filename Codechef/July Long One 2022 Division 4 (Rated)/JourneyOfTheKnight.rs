use std::io;

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    let t: i32 = line.trim().parse().unwrap();
    for _ in 0..t {
        line.clear();
        io::stdin().read_line(&mut line).unwrap();
        let x: Vec<i32> = line.trim().split_whitespace().map(|x| x.parse().unwrap()).collect();
        let x1 = x[0];
        let y1 = x[1];
        let x2 = x[2];
        let y2 = x[3];
        let dif = x1 + y1 - x2 - y2;
        if dif % 2 == 0 {
			println!("YES");
		}
		else {
			println!("NO");
		}
    }
}
