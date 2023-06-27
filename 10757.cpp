#include <iostream>

using namespace std;
int main() 
{
  string a, b, res;
  cin >> a >> b;
  int carry = 0;
  int asize = a.size();
  int bsize = b.size();
  while (asize > 0 || bsize > 0) 
  {
    int acarry = 0;
    if (asize > 0)
      acarry = a[--asize] - '0';
    int bcarry = 0;
    if (bsize > 0)
      bcarry = b[--bsize] - '0';
    int cur = acarry + bcarry + carry;
    carry = cur / 10;
    cur %= 10;
    char ccarry = cur + '0';
    res += ccarry;
  }
  if (carry > 0)
    res += carry + '0';
  for (int i = res.length() - 1; i >= 0; i--)
    cout << res[i];
}
