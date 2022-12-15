#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <time.h>
#include <iostream>
#include <assert.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector <int> vi;
typedef vector <vi> vvi;

// indicate cells of puzzle
struct Point
{
	int r, c;
	Point(int _r = 0, int _c = 0) : r(_r), c(_c) {}
	inline bool operator == (const Point &B) const { return r == B.r && c == B.c; }
	inline bool operator != (const Point &B) const { return r != B.r || c != B.c; }
};

/// Currently Generator class never used, u may ignore it
// class for generates puzzles using maze algorithm
class Generator
{
private:
	int row, col;
	vvi m_grid;
	vector <Point> stack;

	bool partOfSquare(int i, int j);
	Point getRandomChild(int i, int j);

public:
	Generator(int row, int col);
	void generate();
	vvi getGrid() { return m_grid; }
};

// constructor for generator, creates a grid of size row x col
Generator::Generator(int row, int col)
{
	this -> row = row;
	this -> col = col;

	for (int i = 0; i < row; i++) {
		m_grid.push_back(vi());
		for (int j = 0; j < col; j++) {
			m_grid[i].push_back(0);
		}
	}
}

// checks if the current point would be part of a 2x2 if it were to be made black
bool Generator::partOfSquare(int i, int j)
{
	if (i + 1 < row && j + 1 < col) {
		if (m_grid[i+1][j] == -1 && m_grid[i+1][j+1] == -1 && m_grid[i][j+1] == -1) return true;
	}
	if (i + 1 < row && j - 1 >= 0) {
		if (m_grid[i+1][j] == -1 && m_grid[i+1][j-1] == -1 && m_grid[i][j-1] == -1) return true;
	}
	if (i - 1 >= 0 && j + 1 < col) {
		if (m_grid[i-1][j] == -1 && m_grid[i-1][j+1] == -1 && m_grid[i][j+1] == -1) return true;
	}
	if (i - 1 >= 0 && j - 1 >= 0) {
		if (m_grid[i-1][j] == -1 && m_grid[i-1][j-1] == -1 && m_grid[i][j-1] == -1) return true;
	}
	return false;
}

// returns a random valid child (or a Point(-1, -1) if there are no children)
Point Generator::getRandomChild(int i, int j) {
	vector <Point> children;
	if (i + 1 < row) {
		if (m_grid[i+1][j] == 0 && !partOfSquare(i + 1, j)) {
			children.push_back(Point(i + 1, j));
		}
	}
	if (i - 1 >= 0) {
		if (m_grid[i-1][j] == 0 && !partOfSquare(i - 1, j)) {
			children.push_back(Point(i - 1, j));
		}
	}
	if (j + 1 < col) {
		if (m_grid[i][j+1] == 0 && !partOfSquare(i, j + 1)) {
			children.push_back(Point(i, j + 1));
		}
	}
	if (j - 1 >= 0) {
		if (m_grid[i][j-1] == 0 && !partOfSquare(i, j - 1)) {
			children.push_back(Point(i, j - 1));
		}
	}

	if (children.empty()) return Point(-1, -1);

	return children[rand() % children.size()];
}

// Does not guarantee a puzzle with only one solution.
void Generator::generate()
{
	// current Point P, set m_grid[P.r][P.c] to be black
	Point P(rand() % row, rand() % col);
	m_grid[P.r][P.c] = -1;

	// push back the current Point onto the stack
	stack.push_back(P);

	// maze algorithm part (runs until stack is empty)
	while (!stack.empty()) {
		P = stack[stack.size()-1];

		// gets a random valid child
		Point child = getRandomChild(P.r, P.c);

		// if there are no children we remove P from stack and continue
		// OR there is a random chance we ignore the child found \
			(this was an attempt to counteract the shortcomings of the maze algorithm and it had moderate success so I left it in)
		// Sometimes it creates really bad puzzles, but it usually creates higher quality ones than it used to
		if (child.r == -1 || ((double)rand() / RAND_MAX) < 0.005) {
			stack.pop_back();
			continue;
		}

		m_grid[child.r][child.c] = -1;
		stack.push_back(child);
	}
}

// directions for neighbor
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

// queue for bfs
Point Q[10101];
int head, tail;

// search all connected Points which value is val
void bfs(vvi &grid, Point src, int val)
{
	int row = grid.size();
	int col = grid[0].size();
	head = 0, tail = 0;
	Q[tail++] = src;
	grid[src.r][src.c] += 0xff;
	while (head < tail) {
		Point P = Q[head++];
		for (int i = 0; i < 4; i ++) {
			int rr = P.r + dr[i], cc = P.c + dc[i];
			if (rr < 0 || rr >= row || cc < 0 || cc >= col) continue;
			if (grid[rr][cc] == val) {
				Q[tail++] = Point(rr, cc);
				grid[rr][cc] += 0xff;
			}
		}
	}
	// after bfs reset grid to original value
	for (int i = 0; i < tail; i ++) grid[Q[i].r][Q[i].c] -= 0xff;
}

