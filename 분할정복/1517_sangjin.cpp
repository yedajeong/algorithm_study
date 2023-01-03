#include <iostream>
using namespace std;


long long bubble[5000001];
long long tempArray[5000001];
long long cnt = 0;

void merge(long long leftFirst, long long leftLast, long long rightFirst, long long rightLast) {
    long long index = leftFirst;
    long long saveFirst = leftFirst;
    while ((leftFirst <= leftLast) && (rightFirst <= rightLast))
    {
       
        if (bubble[leftFirst] <= bubble[rightFirst])
        {
            tempArray[index] = bubble[leftFirst];
            leftFirst++;
        }
        else
        {
            tempArray[index] = bubble[rightFirst];
            rightFirst++;
            cnt += (leftLast - leftFirst + 1); // left에 남아있는 애들이 다 swap되므로 left애들의 수를 더해야함.
        }
        index++;
    }


    while (leftFirst <= leftLast)
        // Copy remaining items from left half.
    {
        tempArray[index] = bubble[leftFirst];
        leftFirst++;
        index++;
    }

    while (rightFirst <= rightLast)
        // Copy remaining items from right half.
    {
        tempArray[index] = bubble[rightFirst];
        rightFirst++;
        index++;
    }

    for (index = saveFirst; index <= rightLast; index++)
        bubble[index] = tempArray[index];
}

void mergesort(long long first, long long last) {
	if (first < last)
	{
        long long middle = (first + last) / 2;
		mergesort(first, middle);
		mergesort(middle + 1, last);
		merge(first, middle, middle + 1, last);
	}
}

int main() {
    long long N;
	cin >> N;

	for (int i = 0; i < N; i++) {
        long long a;
		cin >> a;
		bubble[i] = a;
	}

    mergesort(0, N - 1);

	cout << cnt << endl;
}
