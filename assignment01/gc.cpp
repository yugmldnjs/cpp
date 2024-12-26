#include <Windows.h>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
using namespace std;

// Skeleton for GC with a Sigleton design pattern
class GarbageCollector {
 private:
  // ���� �߰��Ǵ� ��ü�� ������ ������ �ּҸ� ���ͷ� ����
  vector<void*> instance;
  vector<void**> pointer;

  const int period = 0;
  thread th;
  mutex mtx;  // ����ȭ�� ����
  bool stopThread = false;  // ������ ���� �÷���

  // Disable constructors
  // Default constructor. You can modifiy it if you want
  GarbageCollector() : period(3000) {
    th = thread(&GarbageCollector::timer, this, period);
  }

  GarbageCollector(const GarbageCollector&) = delete;
  GarbageCollector& operator=(const GarbageCollector&) = delete;
  GarbageCollector(GarbageCollector&&) = delete;
  GarbageCollector& operator=(GarbageCollector&&) = delete;

  ~GarbageCollector() {
    stopThread = true;
    if (th.joinable()) {
      th.join();
    }
  }

  // Thread function
  // period��ŭ�� �ֱ�� ������ �÷��� ����
  void timer(int period) {
    while (!stopThread) {
      this_thread::sleep_for(chrono::milliseconds(period));
      collectGarbage();
    }
  }

  void join() { th.join(); }

 public:
  static GarbageCollector& GetInstance() {
    static GarbageCollector instance;
    return instance;
  }

  // ���ο� ������ �߰�
  template <typename T>
  void addPointer(T** address) {
    lock_guard<mutex> lock(mtx);
    pointer.push_back(reinterpret_cast<void**>(address));
  }

  // ���ο� ��ü �߰�
  void addInstance(void* address) {
    lock_guard<mutex> lock(mtx);
    if (address) {
      instance.push_back(address);
    }
  }

  // ��ȿ���� ���� ������ ����
  void removePointer() {
    for (auto pptr = pointer.begin(); pptr != pointer.end();) {
      if (*pptr == nullptr) {
        pptr = pointer.erase(pptr);
      } else {
        ++pptr;
      }
    }
  }

  // ��ü ����
  void removeInstance(void* p) {
    lock_guard<mutex> lock(mtx);
    for (auto inst = instance.begin(); inst != instance.end();) {
      if (*inst == p) {
        instance.erase(inst);
        break;
      } else {
        ++inst;
      }
    }
  }
  
  // ������ �÷��� ����
  void collectGarbage() {
    cout << "������ �÷��� ����" << endl;
    lock_guard<mutex> lock(mtx);
    vector<void*> del_addr;

    removePointer();  // null�� �����ϴ� ������ ����

    for (auto inst = instance.begin(); inst != instance.end();) {
      bool isActive = false;  // Ȱ�� ��ü ���� Ȯ��
      for (auto pptr : pointer) {
        if (*pptr == *inst) {
          isActive = true;
          break;
        }
      }
      if (!isActive) {
        del_addr.push_back(*inst);
        free(*inst);
        inst = instance.erase(inst);

      } else {
        ++inst;
      }
    }
    print_log(del_addr);
  }

  // ������ �÷��� ���� Ȯ�� (delete�� �޸� ��ġ ���)
  void print_log(vector<void*> addr) {
    cout << "Garbage collected." << endl;
    cout << "[ ";
    for (auto i : addr) {
      cout << i << " ";
    }
    cout << "]" << endl;
    cout << "Active objects: " << instance.size() << endl << endl;
  }
};

// Global variable 'GC' for the garbage collector class.
GarbageCollector& GC = GarbageCollector::GetInstance();

// operator new overloading
void* operator new(size_t size) {
  void* ptr = malloc(size);
  return ptr;
}

struct member {
  int x;
  int y;
};

template <typename T>
class smartptr {
 private:
  T* ptr;

 public:
  smartptr(T* p = 0) : ptr(p) { GC.addInstance(ptr); }

  ~smartptr() {
    GC.removeInstance(ptr);  // instacne ���Ϳ��� ��ü ����
    delete ptr;  // �޸� ����
  }
  T* get_ptr() { return ptr; }
  T& operator*() { return *ptr; }
  T* operator->() { return ptr; }

  smartptr& operator=(T* p) {
    if (ptr) {
      GC.removeInstance(ptr);  // ���� ��ü ����
      delete ptr;              // ���� �޸� ����
    }
    ptr = p;
    if (ptr) {
      GC.addInstance(ptr);  // ���ο� ��ü ���
    }
    return *this;
  }
};

int main() {
  // For comman pointers
  int* ptr;
  ptr = new int;
  GC.addInstance(ptr);
  GC.addPointer(&ptr);
  ptr = new int;
  GC.addInstance(ptr);
  ptr = new int;
  GC.addInstance(ptr);
  ptr = new int;
  GC.addInstance(ptr);
  ptr = new int;
  GC.addInstance(ptr);
  ptr = new int;
  GC.addInstance(ptr);
  ptr = new int;
  GC.addInstance(ptr);

  // For class/structure pointers
  member* qtr;
  qtr = new member;
  GC.addInstance(qtr);
  GC.addPointer(&qtr);
  qtr = new member;
  GC.addInstance(qtr);
  qtr = new member;
  GC.addInstance(qtr);
  qtr = new member;
  GC.addInstance(qtr);
  qtr = new member;
  GC.addInstance(qtr);
  qtr = new member;
  GC.addInstance(qtr);
  qtr = new member;
  GC.addInstance(qtr);

  // �ǵ��� ȣ��� ���� ������ �÷��� ���� Ȯ�� �ڵ�
  /*cout << "�ǵ��� ����" << endl;
  GC.collectGarbage();*/

  // For SmartPjointers
  smartptr<member> rtr;
  GC.addPointer(reinterpret_cast<void**>(&rtr));
  rtr = new member;
  rtr = new member;
  rtr = new member;
  rtr = new member;
  rtr = new member;
  rtr = new member;

  while (1) {
    ptr = new int;
    GC.addInstance(ptr);
    qtr = new member;
    GC.addInstance(qtr);
    rtr = new member;
    Sleep(1000);
  }
}
