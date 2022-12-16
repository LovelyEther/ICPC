use std::io;

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    let t: i32 = line.trim().parse().unwrap();
    for _ in 0..t {
        line.clear();
        io::stdin().read_line(&mut line).unwrap();
        let _n: i32 = line.trim().parse().unwrap();
        line.clear();
        io::stdin().read_line(&mut line).unwrap();
        let x: Vec<i32> = line.trim().split_whitespace().map(|x| x.parse().unwrap()).collect();
        let mut win = false;
        let mut odd = 0;
        for v in x {
			if v == 1 {
				win = true;
				break;
			}
			if v % 2 == 1 {
				odd += 1;
			}
		}
		if win || odd % 2 == 1 {
			println!("CHEF");
		}
		else {
			println!("CHEFINA");
		}
    }
}