// puzzle print on cmd
void print_puzzle(vvi &grid)
{
	for (int i = 0; i < grid.size(); i ++) {
		for (int j = 0; j < grid[i].size(); j ++) {
			if (grid[i][j] > 0) {
				if (grid[i][j] < 10) fprintf(stderr, "%d", grid[i][j]);
				else fprintf(stderr, "%c", 'A' + grid[i][j] - 10);
			}
			else if (grid[i][j] == 0) fprintf(stderr, "*");
			else if (grid[i][j] == -1) fprintf(stderr, "#");
		} fprintf(stderr, "\n");
	} fprintf(stderr, "\n");
}

void print_puzzle2(vvi &grid, vvi &color)
{
	for (int i = 0; i < grid.size(); i ++) {
		for (int j = 0; j < grid[i].size(); j ++) {
			if (grid[i][j] > 0) {
				if (grid[i][j] < 10) fprintf(stderr, "%d", grid[i][j]);
				else fprintf(stderr, "%c", 'A' + grid[i][j] - 10);
			}
			else if (color[i][j] == 0) fprintf(stderr, "*");
			else if (color[i][j] == 1) fprintf(stderr, ".");
			else if (color[i][j] == 2) fprintf(stderr, "#");
			else assert(0);
		} fprintf(stderr, "\n");
	} fprintf(stderr, "\n");
}

bool check_puzzle(vvi grid, bool black_connectivity = true)
{
	int row = grid.size();
	int col = grid[0].size();

	// populate search spaces
	vector <Point> white_search;
	vector <Point> black_search;
	for (int i = 0; i < row; i ++) {
		for (int j = 0; j < col; j ++) {
			if (grid[i][j] > 0) {
				white_search.push_back(Point(i, j));
			}
			if (grid[i][j] == -1) {
				black_search.push_back(Point(i, j));
			}
		}
	}

	if (black_search.size() == 0) return false;

	if (black_connectivity) {
		// check if all blacks are connected
		bfs(grid, black_search[0], -1);
		if (tail != black_search.size()) {
			//fprintf(stderr, "ERROR: Walls are disconnected.\n");
			return false;
		}
	}

	// check for 2x2 blacks
	for (int i = 0; i < row - 1; i ++) {
		for (int j = 0; j < col - 1; j ++) {
			if (grid[i][j] == -1 && grid[i][j+1] == -1 && grid[i+1][j] == -1 && grid[i+1][j+1] == -1) {
				//fprintf(stderr, "ERROR: Can't have 2x2 walls.\n");
				return false;
			}
		}
	}

	// bfs call for checking if whites are satisfied
	int white_cells = 0;
	for (int i = 0; i < white_search.size(); i ++) {
		bfs(grid, white_search[i], 0);
		if (tail != grid[white_search[i].r][white_search[i].c]) {
			//fprintf(stderr, "ERROR: Rooms are the wrong size.\n");
			return false;
		}
		white_cells += tail;
	}

	if (white_cells + black_search.size() != row * col) {
		//fprintf(stderr, "ERROR: Rooms without a number.\n");
		return false;
	}

	//fprintf(stderr, "Congratulations! You've solved the puzzle.\n");
	return true;
}

// bfs on every "room" to find the number of cells in that room.
//	Sets a random cell in that room to be the number of cells found.
void fill_numbers(vvi &grid)
{
	int row = grid.size();
	int col = grid[0].size();
	for (int i = 0; i < row; i ++) {
		for (int j = 0; j < col; j ++) if (!grid[i][j]) {
			head = 0, tail = 0;
			Q[tail++] = Point(i, j);
			grid[i][j] = 0xff;
			while (head < tail) {
				Point p = Q[head++];
				for (int k = 0; k < 4; k ++) {
					int ii = p.r + dr[k], jj = p.c + dc[k];
					if (ii < 0 || ii >= row || jj < 0 || jj >= col) continue;
					if (!grid[ii][jj]) {
						Q[tail++] = Point(ii, jj);
						grid[ii][jj] = 0xff;
					}
				}
			}
			int seed = rand() % tail;
			grid[Q[seed].r][Q[seed].c] = tail;
		}
	}
	for (int i = 0; i < row; i ++) {
		for (int j = 0; j < col; j ++) {
			if (grid[i][j] == 0xff) grid[i][j] = 0;
		}
	}
}

int bit(vector <ull> num, int d) {
	return d < 64 ? num[0] >> d & 1 : num[1] >> d - 64 & 1;
}

bool is_lucky(int x, int n) {
	if ((x & 3) == 3 || (x >> n - 2 & 3) == 3) return 0;
	for (int i = 0; i < n - 2; i ++) if ((x >> i & 7) == 7) return 0;
	for (int i = 0; i < n - 1; i ++) if ((x >> i & 3) == 0) return 0;
//	return 1;
	for (int i = 0; i < n - 1; i ++) if ((x >> i & 3) == 3) return 1;
	return 0;
}

int random_lucky_num(int n) {
//	assert(n <= 15);
	while (1) {
		int x = rand() * rand() & ((1 << n) - 1);
		if (is_lucky(x, n)) return x;
	}
}

