#include<iostream>
using namespace std;
//初始英雄类
class Hero_Init{
	public:
		virtual int GetLevel(){
			return 0;
		}
};

//初始怪物类
class Monster_Init{
	public:
		virtual int GetLevel(){
			return 0;
		}
};

//一级英雄类
class Hero_level1:public Hero_Init
{
	public:
		int GetLevel(){
			return 1;
		}
};

//一级怪物类
class Monster_level1:public Monster_Init
{
	public:
		int GetLevel(){
			return 1;
		}
};

//对决方法
void Fight(Hero_Init* hp,Monster_Init* mp){
	cout<<"level "<<hp->GetLevel()<<" 英雄 VS level "<<mp->GetLevel()<<" 怪物"<<endl;
	if(hp->GetLevel()>mp->GetLevel())
		cout<<"英雄胜利"<<endl;
	else if(hp->GetLevel()<mp->GetLevel())
		cout<<"怪物胜利"<<endl;
	else
		cout<<"平局"<<endl;

    cout<<"--------------"<<endl;
}

//更新二级英雄，二级怪物....后续直接拓展，原先代码已经稳定，无需也不建议改动

int main(){
	Hero_Init h0;
	Monster_Init m0;
	Hero_level1 h1;
	Monster_level1 m1;
	
	Fight(&h0,&m0);	
    Fight(&h1,&m0);
    Fight(&h0,&m1);
    Fight(&h1,&m1);			

	return 0;
}

