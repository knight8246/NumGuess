# include<iostream>
# include<cstdlib>
# include<ctime>
using namespace std;

int begin_Y()				//to judge whether to play the game and test the input
{
	char begin;
	cout<<"��Ҫ����Ϸ��(Y/N)��";
	cin>>begin;
	/*if(begin=='Y') return 1;
		else if (begin=='N') return 0;
			else {cout<<"������벻�Ϸ�������������"<<endl;
				begin_Y();
			}*/
	while (begin!='Y' && begin!='N'){
		cout<<"������벻�Ϸ�������������"<<endl;
		cout<<"��Ҫ����Ϸ��(Y/N)��";
		cin>>begin;
	}
	if(begin=='Y') return 1;
		else return 0;
 } 
 
 int guessNum()
 {
 	int num1, num2, num3, num_A, num_B, i=0;
 	int gus1, gus2, gus3;
 	
 	srand(time(NULL));									//span the different random numbers from 0 to 9
 	num1 = rand()%10;
 	while (1) {
 		num2 = rand()%10;
 		if (num2!=num1) break;
	 }
 	num3 = rand()%10;
 	while (num3==num2 or num3==num1) num3 = rand()%10;
 	
 	while (i<7){														//guess number process and output each time
 		num_A=0;num_B=0;
 		cout<<"��������²�����֣�"<<endl;
 		cin>>gus1>>gus2>>gus3;
 		/*while(gus1<'0' or gus1>'9' or gus2<'0' or gus2>'9' or gus3<'0' or gus3>'9') {
 			cout<<"������벻�Ϸ�������������"<<endl;
 			cin>>gus1>>gus2>>gus3;
		 }
		cout<<int(gus1);*/
 		if (gus1==num1) ++num_A;
 			else if (gus1==num2 or gus1==num3) ++num_B;
 		if (gus2==num2) ++num_A;
 			else if (gus2==num1 or gus2==num3) ++num_B;
 		if (gus3==num3) ++num_A;
 			else if (gus3==num1 or gus3==num2) ++num_B;
 		if (num_A==3) {
 			cout<<"��ϲ����¶���"<<endl;
 			return 1;
		 }
 			else cout<<num_A<<"A"<<num_B<<"B"<<endl;
 		i++;
 	}
 	cout<<"���ź�����û���ڹ涨�����ڲ¶ԡ�����"<<num1<<num2<<num3<<endl;
 	return 0;
 }
 
 int main()
 {
 	int sum_num=0, win_num=0;
 	while (1) {															//the program can be carried on infinite many times if user want
 		int flag, judge;
 		flag=begin_Y();
 		if (flag==0) break;												//if user dont want to continue then the program will exit
 		judge = guessNum();
 		++sum_num;
 		if (judge==1) ++win_num;
 	}
 	cout<<"��һ������"<<sum_num<<"�֣�Ӯ��"<<win_num<<"�֣�����"<<sum_num-win_num<<"�֡�"<<endl; 
	return 0;
 }
