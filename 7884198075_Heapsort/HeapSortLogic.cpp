void Formation(string str) {
  x++;
  Heap[x] = str;
  int child = x, index = x/2;
  string temp;

  while(index >= 0) {
    if(Heap[index] > Heap[child]) {
      temp = Heap[index];
      Heap[index] = Heap[child];
      Heap[child] = temp;
      child = index;
      index /=2;
    }
    else {
      break;
    }
  }
}

// Defining Heap sort
void HeapSort() {
  int left1, right1;

  while(x >= 0) {
    string str;
    str = Heap[0];
    cout<<str<<endl;
    Heap[0] = Heap[x];
    x-=1;

    string temp;
    int index=0, length=x;
    left1 = 1;
    right1 = left1+1;

    while(left1 <= length) {
      if(Heap[index] <= Heap[left1] && Heap[index] <= Heap[right1]) {
        break;
      }
      else {
        if(Heap[left1] < Heap[right1]) {
          temp = Heap[index];
          Heap[index] = Heap[left1];
          Heap[left1] = temp;
          index = left1;
        }
        else {
          temp = Heap[index];
          Heap[index] = Heap[right1];
          Heap[right1] = temp;
          index = right1;
        }
      }
      left1 = 2*left1;
      right1 = left1 + 1;
    }
  }
}

void justSort(string str[], int n) {
  for(int i=0;i<n;i++) {
    Formation(str[i]);
  }
  HeapSort();
}
