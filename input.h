#ifndef _INPUT_H_
#define _INPUT_H_

#include <unistd.h>
#include <string.h>
#include <strings.h>
#include <errno.h>
#include <termios.h>
#include <fcntl.h>

#include "head4log.h"


class CmdFunc
{
public:
	int m_pipefd[2];
	struct termios *m_tmp_term;
	struct termios *m_term;
	

	CmdFunc() :m_term(NULL){ classInit(); };
	~CmdFunc() {
		tcsetattr(2, TCSANOW, m_term);
		delete m_term;
		delete m_tmp_term;
	};
protected:
	
private:
	void classInit()
	{
		int ret = pipe(m_pipefd);
		if (ret < 0) {
			LOG("pipe fail errmsg : %s(%d)\n",strerror(errno), errno);
			return;
		}

		m_term = new struct termios;
		if (m_term == NULL) {
			LOG("new fail\n");
			return;
		}
		m_tmp_term = new struct termios;
		if (m_tmp_term == NULL) {
			LOG("new fail\n");
			return;
		}

		tcgetattr(2, m_term);
		memcpy(m_tmp_term, m_term, sizeof(m_term));
		m_tmp_term->c_lflag &= ~(ECHO | ICANON);
		m_tmp_term->c_lflag |= ISIG;
		tcsetattr(2, TCSANOW, m_tmp_term);
		fcntl(m_pipefd[0], F_SETFL, O_NONBLOCK);
	}
};


#endif // _INPUT_H_
