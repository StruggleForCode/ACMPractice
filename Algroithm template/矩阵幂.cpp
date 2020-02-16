#include <iostream>
#include <algorithm>
using namespace std;

struct matrix{
	int a[100][100];
	int n;
};


matrix matrix_mul(matrix A, matrix B, int p){
	matrix C;
	C.n = A.n;
	for (int i = 0; i < C.n; i++){
		for (int j = 0; j < C.n; j++){
			C.a[i][j] = 0;
			for (int k = 0; k < C.n; k++){
				C.a[i][j] = (C.a[i][j] + A.a[i][k] * B.a[k][j] % p) % p;
			}
		}
	}
	return C;
}

matrix unit(int n){
	matrix res;
	res.n = n;
	for (int i = 0; i < res.n; i++){
		for (int j = 0; j < res.n; j++){
			if(i == j){
				res.a[i][j] = 1;
			}else{
				res.a[i][j] = 0;
			}
		}
	}
	return res;
}

matrix matrix_pow(matrix A, int p, int m){
	matrix res = unit(A.n);
	while(p){
		if(p  & 1) res = matrix_mul(res, A, m);
		A = matrix_mul(A, A, m);
		p >>= 1;
	}
	return res;
}

matrix unit2(int n){
	matrix res;
	res.n = n;
	for (int i = 0; i < res.n; i++){
		for (int j = 0; j < res.n; j++){
			res.a[i][j] = 1;
		}
	}
	return res;
}

matrix matrix_sub(matrix A, matrix B){
	matrix C;
	C.n = A.n;
	for (int i = 0; i < C.n; i++){
		for (int j = 0; j < C.n; j++){
			C.a[i][j] = (A.a[i][j] - B.a[i][j]);
		}
	}
	return C;
}

matrix matrix_div(matrix A, matrix B){
	matrix C;
	C.n = A.n;
	for (int i = 0; i < C.n; i++){
		for (int j = 0; j < C.n; j++){
			C.a[i][j] = (A.a[i][j] / B.a[i][j]);
		}
	}
	return C;
}




int main(){
	matrix A;
	int k, m;
	cin >> A.n >> k >> m;
	
	for (int i = 0; i < A.n; i++){
		for (int j = 0; j < A.n; j++){
			cin >> A.a[i][j];
		}
	} 
	
	matrix bas = unit(A.n);
	cout << "djssk" << endl;
	matrix shang = matrix_sub(matrix_pow(A, k + 1, m), A);
	cout << "dsd" << endl; 
	matrix xia = matrix_sub(A, bas);
	cout << "jsdj" << endl;
	
	for (int i = 0; i < shang.n; i++){
		for (int j = 0; j < shang.n; j++){
			if(j != shang.n - 1){
				cout << shang.a[i][j] << " ";
			}else cout << shang.a[i][j] << endl; 
		}
	}
	cout << "jkjk" << endl;
	for (int i = 0; i < xia.n; i++){
		for (int j = 0; j < xia.n; j++){
			if(j != xia.n - 1){
				cout << xia.a[i][j] << " ";
			}else cout << xia.a[i][j] << endl; 
		}
	}
	cout << "dsj" << endl;
	
	matrix C = matrix_div(shang, xia);

	 
	for (int i = 0; i < C.n; i++){
		for (int j = 0; j < C.n; j++){
			if(j != C.n - 1){
				cout << C.a[i][j] << " ";
			}else cout << C.a[i][j] << endl; 
		}
	}
	
	 
	return 0;
} 
