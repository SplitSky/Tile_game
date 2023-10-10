#include<iostream>
#include<vector>
#include<unordered_map>

class Board {
	public:
		std::unordered_map<int, bool> board;
		int total_score = 0;

		//Board();
		Board(int size) {
			for (size_t i{0}; i < size; i++) {
				this->board[i] = false;
			}
		};
	
		int sum_board();
		bool check_value(int key);
		void flip_value(int number);
		void flip_values(std::vector<int> flips);
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
}
bool Board::check_value(int key) { // returns the value at key
	auto it = board.find(key);
	return it->second == true;
}
void Board::flip_values(std::vector<int> flips) { // flips the values
	// takes in the input and flips the numbers
	
}
void Board::flip_value(int key) {
	this->total_score[key] = true;
}


int strat_1() {
	// highest tiles first
}

int strat_2() {
	// lowest tiles first
}

int main() {
	// populate the board
	for (int i = 1; i <= 9; i++) {
		board.setValue(i, false);
	}

	// run the game using different strategies and print out scores
	std::vector<int> scores = {0,0};
	int N = 10; // number of game rounds
	for (int i=0; i<N; i++) {
		scores[0] += strat_1();
		scores[1] += strat_2();
	}
}
