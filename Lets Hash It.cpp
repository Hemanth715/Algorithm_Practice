struct table{
	int s;
	char* a;
};

int count = 0;

struct table t[101] = { 0 };

int hash(char* key, int s)
{
	if (key[0] == '@')
		return 0;

	int h = 0;
	for (int i = 0; i<s; i++)
		h = (h + (i + 1)*key[i]) % 101;

	h = (19 * h) % 101;
	return h;
}

bool isSame(char* input1, int size1, char* input2, int size2)
{
	bool same = true;
	if (size1 != size2)
	{
		return false;
	}

	for (int i = 0; i<size1; i++)
	{
		if (input1[i] != input2[i])
		{
			return false;
		}
	}
	return true;
}

void add(char* operation, int size)
{
	int key, temp_key;
	key = hash(operation, size);
	int empty = -1;
	bool first = true;

	for (int i = 0; i<20; i++)
	{
		temp_key = key;
		temp_key = (temp_key % 101 + (i*i) % 101 + (23 * i) % 101) % 101;

		if (t[temp_key].s == 0 && first)
		{
			empty = temp_key;
			first = false;
		}
		else if (t[temp_key].s != 0)
		{
			if (isSame(t[temp_key].a, t[temp_key].s, operation, size))
			{
				return;
			}
		}
	}
	t[empty].s = size;
	t[empty].a = new char[size + 1];
	for (int i = 0; i <= size; i++)
	{
		t[empty].a[i] = operation[i];
	}
	count++;
	return;
}

void del(char* operation, int size)
{
	int key, temp_key;
	key = hash(operation, size);

	for (int i = 0; i<20; i++)
	{
		temp_key = key;
		temp_key = (temp_key + i*i + 23 * i) % 101;

		if (t[temp_key].s != 0 && isSame(t[temp_key].a, t[temp_key].s, operation, size))
		{
			t[temp_key].s = 0;
			count--;
			return;
		}
	}
}

void processThis(char *operation, int size)
{
	if (size == 4)
	{
		operation[4] = '@';
		size = 5;
	}

	if (operation[0] == 'A')
	{
		add(operation + 4, size - 4);
	}
	else
	{
		del(operation + 4, size - 4);
	}
	return;
}



int storeOutput(char out[102][30])
{
	int k = 0;
	for (int i = 0; i<101; i++)
	{
		if (t[i].s != 0)
		{
			int index = i;
			int len = 0;
			while (index > 0)
			{
				index /= 10;
				len++;
			}
			index = i;

			out[k][len] = ':';
			int temp_len = len;

			if (index == 0)
			{
				out[k][0] = '0';
				out[k][1] = ':';
				temp_len = 1;
			}

			while (index > 0)
			{
				int digit = index % 10;
				index /= 10;
				char digit_char = digit + '0';
				out[k][len - 1] = digit_char;
				len--;
			}



			for (int j = temp_len + 1; j <= temp_len + 1 + t[i].s; j++)
			{
				if (t[i].a[j - temp_len - 1] == '@')
					out[k][j] = '\0';
				else
					out[k][j] = t[i].a[j - temp_len - 1];
			}
			k++;
		}
	}

	for (int i = 0; i<101; i++)
	{
		t[i].s = 0;
		delete t[i].a;
	}
	return k;
}
