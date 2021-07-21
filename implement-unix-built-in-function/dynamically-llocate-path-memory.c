#include "./include/apue.h"
#include <errno.h>
#include <limits.h>

/**
 * 如果<limits.h>中定义了常量 PATH_MAX,不会有操作,如果未定义,则需要调用 pathconf ,因为pathconf 的返回值是基于工作目录的相对路径名的最大长度,而工作目录是其第一个参数,
 * 所以指定根目录为第一个参数,并将得到的返回值加 1 作为结果值.如果 pathconf 指明PATH_MAX是不确定的,那么就猜测一个值
 */
#ifdef PATH_MAX
	static long pathmax = PATH_MAX;
#else
	static long pathmax = 0;
#endif

static long posix_version = 0;
static long xsi_version = 0;

/* If PATH_MAX is indeterminate, no guarantee this is adequate  */
#define PATH_MAX_GUESS 1024

char *path_alloc(size_t *sizep){ /* also return allocated size,if nonnull */
	char *ptr;
	size_t size;

	if(posix_version == 0){
		posix_version = sysconf(_SC_VERSION);
	}

	if(xsi_version == 0){
		xsi_version = sysconf(_SC_XOPEN_VERSION);
	}

	if(pathmax == 0) {
		errno = 0;
		if((pathmax = pathconf("/",_PC_PATH_MAX)) < 0){
			if(errno == 0){
				pathmax = PATH_MAX_GUESS;
			}else {
				err_sys("pathconf error for _PC_PATH_MAX");
			}
		}else {
			pathmax++;
		}
	}

	/*
	 * before POSIX.1-2001, we aren`t guaranteed that PATH_MAX includes
	 * the terminating null byte. asme gose for XPG3
	 */
	if((posix_version < 200112L) && (xsi_version < 4)){
		size = pathmax + 1;
	}else {
		size = pathmax;
	}

	if( (ptr = malloc(size)) == NULL){
		err_sys("malloc error for pathname");
	}

	if(sizep != NULL){
		*sizep = size;
	}
	return(ptr);
}
