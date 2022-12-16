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
        let mut a = 0;
        let mut b = 0;
        let mut c = 0;
        let mut m = 1;
        while m * 2 <= n { m *= 2; }
        while m >= 1 {
			let delta = x[m as usize] - x[0];
			if delta == -3 * m {
				a ^= m;
				b ^= m;
				c ^= m;
			}
			else if delta == -m {
				if a <= c && b <= c {
					a ^= m;
					b ^= m;
				}
				else if a <= b && c <= b {
					a ^= m;
					c ^= m;
				}
				else {
					b ^= m;
					c ^= m;
				}
			}
			else if delta == m {
				if c <= a && c <= b {
					c ^= m;
				}
				else if b <= a && b <= c {
					b ^= m;
				}
				else {
					a ^= m;
				}
			}
			m /= 2;
		}
		println!("{} {} {}", a, b, c);
    }
}
