use std::io;

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    let t: i32 = line.trim().parse().unwrap();
    for _ in 0..t {
        line.clear();
        io::stdin().read_line(&mut line).unwrap();
        let x: Vec<i32> = line.trim().split_whitespace().map(|x| x.parse().unwrap()).collect();
        let max_t = x[0];
        let max_n = x[1];
        let sum_n = x[2];
        let mut cnt = sum_n / max_n;
        if cnt > max_t {
			cnt = max_t;
		}
        let mut rst = sum_n - max_n * cnt;
        if cnt == max_t {
			rst = 0;
		}
        let rlt = max_n * max_n * cnt + rst * rst;
        println!("{}", rlt);
    }
}
