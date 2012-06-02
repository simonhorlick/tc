#include <iostream>
#include <vector>

using namespace std;

#define vi vector<int>
#define vvi vector<vector<int> >
#define range(e) e.begin(),e.end()

int findmin(int N, int pi) {
    for(int i=0; i<N; i++) {
        if(pi == (int)(((double)i / (double)N)*100.0+0.5)) return i;
    }
    return 0x7fffff;
}


int findmax(int N, int pi) {
    for(int i=N; i>=0; i--) {
        if(pi == (int)(((double)i / (double)N)*100.0+0.5)) return i;
    }
    return -0x7fffff;
}

class ElectionFraudDiv1 {
public:
    int MinimumVoters(vi p) {
        // loop all total voters
        for(int N=1; N<500; ++N) {
            int lb=0, ub=0;
            for(int i=0; i<p.size(); i++) {
                lb += findmin(N, p[i]);
                ub += findmax(N, p[i]);
            }
            if(lb <= N && ub >= N) return N;
        }
        return -1;
    }

};

int main(int argc, char** argv) {
    vi e;
    int i;
    while(cin >> i) e.push_back(i);
    ElectionFraudDiv1 ef;
    cout << ef.MinimumVoters(e);
}

