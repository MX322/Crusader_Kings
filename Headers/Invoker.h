#include "Headers/Global.h"

void Invoker()
{
	int masskill[3]{
	0, 0, 0
	};
	int numskill = 0;

	while (true) // ����������� ���� (������� ������)
	{


		int skill = _getch(); // get character (��������� ���� ������� �������)
		cout << skill;
		if (skill == 119 || skill == 113 || skill == 101) {
			masskill[numskill] = skill;
			cout << masskill[0];//�� ����� (���������� �������� ������� � ������� ��������)
			cout << masskill[1];//�� �����
			cout << masskill[2];//�� �����
			cout << numskill;//�� �����
			numskill += 1;
			if (numskill > 2) {// �� ��� ���������� �������� ���������� �������
				numskill = 0;
			}
		}

		if (skill == 32) // ������ ������������� ������ (������)
		{

			if (masskill[0] == 113) {// ���� ������ ������� Q
				if (masskill[1] == 113 && masskill[2] == 113) {
					cout << "\n Q Q Q ";
				}
				else if (masskill[1] == 113 && masskill[2] == 119) {
					cout << "\n Q Q W ";
				}
				else if (masskill[1] == 113 && masskill[2] == 101) {
					cout << "\n Q Q E ";
				}
				else if (masskill[1] == 119 && masskill[2] == 101) {
					cout << "\n Q W E ";
				}
			}
			else if (masskill[0] == 119) {// ���� ������ ������� W
				if (masskill[1] == 119 && masskill[2] == 119) {
					cout << "\n W W W ";
				}
				else if (masskill[1] == 119 && masskill[2] == 113) {
					cout << "\n W W Q ";
				}
				else if (masskill[1] == 119 && masskill[2] == 101) {
					cout << "\n W W E ";
				}
			}
			else if (masskill[0] == 101) {// ���� ������ ������� E
				if (masskill[1] == 101 && masskill[2] == 101) {
					cout << "\n E E E ";
				}
				else if (masskill[1] == 101 && masskill[2] == 113) {
					cout << "\n E E Q ";
				}
				else if (masskill[1] == 101 && masskill[2] == 119) {
					cout << "\n E E W ";
				}

			}

		}
	}
}