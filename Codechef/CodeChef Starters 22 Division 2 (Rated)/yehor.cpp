#include <bits/stdc++.h>
using namespace std;

typedef pair<string, string> pss;


#define MAX_NODE 400
bool checkDynamicDependency(int libCnt, map<string, int> mp, queue<pss> q) {
	int cntTable[MAX_NODE][MAX_NODE] = { 0 };
	while(!q.empty()) {
		pss edge = q.front();
		q.pop();
		int firInd = mp[edge.first];
		int secInd = mp[edge.second];
		for (int k = 0; k < libCnt; k++) {
			for (int l = 0; l < libCnt; l++) {
				if( cntTable[k][firInd] == 0 && k != firInd ) {
					continue;
				}
				if( cntTable[secInd][l] == 0 && l != secInd) {
					continue;
				}
				cntTable[k][l] += 1;
				if (cntTable[k][l] == 2) {
						return true;
				}
			}
		}
	}
	return false;
}

int main() {
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	int testCnt;
	cin >> testCnt;
	for (int i = 0; i < testCnt; i++) {
		int libCnt;
		cin >> libCnt;
		map<string, int> mp;
		queue<pss> q;

		for (int j = 0; j < libCnt; j++) {
			int dependencyCnt;
			string libName;
			cin >> dependencyCnt >> libName;
			for (int k = 0; k < dependencyCnt; k++) {
				string dependName;
				cin >> dependName;
				pss edge;
				edge.first = libName;
				edge.second = dependName;
				q.push(edge);
			}
			mp[libName] = j;
		}
		if (checkDynamicDependency(libCnt, mp, q)  == true)
			cout << "yes" << endl;
		else
			cout << "no" << endl;

	}
	return 0;
}
