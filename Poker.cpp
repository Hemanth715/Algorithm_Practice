#include<iostream>

using namespace std;

int cards[4][15];

bool arr[9] = {0};

string getstr(int i)
{
	switch (i)
	{
	case 0:
		return "Top";
	case 1:
		return "1 Pair";
	case 2:
		return "2 Pair";
	case 3:
		return "Triple";
	case 4:
		return "Straight";
	case 5:
		return "Flush";
	case 6:
		return "Full House";
	case 7:
		return "4 Card";
	case 8:
		return "Straight Flush";
		break;
	}
	return "";
}

int f(char c)
{
	if (c == 'S')
		return 0;
	if (c == 'D')
		return 1;
	if (c == 'H')
		return 2;
	return 3;
}

bool f1()
{
	int count[14] = {0};
	for (int i = 1; i <= 13; i++)
		count[i] = cards[0][i] + cards[1][i] + cards[2][i] + cards[3][i];
	int cur = 0;
	for (int i = 1; i <= 13; i++)
	{
		if (count[i] >= 2)
			cur++;
	}
	if (cur >= 1)
		return true;
	return false;
}

bool f2()
{
	int count[14] = {0};
	for (int i = 1; i <= 13; i++)
		count[i] = cards[0][i] + cards[1][i] + cards[2][i] + cards[3][i];
	int cur = 0;
	for (int i = 1; i <= 13; i++)
	{
		if (count[i] >= 2)
			cur++;
	}
	if (cur >= 2)
		return true;
	return false;
}

bool f3()
{
	int count[14] = {0};
	for (int i = 1; i <= 13; i++)
		count[i] = cards[0][i] + cards[1][i] + cards[2][i] + cards[3][i];
	int cur = 0;
	for (int i = 1; i <= 13; i++)
	{
		if (count[i] == 3)
			cur++;
	}
	if (cur == 1)
		return true;
	return false;
}

bool f4()
{
	for (int i = 1; i <= 10; i++)
	{
		bool t1[4] = {false};
		bool t2[5] = {false};
		for (int j = 0; j<4; j++)
		{
			if (cards[j][i] != 0)
			{
				t1[j] = true;
				t2[0] = true;
			}
			if (cards[j][i + 1] != 0)
			{
				t1[j] = true;
				t2[1] = true;
			}
			if (cards[j][i + 2] != 0)
			{
				t1[j] = true;
				t2[2] = true;
			}
			if (cards[j][i + 3] != 0)
			{
				t1[j] = true;
				t2[3] = true;
			}
			if (cards[j][i + 4] != 0)
			{
				t1[j] = true;
				t2[4] = true;
			}
		}
		bool a = true, b = false;
		for (int i = 0; i<5; i++)
			a = a && t2[i];
		int c = 0;
		for (int i = 0; i<4; i++)
			if (t1[i])
				c++;
		if (c>1)
			b = true;
		if (a && b)
			return true;
	}
	return false;
}

bool f5()
{
	int sum[4] = {0};
	for (int i = 0; i<4; i++)
	{
		for (int j = 1; j<14; j++)
			sum[i] += cards[i][j];
	}
	bool b = false;
	for (int i = 0; i<4; i++)
	{
		if (sum[i] >= 5)
		{
			for (int j = 1; j <= 14; j++)
			{
				if (cards[i][j] != 0)
					b = true;
				if (b && cards[i][j] == 0)
					return true;
			}
		}
	}
	return false;
}


bool f6()
{
	int count[14] = {0};
	for (int i = 1; i <= 13; i++)
	{
		count[i] = cards[0][i] + cards[1][i] + cards[2][i] + cards[3][i];
	}

	bool a = false, b = false;
	for (int i = 1; i <= 13; i++)
	{
		if (!a && count[i] >= 3) 
			a = true;
		else if (count[i] >= 2)
			b = true;
	}
	return a&&b;
}

bool f7()
{
	int count[14] = {0};
	for (int i = 1; i <= 13; i++)
	{
		count[i] = cards[0][i] + cards[1][i] + cards[2][i] + cards[3][i];
	}
	for (int i = 1; i <= 13; i++)
	{
		if (count[i] >= 4)
			return true;
	}
	return false;
}

bool f8()
{
	for (int i = 0; i<4; i++){

		for (int j = 1; j <= 10; j++)
		{
			if (cards[i][j] != 0 && cards[i][j + 1] != 0 && cards[i][j + 2] != 0 && cards[i][j + 3] != 0 && cards[i][j + 4] != 0)
				return true;
		}
	}
	return false;
}



int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{

		for (int i = 0; i<4; i++)
			for (int j = 0; j<15; j++)
				cards[i][j] = 0;

		for (int i = 0; i<7; i++)
		{
			char c; cin >> c;
			int n; cin >> n;
			cards[f(c)][n]++;
			if (n == 1) cards[f(c)][14]++;

		}
		for (int i = 1; i <= 8; i++)
			arr[i] = false;
		arr[0] = true;
		arr[1] = f1();
		arr[2] = f2();
		arr[3] = f3();
		arr[4] = f4();
		arr[5] = f5();
		arr[6] = f6();
		arr[7] = f7();
		arr[8] = f8();
		for (int i = 8; i >= 0; i--)
		{
			if (arr[i])
			{
				cout << "#" << test_case << " " << getstr(i) << endl;
				break;
			}
		}
	}
	return 0;
}
