#define POOL_SIZE (8 * 1024 * 1024)
#define NULL ((void *)0)

typedef unsigned long size_t;
extern char my_mem_pool[POOL_SIZE];

struct header
{
    int size;
    struct header *next;
};

#define HEAD_SIZE sizeof(struct header)
// struct header* last;
size_t current = 0; // 记录一下当前分配了多少

void __attribute__((noinline)) my_init() { // 作为起始，不变化了
    header* head = (header*)my_mem_pool;
    head->size = 0;
    head->next = nullptr;
    current += HEAD_SIZE; // 解引用，读大小写入
    // last = head; // 记录一下
}

void * __attribute__((noinline)) my_malloc(size_t size) {
    if (POOL_SIZE - current < size + HEAD_SIZE) {
        return NULL; // 无了
    }

    char* c_head = my_mem_pool + current; // 新头位置
    struct header* head = (struct header*)c_head;
    head->size = size;
    head->next = nullptr;
    current += size + HEAD_SIZE;

    struct header* iter = (struct header*)my_mem_pool;
    while (iter->next != nullptr)
    {
        iter = iter->next;
    }
    iter->next = head; // 连上去
    
    return head + HEAD_SIZE;
}

void __attribute__((noinline)) my_free(void *ptr) {
    if (ptr == NULL) {
        return;
    }

    struct header* head = (struct header*)((char*)ptr - HEAD_SIZE);
    current -= HEAD_SIZE; // 回收头
    current -= head->size; // 回收数据

    // 断开
    struct header* iter = (struct header*)my_mem_pool;
    if (iter == head) { // 首链
        iter = iter->next;
        return;
    }

    while (iter->next != nullptr) {
        if (iter->next == head) {
            // 找到了
            iter->next = head->next; // 跳过head
            return;
        }
        iter = iter->next;
    }
    return;
}