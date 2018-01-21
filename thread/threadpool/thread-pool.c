#include "thread-pool.h"

//#define TEST_LIB


#define DBG_OUT(args...)\
do{\
    char b__[1024];\
    sprintf(b__, args);\
    fprintf(stderr, "%u:[%s, %d] %s",(unsigned long)time(NULL), __FUNCTION__, __LINE__, b__);\
}while(0)

static void *tp_work_thread(void *pthread);
static void *tp_manage_thread(void *pthread);

static TPBOOL tp_init(tp_thread_pool *this);
static void tp_close(tp_thread_pool *this);
static void tp_process_job(tp_thread_pool *this, tp_work worker, tp_work_desc job);
static int tp_get_thread_by_id(tp_thread_pool *this, pthread_t id);
static TPBOOL tp_add_thread(tp_thread_pool *this);
static TPBOOL tp_delete_thread(tp_thread_pool *this);
static int tp_get_tp_status(tp_thread_pool *this);




