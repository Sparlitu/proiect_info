#include <iostream>
#include <queue>
using namespace std;

const int dx[] = { 0,-1,0,1 };
const int dy[] = { -1,0,1,0 };
//declarare matrice cu max linii si max coloane
//declarare coordonate istart, jstart, istop, jstop de tip int

int Verify(int i, int j) {
	return i >= 1 && i <= n && j >= 1 && j <= m;
}

void Lee(int istart, int jstart) {
	queue<pair<int, int>> Q;
	Q.push(make_pair(istart, jstart));
	while (!Q.empty()) {
		int x = Q.front().first;
		int y = Q.front().second;
		for (int d = 0; d < 4; ++d) {
			int inew = dx[d] + x;
			int jnew = dy[d] + y;
			if (Verify(inew, jnew) != 0 && a[inew][jnew] == 0) {
				a[inew][jnew] = a[x][y] + 1;
				Q.push(make_pair(inew, jnew));
			}
		}
		Q.pop();
	}
}

void Route(int i, int j, int length) {
	if (a[i][j] == 1) {
		cout << length << "\n";
		cout << i << " " << j;
	}
	else {
		for (int d = 0; d < 4; ++d) {
			int inew = dx[d] + i;
			int jnew = dy[d] + j;
			if (Verify(inew, jnew) != 0 && a[inew][jnew] == a[i][j] - 1)
				Route(inew, jnew, length + 1);
		}
		cout << i << " " << j << "\n";
	}
}

int main() {
	//2 optiuni: citire de la tastatura sau din fisier -1 reprezinta obstacolele iar 0 cale libera
	//citire matrice cu n linii si m coloane
	//citire coordonate de start si stop
	Lee(istart, jstart);
	Route(istop, jstop, 1);
	//afisare matrice cu n linii si m coloane
	return 0;
}
