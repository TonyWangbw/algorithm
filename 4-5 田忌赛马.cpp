#include<iostream>
#include<algorithm>

using namespace std;

void saima() {
	int goal=0;
	int n;
	cin>>n;
	int a[n];
	int b[n];
	for(int i=0; i<n; i++) {
		cin>>a[i];
	}
	for(int i=0; i<n; i++) {
		cin>>b[i];
	}
	sort(a,a+n);
	sort(b,b+n);
	
	
	int right=n-1,rig=n-1;
	int left=0,le=0;
	while(le <= rig) {
		if(a[right] > b[rig]) {
			goal++;
			right--;
			rig--;
		} else if(a[right] < b[rig]) {
			//�Ų��������ӻ���
			goal--;
			left++;
			rig--;
		} /*else {
			//��һ�£�ȡ����
			if(a[left] > b[le]) {
				//����ʤ��
				goal++;
				left++;
				le++;
			} else if(a[left] < b[le]) {
				//�Ӳ��������ӻ���
				goal--;
				left++;
				rig--;
			} else {
				//��һ�£�����ս��
				if(a[left] < b[rig]) {
					//ս��lose++
					goal--;
				}
				left++;
				rig--;
			}
		}*/
	}




	cout<<goal*200<<endl;
}

int main() {
	int c;
	cin>>c;
	for(int i=0; i<c; i++) {
		saima();
	}
}


/*3
3
92 83 71
95 87 74
2
21 12
25 20
2
12 11
19 20*/