// get random number which identify the r x c puzzle
// first c bits of this number indicate first row of the puzzle & next c bits are second row & so on.
vector <ull> get_number(int r, int c, int top_row, int left_col, bool left_const, int right_col, bool right_const)
{
	if (top_row != -1) {
		if (left_col != -1) assert((top_row & 1) == (left_col & 1));
		if (right_col != -1) assert((top_row >> c - 1 & 1) == (right_col & 1));
		if (left_const && !(top_row & 1)) assert(top_row >> 1 & 1);
		if (right_const && !(top_row >> c - 1 & 1)) assert(top_row >> c - 2 & 1);
	}

	if (left_const && left_col == -1) {
		while (true) {
			left_col = random_lucky_num(r);
			if (top_row == -1 || (top_row & 1) == (left_col & 1)) break;
		}
	}
	if (right_const && right_col == -1) {
		while (true) {
			right_col = random_lucky_num(r);
			if (top_row == -1 || (top_row >> c - 1 & 1) == (right_col & 1)) break;
		}
	}

	if (left_const) assert(is_lucky(left_col, r));
	if (right_const) assert(is_lucky(right_col, r));

	int all_bit = (1 << c) - 1; // for single row

	int mask = all_bit;
	if (left_col != -1) mask ^= 1;
	if (right_col != -1) mask ^= 1 << c - 1;

	if (top_row) assert(top_row & mask);

	vector <ull> rlt;
	rlt.push_back(0);
	if (r * c > 64) rlt.push_back(0);

	for (int i = 0, prv; i < r; i ++) {
		int x = 0, y = 0;
		while (true) {

			if (!i && top_row != -1) {
				x = top_row; break;
			}

			x = rand() & mask;

			if (left_col != -1) {
				x ^= (left_col >> i & 1);
				if ((x & 1) && (i == r - 1 || !(left_col >> i + 1 & 1))
						&& (!i || !(left_col >> i - 1 & 1) || left_const && !(prv >> 1 & 1))) x |= 1 << 1;
			}
			if (left_const) {
				if (!(x & 1)) x |= 1 << 1;
			}

			if (right_col != -1) {
				x ^= (right_col >> i & 1) << c - 1;
				if ((x >> c - 1 & 1) && (i == r - 1 || !(right_col >> i + 1 & 1))
						&& (!i || !(right_col >> i - 1 & 1) || right_const && !(prv >> c - 2 & 1))) x |= 1 << c - 2;
			}
			if (right_const) {
				if (!(x >> c - 1 & 1)) x |= 1 << c - 2;
			}

			if (!(x & mask)) continue;

			if (!i) break;

			y = x & prv;
			if (!y) continue;

			bool valid = true;
			for (int j = 0; j < c - 1 && valid; j ++) if (((y >> j) & 3) == 3) valid = false;
			if (valid) break;
		}
		if ((i + 1) * c <= 64) {
			rlt[0] ^= ull(x) << i * c;
		}
		else if (i * c < 64) {
			rlt[0] ^= ull(x & ((1 << 64 - i * c) - 1)) << i * c;
			rlt[1] ^= ull(x >> 64 - i * c);
		}
		else {
			rlt[1] ^= ull(x) << i * c - 64;
		}
		prv = x;
	}

	return rlt;
}
/**
vvi get_random_puzzle(int row, int col, int first_col = -1, int first_row = -1)
{
	ull bit = 0;
	while (1) {
		bit = get_number(row, col, first_col, first_row);
		bool nice = true;
		for (int i = col - 1; i + col < row * col; i += col) {
			if (!(bit >> i & 1) && !(bit >> i + col & 1)) nice = false;
		}
		if (nice) break;
	}

	vvi grid;
	for (int i = 0; i < row; i ++) {
		grid.push_back(vi());
		for (int j = 0; j < col; j ++) {
			grid[i].push_back(-((bit >> i * col + j) & 1));
		}
	}
	return grid;
}*/

vvi get_valid_puzzle(int row, int col, int top_row, int left_col, bool left_const, int right_col, bool right_const)
{
	while (true) {

		vector <ull> num = get_number(row, col, top_row, left_col, left_const, right_col, right_const);

		vvi grid;
		for (int i = 0; i < row; i ++) {
			grid.push_back(vi());
			for (int j = 0; j < col; j ++) {
				grid[i].push_back(-bit(num, i * col + j));
			}
		}
		fill_numbers(grid);

		if (check_puzzle(grid)) {
			return grid;
		}
	}
}

