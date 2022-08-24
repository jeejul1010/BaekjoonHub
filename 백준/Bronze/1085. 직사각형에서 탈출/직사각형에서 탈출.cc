#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int x, y, w, h;
	cin >> x >> y >> w >> h;

	vector<int> dist;
	dist.push_back(x);
	dist.push_back(y);
	dist.push_back(w - x);
	dist.push_back(h - y);

	cout << *min_element(dist.begin(), dist.end()) << endl;
	
    return 0;
}