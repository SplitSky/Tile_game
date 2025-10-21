use rand::distributions::{Distribution, Uniform};

fn add_combs(tile: i8, combinations: Vec<Vec<i8>>) -> Vec<Vec<i8>> {
    let new_combs: Vec<Vec<i8>> = combinations
        .iter()
        .map(|c| {
            let mut c = c.clone();
            c.push(tile);
            c
        })
        .collect();
    let mut combined = combinations.clone();
    combined.push(vec![tile]);
    combined.extend(new_combs);
    combined
}

fn gen_all_combs(tiles: Vec<i8>, limit: i8) -> Vec<Vec<i8>> {
    // make empty set
    let mut all_combs: Vec<Vec<i8>> = Vec::new();
    for tile in tiles {
        all_combs = add_combs(tile, all_combs);
    }
    // filter based on limit adding up to less than 12
    all_combs = all_combs
        .into_iter()
        .filter(|x| {
            let mut sum: i8 = 0;
            for entry in x.iter() {
                sum += entry;
                if sum > limit {
                    return false;
                }
            }
            return true;
        })
        .collect();
    all_combs.sort();
    return all_combs;
}

fn gen_all_combs_for_roll(tiles: Vec<i8>, roll: i8) -> Vec<Vec<i8>> {
    // make empty set
    let mut all_combs: Vec<Vec<i8>> = Vec::new();
    for tile in tiles {
        all_combs = add_combs(tile, all_combs);
    }
    // filter based on roll used
    all_combs = all_combs
        .into_iter()
        .filter(|x| {
            let mut sum: i8 = 0;
            for entry in x.iter() {
                sum += entry;
            }
            if sum == roll {
                return true;
            } else {
                return false;
            }
        })
        .collect();
    all_combs.sort();
    return all_combs;
}

fn print_Vector(vector: Vec<Vec<i8>>) {
    for temp in vector {
        for tile in temp {
            print!("{}", tile);
        }
        println!("{}", " ");
    }
}

fn flip_combination(combination: Vec<i8>, tiles: Vec<i8>) -> Vec<i8> {
    // using the combinations remove every occurance from combinations from tiles.
    // combination [1,2] tiles [1,2,3,4,5,6,7,8,9]
    let new_tiles = combination
        .into_iter()
        .filter(|x| {
            for tile in tiles.iter() {
                if tile == x {
                    return false;
                }
            }
            return true;
        })
        .collect();
    new_tiles
}

fn roll_2d6() -> i8 {
    let step = Uniform::new(1, 7); // 1-6
    let mut rng = rand::thread_rng();
    let result: i8 = step.sample(&mut rng) + step.sample(&mut rng);
    result
}

fn play_turn() -> i16 {
    let score: i16 = 0;
    let board: Vec<i8> = vec![1, 2, 3, 4, 5, 6, 7, 8, 9];
    /*
    Conditions to stop playing:
    1. All tiles flipped
    2. Number can't be made from the combination
    if conditions met then add up tiles and return score
    else keep playing
    tile flipped = removed
    */
    let roll: i8 = roll_2d6();
    let choices = gen_all_combs_for_roll(board, roll);
    // check if choices
}

fn main() {
    // let board: Vec<i8> = vec![1, 2, 3, 4, 5, 6, 7, 8, 9];
    // for the tiles generate combinations to pick from
    let tiles: Vec<i8> = vec![1, 2, 3, 4, 5, 6, 7, 8, 9];
    let all_combs = gen_all_combs(tiles, 12);
    // print_Vector(all_combs);

    println!("{}", roll_2d6());
    // play the game loop
}