void solve_puzzle_alap(vvi &grid, vvi &color, bool black_connectivity = true)
{
	int row = grid.size();
	int col = grid[0].size();

	// color can be 0, 1, 2. 0 means white, 2 means black, 1 means unknown cell
	color.clear();
	for (int i = 0; i < row; i ++) {
		color.push_back(vi());
		for (int j = 0; j < col; j ++) {
			color[i].push_back(0);
		}
	}
	for (int i = 0; i < row; i ++) {
		for (int j = 0; j < col; j ++) {
			// neighbors of cells has number 1 are all black
			if (grid[i][j] == 1) {
				if (i > 0) {
					color[i-1][j] = 2;
				}
				if (i + 1 < row) {
					color[i+1][j] = 2;
				}
				if (j > 0) {
					color[i][j-1] = 2;
				}
				if (j + 1 < col) {
					color[i][j+1] = 2;
				}
			}
			else if (grid[i][j] > 1) {
				// cells with number can make cells to white within distance it's number
				for (int ii = 0; ii < row; ii ++) {
					for (int jj = 0; jj < col; jj ++) if (grid[ii][jj] <= 0) {
						if (abs(i - ii) + abs(j - jj) < grid[i][j] && color[ii][jj] == 0) color[ii][jj] = 1;
					}
				}
			}
		}
	}
	for (int i = 0; i < row; i ++) {
		for (int j = 0; j < col; j ++) {
			if (color[i][j] == 0 && grid[i][j] <= 0) color[i][j] = 2;
		}
	}

	int white_all = 0, black_all = 0;
	for (int i = 0; i < row; i ++) {
		for (int j = 0; j < col; j ++) if (grid[i][j] > 0) white_all += grid[i][j];
	}
	black_all = row * col - white_all;

	// solve puzzle as long as we can determine some cells
	bool update = true;
	while (update) {
		update = false;
		for (int i = 0; i < row; i ++) {
			for (int j = 0; j < col; j ++) {
				if (color[i][j] == 1) {
					// when Point(i, j) is black, it makes 2x2, then this cell must be white
					bool white = false;
					if (i > 0 && j > 0 && color[i-1][j-1] == 2 && color[i-1][j] == 2 && color[i][j-1] == 2) white = true;
					else if (i > 0 && j + 1 < col && color[i-1][j] == 2 && color[i-1][j+1] == 2 && color[i][j+1] == 2) white = true;
					else if (i + 1 < row && j > 0 && color[i+1][j] == 2 && color[i][j-1] == 2 && color[i+1][j-1] == 2) white = true;
					else if (i + 1 < row && j + 1 < col && color[i][j+1] == 2 && color[i+1][j] == 2 && color[i+1][j+1] == 2) white = true;
					if (white) {
						color[i][j] = 0;
						update = true;
						continue;
					}
					// if there are at least two number cells among neighbors of one cell, it must be black
					// also if all neighbors are black, then it is black too
					int num_cnt = 0;
					white = true;
					bool black = true;
					for (int k = 0; k < 4; k ++) {
						int ii = i + dr[k], jj = j + dc[k];
						if (ii < 0 || ii >= row || jj < 0 || jj >= col) continue;
						if (grid[ii][jj] > 0) num_cnt ++;
						if (color[ii][jj] != 0) white = false;
						if (color[ii][jj] != 2) black = false;
					}
					if (num_cnt >= 2) black = true;
					if (white) {
						color[i][j] = 0;
						update = true;
						continue;
					}
					if (black) {
						color[i][j] = 2;
						update = true;
						continue;
					}
				}
				else if (color[i][j] == 0) { // white cell
					if (grid[i][j] > 1) {
						bfs(color, Point(i, j), 0);
						if (tail == grid[i][j]) {
							// if all white cells of one number cell are founded, then they are surrounded by black cells
							for (int k = 0; k < tail; k ++) {
								for (int l = 0; l < 4; l ++) {
									int ii = Q[k].r + dr[l], jj = Q[k].c + dc[l];
									if (ii < 0 || ii >= row || jj < 0 || jj >= col) continue;
									if (color[ii][jj] == 1) {
										color[ii][jj] = 2; update = true;
									}
								}
							}
						}
						else {
							// if there is only one neighbor cell that can be white, it is white
							int door = 0, I = -1, J = -1, II = -1, JJ = -1;
							for (int id = 0; id < tail; id ++) {
								for (int k = 0; k < 4; k ++) {
									int ii = Q[id].r + dr[k], jj = Q[id].c + dc[k];
									if (ii < 0 || ii >= row || jj < 0 || jj >= col) continue;
									if (color[ii][jj] == 1) {
										if (!door) I = ii, J = jj;
										else II = ii, JJ = jj;
										door ++;
									}
								}
							}
							if (door == 1) {
								color[I][J] = 0; update = true;
							}
							else if (door == 2 && tail == grid[i][j] - 1) {			// ..##.
								if (abs(I - II) == 1 && abs(J - JJ) == 1) {			// #.3*#
									if (color[I][JJ] == 1) {						// .?.#.	? = #
										color[I][JJ] = 2; update = true;
									}
									if (color[II][J] == 1) {
										color[II][J] = 2; update = true;
									}
								}
							}
						}
					}
					else {
						// if there is only one neighbor cell that can be white, it is white
						bfs(color, Point(i, j), 0);
						int door = 0, I = -1, J = -1;
						for (int id = 0; id < tail; id ++) {
							if (grid[Q[id].r][Q[id].c] == tail) {
								door = 0; break;
							}
							for (int k = 0; k < 4; k ++) {
								int ii = Q[id].r + dr[k], jj = Q[id].c + dc[k];
								if (ii < 0 || ii >= row || jj < 0 || jj >= col) continue;
								if (color[ii][jj] == 1) door ++, I = ii, J = jj;
							}
						}
						if (door == 1) {
							color[I][J] = 0; update = true;
						}
					}
				}
				else if (color[i][j] == 2 && black_connectivity) { // black cell
					// if there is only one neighbor cell that can be black, it is black
					bfs(color, Point(i, j), 2);
					if (tail != black_all) {
						int door = 0, I = -1, J = -1;
						for (int id = 0; id < tail; id ++) {
							for (int k = 0; k < 4; k ++) {
								int ii = Q[id].r + dr[k], jj = Q[id].c + dc[k];
								if (ii < 0 || ii >= row || jj < 0 || jj >= col) continue;
								if (color[ii][jj] == 1) door ++, I = ii, J = jj;
							}
						}
						if (door == 1) {
							color[I][J] = 2; update = true;
						}
					}
				}
			}
		}

		for (int i = 0; i < row; i ++) {
			for (int j = 0; j < col; j ++) {
				if (i < row - 1 && color[i][j] == 1 && color[i+1][j] == 1) {
					if (j && color[i][j-1] == 2 && color[i+1][j-1] == 2 || j + 1 < col && color[i][j+1] == 2 && color[i+1][j+1] == 2) {
						int door = 0;
						for (int k = 0; k < 4; k ++) {
							int ii = i + dr[k], jj = j + dc[k];
							if (ii < 0 || ii >= row || jj < 0 || jj >= col) continue;
							if (color[ii][jj] != 2) door ++;
						}
						if (door == 1) {
							color[i+1][j] = 0; update = true;
						}
						else {
							door = 0;
							for (int k = 0; k < 4; k ++) {
								int ii = i + 1 + dr[k], jj = j + dc[k];
								if (ii < 0 || ii >= row || jj < 0 || jj >= col) continue;
								if (color[ii][jj] != 2) door ++;
							}
							if (door == 1) {
								color[i][j] = 0; update = true;
							}
						}
					}
				}
				if (j < col - 1 && color[i][j] == 1 && color[i][j+1] == 1) {
					if (i && color[i-1][j] == 2 && color[i-1][j+1] == 2 || i + 1 < row && color[i+1][j] == 2 && color[i+1][j+1] == 2) {
						int door = 0;
						for (int k = 0; k < 4; k ++) {
							int ii = i + dr[k], jj = j + dc[k];
							if (ii < 0 || ii >= row || jj < 0 || jj >= col) continue;
							if (color[ii][jj] != 2) door ++;
						}
						if (door == 1) {
							color[i][j+1] = 0; update = true;
						}
						else {
							door = 0;
							for (int k = 0; k < 4; k ++) {
								int ii = i + dr[k], jj = j + 1 + dc[k];
								if (ii < 0 || ii >= row || jj < 0 || jj >= col) continue;
								if (color[ii][jj] != 2) door ++;
							}
							if (door == 1) {
								color[i][j] = 0; update = true;
							}
						}
					}
				}
			}
		}

		vvi reachable, vis;
		for (int i = 0; i < row; i ++) {
			reachable.push_back(vi());
			vis.push_back(vi());
			for (int j = 0; j < col; j ++) {
				reachable[i].push_back(0);
				vis[i].push_back(0);
			}
		}
		vector < vector <Point> > developing_regions;
		for (int i = 0; i < row; i ++) {
			for (int j = 0; j < col; j ++) {
				if (grid[i][j] > 0) {
					bfs(color, Point(i, j), 0);
					if (tail == grid[i][j]) continue;
					vector <Point> tmp;
					for (int k = 0; k < tail; k ++) tmp.push_back(Q[k]);
					developing_regions.push_back(tmp);
				}
			}
		}
		for (int s = 0; s < developing_regions.size(); s ++) {
			for (int i = 0; i < row; i ++) {
				for (int j = 0; j < col; j ++) {
					vis[i][j] = 0;
					if (color[i][j] == 2) vis[i][j] = 1;
				}
			}
			for (int t = 0; t < developing_regions.size(); t ++) if (t != s) {
				for (int id = 0; id < developing_regions[t].size(); id ++) {
					int i = developing_regions[t][id].r, j = developing_regions[t][id].c;
					vis[i][j] = 1;
					for (int k = 0; k < 4; k ++) {
						int ii = i + dr[k], jj = j + dc[k];
						if (ii < 0 || ii >= row || jj < 0 || jj >= col) continue;
						vis[ii][jj] = 1;
					}
				}
			}
			head = tail = 0;
			for (int i = 0; i < developing_regions[s].size(); i ++) Q[tail++] = developing_regions[s][i];
			int step = -tail;
			for (int i = 0; i < tail; i ++) {
				vis[Q[i].r][Q[i].c] = 1;
				if (grid[Q[i].r][Q[i].c] > 0) step += grid[Q[i].r][Q[i].c];
			}
			assert(step >= 0);
			while (step --) {
				int last = tail;
				while (head < last) {
					int i = Q[head].r, j = Q[head].c;
					head ++;
					for (int k = 0; k < 4; k ++) {
						int ii = i + dr[k], jj = j + dc[k];
						if (ii < 0 || ii >= row || jj < 0 || jj >= col) continue;
						if (!vis[ii][jj]) {
							Q[tail++] = Point(ii, jj);
							vis[ii][jj] = 1;
						}
					}
				}
			}
			for (int i = 0; i < tail; i ++) reachable[Q[i].r][Q[i].c] = 1;
		}
		for (int i = 0; i < row; i ++) {
			for (int j = 0; j < col; j ++) {
				if (color[i][j] == 1 && !reachable[i][j]) {
					color[i][j] = 2; update = true;
				}
			}
		}
	}
}

