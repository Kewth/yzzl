#ifndef pos_H
#define pos_H
#include <map>
namespace pos {
	class Pos {
	protected:
		int _x, _y;
	public:
		Pos(int, int);
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
		/* Coord_map<T>(int, int); */
		// 我 tm 是真的 tm 的对模板类无语，贴声明连编译都过不了
		// 到时候再改，先用着
		T& operator () (int x, int y) { return _map[pos::Pos(x, y)]; }
		Coord_map<T>(int x, int y): high(x), width(y) {}
	};
};
#endif
