// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len-1; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if ((arr[i] + arr[j]) == value) {
                count += 1;
                //cout << arr[i] << " " << arr[j] << " " << value << endl;
            }
        }
    }
    return count;
}

int countPairs2(int* arr, int len, int value) {
    int count = 0;
    int i = 0;
    int j = len - 1;
    int checki = 0;
    int checkj = 0;
    while (i < j) {
        if (arr[i] + arr[j] > value) {
            --j;
        } else if (arr[i] + arr[j] == value) {
            for (int j1 = j; j1 >= 0; --j1) {
                if (arr[i] + arr[j1] != value) {
                    break;
                }
                checkj += 1;
                count += 1;
            }
            for (int i1 = i+1; i1 < len; ++i1) {
                if (arr[i1] + arr[j] != value) {
                    break;
                }
                checki = +1;
                count += 1;
            }
            i += checki;
            j -= checkj;
            checki = 0;
            checkj = 0;
        } else if (arr[i] + arr[j] < value) {
            ++i;
        }
        //cout << arr[i] << " " << arr[j] << endl;
    }
    return count;
}

int countPairs3(int* arr, int len, int value) {
    int count = 0;
    for (int k = 0; k < len; ++k) {
        int i = k + 1;
        int j = len - 1;
        while (i < j) {
            int mid = (i + j) / 2;
            if (arr[mid] + arr[k] < value) {
                i = mid + 1;
            } else {
                j = mid;
            }
        }
        while (arr[i] + arr[k] == value) {
            count += 1;
            i += 1;
        }
    }
    return count;
}
