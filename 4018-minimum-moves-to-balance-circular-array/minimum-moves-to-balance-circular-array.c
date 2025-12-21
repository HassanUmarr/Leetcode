#include <stdlib.h>

long long minMoves(int* balance, int n) {
    long long sum = 0;     // total of all balances
    int neg = -1;          // index of the (only) negative person, or -1 if none

    // 1) find total sum and the negative index
    for (int i = 0; i < n; i++) {
        sum += (long long)balance[i];
        if (balance[i] < 0) neg = i;
    }

    // if nobody is negative, already non-negative
    if (neg == -1) return 0;

    // if total sum is negative, impossible
    if (sum < 0) return -1;

    long long need = -(long long)balance[neg];  // how many units we must give to neg

    int maxDist = n / 2;                        // farthest minimum distance on a circle
    long long* supply = (long long*)calloc(maxDist + 1, sizeof(long long));
    if (!supply) return -1;                     // safety (allocation failed)

    // 2) group all positive supplies by their minimum distance to neg
    for (int i = 0; i < n; i++) {
        if (i == neg) continue;

        int cw  = (neg - i + n) % n;            // clockwise distance i -> neg
        int ccw = (i - neg + n) % n;            // counter-clockwise distance i -> neg
        int d = (cw < ccw) ? cw : ccw;          // minimum distance

        supply[d] += (long long)balance[i];     // add i's available units to that distance bucket
    }

    // 3) take units starting from the cheapest distance (1, then 2, then 3...)
    long long moves = 0;
    for (int d = 1; d <= maxDist && need > 0; d++) {
        long long take = (supply[d] < need) ? supply[d] : need;
        moves += take * (long long)d;
        need -= take;
    }

    free(supply);

    // if we couldn't cover the deficit, impossible (shouldn't happen if sum>=0)
    if (need > 0) return -1;

    return moves;
}
