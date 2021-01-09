#include "head4log.h"
#include "russia.h"
#include <pthread.h>
#include <string.h>

#include <iostream>
#include <string>
#include <thread>
#include <mutex>

namespace Tetris {

	class Scr {
	public:
		Scr(int x, int y);
		~Scr();
		int wide() { return m_wide; };
		int high() { return m_high; };
		int size() { return m_size; };

	protected:
		const int m_wide;
		const int m_high;
		const int m_size;
	};

	Scr::Scr(int x, int y) : m_wide(x), m_high(y), m_size(x*y) {}
	Scr::~Scr() {}

	class Game {
	public:
		char *m_buf;
		char *m_map;
		pthread_mutex_t m_scrMutex;

		void gameInit()
		{
			m_mapSize = (this->m_scr.high() + 2)*(this->m_scr.wide() + 2);
			m_map = new char[m_mapSize];
			memset(m_map, 0, m_mapSize);

			m_bufSize = this->m_mapSize * 4;
			m_buf = new char[m_bufSize];
			memset(m_buf, 0, m_bufSize);

			m_scrMutex = PTHREAD_MUTEX_INITIALIZER;
		}

		Game(const int x = 5, const int y = 10) :m_scr(x, y) { gameInit(); };
		Game(const Scr &scr) :m_scr(scr) { gameInit(); };
		~Game() { delete m_buf; };

		size_t bufSize() { return m_bufSize; };
		size_t mapSize() { return m_mapSize; };

	private:
		Scr m_scr;
		size_t m_bufSize;
		size_t m_mapSize;
	};
}



using namespace Tetris;
using namespace std;

int main()
{



	creat_log("./", NULL);
	Game game(4, 6);
	cout << game.m_bufSize << endl;
}