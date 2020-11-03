#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdio>
#include <ctime>
#include <iomanip>

using namespace std;

vector< vector<int> > mat1;
vector< vector<int> > mat2;
vector< vector<int> > mat3;


int curr_i,curr_j = 0;

int _m, _n, _p = 0;

pthread_mutex_t lock;

pthread_t *threads;

int *threadstatus;

void* compute(int id){
	while(true){
		int loc_i, loc_j;

		pthread_mutex_lock(&lock); 
		loc_i = curr_i;
		loc_j = curr_j;
		if(curr_i < _m){
			curr_j++;
			if(curr_j >= _p){
				curr_i++;
				curr_j = 0;
			}
		}
		pthread_mutex_unlock(&lock);
		if(loc_i < _m){
			mat3[loc_i][loc_j] = 0;
			for(int i = 0;i < _n;i++){
				mat3[loc_i][loc_j] += mat1[loc_i][i] * mat2[i][loc_j];
			}
		}
		if(threadstatus[id-1] == 0){
			pthread_exit(0);
		}
	}
}


int main(){
	int m, n, p, num;
	num = 0;

	while(true){
		int no, i, j, entry;
		m = n = p = i = j = 0;

		string in1, in2;

		cout << "\nEnter M, N, P value to multiply matrix A [MxN] and matrix B [NxP]" << endl;
		cout << "M: ";
		cin >> m;
        	cout << "N: ";
		cin >> n;
		cout << "P: ";
		cin >> p;
		cout << "Number of threads to create: ";
		cin >> no;

		cout<< "\nName of input file for Matrix A: ";
		cin >> in1;

	
		mat1.resize(m);
		mat2.resize(n);
		mat3.resize(m);

		for(int i = 0;i < m; i++){
			mat1[i].resize(n);
			mat3[i].resize(p);
		}

		for(int i = 0;i < n;i++){
			mat2[i].resize(p);
		}

   
		ifstream file;
		file.open(in1.c_str());

		i = 0;
		j = 0;

	
		while (1){
			file >> entry;
			mat1[i][j] = entry;
			j++;
			if(j >= n){
				i++;
				j = 0;
			}
			if(i >= m)
				break;
		}

		cout << "\nMatrix A of order " << m << " x" << n << " is : \n";

		for(i = 0; i < m; i++){
			for(j = 0; j < n; j++){
				cout << setw(5) << mat1[i][j] << " ";
			}
			cout << endl;
		}

		file.close();

		cout << "\nName of input file for Matrix B: ";
		cin >> in2;

		file.open(in2.c_str());

        i = 0;
		j = 0;
		
		while (1){
			file >> entry;
			mat2[i][j] = entry;
			j++;
			if(j >= p){
				i++;
				j = 0;
			}
			if(i >= n){
				break;
			}
		}

		cout << "\nMatrix B of order " << n << " x" << p << " is : \n";
		for(i = 0; i < n; i++){
			for(j = 0; j < p; j++){
				cout << setw(5) << mat2[i][j] << " ";
			}
			cout << endl;
		}
		file.close();

		cout << endl;

	\
		pthread_mutex_lock(&lock);
		if(num > no){
			for(;num > no; num--){
           \
				threadstatus[num-1] = 0;
				cout<<"Thread "<<num<<" terminated\n";
			}
			threads = (pthread_t *) realloc(threads, sizeof(pthread_t) * num);
			cout << "\nThere are " << num << " threads in the thread pool.\n\n";
		}

		curr_i = 0;
		curr_j = 0;
		_m = m;
		_n = n;
		_p = p;

		pthread_mutex_unlock(&lock);

       
        double duration;
        clock_t start;
        start = clock();

	
		if(no > num){
			threads = (pthread_t *) realloc(threads, sizeof(pthread_t) * no);
			threadstatus = (int *) realloc(threadstatus, sizeof(int) * no);
			for(;num < no; num++){
				threadstatus[num] = 1;
				pthread_create(&threads[num], NULL, (void *(*) (void *)) compute, (void *) (num + 1));
				cout << "Thread " << (num + 1) << " created\n";
			}
			cout << "\nThere are " << num <<" threads in threads.\n\n";
		}

		
		while(curr_i <_m);
        cout << "\nThe multiplied matrix is - \n";
		for(int i = 0;i < m;i++){
			for(int j = 0;j < p;j++){
				cout<<mat3[i][j]<<"\t";
			}
			cout<<"\n";
		}

	
        cout << "time: " << (clock()-start)/double(CLOCKS_PER_SEC) << endl;

		break;
	}

	return 0;
}
