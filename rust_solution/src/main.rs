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

fn gen_all_combs_for_roll(tiles: &Vec<i8>, roll: i8) -> Vec<Vec<i8>> {
    // doesn't filter the tiles based on possibilities
    let mut all_combs: Vec<Vec<i8>> = Vec::new();
    for &tile in tiles.iter() {
        all_combs = add_combs(tile, all_combs);
    }
    all_combs
        .into_iter()
        .filter(|x| x.iter().sum::<i8>() == roll)
        .collect()
}

fn filter_combs_on_tiles(combinations: Vec<Vec<i8>>, tiles: &Vec<i8>) -> Vec<Vec<i8>> {
    //tiles.iter().filter(|x| !combinations)
    let filtered_combs: Vec<Vec<i8>> = combinations
        .into_iter()
        .filter(|x| {
            for tile in x.iter() {
                if !tiles.contains(tile) {
                    return false;
                }
            }
            return true;
        })
        .collect();
    return filtered_combs;
}

fn print_vector(vector: &Vec<Vec<i8>>) {
    println!("Start printing vector");
    for temp in vector {
        for tile in temp {
            print!("{}", tile);
        }
        println!("{}", " ");
    }
    println!("End printing vector");
}

fn flip_combination(combination: Vec<i8>, tiles: &Vec<i8>) -> Vec<i8> {
    tiles
        .iter()
        .filter(|t| !combination.contains(t))
        .copied()
        .collect()
}

fn roll_2d6() -> i8 {
    let step = Uniform::new(1, 7); // 1-6
    let mut rng = rand::thread_rng();
    let result: i8 = step.sample(&mut rng) + step.sample(&mut rng);
    result
}

fn strat_1(combinations: &Vec<Vec<i8>>, tiles: &Vec<i8>) -> Vec<i8> {
    // select based on tree branching count
    // i.e. for each comb generate combinations. Count and make a dict.
    // Then pick one with the largest count of possible combinations
    let combs = &combinations;
    let mut boards: Vec<Vec<i8>> = vec![];
    let mut scores: Vec<i16> = Vec::new();
    for combination in combs.into_iter() {
        // generate a board for each selection
        let mut board = flip_combination(combination, tiles);
        boards.push(board);
    }
    // evaluate the board combination counts
    let lowest = 1000;
    let best_comb = 
    for board in boards.into_iter() {
        let sim_combs = gen_all_combs(board, 12);
        scores.push(sim_combs.len());
    }
}

struct board_comb{
    board: Vec<i8>,
    choice: Vec<i8>,
    score: i8 = board.iter().sum::<i8>(),
}
impl board_comb {
    fn new(board: Vec<i8>, choice: Vec<i8>) {

    }
}

fn pick_combination_strat(combinations: Vec<Vec<i8>>, strat: i8, tiles: &Vec<i8>) -> Vec<i8> {
    // pick the first combination
    print_vector(&combinations);
    if strat == 0 {
        return combinations[combinations.len() - 1].clone();
    } else if strat == 1 {
        return strat_1(&combinations, tiles);
    } else {
        return combinations[0].clone();
    }
}

fn play_turn() -> i8 {
    let mut board: Vec<i8> = vec![1, 2, 3, 4, 5, 6, 7, 8, 9];
    let mut keep_playing = true;
    let mut roll: i8 = roll_2d6();
    let mut choices: Vec<Vec<i8>>;
    let mut score: i8 = 0;

    println!("{}", roll);

    while keep_playing == true {
        roll = roll_2d6();
        choices = gen_all_combs_for_roll(&board, roll); // generate tile combinations for a given
        // roll
        choices = filter_combs_on_tiles(choices, &board);
        if choices.is_empty() {
            keep_playing = false;
            score = board.iter().sum::<i8>();
        } else {
            let choice = pick_combination_strat(choices.clone(), 0, &board);
            board = flip_combination(choice, &board);
        }
    }
    return score;
}

fn main() {
    // for the tiles generate combinations to pick from
    let tiles: Vec<i8> = vec![1, 2, 3, 4, 5, 6, 7, 8, 9];
    let all_combs = gen_all_combs(tiles, 12);
    // print_Vector(all_combs);

    println!("{}", roll_2d6());
    // play the game loop
    let score = play_turn();
    println!("{}", score);
}
