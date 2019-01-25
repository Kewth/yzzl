#ifndef pos_H
#define pos_H
#include <map>
namespace pos {
	class Pos {
	protected:
	public:
		int _x, _y;
		Pos(int=0, int=0);
		bool operator < (Pos) const;
	};
	template<class T>
	class Coord_map {
		// 维护二维数组
	protected:
		std::map<Pos, T> _map;
	public:
		int high, width;
		/* T& operator () (int, int); */
		/* T& operator () (Pos); */
		/* Coord_map<T>(int, int); */
		// 我 tm 是真的 tm 的对模板类无语，贴声明连编译都过不了
		// 到时候再改，先用着
		T& operator () (int x, int y) { return _map[pos::Pos(x, y)]; }
		T& operator () (Pos p) { return _map[p]; }
		Coord_map<T>(int x, int y): high(x), width(y) {}
	};
};
#endif
