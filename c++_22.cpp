//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
//class Goods {
//private:
//	int weight;
//	static int total_weight;
//	static int total_count;
//public:
//	Goods* next;
//
//	int GetWeight() {
//		return weight;
//	}
//
//	Goods() {
//		weight = 0;
//		next = NULL;
//	}
//
//	Goods(int w) {
//		weight = w;
//		total_count++;
//		total_weight += weight;
//		cout << "进货一件重量为" << weight << "的货物" << endl;
//	}
//
//	~Goods() {
//		total_count--;
//		total_weight -= weight;
//		cout << "出货一件重量为" << weight << "的货物" << endl;
//	}
//
//	static int GetTotalWeight() {
//		return total_weight;
//	}
//	
//	static int GetTotalCount() {
//		return total_count;
//	}
//};
//
//int Goods::total_weight = 0;
//int Goods::total_count = 0;
//
//void PrintMenu() {
//	cout << "1. 进货" << endl;
//	cout << "2. 出货" << endl;
//	cout << "0. 退出" << endl;
//}
//
//void buy(Goods** head,int w) {
//	if (*head == NULL)                       //将初始化和结点插入合成一个函数
//	{
//		Goods* temp = new Goods(w);                   
//		*head = temp;                        //无空头结点版单链表
//	}
//	else
//	{
//		Goods* temp = new Goods(w);
//		temp->next = (*head);
//		*head = temp;
//	}
//}
//
//void sale(Goods** head) {
//	if (*head == NULL)
//		cout << "空!" << endl;
//	else
//	{
//		Goods* tmp = *head;
//		*head = (*head)->next;
//		delete tmp;
//		tmp = NULL;
//	}
//}
//
//void FindInformation() {
//	cout << "----------------------------" << endl;
//	cout << "仓库货物的总数量：" << Goods::GetTotalCount() << endl;
//	cout << "仓库货物的总重量：" << Goods::GetTotalWeight() << endl;
//	cout << "----------------------------" << endl;
//}
//
//int main() {
//	int choose;
//	int w;
//	Goods* head=NULL;
//
//	while (true) {
//		PrintMenu();
//		cout << ">";
//		cin >> choose;
//		switch (choose)
//		{
//		case 1:
//			cout << "请输入货物重量:";
//			cin >> w;
//			buy(&head,w);
//			break;
//		case 2:
//			sale(&head);
//			break;
//		case 0:
//			return 0;
//		}
//		FindInformation();
//	}
//	return 0;
//}
//
