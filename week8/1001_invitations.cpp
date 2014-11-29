// Copyright (c) 2014 Junjie_Huang@SYSU(SNO:13331087). All Rights Reserved.
// week8/1001_invitations.cpp: DataStructure2014@PanYan
// http://soj.me/show_problem.php?pid=1001&cid=1583
#include <cstdio>

int main() {
  int test_cases = 0;
  long long int friends_num, families_num,
    max, i, temp;
  scanf("%lld", &test_cases);

  while (test_cases--) {

    scanf("%lld %lld", &friends_num, &families_num);

    for (i = 0, max = 0; i < friends_num; i++) {
      scanf("%lld", &temp);
      if (max < temp) max = temp;
    }
    for (i = 0; i < families_num; i++) {
      scanf("%lld", &temp);
      if (temp == max) printf("%lld\n", i*50);
    }
  }
  return 0;
}
