#include"OrderManager.h"

pthread_mutex_t OrderManager::lock = PTHREAD_MUTEX_INITIALIZER;
OrderManager * OrderManager:: instance = nullptr;