bool simple_nice_check(vvi &grid)
{
	int row = grid.size();
	int col = grid[0].size();
	vector <Point> whitePoints, blackPoints;
	for (int i = 0; i < row; i ++) {
		for (int j = 0; j < col; j ++) {
			if (grid[i][j] == 0) whitePoints.push_back(Point(i, j));
			else if (grid[i][j] == -1) blackPoints.push_back(Point(i, j));
		}
	}
	for (int i = 0; i < whitePoints.size(); i ++) {
		for (int j = 0; j < blackPoints.size(); j ++) {
			vvi tmp_grid = grid;
			swap(tmp_grid[whitePoints[i].r][whitePoints[i].c], tmp_grid[blackPoints[j].r][blackPoints[j].c]);
			if (check_puzzle(tmp_grid)) return false;
		}
	}
	return true;
}

bool is_nice_puzzle(vvi &grid, int difficulty, vector <vvi> &candidates)
{
	int row = grid.size();
	int col = grid[0].size();

	int maxn = 0;
	for (int i = 0; i < row; i ++) {
		for (int j = 0; j < col; j ++) maxn = max(maxn, grid[i][j]);
	}

	if (difficulty == 0) {
		if (!(3 <= maxn && maxn <= 5)) {
			return false;
		}
	}
	else if (difficulty == 1) {
		if (!(5 <= maxn && maxn <= 7)) {
			return false;
		}
	}
	else if (difficulty == 2) {
		if (!(7 <= maxn)) {
			return false;
		}
	}

	if (!simple_nice_check(grid)) return false;

	vvi color;
	solve_puzzle_alap(grid, color);

	int white_counts = 0;
	int black_counts = 0;
	vector <Point> unknownPoints;

	for (int i = 0; i < row; i ++) {
		for (int j = 0; j < col; j ++) {
			if (grid[i][j] > 0) {
				white_counts += grid[i][j];
			}
			else {
				if (color[i][j] == 1) unknownPoints.push_back(Point(i, j));
				else if (color[i][j] == 2) black_counts ++;
			}
		}
	}

	int unknown = unknownPoints.size();
	int blacks_more = row * col - white_counts - black_counts;

#define SHOW_CHECKING_NICE0
#ifdef SHOW_CHECKING_NICE
	print_puzzle2(grid, color);
	fprintf(stderr, "? %d, # %d\n\n", unknown, blacks_more);
//	exit(0);
#endif // SHOW_CHECKING_NICE

	// when execution time will be very big, we return false
	if (unknown > 24 || unknown > 20 && blacks_more > 10) return false;

	candidates.clear();

	// check all possible puzzle solution
	for (int i = 0; i < (1 << unknown); i ++) {
#ifdef SHOW_CHECKING_NICE
		int semi = 1 << max(0, unknown - 3);
		if (i % semi == semi - 1) fprintf(stderr, "checking %.1lf%% done.\n", (i + 1.0) / semi * 12.5);
#endif // SHOW_CHECKING_NICE
		if (__builtin_popcount(i) != blacks_more) continue;
		vvi tmp_grid = grid;
		for (int j = 0; j < unknown; j ++) {
			if (i & (1 << j)) tmp_grid[unknownPoints[j].r][unknownPoints[j].c] = -1;
			else tmp_grid[unknownPoints[j].r][unknownPoints[j].c] = 0;
		}
		if (check_puzzle(tmp_grid, false)) {
			candidates.push_back(tmp_grid);
			if (tmp_grid != grid && check_puzzle(tmp_grid)) return false;
		}
	}
#ifdef SHOW_CHECKING_NICE
	fprintf(stderr, "\n");
#endif // SHOW_CHECKING_NICE
	return true;
}

bool is_nice_match(int x, int y, int n) {
	if (!(x & y) || (x | y) != (1 << n) - 1) return 0;
	for (int i = 0; i < n - 1; i ++) if (((x & y) >> i & 3) == 3) return 0;
	return 1;
}

int get_nice_belt(int x, int n) {
//	assert(n <= 15);
	while (true) {
		int y = rand() * rand() & ((1 << n) - 1);
		if (is_nice_match(x, y, n)) return y;
	}
}

int rev(int x, int n) {
	int y = 0;
	for (int i = 0; i < n; i ++) if (x >> i & 1) y |= 1 << n - 1 - i;
	return y;
}

// return a puzzle we want to find
// last row can be determined before or not
vvi get_primary_puzzle(vector <vvi> &candidates, int row, int col, int difficulty,
						int left_col, bool left_const, int right_col, bool right_const, int time_limit = 1e8)
{
//	fprintf(stderr, "%d %d %d %d\n", row, col, difficulty, left_col);
	vvi grid;

	int start = clock();

	while (clock() - start < time_limit) {
	//	fprintf(stderr, "a\n");
		grid = get_valid_puzzle(row, col, -1, left_col, left_const, right_col, right_const);
	//	fprintf(stderr, "b\n");
	//	print_puzzle(grid);
		if (is_nice_puzzle(grid, difficulty, candidates)) {
			if (left_const) {
				bool acceptable = true;
				for (int k = 0; k < candidates.size() && acceptable; k ++) {
					for (int i = 0; i < row; i ++) if (grid[i][0] != candidates[k][i][0]) acceptable = false;
				}
				assert(acceptable);
			}
			if (right_const) {
				bool acceptable = true;
				for (int k = 0; k < candidates.size() && acceptable; k ++) {
					for (int i = 0; i < row; i ++) if (grid[i][col-1] != candidates[k][i][col-1]) acceptable = false;
				}
				assert(acceptable);
			}
		//	print_puzzle(grid);
		//	fprintf(stderr, "candidates : %d\n\n", candidates.size());
			return grid;
		}
	}

	grid.clear();

	return grid;
}

