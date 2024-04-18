#include <iostream>
#include <vector>

using namespace std;

int countDown(int n) {
    if (n <= 0) {
        return 0;
    } else {
        n = n + countDown(n - 1);
        return n;
    }
}

void countCharacter(string str) {
    if (str.length() == 0) {
        return;
    } else {

        countCharacter(str.substr(1));
        cout << str[0] << endl;
    }
}

string sumString(string str) {
    if (str.length() == 0) {
        return "";
    } else {

        return sumString(str.substr(1)) + str[0];

    }
}

vector<string> accumString(vector<string> str, int size) {
    if (str.empty()) {
        return {};
    } else {
        vector<string> v;
        if (str[0].size() == size) {
            v.push_back(str[0]);
        }

        str.erase(str.begin());
        vector<string> rest = accumString(str, size);
        v.insert(v.end(), rest.begin(), rest.end());
        return v;
    }
}

int search(int arr[], int low, int high, int key) {
    if (low > high) {
        return -1;
    }

    if (arr[low] == key) {
        return low;
    }

    if (arr[high] == key) {
        return high;
    }

    return search(arr, low + 1, high - 1, key);
}

int binary_search(int arr[], int low, int high, int key) {
    if (low > high) {
        return -1;
    }

    int mid = (low + high) / 2;

    if (arr[mid] == key) {
        return mid;
    }

    if (arr[mid] > key) {
        return binary_search(arr, low, mid - 1, key);
    } else {
        return binary_search(arr, mid + 1, high, key);
    }
}

void print(vector<string> v) {
    if (v.empty()) {
        return;
    } else {
        cout << v[0] << endl;
        v.erase(v.begin());
        print(v);

    }
}

int main() {
    // create a sorted array with 10 elements
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int key = 5;
    cout << "Linear search: " << search(arr, 0, 9, key) << endl;

    vector<string> v = {"am", "bcc", "cd", "d", "echo", "f", "g", "h", "i", "j"};

    vector<string> v1 = accumString(v, 2);
    print(v1);
    return 0;
}
//int main() {
//    // cout << countDown(5) << endl;
//    // countCharacter("Hello");
//    string s = sumString("Hello");
//    cout << s << endl;
//    return 0;
//}
