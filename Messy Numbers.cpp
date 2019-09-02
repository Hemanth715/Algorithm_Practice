#include<malloc.h>

extern void add_element(char *x);
extern bool check_element(char* x);
extern void compile_set();

void restore_permutation(int n, int w, int r, int* result) {
	add_element("0");
	compile_set();
	check_element("0");
	int i, j, setbit, active, start, ind, listsize, listind, ind1, ind2, cw, cr;
	cw = 0;
	cr = 0;
	bool change, check, ans;
	ans = true;
	char **str;
	int *reflist = (int*)malloc(n * sizeof(int));
	int *uplist = (int*)malloc(n * sizeof(int));
	int *temp;
	str = (char**)malloc(n * sizeof(char*));
	for (i = 0; i < n; i++)
	{
		str[i] = (char*)malloc(n * sizeof(char));
	}
	setbit = -1;
	for (i = 0; i < n / 2; i++)
	{
		for (j = 0; j < n; j++)
		{
			str[i][j] = '0';
			str[i][++setbit] = '1';
			add_element(str[i]);
		}
	}
	active = n / 2;
	while (active != 1)
	{
		start = 0;
		ind = 0;
		while (start < n)
		{
			for (i = 0; i < active / 2; i++)
			{
				for (j = 0; j < active; j++)
				{
					str[ind][start + active + j] = '1';
				}
				add_element(str[ind]);
				cw++;
				ind++;
			}
			setbit = start + active - 1;
			for (i = 0; i < active / 2; i++)
			{
				for (j = 0; j < active; j++)
				{
					str[ind][start + j] = '1';
				}
				str[ind][++setbit] = '1';
				add_element(str[ind]);
				cw++;
				ind++;
			}
			start = start + 2 * active;
		}
		active /= 2;
	}

	compile_set();

	setbit = -1;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			str[i][j] = '0';
		}
		str[i][++setbit] = '1';
	}
	for (i = 0; i < n; i++)
		reflist[i] = i;
	listsize = n;
	while (listsize != 1)
	{
		listind = 0;
		change = true;
		while (listind < n)
		{
			if (listsize != n && change)
			{
				for (i = listind; i < listind + listsize; i++)
				{
					for (j = listind + listsize; j < listind + 2 * listsize; j++)
					{
						str[reflist[i]][reflist[j]] = '1';
						str[reflist[j]][reflist[i]] = '1';
					}
				}
				change = false;
			}
			else
				change = true;
			ind1 = listind;
			ind2 = listind + listsize / 2;
			check = true;
			for (i = 0; i < listsize; i++)
			{
				if (check)
				{
					ans = check_element(str[reflist[listind + i]]);
					cr++;
				}
				if (ans)
				{
					uplist[ind1++] = reflist[listind + i];
					if (ind1 == listind + listsize / 2)
					{
						ans = false;
						check = false;
					}
				}
				else
				{
					uplist[ind2++] = reflist[listind + i];
					if (ind2 == listind + listsize)
					{
						ans = true;
						check = false;
					}
				}
			}
			listind = listind + listsize;
		}
		temp = reflist;
		reflist = uplist;
		uplist = temp;
		listsize = listsize / 2;
	}

	for (i = 0; i < n; i++)
	{
		uplist[reflist[i]] = i;
	}
	for (i = 0; i < n; i++)
	{
		result[i] = uplist[i];
	}
}