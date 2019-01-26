#include "../include/pos.h"

namespace pos {
	pos::Pos::Pos(int x, int y): _x(x), _y(y) {
	}
	bool pos::Pos::operator < (pos::Pos an) const {
		return _x == an._x ? _y < an._y : _x < an._x;
	}

	// 我 tm 是真的 tm 的对模板类无语，贴声明连编译都过不了
	// 到时候再改，先用着
	/* template<class T> */
	/* T& pos::Coord_map<T>::operator () (int x, int y) { */
	/* 	return _map[pos::Pos(x, y)]; */
	/* } */

	/* template<class T> */
	/* pos::Coord_map<T>::Coord_map(int high, int width): */
	/* 	high(high), width(width) { */
	/* } */

	/* int main() { */
	/* 	std::map<pos::Pos, int> mp; */
	/* 	pos::Pos p(1, 2), pp(2, 1); */
	/* 	if(p < pp) */
	/* 		return  0; */
	/* 	pos::Coord_map<char> map(1, 2); */
	/* 	map(0, 0) = '1'; */
	/* } */
};
