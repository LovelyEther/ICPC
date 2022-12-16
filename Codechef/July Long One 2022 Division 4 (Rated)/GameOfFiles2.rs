use std::io;

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    let t: i32 = line.trim().parse().unwrap();
    for _ in 0..t {
        line.clear();
        io::stdin().read_line(&mut line).unwrap();
        let n: i32 = line.trim().parse().unwrap();
        line.clear();
        io::stdin().read_line(&mut line).unwrap();
        let x: Vec<i32> = line.trim().split_whitespace().map(|x| x.parse().unwrap()).collect();
        let mut one = 0;
        let mut two = 0;
        let mut odd = 0;
        let mut sum = 0;
        for v in x {
			if v == 1 {
				one += 1;
			}
			if v == 2 {
				two += 1;
			}
			if v % 2 == 1 {
				odd += 1;
			}
			sum += v % 2 + 2;
		}
		if one >= 2 {
			if (sum - 2 - (n - 2)) % 2 == 1 {
				println!("CHEF");
			}
			else {
				println!("CHEFINA");
			}
		}
		else if one == 1 {
			if (odd - 1) % 2 == 0 {
				println!("CHEF");
			}
			else {
				if two > 0 && (sum - (n - 2)) % 2 == 1 {
					println!("CHEF");
				}
				else {
					println!("CHEFINA");
				}
			}
		}
		else {
			if sum % 2 == 1 {
				println!("CHEF");
			}
			else {
				println!("CHEFINA");
			}
		}
    }
}
