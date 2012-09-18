#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <functional>
#include <numeric>

using namespace std;

#define vi vector<int>
#define vvi vector<vector<int> >
#define all(e) e.begin(),e.end()
#define pb push_back

class XorBoardDivTwo {
public:
    int theMax(vector <string> b) {
        int ans = 0;
        int n=b.size();
        int m=b[0].size();
        int ones = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(b[i][j] == '1') ones++;
            }
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                int d = 0;
                //across
                for(int k=0; k<m; k++) {
                    if(k==j) continue;
                    if(b[i][k] == '0')
                        d++;
                    else
                        d--;
                }
                for(int k=0; k<n; k++) {
                    if(k==i) continue;
                    if(b[k][j] == '0')
                        d++;
                    else
                        d--;
                }
                ans = max(ans, ones+d);
                //cout << "(" << i << "," << j << ") => " << (ones+d) << endl;
            }
        }
        return ans;
    }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"101",
 "010",
 "101"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(0, Arg1, theMax(Arg0)); }
	void test_case_1() { string Arr0[] = {"111",
 "111",
 "111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(1, Arg1, theMax(Arg0)); }
	void test_case_2() { string Arr0[] = {"0101001",
 "1101011"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(2, Arg1, theMax(Arg0)); }
	void test_case_3() { string Arr0[] = {"000",
 "001",
 "010",
 "011",
 "100",
 "101",
 "110",
 "111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 15; verify_case(3, Arg1, theMax(Arg0)); }
	void test_case_4() { string Arr0[] = {"000000000000000000000000",
 "011111100111111001111110",
 "010000000100000001000000",
 "010000000100000001000000",
 "010000000100000001000000",
 "011111100111111001111110",
 "000000100000001000000010",
 "000000100000001000000010",
 "000000100000001000000010",
 "011111100111111001111110",
 "000000000000000000000000"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 105; verify_case(4, Arg1, theMax(Arg0)); }

// END CUT HERE
};

// BEGIN CUT HERE
int main(int argc, char** argv) {
    XorBoardDivTwo test;
    test.run_test(-1);
    return 0;
}
// END CUT HERE
