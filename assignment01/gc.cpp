#include <Windows.h>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
using namespace std;

// Skeleton for GC with a Sigleton design pattern
class GarbageCollector {
 private:
  // 새로 추가되는 객체와 포인터 변수의 주소를 벡터로 관리
  vector<void*> instance;
  vector<void**> pointer;

  const int period = 0;
  thread th;
  mutex mtx;  // 동기화를 위해
  bool stopThread = false;  // 스레드 종료 플래그

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
  // period만큼의 주기로 가비지 컬렉터 실행
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

  // 새로운 포인터 추가
  template <typename T>
  void addPointer(T** address) {
    lock_guard<mutex> lock(mtx);
    pointer.push_back(reinterpret_cast<void**>(address));
  }

  // 새로운 객체 추가
  void addInstance(void* address) {
    lock_guard<mutex> lock(mtx);
    if (address) {
      instance.push_back(address);
    }
  }

  // 유효하지 않은 포인터 제거
  void removePointer() {
    for (auto pptr = pointer.begin(); pptr != pointer.end();) {
      if (*pptr == nullptr) {
        pptr = pointer.erase(pptr);
      } else {
        ++pptr;
      }
    }
  }

  // 객체 삭제
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
  
  // 가비지 컬렉터 실행
  void collectGarbage() {
    cout << "가비지 컬렉터 실행" << endl;
    lock_guard<mutex> lock(mtx);
    vector<void*> del_addr;

    removePointer();  // null을 참조하는 포인터 제거

    for (auto inst = instance.begin(); inst != instance.end();) {
      bool isActive = false;  // 활성 객체 여부 확인
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

  // 가비지 컬렉터 동작 확인 (delete된 메모리 위치 출력)
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
    GC.removeInstance(ptr);  // instacne 벡터에서 객체 제거
    delete ptr;  // 메모리 해제
  }
  T* get_ptr() { return ptr; }
  T& operator*() { return *ptr; }
  T* operator->() { return ptr; }

  smartptr& operator=(T* p) {
    if (ptr) {
      GC.removeInstance(ptr);  // 기존 객체 제거
      delete ptr;              // 기존 메모리 해제
    }
    ptr = p;
    if (ptr) {
      GC.addInstance(ptr);  // 새로운 객체 등록
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

  // 의도적 호출로 인한 가비지 컬렉터 동작 확인 코드
  /*cout << "의도적 실행" << endl;
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
