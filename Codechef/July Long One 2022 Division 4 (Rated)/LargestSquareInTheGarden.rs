use std::io;
use std::cmp;

const N: usize = 1001001;
const M: usize = 22;

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    let n: usize = line.trim().parse().unwrap();
    let mut a: [i32; N] = [0; N];
    let mut b: [i32; N] = [0; N];
    let mut fa: [[i32; M]; N] = [[0; M]; N];
    let mut fb: [[i32; M]; N] = [[0; M]; N];
    for i in 0..n {
        line.clear();
        io::stdin().read_line(&mut line).unwrap();
        let x: Vec<i32> = line.trim().split_whitespace().map(|x| x.parse().unwrap()).collect();
        a[i] = x[0];
        b[i] = x[1];
    }
    for i in 0..n {
		fa[i][0] = a[i];
		fb[i][0] = b[i];
	}
	for j in 1..M {
		if (1 << j) > n {
			break;
		}
		for i in 0..(n - (1 << j) + 1) {
			fa[i][j] = cmp::max(fa[i][j-1], fa[i+(1<<j-1)][j-1]);
			fb[i][j] = cmp::min(fb[i][j-1], fb[i+(1<<j-1)][j-1]);
		}
	}
	let mut st = 0;
	let mut en = n + 1;
	while en - st > 1 {
		let md = (st + en) >> 1;
		let mut d = 0;
		while (1 << d + 1) <= md { d += 1; }
		let mut good = false;
		for i in 0..(n - md + 1) {
			let begin = cmp::max(fa[i][d], fa[i+md-(1<<d)][d]);
			let end = cmp::min(fb[i][d], fb[i+md-(1<<d)][d]);
			if end - begin + 1 >= md as i32 { good = true; }
		}
		if good {
			st = md;
		}
		else {
			en = md;
		}
	}
	println!("{}", st);
}
