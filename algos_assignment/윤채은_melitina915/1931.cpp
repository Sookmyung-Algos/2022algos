#include <iostream>
#include <algorithm>
using namespace std;

typedef struct st {
	unsigned int start;
	unsigned int end;
} info;
bool compare(info& start, info& end) {
	if (start.end < end.end) {
		return true;
	}
	else if (start.end == end.end) {
		return (start.start < end.start);
	}
	else {
		return false;
	}

}
int main() {
	int N;
	cin >> N;

	info array[100000];

	for (int i = 0; i < N; i++) {
		cin >> array[i].start >> array[i].end;
	}
	sort(array, array + N, compare);

	int count = 1;
	unsigned int temp = array[0].end;

	for (int i = 1; i < N; i++) {

		if (array[i].start < temp) {
			continue;
		}
		else {
			temp = array[i].end;
			count++;
		}

	}
	cout << count << endl;

	return 0;
}
