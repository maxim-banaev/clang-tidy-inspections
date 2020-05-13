#include <iostream>

namespace bugprone::spuriously_wake_up_functions {

    struct Node1 {
        void * Node1;
        struct Node1 * next;
    };

    typedef struct mtx_t {
    } mtx_t;
    typedef struct cnd_t {
    } cnd_t;
    struct timespec {
    };

    int cnd_wait(cnd_t * cond, mtx_t * mutex) {}

    int cnd_timedwait(cnd_t * cond, mtx_t * mutex,
                      const struct timespec * time_point) {}

    struct Node1 list_c;
    static mtx_t lock;
    static cnd_t condition_c;
    struct timespec ts;

    void check() {
        std::cout << "-- check spuriously-wake-up-functions FIXME" << std::endl;

        if (list_c.next == NULL) {
            if (0 != cnd_wait(&condition_c, &lock)) {} //should warn here
        }
    }
} // namespace bugprone::spuriously_wake_up_functions
