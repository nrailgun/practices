// O(n logn) not good enough.
class Comparator {
public:
    int *counts;
    Comparator(int *c)
    : counts(c) {
    }

    // 特别注意这两个条件不能反过来写！如果先 counts[i] > counts[j] return true，
    // 那么 counts[i] > counts[j] 且 i > j，那么 (i, j) 和 (j, i) 都 return true，算法爆炸。
    bool operator()(char i, char j) const {
        if (counts[i] == counts[j])
            return i < j;
        return counts[i] > counts[j];
    }
};

class Solution {
public:
    string frequencySort(string s) {
        int counts[256] = { 0 };
        for (auto i : s) {
            counts[i]++;
        }
       
        Comparator comp(counts);
        sort(s.begin(), s.end(), comp);
        return s;
    }
};

// 表面上 sort 复杂度是 O(n log(n))，其实是 O(1)。
class Comparator {
public:
    int *counts;
    Comparator(int *c)
    : counts(c) {
    }

    bool operator()(int i, int j) const {
        if (counts[i] == counts[j])
            return i < j;
        return counts[i] > counts[j];
    }
};

class Solution {
public:
    string frequencySort(string s) {
        int counts[256] = { 0 };
        for (auto i : s) {
            counts[i]++;
        }
        
        int idxs[256];
        for (int i = 0; i < 256; i++)
            idxs[i] = i;
        Comparator comp(counts);
        sort(idxs, idxs + 256, comp);
        
        int k = 0;
        for (int i = 0; i < 256; i++) {
            for (int j = 0; j < counts[idxs[i]]; j++)
                s[k++] = idxs[i];
        }
        return s;
    }
};
