# include<iostream>
# include<cstdlib>
# include<ctime>
using namespace std;

int begin_Y()				//to judge whether to play the game and test the input
{
	char begin;
	int judge = 0;
	cout<<"需要玩游戏吗(Y/N)？";
	cin>>begin;
	if(begin=='Y') return 1;
		else if (begin=='N') return 0;
			else {cout<<"你的输入不合法，请重新输入"<<endl;
				begin_Y();
			}
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
 		cout<<"请输入你猜测的数字："<<endl;
 		cin>>gus1>>gus2>>gus3;
 		/*while(gus1<'0' or gus1>'9' or gus2<'0' or gus2>'9' or gus3<'0' or gus3>'9') {
 			cout<<"你的输入不合法，请重新输入"<<endl;
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
 			cout<<"恭喜，你猜对了"<<endl;
 			return 0;
		 }
 			else cout<<num_A<<"A"<<num_B<<"B"<<endl;
 		i++;
 	}
 	cout<<"很遗憾，你没有在规定次数内猜对。答案是"<<num1<<num2<<num3<<endl;
 	return 0;
 }
 
 int main()
 {
 	while (1) {															//the program can be carried on infinite many times if user want
 		int flag;
 		flag=begin_Y();
 		if (flag==0) break;												//if user dont want to continue then the program will exit
 		guessNum();
 	}
	return 0;
 }
