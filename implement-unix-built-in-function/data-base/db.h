typedef	void *	DBHANDLE;

DBHANDLE db_open(const char *, int,.../* int mode*/);

void db_close(DBHANDLE);

int db_store(DBHANDLE,const char *,const char *,int);

char *db_fetch(DBHANDLE,const char *);

int db_deleye(DBHANDLE ,const char *);

void db_rewind(DBHANDLE);

char *db_nextrec(DBHANDLE,char *);
