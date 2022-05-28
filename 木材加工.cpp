#include <iostream>
#include <algorithm>
using namespace std;
int a[100010], n, k, ans, ma;
//a[i]用来记录第 i 块木头长度, ma 是最长的木头的长度, ans 最终要求的结果; 
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		ma = max(ma, a[i]);//找到最长的木头长度; 
	}
	sort(a, a + n, cmp);//将木头按长度由长到短排列; 
	int lf, ri, md, sum;
	lf = 0;
	ri = ma;//令 ri 初始值为 ma, 因为所有木头长度都小于等于 ma;  
	//lf 长度左值, ri 长度右值, md 中间长度值;
	// sum 获得的 md 长度木块的数量; 
	while (lf <= ri) {
		sum = 0;
		md = lf + (ri - lf) / 2;
		if (md == 0) {
	//md == 0 即 md 大于 1 不能得到 sum 个长
	//为 md 的木块,使 sum == k, 返回结果 ans == 0; 
			ans = 0;
			break;
		}
		for (int i = 0; i < n; i++) {// 遍历所有木块找到比 md 长度小的木块; 
			if (a[i] >= md) {
				sum += a[i] / md; 
			}
			else {
		//如果长度小于 md, 即结束循环, 因为数组 a 已是下降序列, 之后的数也小于 md; 
				break;
			}
		}
		if (sum >= k) { //此时证明 md 数值小于或等于我们求的最终结果; 
			ans = md;//先令结果 ans == md 以作进一步判断; 
			lf = md + 1;
		}
		else {//证明 md 数值过大求不出结果; 
			ri = md - 1; 
		}
	}
	cout << ans << endl;
	return 0;
}