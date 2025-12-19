#define POOL_SIZE (8 * 1024 * 1024)
#define CHUNK_SIZE 8 * 1024 * 1024 / 32 // 32 字节为一块
#define NULL ((void *)0)

typedef unsigned long size_t;
extern char my_mem_pool[POOL_SIZE];

struct header
{
    int chunk; // 占用的块号
    int amount; // 占用的块数
    int freed; // 是否释放
    struct header *next; // 下一个
};

#define HEAD_SIZE sizeof(struct header)
struct header *head_chunk;
unsigned long used_chunks = 0;

void __attribute__((noinline)) my_init() {
    // 定义出首块
    head_chunk = (struct header *)my_mem_pool;
    head_chunk->chunk = 1;
    head_chunk->amount = 1;
    head_chunk->freed = 0;
    head_chunk->next = NULL;
    used_chunks += 1;
}

void * __attribute__((noinline)) my_malloc(size_t size) {
    if (size == 0 || size > 4096) {
        return NULL;
    }

    unsigned long need_chunk = (size + HEAD_SIZE + 31) / 32; // 需要的块数
    if (used_chunks + need_chunk > CHUNK_SIZE) {
        return NULL;
    }

    used_chunks += need_chunk;
    struct header *iter = head_chunk;

    // 在中间搜索可用空缺
    while (iter->next != NULL) {
        struct header *next = iter->next; // 下一个块
        if (next->chunk - (iter->chunk + iter->amount) >= need_chunk) { // 能插入
            struct header *new_header = (struct header *)((char *)my_mem_pool + (iter->chunk + iter->amount) * 32); // 定位新头位置
            new_header->chunk = iter->chunk + iter->amount;
            new_header->amount = need_chunk;
            new_header->freed = 0;
            new_header->next = next;
            iter->next = new_header;
            return (void *)((char *)new_header + HEAD_SIZE);
        }

        iter = next;
    }
    
    // 尾巴
    struct header *new_header = (struct header *)((char *)my_mem_pool + (iter->chunk + iter->amount) * 32);
    new_header->chunk = iter->chunk + iter->amount;
    new_header->amount = need_chunk;
    new_header->freed = 0;
    new_header->next = NULL;
    iter->next = new_header;
    return (void *)((char *)new_header + HEAD_SIZE);
}

void __attribute__((noinline)) my_free(void *ptr) {
    if (ptr == NULL) return;

    struct header *block = (struct header *)((char *)ptr - HEAD_SIZE);
    if (block->freed) return;

    used_chunks -= block->amount;
    block->freed = 1;

    // 头链
    struct header *iter = head_chunk;
    if (iter == block) {
        head_chunk = block->next;
        return;
    }

    // 其他后方的
    while (iter->next != NULL) {
        if (iter->next == block) {
            iter->next = block->next;
            return;
        }
        iter = iter->next;
    }
}