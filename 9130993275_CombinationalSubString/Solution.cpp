#include<iostream>
using namespace std;

void printComb(char set[], int k,int n);
void printCombEach(char set[], string prefix, int n, int k);
int isSubstring(string s1, string s2);
int stat = 0;
string str1 = "BC";

void f(int n) {
    char one ='A';
    char two[] = {'A', 'B'};
    char three[] = {'A', 'B', 'C'};
    char ten[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    if(n == 1) {
        cout<<endl<<"Combinations for f(1): ";
        cout<<one;
    }
    else if(n == 2) {
        cout<<endl<<"Combinations for f(2): ";
        cout<<two[0]<<two[1]<<" "<<two[1]<<two[0];
    }
    else if(n == 3) {
        cout<<endl<<"Combinations for f(3): ";
        printComb(three, 3, 3);
    }
    else if(n == 10) {
        cout<<endl<<"Combinations for f(10): ";
        printComb(ten, 10, 10);
    }
}

void printComb(char set[], int k,int n) {
    printCombEach(set, "", n, k);
}

void printCombEach(char set[], string prefix, int n, int k) {
    if(k==0) {
        stat = isSubstring(str1, prefix); 
        if(stat == -1) {
            cout<<(prefix)<<" ";
        }
        return;
    }
    for(int i=0;i<n;i++) {
        string newPrefix;
        newPrefix = prefix + set[i];
        printCombEach(set, newPrefix, n, k - 1); 
	}
}

int isSubstring(string s1, string s2) {
    int M = s1.length(); 
    int N = s2.length();
    
    for(int i=0;i<=N-M;i++) {
        int j;
        for(j=0;j<M;j++) {
            if (s2[i + j] != s1[j]) {
                break;
            }
        }
        if (j == M) 
            return i; 
    }
    return -1; 
}

int main() {
    f(1);
    f(2);
    f(3);
    f(10);
} 