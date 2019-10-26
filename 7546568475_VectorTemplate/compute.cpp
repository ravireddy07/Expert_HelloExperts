#include<iostream>
#include<vector>
using namespace std;

template <class Temp>
class NumberClass {

  Temp(T a) {

  }

  T Display() {

  }

};


int main() {
  Temp<int> Temp()
  NumberClass<int>myNum({99,34,12,44,77,2,37,4,54,68, 44, 102, 5, 42});
  cout<<"Print the elements in the vector"<<endl;
  myNum.printNumber();
}

/*
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

template <typename T>
class Temp {
    public:
    T n;
    Temp(vector<T> Vec1) {
        Vec1.push_back(99);
        Vec1.push_back(34);
        Vec1.push_back(12);
        Vec1.push_back(44);
        Vec1.push_back(77);
        Vec1.push_back(2);
        Vec1.push_back(37);
        Vec1.push_back(4);
        Vec1.push_back(54);
        Vec1.push_back(68);
        Vec1.push_back(44);
        Vec1.push_back(102);
        Vec1.push_back(5);
        Vec1.push_back(42);
        n = sizeof(Vec1);
        }
        void Display(vector<int>Vec1) {
        for (auto i = 0; i < n; i++) {
            cout<<Vec1[i]<<" ";
        }
        return;
        }
};
  //{99,34,12,44,77,2,37,4,54,68, 44, 102, 5, 42}

int main() {
    vector<int> Vec1;
    Temp<int> obj1(Vec1);
    obj1.Display(Vec1);
    return 0;
}
*/