// main function
// if size of puzzle is small, then we return by get_primary_puzzle
// if not, we construct puzzle in 2 steps
vvi get_puzzle(int row, int col, int difficulty)
{
	vvi grid;
	vector <vvi> candidates;

	bool tran = false;

	if (max(row, col) <= 10) {
		if (row < col) swap(row, col), tran = true;

		int left_col = -1, right_col = -1;
		bool left_const = false, right_const = false;
		while (true) {
		//	if (col >= 6) left_col = random_lucky_num(row);
		//	if (col >= 7) left_const = true;
		//	if (col >= 9) right_const = true;
			if (col >= 5) left_col = rand() & ((1 << row) - 1);
			if (col >= 7) right_col = rand() & ((1 << row) - 1);
			if (col >= 9) {
				left_col = random_lucky_num(row), left_const = 1;
				right_col = random_lucky_num(row), right_const = 1;
			}
			grid = get_primary_puzzle(candidates, row, col, difficulty, left_col, left_const, right_col, right_const, 1000);
			if (grid.size()) break;
		}
	}
	else {
		if (row > col) swap(row, col), tran = true;

		while (true) {

			int sub_col[10], cnt, sub_difficulty[10];

			if (col <= 13 || row <= 7) cnt = 2;
			else if (col <= 17) cnt = 3;
			else cnt = 4;

			for (int i = 0; i < cnt; i ++) sub_col[i] = col / cnt + (i && i <= col % cnt);
			if (sub_col[cnt-1] > sub_col[0]) swap(sub_col[cnt-1], sub_col[0]);

			if (col == 15 && cnt == 3) sub_col[0] = 5, sub_col[1] = 6, sub_col[2] = 4;
			if (col == 16 && cnt == 3) sub_col[0] = 6, sub_col[1] = 6, sub_col[2] = 4;

			sub_difficulty[0] = difficulty;
			for (int i = 1; i < cnt; i ++) sub_difficulty[i] = sub_col[i] <= 6 || row <= 6 ? min(difficulty, 1) : difficulty;

			vvi sub_grid[10];

		//	fprintf(stderr, "+++++++++++++++++++++++++++++++\n");
		//	for (int i = 0; i < cnt; i ++) fprintf(stderr, "%dx%d:%d   ", row, sub_col[i], sub_difficulty[i]); fprintf(stderr, "\n");

			int all_bit = (1 << row) - 1;
			int prv_belt = 0, nxt_belt = 0;

			int sub_belt = -1;
			bool sub_const = false;

			for (int t = 0; t < cnt; t ++) {
			//	fprintf(stderr, "generating %d-th sub puzzle...\n", t + 1); if (t) fprintf(stderr, "\n");
				if (!t) {
					prv_belt = nxt_belt = 0;
					while (true) {
						sub_belt = -1, sub_const = false;
						if (!sub_const && sub_col[0] >= 5) sub_belt = rand()* rand() & ((1 << row) - 1);
					//	if (sub_col[0] >= 7) sub_belt = random_lucky_num(row), sub_const = true;
						sub_grid[0] = get_primary_puzzle(candidates, row, sub_col[0], sub_difficulty[0], sub_belt, sub_const, -1, true, 5 * 1000);
						if (!sub_grid[0].size()) continue;
						for (int j = 0; j < row; j ++) if (sub_grid[0][j][sub_col[0]-1] == -1) prv_belt ^= 1 << j;
						if (prv_belt) break;
					}
				//	print_puzzle(sub_grid[0]);
				}
				else {
					int bad_count = 0;
					while (true) {
					//	fprintf(stderr, "start\n");
						nxt_belt = get_nice_belt(prv_belt, row);
					//	for (int j = 0; j < row; j ++) fprintf(stderr, "%d", prv_belt >> j & 1); fprintf(stderr, "\n");
					//	for (int j = 0; j < row; j ++) fprintf(stderr, "%d", nxt_belt >> j & 1); fprintf(stderr, "\n");
					//	fprintf(stderr, "finish\n");

						sub_belt = -1, sub_const = t < cnt - 1;
						if (!sub_const && sub_col[t] >= 5) sub_belt = rand() * rand() & ((1 << row) - 1);
					//	if (sub_col[t] >= 7) sub_belt = random_lucky_num(row), sub_const = true;

						vector <vvi> sub_can, tmp_can;
						sub_grid[t] = get_primary_puzzle(sub_can, row, sub_col[t], sub_difficulty[t], nxt_belt, false, sub_belt, sub_const, 5 * 1000);
						if (!sub_grid[t].size()) continue;
					//	print_puzzle(sub_grid[t]);

						int tmp_belt = 0;
						for (int i = 0; i < row; i ++) if (sub_grid[t][i][sub_col[t]-1] == -1) tmp_belt ^= 1 << i;
						if (t < cnt - 1) assert(is_lucky(tmp_belt, row));

						int sol = 0;
						for (int x = 0; x < candidates.size(); x ++) {
							for (int y = 0; y < sub_can.size(); y ++) {
								vvi tmp = candidates[x];
								for (int ii = 0; ii < row; ii ++) {
									for (int jj = 0; jj < sub_col[t]; jj ++) tmp[ii].push_back(sub_grid[t][ii][jj]);
								}
								if (check_puzzle(tmp, 0)) {
									tmp_can.push_back(tmp);
									if (check_puzzle(tmp)) sol ++;
								}
							}
						}

					//	fprintf(stderr, "%d solutions are founded.\n", sol, t - 1, t);

						assert(sol);

						if (sol == 1) {
							candidates = tmp_can;
							prv_belt = tmp_belt;
							break;
						}
						else {
							if (++ bad_count >= 5) {
								t = -1;
								break;
							}
						}
					}
				//	fprintf(stderr, "\n");
				}
			}

			grid.clear();
			for (int i = 0; i < row; i ++) {
				grid.push_back(vi());
				for (int t = 0; t < cnt; t ++) {
					for (int j = 0; j < sub_col[t]; j ++) grid[i].push_back(sub_grid[t][i][j]);
				}
			}

			if (simple_nice_check(grid)) break;
		}
	}

	if (tran) {
		vvi tmp_grid;
		for (int i = 0; i < col; i ++) {
			tmp_grid.push_back(vi());
			for (int j = 0; j < row; j ++) tmp_grid[i].push_back(grid[j][i]);
		}
		grid = tmp_grid;
		swap(row, col);
	}

	assert(check_puzzle(grid));

	return grid;

	/*
	double start = clock();
	int limit_org = max(row, col) - 1 - rand() % 3;

	while (true) {

		Generator G(row, col);
		G.generate();
		grid = G.getGrid();
		fill_numbers(grid);

		int nums = 0, ones = 0, maxn = 0, inmax = 0;
		for (int i = 0; i < grid.size(); i ++) {
			for (int j = 0; j < grid[i].size(); j ++) {
				if (grid[i][j] > 0) nums ++;
				if (grid[i][j] == 1) ones ++;
				maxn = max(maxn, grid[i][j]);
				if (i > 1 && j > 1 && i < row - 2 && j < col - 2) inmax = max(inmax, grid[i][j]);
			}
		}
		int limit = limit_org - (int)((clock() - start) / 1000);
		int max_ones = nums * 0.7;
		if (ones > max_ones || maxn < limit || inmax < maxn - 2) continue;

		if (is_nice_puzzle(grid)) {
			print_puzzle(grid);
			return grid;
		}
	}
	*/
}

