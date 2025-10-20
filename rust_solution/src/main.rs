struct Combination {
    tiles: Vec<i8>,
}

impl Combination {
    fn sort_tiles(Self) {
        tiles.sort();
    }
}

fn add_combs(tile: i8, combinations: Vec<Vec<i8>>) -> Vec<Vec<i8>> {
    // copy combinations as mutable
    let mut comb_copy = Vec::new();
    comb_copy = combinations.clone();
    // append the tile to every entry in comb_copy
    for mut combination in comb_copy {
        combination.push(tile);
    }
    comb_copy
}

fn main() {
    let board: Vec<i8> = vec![1, 2, 3, 4, 5, 6, 7, 8, 9];
}
