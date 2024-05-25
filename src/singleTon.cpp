#include <iostream>
#include <mutex>
#include <atomic>
using namespace std;

// ����һ������ģʽ���������

#if 0
// ����ʽ��ԭ�ӱ���+˫�ؼ������
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
        cout << "��������ʽ������ԭ�ӱ���+˫�ؼ������" << endl;
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
// ����ʽ����̬�ֲ��������̰߳�ȫ
class TaskQueue {
public:
    static TaskQueue* getInstance() {
        static TaskQueue task;
        return &task;
    }

    void print() {
        cout << "��������ʽ�����þ�̬�ֲ�����" << endl;
    }

private:
    TaskQueue() = default;
    TaskQueue(const TaskQueue& t) = default;
    TaskQueue& TaskQueue::operator=(const TaskQueue& t) = default;
};
#endif

#if 0
// ����ʽ
class TaskQueue {
public:
    static TaskQueue* getInstance() {
        return m_task;
    }

    void print() {
        cout << "���Ƕ���ʽ����ģʽ" << endl;
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