string puzzle_to_string(vvi &grid)
{
	int row = grid.size();
	int col = grid[0].size();

	char buf[11];

	string rlt = "";

	sprintf(buf, "%dx%d:", col, row);
	string rlt_kakuro_form = buf;

	for (int i = 0; i < grid.size(); i ++) {
		for (int j = 0; j < grid[i].size(); j ++) {
			if (grid[i][j] > 0) {
				sprintf(buf, "%d", grid[i][j]);
				rlt += buf;
				rlt_kakuro_form += buf;
			}
			else {
				if (grid[i][j] == 0) rlt += '*';
				else rlt += '#';
				rlt_kakuro_form += '-';
			}
			if (i < grid.size() - 1 || j < grid[i].size() - 1) {
				rlt += ',';
				rlt_kakuro_form += ',';
			}
		}
	}
//	return rlt_kakuro_form;
	return rlt;
}

char suf[][3] = {"st", "nd", "rd", "th"};

int main()
{
	freopen("out.txt", "w", stdout);
	srand(time(NULL));

	int row = 20, col = 20;
	int difficulty = 2, counts = 10;

	while (true) {
		fprintf(stderr, "Please input puzzle size, difficulty & counts. (ex. 5 5 2 10):\n");
		fprintf(stderr, "(difficulty can be -1, 0, 1, 2. if you don't want to set difficulty, input -1.)\n\n");
		cin >> row >> col >> difficulty >> counts;
		if (row < 5 || row > 100 || col < 5 || col > 100) {
			fprintf(stderr, "Invalid size. Input again.\n");
			continue;
		}
		if (difficulty < -1 || difficulty > 2) {
			fprintf(stderr, "Difficulty can be one of {-1, 0, 1, 2}.\n");
			continue;
		}
		fprintf(stderr, "\n");
		break;
	}

	for (int i = 0; i < counts; i ++) {
		double start = clock();
		vvi grid = get_puzzle(row, col, difficulty);
		print_puzzle(grid);
		cout << puzzle_to_string(grid) << endl;
		fprintf(stderr, "%d-%s puzzle generated in %.3lf s\n", i + 1, suf[min(i,3)], (clock() - start) / 1000.0);
		fprintf(stderr, "-------------------------------------------------------------------------------\n\n\n");
	}
	return 0;
}
