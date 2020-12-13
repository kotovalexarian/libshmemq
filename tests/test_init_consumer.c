#include <shmemq.h>

#include <assert.h>
#include <string.h>
#include <sys/mman.h>

int main()
{
    struct Shmemq shmemq;
    memset(&shmemq, 0, sizeof(shmemq));

    assert(shmemq_init(&shmemq, "/foobar", true) == SHMEMQ_ERROR_NONE);

    assert(strcmp(shmemq.name, "/foobar") == 0);
    assert(shmemq.is_consumer == true);
    assert(shmemq.shm_id != -1);
    assert(shmemq.buffer != NULL);
    assert(shmemq.buffer->header.frames_count == 0);
    assert(shmemq.buffer->header.read_frame_index == 0);
    assert(shmemq.buffer->header.write_frame_index == 0);

    assert(shm_unlink("/foobar") == 0);

    return 0;
}
