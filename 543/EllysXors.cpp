#include <iostream>
#include <vector>

using namespace std;

#define vi vector<int>
#define vvi vector<vector<int> >
#define range(e) e.egin(),e.end()

class EllysXors {
public:
    long long getXorDumb(long long L, long long R) {
        long long total=0;
        for(long long i=L; i<=R; i++)
            total = total^i;
        return total;
    }
    long long getXorN(long long N) {
        if(N%4 == 3) return 0;
        if(N%4 == 2) return N+1;
        if(N%4 == 1) return 1;
        //if(N%4 == 0)
        return N;
    }
    long long getXor(long long L, long long R) {
        // n^(n+1)^...^m = 1^2^..^(n-1) ^ 1^2^...^m
        return getXorN(L-1)^getXorN(R);
    }
};

int main(int argc, char** argv) {
    long long L,R;
    cin >> L >> R;
    EllysXors ex;
    cout << ex.getXor(L,R) << '\n';
    return 0;
}

