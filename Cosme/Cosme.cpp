#include"CosmeticManager.h"

int main()
{
	CosmeticManager m;
	m.showMenu();
	int choice;
	string cName;
	while (true) {
		cout << "请输入您的选择（0/1/2/3/4）：";
		cin >> choice;
		switch (choice)
		{
		case 0:
			m.exitsystem();
			break;
		case 1:
			cout << "请输入要操作的数量：";
			int n;
			cin >> n;
			m.Purchasegoods(n);
			break;
		case 2:
			system("cls");
			m.showSonMenu();
			int b;
			while (true) {
			cout << "请输入您的选择（0/1/2/3/4/5/6）：";
				cin >> b;
				switch (b) {
				case 1:
					m.SortCosmeticManager();
					system("cls");
					m.showSonMenu();
					break;
				case 2:
					cout << "输入国产或者进口？（国产 1|进口 0）";
					int type;
					cin >> type;
					m.TyproCosmrticManager(type);
					system("cls");
					m.showSonMenu();
					break;
				case 3:
					m.printCosmetic();
					system("pause");
					system("cls");
					m.showSonMenu();
					break;
				case 4:
					cout << "请输入一个单价：";
					int price;
					cin >> price;
					m.printByPriceCondition(price);
					system("cls");
					m.showSonMenu();
					break;
				case 5:
					cout << "请输入化妆品的品牌：";
					cin >> cName;
					m.printByName(cName);
					system("cls");
					m.showSonMenu();
					break;
				case 6: {
					cout << "请输入统计日期（格式：x/x/x）";
					string times;
					cin >> times;
					m.showRepertory(times);
					system("cls");
					m.showSonMenu();
					break;
				}
				default:
					break;
				}
				if (b != 1 && b != 2 && b != 3 && b != 4 && b != 5) {
					break;
				}
			}
			system("cls");
			m.showMenu();
			break;
		case 3:
			cout << "请输入要修改化妆品的品牌：";
			cin >> cName;
			m.modifyCosmetic(cName);
			system("cls");
			m.showMenu();
			break;
		case 4:
			cout << "请输入要删除化妆品的名字：";
			cin >> cName;
			m.delCosmetic(cName);
			system("cls");
			m.showMenu();
			break;
		default:
			break;
		}
	}
	return 0;
}

