#ifndef color_H
#define color_H
namespace color {
	class Color {
	protected:
		virtual void _change_fore() = 0;
		virtual void _change_back() = 0;
	public:
		void change_fore();
		void change_back();
		void reset_fore();
		void reset_back();
		virtual ~Color();
	};
	class Black: public Color {
	protected:
		void _change_fore();
		void _change_back();
	public:
		Black(int=0);
	};
	class White: public Color {
	protected:
		void _change_fore();
		void _change_back();
	public:
		White(int=0);
	};
	class Green: public Color {
	protected:
		void _change_fore();
		void _change_back();
	public:
		Green(int=0);
	};
};
#endif
