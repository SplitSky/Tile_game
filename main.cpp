#include<iostream>
#include<vector>
#include<unordered_map>
#include<random>

class Board {
	public:
		std::unordered_map<int, bool> board;
		int total_score = 0;
		int size = 0;
		Board(int size) {
			this->size = size;
			for (size_t i{0}; i < size; i++) {
				this->board[i] = false;
			}
		};
		int sum_board();
		bool check_value(int key);
		void flip_value(int number);
		void flip_values(std::vector<int> flips);
		std::vector<int> board_state();
		int play_turn(bool (*func)(std::unordered_map<int, bool>));
};

int Board::sum_board() {
	int sum = 0;
	int i = 1;
	while (i < board.size()) {
		if (check_value(i)) {
			sum += i;
		}	
		i ++;
	}
	this->total_score = sum;
	return sum;
}
bool Board::check_value(int key) { // returns the value at key
	auto it = board.find(key);
	return it->second == true;
}
void Board::flip_values(std::vector<int> flips) { // flips the values
	// takes in the input and flips the numbers
	for (int value : flips) {
		this->flip_value(value);
	}
}
void Board::flip_value(int key) {
	this->board.emplace(key, true);
}
std::vector<int> Board::board_state() {
	std::vector<int> numbers;
	for (size_t i{0}; i < this->size; i++) {
		if (this->board[i] == false) {
			numbers.push_back(i);
		}
	}
	return numbers;
}
int Board::play_turn(bool (*func)(std::unordered_map<int, bool>)) {
	// plays the turn using a given strategy function
	// repeats the turn until exhausted
	bool keep_going = true;
	while (keep_going) {
		if (func(this->board) == false) {
			keep_going = false;
			this->total_score = this->sum_board();
		}
	}
	return this->total_score;
}

bool strat_1(std::unordered_map<int, bool> board, std::vector<int> tiles) {
	// highest tiles first
	std::vector<int> board_state;
	for (size_t i{0}; i<size; i++) {

	}
}

int strat_2() {
	// lowest tiles first
}

int roll() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(1, 6); // Define the distribution for 1 to 6
    // Simulate rolling two 1d6 dice and sum the results
    int result = distribution(gen) + distribution(gen);
    return result;
}

int main() {
	// populate the board
	Board test_board = Board(9);

	// run the game using different strategies and print out scores
	std::vector<int> scores = {0,0};
	int N = 10; // number of game rounds
	for (int i=0; i<N; i++) {
		scores[0] += strat_1();
		scores[1] += strat_2();
	}
}
