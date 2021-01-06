#include "head4log.h"
#include "russia.h"
#include <iostream>

namespace Tetris {

	class Scr {
	public:
		Scr(int x, int y) : _wide(x), _high(y), _size(x*y)
		{

		}

		Scr(const Scr &_scr) : _wide(_scr._wide), _high(_scr._high), _size(_scr._size)
		{

		}

		int size() {
			return _size;
		}

		int wide() {
			return _wide;
		}

		int high() {
			return _high;
		}
	protected:
		const int _wide;
		const int _high;
		const int _size;

	};

	class Game {
	public:
		char *buf;
		size_t buf_size;

		Game(const int x = 5, const int y = 10) : scr(x , y)
		{
			buf_size = scr.size() * 4;
			buf = new char[buf_size];
		}

		Game(const Scr &_scr) : scr(_scr)
		{
			buf_size = scr.high() * 4;
			buf = new char[buf_size];
		}
		

	protected:
		Scr scr;
	};

}

using namespace std;
using namespace Tetris;

int main()
{
	creat_log("./", NULL);
	Game game(4, 6);
	cout << game.buf_size << endl;
}