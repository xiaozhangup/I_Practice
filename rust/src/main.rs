fn main() {
    let tup: (i32, f64, u8, u8) = (500, 6.4, 1, 2);
    let a = [1, 2, 3, 4, 5];
    for i in a {
        println!("{}", i);
    }
}

fn main3() {
    let x = 10;

    println!("默认: {}", x);
    println!("二进制: {:b}", x);
    println!("八进制: {:o}", x);
    println!("十六进制: {:x}", x);
    println!("带前缀二进制: {:#b}", x);
    println!("带前缀八进制: {:#o}", x);
    println!("带前缀十六进制: {:#x}", x);
}

fn main2() {
    let a: i32 = 10;
    let b: i32 = 3;

    println!("a + b = {}", a + b);
    println!("a - b = {}", a - b);
    println!("a * b = {}", a * b);
    println!("a / b = {}", a / b);
    println!("a % b = {}", a % b);
    println!("a ^ b = {}", a.pow(b as u32));
    println!("{}", a.to_string());
}

fn main1() {
    let s1 = String::from("hello");
    let s2 = &s1; // s1 的所有权被转移给了 s2
    let user = Obj {
        name: String::from("Alice"),
        id: 1,
        time: 1234567890,
        sex: Emu::female
    };
    match user.sex {
        Emu::male => println!("male"),
        Emu::female => println!("female"),
    }
    println!("{} {} {}", s1, s2, user.name);
    match add(2, 2) {
        Ok(value) => println!("Result: {}", value),
        Err(e) => println!("Error: {}", e),
    }
}

struct Obj {
    name: String,
    id: i32,
    time: i64,
    sex: Emu
}

enum Emu {
    male,
    female
}

fn add(a: i32, b: i32) -> Result<i32, String> {
    if a == 2 && b == 2 {
        println!("FANK");
        return Err(String::from("Invalid input"));
    }
    Ok(a + b)
}