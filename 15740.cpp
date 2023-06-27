#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string sadd(string a, string b) {
  string res(max(a.size(), b.size()), '0');
  bool carry = false;
  for (int i = 0; i < res.size(); i++) {
    int tmp = carry;
    carry = false;
    if (i < a.size())
      tmp += a[a.size() - i - 1] - '0';
    if (i < b.size())
      tmp += b[b.size() - i - 1] - '0';
    if (tmp >= 10) {
      carry = true;
      tmp -= 10;
    }
    res[res.size() - i - 1] = tmp + '0';
  }
  if (carry)
    res.insert(res.begin(), '1');
  return res;
}

bool abvalcheck(string a, string b) {
  if (a.size() != b.size())
    return a.size() > b.size();
  for (int i = 0; i < a.size(); i++) {
    if (a[i] == b[i])
      continue;
    return a[i] > b[i];
  }
  return true;
}

string ssub(string a, string b) {
  if (abvalcheck(a, b) == false)
    swap(a, b);
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  string res = a;
  int carry = 0;
  for (int i = 0; i < res.size(); i++) {
    int tmpc = carry;
    carry = 0;
    int tmp = (a[i] - '0') - tmpc;
    if (tmp < 0) {
      carry = 1;
      tmp += 10;
    }
    if (i < b.size()) {
      tmp -= (b[i] - '0');
      if (tmp < 0) {
        carry = 1;
        tmp += 10;
      }
    }
    res[i] = tmp + '0';
  }
  if (carry) {
    int ld = res[res.size() - 1];
    ld--;
    res[res.size() - 1] = ld + '0';
  }
  reverse(res.begin(), res.end());
  int nzero = res.size();
  for (int i = 0; i < res.size(); i++) {
    if (res[i] != '0') {
      nzero = i;
      break;
    }
  }
  if (nzero == res.size())
    return "0";
  return res.substr(nzero);
}

int main() {
  string sa, sb;
  cin >> sa >> sb;
  bool posa = (sa[0] == '-') ? false : true;
  bool posb = (sb[0] == '-') ? false : true;
  if (posa && posb)
    cout << sadd(sa, sb) << '\n';
  else if (posa == false && posb == false)
    cout << '-' << sadd(sa.substr(1), sb.substr(1)) << '\n';
  else if (posa == true && posb == false) {
    string stmp = ssub(sa, sb.substr(1));
    if (abvalcheck(sa, sb.substr(1)) || stmp == "0")
      cout << stmp << '\n';
    else
      cout << '-' << stmp << '\n';
  } else if (posa == false && posb == true) {
    string stmp = ssub(sa.substr(1), sb);
    if (abvalcheck(sa.substr(1), sb) && stmp != "0")
      cout << '-' << stmp << '\n';
    else
      cout << stmp << '\n';
  }
}
