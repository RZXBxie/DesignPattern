#include <iostream>
#include <mutex>
#include <atomic>
using namespace std;

// 定义一个单例模式的任务队列

#if 0
// 懒汉式，原子变量+双重检查锁定
class TaskQueue {
public:
    static TaskQueue* getInstance() {
        TaskQueue* task = m_task.load();
        if (task == nullptr) {
            m_mutex.lock();
            task = m_task.load();
            if (task == nullptr) {
                task = new TaskQueue;
                m_task.store(task);
            }
            m_mutex.unlock();
        }
        return task;
    }

    void print() {
        cout << "这是懒汉式，采用原子变量+双重检查锁定" << endl;
    }

private:
    static atomic<TaskQueue*> m_task;
    static mutex m_mutex;
    TaskQueue() = default;
    TaskQueue(const TaskQueue& t) = default;
    TaskQueue& TaskQueue::operator=(const TaskQueue& other) = default;
};
atomic<TaskQueue*> TaskQueue::m_task;
mutex TaskQueue::m_mutex;
#endif

#if 1
// 懒汉式，静态局部对象解决线程安全
class TaskQueue {
public:
    static TaskQueue* getInstance() {
        static TaskQueue task;
        return &task;
    }

    void print() {
        cout << "这是懒汉式，采用静态局部对象" << endl;
    }

private:
    TaskQueue() = default;
    TaskQueue(const TaskQueue& t) = default;
    TaskQueue& TaskQueue::operator=(const TaskQueue& t) = default;
};
#endif

#if 0
// 饿汉式
class TaskQueue {
public:
    static TaskQueue* getInstance() {
        return m_task;
    }

    void print() {
        cout << "这是饿汉式单例模式" << endl;
    }

private:
    static TaskQueue* m_task;
    TaskQueue() = default;
    TaskQueue(const TaskQueue& t) = default;
    TaskQueue& TaskQueue::operator=(const TaskQueue& other) = default;
};
TaskQueue* TaskQueue::m_task = new TaskQueue;
#endif

int main()
{
    TaskQueue* my_task = TaskQueue::getInstance();
    my_task->print();
    system("pause");
    return 0;
}
