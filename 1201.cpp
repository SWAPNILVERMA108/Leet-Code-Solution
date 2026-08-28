// problem no : 1201
class Solution {
public:
    using ll = long long;
    ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }

    int nthUglyNumber(int n, int a, int b, int c) {
        ll ab = lcm(a, b);
        ll bc = lcm(b, c);
        ll ac = lcm(a, c);
        ll abc = lcm(ab, c);

        ll left = 1;
        ll right = 2e9;

        while (left < right) {
            ll mid = left + (right - left) / 2;

            ll cnt = mid / a + mid / b + mid / c - mid / ab - mid / bc -
                     mid / ac + mid / abc;

            if (cnt >= n) {
                right = mid;
            } else {


                left = mid + 1;
            }

        }

        return left;
    }
};