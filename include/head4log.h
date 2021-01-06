#ifndef __HEAD4LOG_H__
#define __HEAD4LOG_H__

#include <stdarg.h>
#include <stdint.h>


#define COL_BK	30
#define COL_RD	31
#define COL_GN	32
#define COL_YE	33
#define COL_BU	34
#define COL_VT	35
#define COL_DG	36
#define COL_WH	37

#define PRINT_COLV_BK printf("\033[%dm",COL_BK)
#define PRINT_COLV_RD printf("\033[%dm",COL_RD)
#define PRINT_COLV_GN printf("\033[%dm",COL_GN)
#define PRINT_COLV_YE printf("\033[%dm",COL_YE)
#define PRINT_COLV_BU printf("\033[%dm",COL_BU)
#define PRINT_COLV_VT printf("\033[%dm",COL_VT)
#define PRINT_COLV_DG printf("\033[%dm",COL_DG)
#define PRINT_COLV_WH printf("\033[%dm",COL_WH)
#define PRINT_COLV_0  printf("\033[%dm",0)

#ifndef LOG_FILE_NAME
#define LOG_FILE_NAME	"default"
#endif // !LOG_FILE_NAME

#ifndef LOG_FILE_PATH
#define LOG_FILE_PATH "./log/"
#endif // !LOG_FILE_PATH

#ifndef LOG_BUFFER_SIZE
#define LOG_BUFFER_SIZE 4096
#endif // !LOG_BUFFER_SIZE


extern int log_color;
extern int __is_printf;

#define NPRINTF do{__is_printf=0;}while(0)
#define SET_LOGCOLOR(color) do{	log_color = color; \
								}while(0)
#define LOGNT(msg, ...) log_printf(0, log_color, msg, ##__VA_ARGS__)
#define LOGNL(msg, ...) log_printf(1, log_color, msg, ##__VA_ARGS__)
#define LOG(msg, ...)	log_printf(1, log_color, "[%s-%d]:"msg, __FUNCTION__, __LINE__, ##__VA_ARGS__)
#define LOGC(color_flag, msg, ...) log_printf(1,color_flag,"[%s-%d]:"msg, __FUNCTION__, __LINE__, ##__VA_ARGS__)
#define LOGCNT(color_flag, msg, ...) log_printf(0, color_flag, msg, ##__VA_ARGS__)

extern "C" {
	int _creat_log_path(const char *path);
	int creat_log(const char *path, const char *tag);
	void log_printf(uint8_t log_time_flag, int color_flag, const char *fmt, ...);
}

#ifdef LOGS
typedef struct log_node
{
	char *key;
	struct log_node *next, *prev;
	FILE *fp;
}log_node;
#endif // !ONE_LOG







#endif // !__HEAD4LOG_H__


