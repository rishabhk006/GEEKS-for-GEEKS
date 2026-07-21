#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    int countWays(string &s) {
        int n = s.length();

        // T[i][j] stores ways to make s[i...j] True
        // F[i][j] stores ways to make s[i...j] False
        vector<vector<int>> T(n, vector<int>(n, 0));
        vector<vector<int>> F(n, vector<int>(n, 0));

        // Base Case: Single character sub-expressions
        for (int i = 0; i < n; i += 2) {
            if (s[i] == 'T') {
                T[i][i] = 1;
                F[i][i] = 0;
            } else if (s[i] == 'F') {
                T[i][i] = 0;
                F[i][i] = 1;
            }
        }

        // L is the length of the sub-expression (considering only symbols and operators)
        for (int length = 3; length <= n; length += 2) {
            for (int i = 0; i <= n - length; i += 2) {
                int j = i + length - 1;

                T[i][j] = 0;
                F[i][j] = 0;

                // Split at every operator index k between i and j
                for (int k = i + 1; k < j; k += 2) {
                    int leftT = T[i][k - 1];
                    int leftF = F[i][k - 1];
                    int rightT = T[k + 1][j];
                    int rightF = F[k + 1][j];

                    if (s[k] == '&') {
                        T[i][j] += leftT * rightT;
                        F[i][j] += (leftT * rightF) + (leftF * rightT) + (leftF * rightF);
                    } else if (s[k] == '|') {
                        T[i][j] += (leftT * rightT) + (leftT * rightF) + (leftF * rightT);
                        F[i][j] += leftF * rightF;
                    } else if (s[k] == '^') {
                        T[i][j] += (leftT * rightF) + (leftF * rightT);
                        F[i][j] += (leftT * rightT) + (leftF * rightF);
                    }
                }
            }
        }

        return T[0][n - 1];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna